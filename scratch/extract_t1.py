def main():
    log_path = "/home/adrianojr59/Vídeos/NX809J_Android16_kernel/new-console-ramoops-clean.txt"
    with open(log_path, 'r', errors='ignore') as f:
        lines = f.readlines()
        
    t1_lines = []
    for i, line in enumerate(lines):
        if "T1]" in line:
            t1_lines.append(f"L{i+1}: {line.strip()}")
            
    with open("/home/adrianojr59/Vídeos/NX809J_Android16_kernel/scratch/t1_lines.txt", "w") as out:
        out.write("\n".join(t1_lines))
        
    print(f"Extracted {len(t1_lines)} lines to scratch/t1_lines.txt")

if __name__ == '__main__':
    main()
