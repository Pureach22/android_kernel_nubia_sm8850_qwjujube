#!/usr/bin/env python3
import os
import re

TPD_DIR = os.path.dirname(os.path.abspath(__file__))

def main():
    c_files = [os.path.join(TPD_DIR, f) for f in os.listdir(TPD_DIR) if f.endswith(".c")]
    
    # Matches:
    # if ( *((_DWORD *)v2 - 1) != 1945898361 )
    #   __break(0x8228u);
    pattern = re.compile(
        r'if\s*\(\s*\*\(\(_DWORD\s*\*\)\s*\w+\s*-\s*1\)\s*!=\s*\d+\s*\)\s*\n?\s*__break\(0x[0-9a-fA-F]+u?\);',
        re.MULTILINE
    )
    
    total_replaced = 0
    for filepath in c_files:
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
            
        new_content, count = pattern.subn("/* CFI check removed */", content)
        if count > 0:
            with open(filepath, "w", encoding="utf-8") as f:
                f.write(new_content)
            total_replaced += count
            print(f"Replaced {count} CFI checks in {os.path.basename(filepath)}")
            
    print(f"Total CFI checks removed: {total_replaced}")

if __name__ == "__main__":
    main()
