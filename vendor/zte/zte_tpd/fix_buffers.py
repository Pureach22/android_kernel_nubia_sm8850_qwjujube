#!/usr/bin/env python3
import os

TPD_DIR = os.path.dirname(os.path.abspath(__file__))

def main():
    c_files = [os.path.join(TPD_DIR, f) for f in os.listdir(TPD_DIR) if f.endswith(".c")]
    
    total_replaced = 0
    for filepath in c_files:
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
            
        modified = False
        if "char s[8];" in content:
            content = content.replace("char s[8];", "char s[32];")
            modified = True
            
        if "char s[4];" in content:
            content = content.replace("char s[4];", "char s[32];")
            modified = True
            
        if modified:
            with open(filepath, "w", encoding="utf-8") as f:
                f.write(content)
            total_replaced += 1
            print(f"Fixed buffer size in {os.path.basename(filepath)}")
            
    print(f"Total files modified: {total_replaced}")

if __name__ == "__main__":
    main()
