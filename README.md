<div align="center">

# Tremolo Audio Plugin

[![License](https://img.shields.io/badge/license-Unlicense-blue.svg)](LICENSE.md)
![CMake](https://img.shields.io/badge/CMake-3.25+-064F8C.svg?logo=cmake)
![C++](https://img.shields.io/badge/C++-23-00599C.svg?logo=cplusplus)
![JUCE](https://img.shields.io/badge/JUCE-8.0.10-orange.svg)
![Platform](https://img.shields.io/badge/platform-macOS%20%7C%20Windows%20%7C%20Linux-lightgrey.svg)

<img alt="Tremolo user interface" src="docs/UI.png" width="512px">

A cross-platform real-time **Tremolo** audio effect plugin built with modern **C++23** and **JUCE 8**, featuring selectable LFO waveforms, real-time LFO visualization, and DAW state persistence.

</div>

---

## ✨ Overview & Features

* **Multi-Format Support:** Native builds for **VST3**, **AU**, and **Standalone** targets.
* **Real-Time Amplitude Modulation:** Sub-audio-rate tremolo DSP engine with adjustable **Modulation Rate**, switchable **LFO Waveforms**, and click-free **Bypass**.
* **Interactive GUI & Visualization:** Custom user interface featuring a real-time LFO waveform display synchronized with audio processing.
* **DAW State Persistence:** Full XML parameter and state serialization for seamless preset management and project recall.
* **Modern C++ Engineering:**
  * Built in **C++23** with automated dependency management via [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake).
  * DSP unit testing integrated with [GoogleTest](https://github.com/google/googletest).
  * Consistent code style and static analysis enforced via `.clang-format` and `.clang-tidy`.

---

## 📂 Project Structure

```text
Audio-Plugin-Juce-Project/
├── plugin/                  # Core plugin source code (DSP engine, GUI editor, unit tests, CMake config)
├── docs/                    # UI screenshots and visual assets
├── .clang-format            # C++ code formatting rules
├── .clang-tidy              # Static code analysis rules
└── LICENSE.md               # License terms