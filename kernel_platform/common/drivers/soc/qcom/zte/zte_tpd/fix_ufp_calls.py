#!/usr/bin/env python3
import os

TPD_DIR = os.path.dirname(os.path.abspath(__file__))
files_to_fix = [
    "syna_dev_process_touch_report.c",
    "syna_dev_resume.c",
    "set_finger_lock_flag.c",
    "syna_dev_free_input_events.c"
]

def main():
    for filename in files_to_fix:
        filepath = os.path.join(TPD_DIR, filename)
        if not os.path.exists(filepath):
            continue
            
        with open(filepath, "r", encoding="utf-8") as f:
            content = f.read()
            
        modified = False
        # Replace the casts with direct function call
        targets = [
            "((void (__fastcall *)(__int64))report_ufp_uevent)(",
            "((void (__fastcall *)(_QWORD))report_ufp_uevent)("
        ]
        
        for target in targets:
            if target in content:
                content = content.replace(target, "report_ufp_uevent(")
                modified = True
                
        if modified:
            with open(filepath, "w", encoding="utf-8") as f:
                f.write(content)
            print(f"Fixed report_ufp_uevent call in {filename}")

if __name__ == "__main__":
    main()
