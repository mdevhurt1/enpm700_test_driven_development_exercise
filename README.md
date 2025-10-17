# enpm700_test_driven_development_exercise

# Badges
![CICD Workflow status](https://github.com/mdevhurt1/enpm700_test_driven_development_exercise/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg) [![codecov](https://codecov.io/gh/mdevhurt1/enpm700_test_driven_development_exercise/branch/main/graph/badge.svg)](https://codecov.io/gh/mdevhurt1/enpm700_test_driven_development_exercise) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

# Authors

## Part 1

- Marcus Hurt (`mdevhurt1`) - Driver, Navigator

## Part 2

- Venkata Madhav Tadavarthi (`madhav2133`) - Driver
- Rahul Kumar (`rahulk-99`) - Navigator

# UML Diagram
![PID Controller Class Diagram](libs/pid_controller/pid_controller_UML_diagram.png)

<!-- # Future Work
The file in libs/pid_controller pid_controller.cpp contains stubs for the implementation of the PID class. There are inline TODO comments for the work that is needed.

## Inline TODOs in `pid_controller.cpp`
- Implement constructor logic to initialize PID gains and internal state.
- Implement `compute()` method for PID control logic.
- Implement getter methods: `getKp()`, `getKi()`, `getKd()`.
- Implement setter methods: `setKp()`, `setKi()`, `setKd()`.
- Implement `reset()` method to clear internal state (integral, previous error). -->

### Project Structure
The project uses:
- CMake for build management
- GoogleTest for unit testing
- Doxygen for documentation

### Basic Installation and Setup
```bash
# Clone the repository
git clone https://github.com/mdevhurt1/enpm700_test_driven_development_exercise.git
cd enpm700_test_driven_development_exercise

# Configure and build the project
cmake -S ./ -B build/
cmake --build build/

```

### Implementation
The PID controller implementation consists of:
- Header (`libs/pid_controller/pid_controller.hpp`): Class declaration with gains (kp, ki, kd)
- Source (`libs/pid_controller/pid_controller.cpp`): Implementation returning constant value

To run the implementation:
```bash
./build/app/shell-app
```

### Testing
The project includes unit tests for the PID controller in `test/pid_test.cpp`:
- Stub implementation verification
- Constructor initialization test
- Edge cases testing (zero, large, negative velocities)

To run the tests:
```bash
./build/test/cpp-test
```

## Additional test suggestions for `pid_controller_test.cpp`

Below are concrete unit tests we recommend adding to increase coverage and catch common PID bugs. Add these at the end of `test/pid_controller_test.cpp` (or a new test file) as small, focused GoogleTest cases.

- Proportional-only behavior
	- Set Kp != 0, Ki = Kd = 0. Verify output = Kp * error for a single call to compute(error, dt).

- Integral accumulation and reset
	- Set Ki != 0, Kp = Kd = 0. Call compute() repeatedly with a constant error and verify the output increases over time (integral grows).
	- Call reset() and verify subsequent compute() does not include the previous integral (output drops accordingly).

- Derivative term correctness
	- Set Kd != 0, Kp = Ki = 0. Feed two inputs separated by a known dt and verify the derivative term contribution equals Kd * (error - prev_error) / dt (within a small tolerance).

- Zero and very small dt handling
	- Ensure compute(..., dt=0) does not divide-by-zero or crash. Expectation: implementation should guard against dt==0 (return 0 derivative or handle safely). Test that the call is safe and deterministic.

- Negative and large gains
	- Verify behavior with negative gains (output should follow the algebraic sign) and with very large gains (ensure no unexpected overflow/crash).

- Sequence / step response smoke test
	- Provide a short sequence of inputs (e.g., step from 0 to target) and assert qualitative behavior: the controller should move the output in the correct direction and not produce NaNs or Infs.