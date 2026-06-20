#!/usr/bin/env python3
import os

TPD_DIR = os.path.dirname(os.path.abspath(__file__))

def main():
    c_files = [os.path.join(TPD_DIR, f) for f in os.listdir(TPD_DIR) if f.endswith(".c")]
    
    targets = {
        "cancel_report_lcd_state_delayed_work()": "cancel_report_lcd_state_delayed_work(void)",
        "get_lcd_panel_name()": "get_lcd_panel_name(void)",
        "syna_hw_interface_exit()": "syna_hw_interface_exit(void)",
        "syna_dev_module_exit()": "syna_dev_module_exit(void)",
        "cleanup_module()": "cleanup_module(void)"
    }
    
    total_replaced = 0
    for filepath in c_files:
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
            
        modified = False
        for old, new in targets.items():
            if old in content:
                content = content.replace(old, new)
                modified = True
                
        if modified:
            with open(filepath, "w", encoding="utf-8") as f:
                f.write(content)
            total_replaced += 1
            print(f"Fixed prototypes in {os.path.basename(filepath)}")
            
    print(f"Total prototype files modified: {total_replaced}")

if __name__ == "__main__":
    main()
