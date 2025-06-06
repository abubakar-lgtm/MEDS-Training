# 📘 Digital Design & Computer Architecture – Lecture Summaries

This repository contains summaries of core topics covered in the "Digital Design and Computer Architecture" course. The notes aim to simplify concepts, clarify distinctions, and help you revise efficiently.

---

## 📚 Lecture 1: Introduction & Transistors

### 🧠 Course Goals
- Understand how computers work from the ground up.
- Learn digital design and computer architecture principles.
- Design and debug a simple microprocessor.
- Think critically and systematically about computing systems.

### 💡 What is a Computer?
- Comprised of computation, communication, and storage/memory.
- Translates from Problem → Algorithm → Program → System Software → Hardware.

### 🧱 Transformation Hierarchy
- Electrons → Devices → Logic → Architecture → Language → Problem.
- Co-design across layers is essential.

### 💻 General-Purpose vs. Special-Purpose Systems
- **CPUs**: Flexible and programmable.
- **GPUs/ASICs/FPGAs**: High performance, less flexibility.

### ⚙️ Transistors and CMOS Logic
- **MOSFETs**: NMOS conducts when Gate=High; PMOS conducts when Gate=Low.
- **CMOS Inverter**: PMOS + NMOS = NOT gate.

### 📈 Moore’s Law
- Transistor count doubles ~every 2 years → better performance and cost efficiency.

---

## 🔧 Lecture 2: Logic Gates and Boolean Algebra

### 🔌 Logic Basics
- Combinational logic: output = f(inputs).
- Gates: AND, OR, NOT, NAND, NOR, XOR.
- Avoid floating inputs; use tri-state buffers for buses.

### 🧮 Boolean Algebra
- Tools: DeMorgan’s Laws, Duality, Truth Tables.
- Canonical forms: SOP (Σm), POS (ΠM).
- Laws: Commutative, Associative, Distributive.

### 🧱 Building Blocks
- **Decoder**: n inputs → 2^n outputs.
- **Multiplexer**: 2^n inputs → 1 output.
- **Adders**: Half, Full, Ripple-Carry.
- **PLAs**: Flexible SOP logic.
- Minimization: Boolean Algebra, Karnaugh Maps, Quine-McCluskey.

---

## 🔁 Lecture 3: Sequential Logic

### 🔄 Combinational vs. Sequential
- **Sequential**: Output depends on inputs AND previous state.
- Requires storage: Latches, Flip-Flops.

### 🧠 Memory Elements
- SR Latch, D Latch, D Flip-Flop (edge-triggered).
- Registers = Group of Flip-Flops.
- Memory = Addressable array of registers.

### 🚦 Finite State Machines (FSMs)
- Components: States, Inputs/Outputs, Transition Logic.
- **Moore FSM**: output depends on state.
- **Mealy FSM**: output depends on state + input.

---

## 🚦 Lecture 4: FSM Design & FPGA Introduction

### ✅ FSM Design Process
1. Identify states.
2. Define transitions and outputs.
3. Choose encoding: binary, one-hot, output-encoded.
4. Draw state diagram/table.
5. Implement using Flip-Flops and logic.

### 🕒 Timing Concepts
- Setup Time, Hold Time.
- Clock Period must accommodate logic delay.
- Clock Skew affects timing margins.

### 🔌 FPGA Overview
- LUT-based logic, configurable routing.
- Use cases: AI, bioinformatics, cryptography.

---

## 💻 Lecture 5: Verilog & Hardware Description Languages

### 🛠️ HDL Motivation
- Supports structural & behavioral modeling.
- Simulation and synthesis for digital circuits.

### 🧱 Verilog Essentials
- Modules, `assign`, `always` blocks.
- Operators: `&`, `|`, `~`, `^`, `? :`, `case`.

### 📦 Behavioral vs Structural
- **Behavioral**: Describes what circuit does.
- **Structural**: Describes how it’s built.

### 🧬 FSM in Verilog
- 3-part model: State Register, Next-State Logic, Output Logic.

---

## ⏱️ Lecture 6: Timing & Verification

### 🧭 Circuit Timing

#### Combinational
- **Propagation delay (tpd)**: Max output delay.
- **Contamination delay (tcd)**: Min output delay.
- Glitches: Due to unequal delays.

#### Sequential
- **Setup Time**: Data stable before clock.
- **Hold Time**: Data stable after clock.
- **Clock-to-Q delay**: Time from clock to output change.

- Timing equations:
  - Setup: `Tc > tpcq + tpd + tsetup`
  - Hold: `tccq + tcd > thold`

- Clock Skew impacts timing margins.

### 🧪 Verification Types
- **Functional**: Logic correctness.
- **Timing**: Meet setup/hold constraints.
- **Simulation**: Testbenches (manual, self-checking, golden models).
- **Formal Verification**: SAT solvers, model checking.

### 🛠️ Tools & Optimization
- Vivado, SPICE, Logic Synthesis, Place-and-Route.
- Use pipelining, critical path reduction.
- Consider process variation and worst-case delays.

---

## ✅ Best Practices & Pitfalls

### ✅ Do:
- Plan for timing from the beginning.
- Write synthesizable Verilog.
- Use self-checking testbenches.
- Balance logic across flip-flop paths.
- Document everything clearly.

### ❌ Avoid:
- Ignoring hold time or skew.
- Mixed blocking/non-blocking assignments.
- Incomplete `case` or `if` statements.
- Over-reliance on simulation without timing checks.

---
