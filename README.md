# DFA Minimization Project

## Overview
This project implements two distinct algorithms for minimizing Deterministic Finite Automata (DFA) using C++:
1. **Myhill-Nerode Theorem Implementation** (`MyhillNerode.cpp`)
2. **Partition Refinement Method** (`PartitioningMethod.cpp`)

Both programs take a DFA as input, defined by a set of states, transitions, and accepting states, and output a minimized DFA with the smallest possible number of states while preserving the language recognized by the original DFA.

---

## Features
- **Input Flexibility**: Accepts user-defined DFA configurations, including the number of states, transitions for inputs `a` and `b`, and accepting states.
- **Myhill-Nerode Implementation**:
  - Uses a table-filling algorithm to identify distinguishable states.
  - Groups equivalent states to construct the minimized DFA.
  - Outputs a clear transition table and state mappings.
- **Partition Refinement Implementation**:
  - Employs iterative partitioning to group states based on their behavior.
  - Displays the minimized DFA's transitions with concatenated state names.
- **Error Handling**: Validates user inputs to ensure states and transitions are within valid ranges.
- **Clear Output**: Both implementations provide formatted outputs, including state mappings, transition tables, and accepting states.

---

## Prerequisites
- A C++ compiler (e.g., g++, clang++) supporting C++11 or later.
- Standard C++ libraries (`iostream`, `vector`, `unordered_map`, `unordered_set`, `algorithm`).
- Git (for cloning the repository).

---

## Installation
1. Clone the project repository:
   ```bash
   git clone https://github.com/AbdullahShariq/DFA-Minimization.git
   cd DFA-Minimization
   ```
2. Ensure a C++ compiler is installed on your system.
3. Compile the source files using:
   ```bash
   g++ -o MyhillNerode MyhillNerode.cpp
   g++ -o PartitioningMethod PartitioningMethod.cpp
   ```

---

## Usage
1. **Running MyhillNerode.cpp**:
   - Execute the compiled program:
     ```bash
     ./MyhillNerode
     ```
   - Enter the number of states.
   - For each state, input the next state for inputs `a` and `b` (e.g., `q0` for state 0).
   - Specify the number of accepting states and their identifiers.
   - The program outputs the minimized DFA, including the number of states, state mappings, transition table, and accepting states.

2. **Running Partitioning Method.cpp**:
   - Execute the compiled program:
     ```bash
     ./PartitioningMethod
     ```
   - Follow similar input prompts as above.
   - The program outputs the minimized DFA with state concatenations and transitions.

  ---

## Algorithm Details
- **Myhill-Nerode Theorem**:
  - Marks pairs of states as distinguishable if one is accepting and the other is not.
  - Iteratively marks pairs based on transitions leading to distinguishable states.
  - Groups indistinguishable states to form the minimized DFA.
- **Partition Refinement**:
  - Starts with two groups: accepting and non-accepting states.
  - Refines groups by comparing transitions for inputs `a` and `b`.
  - Continues until no further partitioning is possible, yielding the minimized DFA.

---

## Acknowledgments
- Inspired by the Myhill-Nerode theorem and partition refinement techniques from automata theory.
- Built for educational purposes to demonstrate DFA minimization.

