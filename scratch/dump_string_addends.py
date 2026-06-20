import struct

def parse_elf(filename):
    with open(filename, 'rb') as f:
        elf_data = f.read()

    e_shoff = struct.unpack('<Q', elf_data[40:48])[0]
    e_shentsize = struct.unpack('<H', elf_data[58:60])[0]
    e_shnum = struct.unpack('<H', elf_data[60:62])[0]
    e_shstrndx = struct.unpack('<H', elf_data[62:64])[0]

    sections = []
    for i in range(e_shnum):
        sh_offset = e_shoff + i * e_shentsize
        sh_hdr = elf_data[sh_offset : sh_offset + e_shentsize]
        sh_name, sh_type, sh_flags, sh_addr, sh_offset_file, sh_size = struct.unpack('<IIQQQQ', sh_hdr[:40])
        sections.append({
            'idx': i,
            'name_idx': sh_name,
            'type': sh_type,
            'flags': sh_flags,
            'addr': sh_addr,
            'offset': sh_offset_file,
            'size': sh_size
        })

    shstrtab_offset = sections[e_shstrndx]['offset']
    def get_sh_name(idx):
        end = shstrtab_offset + idx
        while elf_data[end] != 0:
            end += 1
        return elf_data[shstrtab_offset + idx : end].decode('utf-8')

    for s in sections:
        s['name'] = get_sh_name(s['name_idx'])

    str_sec = next((s for s in sections if s['name'] == '.rodata.str1.1'), None)
    if not str_sec:
        print("No .rodata.str1.1 section found")
        return

    addends = [47210, 31432, 5692]
    for addend in addends:
        file_offset = str_sec['offset'] + addend
        end_idx = file_offset
        while end_idx < len(elf_data) and elf_data[end_idx] != 0:
            end_idx += 1
        str_val = elf_data[file_offset:end_idx].decode('utf-8', errors='replace')
        print(f"Addend {addend} (0x{addend:x}): '{str_val}'")

if __name__ == '__main__':
    parse_elf('vendor/zte/zte_tpd/official_zte_tpd.ko')
