# Code Debugging and Optimization — C++ Game Target Selector

## Scope note
The task instructions refer to a supplied code snippet, but no snippet was present in the task text available to me. This package therefore uses a clearly labeled illustrative example: finding the nearest active enemy in a 2D game. Confirm with the internship provider that a self-selected example is acceptable.

## Files
- `src/original_snippet.cpp`: illustrative buggy version.
- `src/TargetSelector.h`: refactored implementation.
- `tests/test_target_selector.cpp`: assertion-based test cases.
- `Debugging_Optimization_Report.pdf`: analysis, annotations, testing plan, and performance discussion.

## Compile and run (g++)
```bash
g++ -std=c++17 -Isrc tests/test_target_selector.cpp -o target_selector_tests
./target_selector_tests
```
In Visual Studio, create a C++ Console App, add the test `.cpp` file, ensure `src` is an additional include directory, then build and run.

## Main issues fixed
1. Initializing the best distance to zero meant no non-negative distance could be smaller, so the old function returned -1 for all inputs.
2. Square roots were computed unnecessarily; comparing squared distances gives the same nearest-item ordering.
3. The refactor uses `std::size_t` for vector indexing and a const reference to avoid copying each enemy.

Run tests yourself and report the actual observed results. No measured benchmark numbers are claimed in this package.
