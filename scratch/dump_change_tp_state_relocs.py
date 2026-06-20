import struct
import sys

def parse_elf(filename):
    with open(filename, 'rb') as f:
        elf_data = f.read()

    # Read ELF64 header
    e_shoff = struct.unpack('<Q', elf_data[40:48])[0]
    e_shentsize = struct.unpack('<H', elf_data[58:60])[0]
    e_shnum = struct.unpack('<H', elf_data[60:62])[0]
    e_shstrndx = struct.unpack('<H', elf_data[62:64])[0]

    # Parse section headers
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

    # Get shstrtab
    shstrtab_offset = sections[e_shstrndx]['offset']
    def get_sh_name(idx):
        end = shstrtab_offset + idx
        while elf_data[end] != 0:
            end += 1
        return elf_data[shstrtab_offset + idx : end].decode('utf-8')

    for s in sections:
        s['name'] = get_sh_name(s['name_idx'])

    sec_idx_to_name = {s['idx']: s['name'] for s in sections}

    # Find sections
    symtab = next((s for s in sections if s['name'] == '.symtab'), None)
    strtab = next((s for s in sections if s['name'] == '.strtab'), None)
    rela_text = next((s for s in sections if s['name'] == '.rela.text'), None)

    # Read string table
    strtab_data = elf_data[strtab['offset'] : strtab['offset'] + strtab['size']]
    def get_str(idx):
        if idx >= len(strtab_data):
            return ""
        end = idx
        while end < len(strtab_data) and strtab_data[end] != 0:
            end += 1
        return strtab_data[idx:end].decode('utf-8')

    # Read symbol table
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

    # Parse relocations
    relocs = []
    if rela_text:
        rela_entry_size = 24
        for offset in range(rela_text['offset'], rela_text['offset'] + rela_text['size'], rela_entry_size):
            entry = elf_data[offset : offset + rela_entry_size]
            r_offset, r_info, r_addend = struct.unpack('<QQq', entry)
            sym_idx = r_info >> 32
            relocs.append({
                'offset': r_offset,
                'sym_idx': sym_idx,
                'addend': r_addend,
                'type': r_info & 0xffffffff
            })

    # Sort relocations by offset
    relocs.sort(key=lambda r: r['offset'])
    for r in relocs:
        # Range of change_tp_state function in .text
        if 0x861c <= r['offset'] < 0x8794:
            sym = symbols[r['sym_idx']]
            print(f"Offset 0x{r['offset']:04x}: type={r['type']} sym_idx={r['sym_idx']} name='{sym['name']}' value=0x{sym['value']:x} shndx={sym['shndx']} addend={r['addend']}")

if __name__ == '__main__':
    parse_elf('vendor/zte/zte_tpd/official_zte_tpd.ko')
