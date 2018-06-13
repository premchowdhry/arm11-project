#include "utilities.h"
#include <stdint.h>

// Checks the bit pattern of the instruction to determine its type.
instructionType getInstructionType(uint32_t instruction) {
    if (CHECK_BIT(instruction, 27) && !CHECK_BIT(instruction, 26) && CHECK_BIT(instruction, 25) && !CHECK_BIT(instruction, 24)) {
        return BRANCH;
    }
    else if (!CHECK_BIT(instruction, 27) && CHECK_BIT(instruction, 26) && !CHECK_BIT(instruction, 22) && !CHECK_BIT(instruction, 21)) {
        return DATA_TRANSFER;
    }
    else if (!CHECK_BIT(instruction, 27) && !CHECK_BIT(instruction, 26) && !CHECK_BIT(instruction, 25) && !CHECK_BIT(instruction, 24)
             && !CHECK_BIT(instruction, 23) && !CHECK_BIT(instruction, 22)
             && CHECK_BIT(instruction, 7) && !CHECK_BIT(instruction, 6) && !CHECK_BIT(instruction, 5) && CHECK_BIT(instruction, 4)) {
                return MULTIPLY;
    }
    else {
        return DATA_PROCESSING;
    }
}

// Returns the struct contained the decoded components of the provided Data Processing instruction.
decodedInstruction decodeDP(uint32_t instruction) {
    decodedInstruction decoded;
    decoded.type = DATA_PROCESSING;

    uint32_t result = extractBits(instruction, 4, 29);
    decoded.cond = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 1, 26);
    decoded.i = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 4, 22);
    decoded.opcode = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 1, 21);
    decoded.s = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 4, 17);
    decoded.rn = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 4, 13);
    decoded.rd = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 12, 1);
    decoded.operand2 = ((uint16_t*)(&result))[0];

    return decoded;
}

decodedInstruction decodeBranch(uint32_t instruction) {
    decodedInstruction decoded;
    decoded.type = BRANCH;
    uint32_t result = extractBits(instruction, 4, 29);
    decoded.cond = ((uint8_t*)(&result))[0];
    decoded.offset = extractBits(instruction, 24, 1);

    return decoded;
}

// Decodes a Multiply instruction.
decodedInstruction decodeMultiply(uint32_t instruction) {
    decodedInstruction decoded;
    decoded.type = MULTIPLY;

    uint32_t result = 0;
    result = extractBits(instruction, 4, 29);
    decoded.cond = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 1, 22);
    decoded.a = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 1, 21);
    decoded.s = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 4, 17);
    decoded.rd = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 4, 13);
    decoded.rn = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 4, 9);
    decoded.rs = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 4, 1);
    decoded.rm = ((uint8_t*)(&result))[0];

    return decoded;
}

// Decodes Single Data Transfer instructions
decodedInstruction decodeDT(uint32_t instruction) {
    decodedInstruction decoded;
    decoded.type = DATA_TRANSFER;

    uint32_t result = 0;
    result = extractBits(instruction, 4, 29);
    decoded.cond = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 1, 26);
    decoded.i = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 1, 25);
    decoded.p = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 1, 24);
    decoded.u = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 1, 21);
    decoded.l = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 4, 17);
    decoded.rn = ((uint8_t*)(&result))[0];

    result = extractBits(instruction, 4, 13);
    decoded.rd = ((uint8_t*)(&result))[0];

    decoded.offset = extractBits(instruction, 12, 1);

    return decoded;
}