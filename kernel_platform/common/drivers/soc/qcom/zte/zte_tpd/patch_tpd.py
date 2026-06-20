#!/usr/bin/env python3
import struct
import sys
import os

def parse_elf_sections_and_syms(filename):
    with open(filename, 'rb') as f:
        data = f.read()
        
    assert data[:4] == b'\x7fELF'
    e_shoff = struct.unpack('<Q', data[40:48])[0]
    e_shentsize = struct.unpack('<H', data[58:60])[0]
    e_shnum = struct.unpack('<H', data[60:62])[0]
    e_shstrndx = struct.unpack('<H', data[62:64])[0]
    
    shstrtab_offset = struct.unpack('<Q', data[e_shoff + e_shstrndx * e_shentsize + 24 : e_shoff + e_shstrndx * e_shentsize + 32])[0]
    
    sections = {}
    symtab_offset = None
    symtab_size = None
    strtab_offset = None
    
    for i in range(e_shnum):
        entry = e_shoff + i * e_shentsize
        sh_name_idx = struct.unpack('<I', data[entry : entry + 4])[0]
        sh_type = struct.unpack('<I', data[entry + 4 : entry + 8])[0]
        sh_offset = struct.unpack('<Q', data[entry + 24 : entry + 32])[0]
        sh_size = struct.unpack('<Q', data[entry + 32 : entry + 40])[0]
        
        name_offset = shstrtab_offset + sh_name_idx
        section_name = data[name_offset:].split(b'\x00', 1)[0].decode('utf-8', errors='ignore')
        
        sections[i] = {
            'offset': sh_offset,
            'size': sh_size,
            'name': section_name,
            'type': sh_type
        }
        
        if sh_type == 2: # SHT_SYMTAB
            symtab_offset = sh_offset
            symtab_size = sh_size
            sh_link = struct.unpack('<I', data[entry + 40 : entry + 44])[0]
            strtab_entry = e_shoff + sh_link * e_shentsize
            strtab_offset = struct.unpack('<Q', data[strtab_entry + 24 : strtab_entry + 32])[0]

    symbols = []
    if symtab_offset and strtab_offset:
        sym_entry_size = 24
        num_symbols = symtab_size // sym_entry_size
        for i in range(num_symbols):
            offset = symtab_offset + i * sym_entry_size
            st_name = struct.unpack('<I', data[offset : offset + 4])[0]
            st_info = data[offset + 4]
            st_shndx = struct.unpack('<H', data[offset + 6 : offset + 8])[0]
            st_value = struct.unpack('<Q', data[offset + 8 : offset + 16])[0]
            st_size = struct.unpack('<Q', data[offset + 16 : offset + 24])[0]
            
            name = data[strtab_offset + st_name:].split(b'\x00', 1)[0].decode('utf-8', errors='ignore')
            symbols.append({
                'name': name,
                'info': st_info,
                'shndx': st_shndx,
                'value': st_value,
                'size': st_size
            })
            
    return data, sections, symbols

def extract_official_data(official_ko):
    data, sections, symbols = parse_elf_sections_and_syms(official_ko)
    
    # Extract CRCs from __versions section
    versions_sec = next((sec for sec in sections.values() if sec['name'] == '__versions'), None)
    official_crcs = {}
    if versions_sec:
        entry_size = 64
        num_entries = versions_sec['size'] // entry_size
        for i in range(num_entries):
            offset = versions_sec['offset'] + i * entry_size
            crc, padding = struct.unpack('<II', data[offset : offset + 8])
            name = data[offset + 8 : offset + 64].split(b'\x00', 1)[0].decode('utf-8', errors='ignore')
            official_crcs[name] = crc
            
    # Extract KCFI hashes
    kcfi_hashes = {}
    for sym in symbols:
        # Check if it is a function (STT_FUNC)
        if (sym['info'] & 0xf) == 2 and sym['size'] > 0:
            if sym['shndx'] in sections:
                sec = sections[sym['shndx']]
                if sec['name'] in ('.text', '.init.text', '.exit.text'):
                    if sym['value'] >= 4:
                        func_file_offset = sec['offset'] + sym['value']
                        hash_file_offset = func_file_offset - 4
                        kcfi_hash = struct.unpack('<I', data[hash_file_offset : hash_file_offset + 4])[0]
                        kcfi_hashes[sym['name']] = kcfi_hash
                        
    return official_crcs, kcfi_hashes

def patch_custom_ko(custom_ko, official_crcs, kcfi_hashes):
    # Parse custom KO sections and symbols
    with open(custom_ko, 'r+b') as f:
        data = f.read()
        
        # Read ELF64 Header info
        e_shoff = struct.unpack('<Q', data[40:48])[0]
        e_shentsize = struct.unpack('<H', data[58:60])[0]
        e_shnum = struct.unpack('<H', data[60:62])[0]
        e_shstrndx = struct.unpack('<H', data[62:64])[0]
        
        _, sections, symbols = parse_elf_sections_and_syms(custom_ko)
        
        # 1. Patch __versions
        versions_sec = next((sec for sec in sections.values() if sec['name'] == '__versions'), None)
        if versions_sec:
            print(f"Found __versions section at offset {hex(versions_sec['offset'])}")
            entry_size = 64
            num_entries = versions_sec['size'] // entry_size
            for i in range(num_entries):
                offset = versions_sec['offset'] + i * entry_size
                crc, padding = struct.unpack('<II', data[offset : offset + 8])
                name = data[offset + 8 : offset + 64].split(b'\x00', 1)[0].decode('utf-8', errors='ignore')
                
                if name in official_crcs:
                    target_crc = official_crcs[name]
                    if crc != target_crc:
                        print(f"Patching CRC for '{name}': {hex(crc)} -> {hex(target_crc)}")
                        f.seek(offset)
                        f.write(struct.pack('<I', target_crc))
                    else:
                        print(f"CRC for '{name}' already matches: {hex(crc)}")
                else:
                    print(f"Warning: Symbol '{name}' not found in official CRCs list")
        else:
            print("Could not find __versions section in custom KO!")
            
        # 2. Patch KCFI hashes
        print("Starting KCFI hashes patching...")
        for sym in symbols:
            if (sym['info'] & 0xf) == 2 and sym['size'] > 0:
                if sym['shndx'] in sections:
                    sec = sections[sym['shndx']]
                    if sec['name'] in ('.text', '.init.text', '.exit.text'):
                        if sym['name'] in kcfi_hashes:
                            target_hash = kcfi_hashes[sym['name']]
                            if sym['value'] >= 4:
                                func_file_offset = sec['offset'] + sym['value']
                                hash_file_offset = func_file_offset - 4
                                current_hash = struct.unpack('<I', data[hash_file_offset : hash_file_offset + 4])[0]
                                if current_hash != target_hash:
                                    print(f"Patching KCFI hash for '{sym['name']}': {hex(current_hash)} -> {hex(target_hash)}")
                                    f.seek(hash_file_offset)
                                    f.write(struct.pack('<I', target_hash))

if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("Usage: patch_tpd.py <official_tpd.ko> <custom_tpd.ko>")
        sys.exit(1)
        
    official = sys.argv[1]
    custom = sys.argv[2]
    
    print(f"Extracting signatures from {official}...")
    crcs, hashes = extract_official_data(official)
    print(f"Extracted {len(crcs)} CRCs and {len(hashes)} KCFI hashes.")
    
    print(f"Patching {custom}...")
    patch_custom_ko(custom, crcs, hashes)
    print("Done!")
