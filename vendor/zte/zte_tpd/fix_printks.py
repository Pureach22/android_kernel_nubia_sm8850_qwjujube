#!/usr/bin/env python3
import os

TPD_DIR = os.path.dirname(os.path.abspath(__file__))

def main():
    c_files = [os.path.join(TPD_DIR, f) for f in os.listdir(TPD_DIR) if f.endswith(".c")]
    
    total_replaced = 0
    for filepath in c_files:
        if filepath.endswith("globals.c"):
            continue
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
            
        modified = False
        # Find references to &unk_ and replace with unk_
        if "&unk_" in content:
            # We can use simple string replacement because "&unk_" is always followed by hexadecimal digits
            content = content.replace("&unk_", "unk_")
            modified = True
            
        if modified:
            with open(filepath, "w", encoding="utf-8") as f:
                f.write(content)
            total_replaced += 1
            print(f"Fixed printk format pointers in {os.path.basename(filepath)}")
            
    print(f"Total printk format files modified: {total_replaced}")

if __name__ == "__main__":
    main()
