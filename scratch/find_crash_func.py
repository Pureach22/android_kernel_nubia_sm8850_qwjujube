import struct
import sys

def search_instructions():
    # Little-endian instruction bytes for AArch64
    seq = (
        b'\xfd\x7b\xbd\xa9' + # stp x29, x30, [sp, #-0x30]!
        b'\xf6\x57\x01\xa9' + # stp x22, x21, [sp, #0x10]
        b'\xf4\x4f\x02\xa9' + # stp x20, x19, [sp, #0x20]
        b'\xfd\x03\x00\x91' + # mov x29, sp
        b'\x08\x04\x40\xf9'   # ldr x8, [x0, #0x8]
    )
    
    with open('vendor/zte/zte_tpd/official_zte_tpd.ko', 'rb') as f:
        data = f.read()
        
    idx = data.find(seq)
    if idx == -1:
        # Let's try without the first instruction in case it starts without PAC (paciasp)
        print("Sequence not found with PAC, trying without paciasp...")
        # What if it has paciasp (d503233f)?
        seq_pac = b'\x3f\x23\x03\xd5' + seq
        idx = data.find(seq_pac)
        if idx != -1:
            print(f"Found with PAC at offset: {hex(idx)}")
            return
        
        # Let's search for the first few instructions
        seq_short = seq[:16]
        idx = data.find(seq_short)
        while idx != -1:
            print(f"Found short sequence at offset: {hex(idx)}")
            idx = data.find(seq_short, idx + 1)
    else:
        print(f"Found exact sequence at offset: {hex(idx)}")

if __name__ == '__main__':
    search_instructions()
