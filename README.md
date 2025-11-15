# Initial parsing engine implementation
STILL IN DEVELOPMENT (my first project)
This is the first stable version of the text parser.

## 🚀 Core features
- Line-by-line parsing system
- Whitespace normalization (`trimAndCollapse`)
- Configurable preprocessing pipeline:
  - lowercase conversion
  - punctuation removal (with hyphen support)
  - optional digit ignoring
- Safe usage of `<cctype>` functions using `static_cast<unsigned char>` to avoid UB

- ## 📊 Analytics
The parser now collects:
- total words  
- total letters  
- total digits  
- total characters

- ## 🛠 File validation
Includes:
- path checks  
- file existence  
- type check (regular file)  
- size limit validation  
- extension filtering (`.txt`, `.log`)

- ## 🔧 Code structure
- `Parser` — text processing core  
- `Analytics` — statistic counters  
- `ParseSettings` — settings container  
- `MultiThreadParser` — entry point for future multithread support  

---

This version establishes the base architecture for future enhancements.
