import re

def clean_ramoops():
    input_path = '/home/adrianojr59/Vídeos/NX809J_Android16_kernel/scratch/ramoops.log'
    output_path = '/home/adrianojr59/Vídeos/NX809J_Android16_kernel/scratch/ramoops_clean.txt'
    
    with open(input_path, 'rb') as f:
        data = f.read()
        
    # Replace null bytes with spaces, decodes non-ascii characters gracefully
    decoded = data.decode('utf-8', errors='replace')
    
    # Let's clean up backspaces or null chars
    cleaned = re.sub(r'[\x00-\x08\x0b\x0c\x0e-\x1f]', '', decoded)
    
    with open(output_path, 'w', encoding='utf-8') as f:
        f.write(cleaned)
        
    print(f"Cleaned ramoops written to {output_path}")

if __name__ == '__main__':
    clean_ramoops()
