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

    sec_idx_to_name = {s['idx']: s['name'] for s in sections}

    symtab = next((s for s in sections if s['name'] == '.symtab'), None)
    strtab = next((s for s in sections if s['name'] == '.strtab'), None)
    rela_rodata = next((s for s in sections if s['name'] == '.rela.rodata'), None)

    strtab_data = elf_data[strtab['offset'] : strtab['offset'] + strtab['size']]
    def get_str(idx):
        if idx >= len(strtab_data):
            return ""
        end = idx
        while end < len(strtab_data) and strtab_data[end] != 0:
            end += 1
        return strtab_data[idx:end].decode('utf-8')

    symbols = []
    sym_entry_size = 24
    for offset in range(symtab['offset'], symtab['offset'] + symtab['size'], sym_entry_size):
        entry = elf_data[offset : offset + sym_entry_size]
        st_name, st_info, st_other, st_shndx, st_value, st_size = struct.unpack('<IBBHQQ', entry)
        symbols.append({
            'idx': len(symbols),
            'name': get_str(st_name),
            'value': st_value,
            'size': st_size,
            'shndx': st_shndx,
            'info': st_info
        })

    relocs = []
    if rela_rodata:
        rela_entry_size = 24
        for offset in range(rela_rodata['offset'], rela_rodata['offset'] + rela_rodata['size'], rela_entry_size):
            entry = elf_data[offset : offset + rela_entry_size]
            r_offset, r_info, r_addend = struct.unpack('<QQq', entry)
            sym_idx = r_info >> 32
            relocs.append({
                'offset': r_offset,
                'sym_idx': sym_idx,
                'addend': r_addend,
                'type': r_info & 0xffffffff
            })

    relocs.sort(key=lambda r: r['offset'])
    
    # We want to print relocations in .rodata at 0xdd8 to 0xe10
    # Let's find the .rodata section address/offset
    rodata_sec = next((s for s in sections if s['name'] == '.rodata'), None)
    if rodata_sec:
        print(f".rodata section has idx={rodata_sec['idx']}, size={rodata_sec['size']}, addr=0x{rodata_sec['addr']:x}")
        
    for r in relocs:
        if 0xdd8 <= r['offset'] < 0xe10:
            sym = symbols[r['sym_idx']]
            target_shndx = sym['shndx']
            target_val = sym['value'] + r['addend']
            sh_name = sec_idx_to_name.get(target_shndx, f"SEC_{target_shndx}")
            
            # Read string directly from ELF file if it points to .rodata.str1.1
            str_val = "N/A"
            if sh_name == '.rodata.str1.1':
                str_sec = next((s for s in sections if s['name'] == '.rodata.str1.1'), None)
                if str_sec:
                    file_offset = str_sec['offset'] + target_val
                    end_idx = file_offset
                    while end_idx < len(elf_data) and elf_data[end_idx] != 0:
                        end_idx += 1
                    str_val = elf_data[file_offset:end_idx].decode('utf-8', errors='replace')
                    
            print(f"Offset 0x{r['offset']:04x}: points to {sym['name'] or sh_name}+0x{r['addend']:x} -> '{str_val}'")

if __name__ == '__main__':
    parse_elf('vendor/zte/zte_tpd/official_zte_tpd.ko')
