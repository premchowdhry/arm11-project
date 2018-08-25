# ARM11 project

## Source Code

See the `src` directory.

- `emulate.c` contains the main functionality for the emulator.
- `assemble.c` contains the main functionality for the assembler.
- `emulate_utils` contains helper functions for emulate.
- `assemble_utils` contains helper functions for assemble.

You can make emulate using `make emulate`, and assemble using `make assemble`.

## Tests

See `test_suite` for our extended ruby test suite.

## Documentation

See the `doc` directory. Use `make` to generate the pdf files.

- `Checkpoint.pdf` is the checkpoint report.
- `Report.pdf` is the final report.
- `LaTeX Documentation/refman.pdf` is the documentation for emulate and assemble.

## GPIO

See `programs` for the Part III GPIO program. This can be assembled using `assemble` from `src`. It has been emulated and tested on the Raspberry Pi and works as intended.

## Extension: 7-Segment LED Display
