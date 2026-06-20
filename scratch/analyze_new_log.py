import re

def main():
    log_path = "/home/adrianojr59/Vídeos/NX809J_Android16_kernel/new-console-ramoops-clean.txt"
    with open(log_path, 'r', errors='ignore') as f:
        lines = f.readlines()
    
    print(f"Total lines: {len(lines)}")
    
    # 1. Print all occurrences of 'insmod' or 'failed' or 'duplicate'
    interesting_patterns = [
        re.compile(r'insmod', re.IGNORECASE),
        re.compile(r'duplicate', re.IGNORECASE),
        re.compile(r'verification failed', re.IGNORECASE),
        re.compile(r'exec format error', re.IGNORECASE),
        re.compile(r'InitFatalReboot', re.IGNORECASE),
    ]
    
    found_any = False
    for i, line in enumerate(lines):
        for pattern in interesting_patterns:
            if pattern.search(line):
                print(f"Line {i+1}: {line.strip()}")
                found_any = True
                break
                
    if not found_any:
        print("No matching patterns found.")

if __name__ == '__main__':
    main()
