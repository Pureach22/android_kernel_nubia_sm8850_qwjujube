#!/usr/bin/env python3
import os
import re

TPD_DIR = os.path.dirname(os.path.abspath(__file__))

def main():
    c_files = [os.path.join(TPD_DIR, f) for f in os.listdir(TPD_DIR) if f.endswith(".c") and f not in ["globals.c", "offset_test.c"]]
    
    # Sets to collect variables
    qwords = set()
    dwords = set()
    words = set()
    bytes_val = set()
    unks = set()
    
    # To check which unks are accessed without '&'
    # We read all file contents into memory
    all_content = ""
    for filepath in c_files:
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            all_content += f.read() + "\n"
            
    # Find all matches
    qwords.update(re.findall(r'\bqword_[0-9A-Fa-f]+\b', all_content))
    dwords.update(re.findall(r'\bdword_[0-9A-Fa-f]+\b', all_content))
    words.update(re.findall(r'\bword_[0-9A-Fa-f]+\b', all_content))
    bytes_val.update(re.findall(r'\bbyte_[0-9A-Fa-f]+\b', all_content))
    unks.update(re.findall(r'\bunk_[0-9A-Fa-f]+\b', all_content))
    
    print(f"Found: {len(qwords)} qwords, {len(dwords)} dwords, {len(words)} words, {len(bytes_val)} bytes, {len(unks)} unks.")
    
    # Classify unks
    unk_as_var = set()
    unk_as_str = set()
    for unk in unks:
        # Search for occurrences of unk not preceded by '&'
        # To be robust, we search for all occurrences of unk
        # and see if any of them is not preceded by '&' (ignoring whitespace)
        pattern = r'(?:&\s*)?' + unk
        matches = re.findall(pattern, all_content)
        
        has_var_access = False
        for m in matches:
            if not m.startswith('&'):
                has_var_access = True
                break
                
        if has_var_access:
            unk_as_var.add(unk)
        else:
            unk_as_str.add(unk)
            
    print(f"Classified unks: {len(unk_as_var)} as variables, {len(unk_as_str)} as strings.")
    
    # Write globals.h
    header_path = os.path.join(TPD_DIR, "globals.h")
    with open(header_path, "w", encoding="utf-8") as h:
        h.write("#ifndef _GLOBALS_H\n#define _GLOBALS_H\n\n#include <linux/types.h>\n\n")
        
        h.write("// qwords\n")
        for q in sorted(qwords):
            h.write(f"extern uint64_t {q};\n")
            
        h.write("\n// dwords\n")
        for d in sorted(dwords):
            h.write(f"extern uint32_t {d};\n")
            
        h.write("\n// words\n")
        for w in sorted(words):
            h.write(f"extern uint16_t {w};\n")
            
        h.write("\n// bytes\n")
        for b in sorted(bytes_val):
            h.write(f"extern uint8_t {b};\n")
            
        h.write("\n// unk as variables\n")
        for uv in sorted(unk_as_var):
            h.write(f"extern uint64_t {uv};\n")
            
        h.write("\n// unk as format strings\n")
        for us in sorted(unk_as_str):
            h.write(f"extern char {us}[];\n")
            
        h.write("\n#endif // _GLOBALS_H\n")
        
    # Write globals.c
    source_path = os.path.join(TPD_DIR, "globals.c")
    with open(source_path, "w", encoding="utf-8") as s:
        s.write("#include \"globals.h\"\n\n")
        
        s.write("// qwords definitions\n")
        for q in sorted(qwords):
            s.write(f"uint64_t {q} = 0;\n")
            
        s.write("\n// dwords definitions\n")
        for d in sorted(dwords):
            s.write(f"uint32_t {d} = 0;\n")
            
        s.write("\n// words definitions\n")
        for w in sorted(words):
            s.write(f"uint16_t {w} = 0;\n")
            
        s.write("\n// bytes definitions\n")
        for b in sorted(bytes_val):
            s.write(f"uint8_t {b} = 0;\n")
            
        s.write("\n// unk as variables definitions\n")
        for uv in sorted(unk_as_var):
            s.write(f"uint64_t {uv} = 0;\n")
            
        s.write("\n// unk as format strings definitions\n")
        for us in sorted(unk_as_str):
            # Define them as format-safe string containing "%p" or plain text
            s.write(f"char {us}[256] = \"zte_tpd_log\";\n")
            
    print("Successfully generated globals.h and globals.c!")

if __name__ == "__main__":
    main()
