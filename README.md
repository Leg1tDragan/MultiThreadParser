# MultiThreadParser

[![C++](https://img.shields.io/badge/C%2B%2B-11-00599C?style=flat&logo=c%2B%2B)](https://en.wikipedia.org/wiki/C%2B%2B)  
[![GitHub](https://img.shields.io/badge/GitHub-Repository-24292F?style=flat&logo=github)](https://github.com/Leg1tDragan/MultiThreadParser)  
[![License](https://img.shields.io/badge/License-MIT-green)](https://opensource.org/licenses/MIT)

## 🚀 Overview

**MultiThreadParser** is a high-performance, multi-threaded text parsing engine built with **C++11**. It processes large files efficiently. The parser supports various text transformations, file validation, and provides statistics on parsed data.
---

## 🔑 Key Features

- **🚀 Multi-Threaded Parsing**:  
  Accelerates the parsing process by splitting the task across multiple threads, ideal for large-scale data processing.

- **⚙️ Customizable Preprocessing**:
  - Convert text to lowercase.
  - Remove punctuation (with support for hyphenation).
  - Optionally filter digits.
  - Custom text filters for preprocessing.

- **📊 Analytics**:  
  Collects statistics about the parsed content:
  - Total words
  - Total letters
  - Total digits
  - Total characters

- **🔒 Safe Data Handling**:  
  Uses `static_cast<unsigned char>` to ensure safe handling of characters, avoiding undefined behavior.

- **🛠 File Validation**:  
  Ensures the input file is valid, checking:
  - File path existence
  - Correct file type (regular files only)
  - Size constraints
  - Supported file extensions (e.g., `.txt`, `.log`)

---

## ⚡ Quick Start

### 1. Clone the repository

```bash
git clone https://github.com/Leg1tDragan/MultiThreadParser.git
cd MultiThreadParser
