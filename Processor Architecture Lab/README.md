<!-- =========================================================================================
                                     HEADER SECTION
     ========================================================================================= -->
<div align="center">

  <!-- Title -->
  # Processor Architecture Lab

  <!-- Subtitle -->
  ### CSL403 · Semester IV · Computer Engineering

  <!-- Badges -->
  [![Curated by](https://img.shields.io/badge/Curated%20by-Amey%20Thakur-blue.svg)](https://github.com/Amey-Thakur)
  [![Experiments](https://img.shields.io/badge/Experiments-10-yellowgreen.svg)](#quick-navigation)
  [![Language](https://img.shields.io/badge/Language-C%20%7C%20Logisim-blueviolet.svg)](.)
  [![Lab Manual](https://img.shields.io/badge/Lab%20Manual-Available-brightgreen.svg)](PRACTICAL%20LAB.pdf)

  <!-- Short Description -->
  **A comprehensive collection of 10 experiments covering processor architecture, arithmetic algorithms, digital circuit design, and memory organization with detailed documentation and industry-standard practices.**

  ---

  <!-- Navigation Links -->
  **[How to Use](#how-to-use)** &nbsp;·&nbsp; **[Learning Path](#learning-path)** &nbsp;·&nbsp; **[Lab Manual](#lab-manual)** &nbsp;·&nbsp; **[Experiment 1](#experiment-1-introduction-to-processor-architecture)** &nbsp;·&nbsp; **[Experiment 2](#experiment-2-booths-multiplication-algorithm)** &nbsp;·&nbsp; **[Experiment 3](#experiment-3-restoring-division-algorithm)** &nbsp;·&nbsp; **[Experiment 4](#experiment-4-ripple-carry-adder-design)** &nbsp;·&nbsp; **[Experiment 5](#experiment-5-alu-design)** &nbsp;·&nbsp; **[Experiment 6](#experiment-6-shift-register-design)** &nbsp;·&nbsp; **[Experiments 7-10](#experiments-7-10-advanced-topics)**

</div>

---

> [!TIP]
> **Circuit Visualization**: When working with Logisim circuits, always trace signal propagation step-by-step and verify truth tables for each component. For algorithms like Booth's multiplication and restoring division, draw timing diagrams showing register states at each clock cycle. Understanding the hardware-software relationship is key to mastering processor architecture.

> [!WARNING]
> **Hardware Testing**: Always test your Logisim circuits with multiple test cases including edge cases (all 0s, all 1s, maximum values). Document the truth tables and verify outputs match expected results before final submission.

---

<!-- =========================================================================================
                                     HOW TO USE SECTION
     ========================================================================================= -->
## How to Use

### C Programs (Experiments 2-3)

1. **Navigate** to the desired experiment folder
2. **Open** the `.c` file
3. **Compile** using: `gcc filename.c -o output -lm`
4. **Run** using: `./output` (Linux/Mac) or `output.exe` (Windows)

Example:
```bash
cd "Experiment-2"
gcc Booths_Multiplication_Algorithm.c -o Booths -lm
./Booths
```

### Logisim Circuits (Experiments 4-6)

1. **Download** [Logisim](http://www.cburch.com/logisim/) or [Logisim Evolution](https://github.com/logisim-evolution/logisim-evolution)
2. **Open** the `.circ` file in Logisim
3. **Simulate** the circuit using the built-in tools

---

<!-- =========================================================================================
                                     LEARNING PATH SECTION
     ========================================================================================= -->
## Learning Path

**Beginner Level:**
- Start with Experiment 1 (Introduction to Processor Architecture)
- Understand basic processor concepts and architecture fundamentals

**Intermediate Level:**
- Explore Experiments 2-3 (Arithmetic Algorithms)
- Learn Booth's multiplication and restoring division algorithms
- Study Experiments 4-6 (Digital Circuit Design)
- Design and simulate adders, ALU, and shift registers in Logisim

**Advanced Level:**
- Study Experiments 7-8 (Control Unit and Memory)
- Understand control unit design and memory organization
- Analyze Experiments 9-10 (Cache and Pipelining)
- Master cache memory design and pipelining concepts

---

<!-- =========================================================================================
                                     LAB MANUAL SECTION
     ========================================================================================= -->
## Lab Manual

| Resource | Description |
|:---|:---|
| [PRACTICAL LAB.pdf](PRACTICAL%20LAB.pdf) | Complete laboratory manual with all experiments |

---

<!-- =========================================================================================
                                     EXPERIMENT 1
     ========================================================================================= -->
## Experiment 1: Introduction to Processor Architecture

| # | Resource | Description |
|:---|:---|:---|
| 1 | [AMEY_B-50_PAL_EXPERIMENT-1.pdf](Experiment-1/AMEY_B-50_PAL_EXPERIMENT-1.pdf) | Introduction to processor architecture concepts |

---

<!-- =========================================================================================
                                     EXPERIMENT 2
     ========================================================================================= -->
## Experiment 2: Booth's Multiplication Algorithm

| # | Program | Algorithm | Description |
|:---|:---|:---|:---|
| 1 | [Booths_Multiplication_Algorithm.c](Experiment-2/Booths_Multiplication_Algorithm.c) | Booth's Algorithm | Signed binary multiplication using two's complement |

**Output**: [View Output](Experiment-2/Output.png)

---

<!-- =========================================================================================
                                     EXPERIMENT 3
     ========================================================================================= -->
## Experiment 3: Restoring Division Algorithm

| # | Program | Algorithm | Description |
|:---|:---|:---|:---|
| 1 | [Restoring_Division_Algorithm.c](Experiment-3/Restoring_Division_Algorithm.c) | Restoring Division | Binary division with restoration step |

---

<!-- =========================================================================================
                                     EXPERIMENT 4
     ========================================================================================= -->
## Experiment 4: Ripple Carry Adder Design

| # | Circuit | Description |
|:---|:---|:---|
| 1 | [RIPPLE_CARRY_ADDER.circ](Experiment-4/RIPPLE_CARRY_ADDER.circ) | 4-bit Ripple Carry Adder in Logisim |

**Circuit Diagrams**: [Half Adder](Experiment-4/HALF_ADDER.png) · [Full Adder](Experiment-4/FULL_ADDER.png) · [Ripple Carry Adder](Experiment-4/RIPPLE_CARRY_ADDER.png)

---

<!-- =========================================================================================
                                     EXPERIMENT 5
     ========================================================================================= -->
## Experiment 5: ALU Design

| # | Circuit | Description |
|:---|:---|:---|
| 1 | [ALU.circ](Experiment-5/ALU.circ) | Basic ALU component |
| 2 | [ALU_Design.circ](Experiment-5/ALU_Design.circ) | Complete ALU design in Logisim |

---

<!-- =========================================================================================
                                     EXPERIMENT 6
     ========================================================================================= -->
## Experiment 6: Shift Register Design

| # | Circuit | Description |
|:---|:---|:---|
| 1 | [SHIFT_REGISTER.circ](Experiment-6/SHIFT_REGISTER.circ) | Complete shift register implementation |

**Circuit Diagrams**: [Left Shift](Experiment-6/LEFT_SHIFT_REGISTER.png) · [Right Shift](Experiment-6/RIGHT_SHIFT_REGISTER.png) · [PIPO](Experiment-6/PIPO_SHIFT_REGISTER.png)

---

<!-- =========================================================================================
                                     EXPERIMENTS 7-10
     ========================================================================================= -->
## Experiments 7-10: Advanced Topics

| # | Experiment | Topic | Resource |
|:---|:---|:---|:---|
| 7 | **Experiment 7** | Control Unit Design | [View](Experiment-7/AMEY_B-50_PAL_EXPERIMENT-7.pdf) |
| 8 | **Experiment 8** | Memory Organization | [View](Experiment-8/AMEY_B-50_PAL_EXPERIMENT-8.pdf) |
| 9 | **Experiment 9** | Cache Memory Design | [View](Experiment-9/AMEY_B-50_PAL_EXPERIMENT-9.pdf) |
| 10 | **Experiment 10** | Pipelining Concepts | [View](Experiment-10/AMEY_B-50_PAL_EXPERIMENT-10.pdf) |

---


<!-- =========================================================================================
                                     FOOTER SECTION
     ========================================================================================= -->
<div align="center">

  <!-- Footer Navigation -->
  **[↑ Back to Top](#processor-architecture-lab)**

  **[How to Use](#how-to-use)** &nbsp;·&nbsp; **[Learning Path](#learning-path)** &nbsp;·&nbsp; **[Lab Manual](#lab-manual)** &nbsp;·&nbsp; **[Experiment 1](#experiment-1-introduction-to-processor-architecture)** &nbsp;·&nbsp; **[Experiment 2](#experiment-2-booths-multiplication-algorithm)** &nbsp;·&nbsp; **[Experiment 3](#experiment-3-restoring-division-algorithm)** &nbsp;·&nbsp; **[Experiment 4](#experiment-4-ripple-carry-adder-design)** &nbsp;·&nbsp; **[Experiment 5](#experiment-5-alu-design)** &nbsp;·&nbsp; **[Experiment 6](#experiment-6-shift-register-design)** &nbsp;·&nbsp; **[Experiments 7-10](#experiments-7-10-advanced-topics)**

  <br>

  **[🏠 Back to Main Repository](../)**

  ---

  ### [Computer Organization and Architecture and Processor Architecture Lab](https://github.com/Amey-Thakur/COMPUTER-ORGANIZATION-AND-ARCHITECTURE-AND-PROCESSOR-ARCHITECTURE-LAB)

  **CSC403 & CSL403 · Semester IV · Computer Engineering**

  *University of Mumbai · Curated by [Amey Thakur](https://github.com/Amey-Thakur)*

</div>
