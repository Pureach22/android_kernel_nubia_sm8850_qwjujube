#!/usr/bin/env python3
import struct
import sys

# Official CRCs list
OFFICIAL_CRCS = {
    "ktime_get_with_offset": 0x9d1dd621,
    "ns_to_timespec64": 0xb219cb65,
    "_printk": 0x16b5b21d,
    "__stack_chk_fail": 0xd272d446,
    "alarm_try_to_cancel": 0xefa2bcf5,
    "alarm_start_relative": 0xe4d5dbb6,
    "queue_delayed_work_on": 0xbb4f284a,
    "sscanf": 0xf5197fd4,
    "__pm_stay_awake": 0xa2abfdcd,
    "__pm_relax": 0xa2abfdcd,
    "snprintf": 0xf4386284,
    "power_supply_get_by_name": 0x4c5ea0f6,
    "power_supply_get_property": 0xb7cfc328,
    "power_supply_put": 0xc5d0024b,
    "__platform_driver_register": 0x26d0cf2d,
    "platform_driver_unregister": 0x8af50346,
    "power_supply_set_property": 0x9bda58c6,
    "zte_power_supply_get_by_name": 0x2442e63e,
    "zte_power_supply_get_property": 0x99e4d443,
    "zte_power_supply_put": 0x37f3a7b5,
    "zte_power_supply_set_property": 0xa1d8d1c7,
    "zte_poweroff_charging_status": 0x7851be11,
    "devm_kmalloc": 0xd1263f9d,
    "of_property_read_variable_u32_array": 0x5de0294f,
    "of_property_read_string": 0xfc9f25c0,
    "devm_kfree": 0x963fe25e,
    "alloc_workqueue": 0xc531e61f,
    "delayed_work_timer_fn": 0xb0f9b474,
    "init_timer_key": 0x534026f3,
    "power_supply_unreg_notifier": 0x8c705ff7,
    "wakeup_source_unregister": 0xa2abfdcd,
    "alarm_init": 0xf61597b3,
    "power_supply_reg_notifier": 0x0a227d4d,
    "devm_power_supply_register": 0x492e2f3a,
    "zte_misc_register_callback": 0xfd820cec,
    "wakeup_source_register": 0x6f3ab219,
    "power_supply_changed": 0xc5d0024b,
    "strcmp": 0xf5df0401,
    "power_supply_get_drvdata": 0x8d332884,
    "module_layout": 0xe976b219,
    "param_ops_ulong": 0xfc32a8b7,
    "bus_find_device": 0xaba5547a,
    "put_device": 0x2aa807c4,
    "cancel_delayed_work_sync": 0x22a4e35b,
    "destroy_workqueue": 0xc3325950,
    "platform_bus_type": 0x021aff95,
}

# Official KCFI Hashes list (Little Endian)
KCFI_HASHES = {
    # Module Init/Exit
    "init_module": 0x6fbb3035,
    "cleanup_module": 0xe5c47d60,
    
    # zte_cleanup.c
    "match_device_name": 0x41e74928,
    
    # alarm / work / notifier callbacks
    "charger_policy_timeout_alarm_cb": 0xaeec016a,
    "charger_policy_probe_work": 0xa607748c,
    "charger_policy_timeout_handler_work": 0xa607748c,
    "charger_policy_notifier_switch": 0xd5127a3b,
    
    # power_supply callbacks
    "policy_psy_get_property": 0xe8990cd3,
    "policy_psy_set_property": 0x719ad693,
    "policy_property_is_writeable": 0x618f9ead,
    "policy_external_power_changed": 0x19768773,
    
    # zte_misc set callbacks
    "charger_policy_demo_sts_set": 0x4cf999cb,
    "charger_policy_expired_sec_set": 0x4cf999cb,
    "charger_policy_force_disching_sec_set": 0x4cf999cb,
    "charger_policy_cap_min_set": 0x4cf999cb,
    "charger_policy_cap_max_set": 0x4cf999cb,
    "charger_policy_enable_status_set": 0x4cf999cb,
    
    # zte_misc get/show callbacks
    "charger_policy_demo_sts_get": 0x2990b6e9,
    "charger_policy_expired_sts_get": 0x2990b6e9,
    "charger_policy_expired_sec_get": 0x2990b6e9,
    "charger_policy_force_disching_sec_get": 0x2990b6e9,
    "charger_policy_cap_min_get": 0x2990b6e9,
    "charger_policy_cap_max_get": 0x2990b6e9,
    "charger_policy_enable_status_get": 0x2990b6e9,
    
    # platform driver probe/remove/get_status
    "charger_policy_get_status": 0x2fad8a96,
    "charger_policy_probe": 0xc7f8c87c,
    "charger_policy_remove": 0x24a11bb9,
}

def patch_kcfi(f, data, e_shoff, e_shentsize, e_shnum, e_shstrndx):
    # Find Section Name String Table (shstrtab)
    shstrtab_entry = e_shoff + e_shstrndx * e_shentsize
    shstrtab_offset = struct.unpack('<Q', data[shstrtab_entry + 24 : shstrtab_entry + 32])[0]
    
    # Maps section index to (offset, size, name)
    sections = {}
    for i in range(e_shnum):
        entry = e_shoff + i * e_shentsize
        sh_name_idx = struct.unpack('<I', data[entry : entry + 4])[0]
        sh_type = struct.unpack('<I', data[entry + 4 : entry + 8])[0]
        sh_offset = struct.unpack('<Q', data[entry + 24 : entry + 32])[0]
        sh_size = struct.unpack('<Q', data[entry + 32 : entry + 40])[0]
        
        name_offset = shstrtab_offset + sh_name_idx
        section_name = data[name_offset:].split(b'\x00', 1)[0].decode('utf-8', errors='ignore')
        
        if sh_type in (1, 14, 15): # SHT_PROGBITS
            sections[i] = {
                'offset': sh_offset,
                'size': sh_size,
                'name': section_name
            }
            
    # Find Symtab
    symtab_offset = None
    symtab_size = None
    strtab_offset = None
    
    for i in range(e_shnum):
        entry = e_shoff + i * e_shentsize
        sh_type = struct.unpack('<I', data[entry + 4 : entry + 8])[0]
        if sh_type == 2: # SHT_SYMTAB
            symtab_offset = struct.unpack('<Q', data[entry + 24 : entry + 32])[0]
            symtab_size = struct.unpack('<Q', data[entry + 32 : entry + 40])[0]
            sh_link = struct.unpack('<I', data[entry + 40 : entry + 44])[0]
            strtab_entry = e_shoff + sh_link * e_shentsize
            strtab_offset = struct.unpack('<Q', data[strtab_entry + 24 : strtab_entry + 32])[0]
            break
            
    if not symtab_offset or not strtab_offset:
        print("Could not find symtab or strtab for KCFI patching!")
        return

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
        
        # Check if it is a function (STT_FUNC)
        if (st_info & 0xf) == 2 and st_size > 0:
            if st_shndx in sections:
                sec = sections[st_shndx]
                if sec['name'] in ('.text', '.init.text', '.exit.text'):
                    if name in KCFI_HASHES:
                        target_hash = KCFI_HASHES[name]
                        # The hash is located in the 4 bytes immediately preceding the function entry point
                        if st_value >= 4:
                            func_file_offset = sec['offset'] + st_value
                            hash_file_offset = func_file_offset - 4
                            
                            # Read current hash
                            current_hash = struct.unpack('<I', data[hash_file_offset : hash_file_offset + 4])[0]
                            if current_hash != target_hash:
                                print(f"Patching KCFI hash for '{name}' in {sec['name']}: {hex(current_hash)} -> {hex(target_hash)}")
                                f.seek(hash_file_offset)
                                f.write(struct.pack('<I', target_hash))
                            else:
                                print(f"KCFI hash for '{name}' already matches: {hex(current_hash)}")

def patch_ko(filename):
    with open(filename, 'r+b') as f:
        data = f.read()
        
        # Read ELF64 Header
        assert data[:4] == b'\x7fELF'
        e_shoff = struct.unpack('<Q', data[40:48])[0]
        e_shentsize = struct.unpack('<H', data[58:60])[0]
        e_shnum = struct.unpack('<H', data[60:62])[0]
        e_shstrndx = struct.unpack('<H', data[62:64])[0]
        
        # Find __versions section
        shstrtab_offset = struct.unpack('<Q', data[e_shoff + e_shstrndx * e_shentsize + 24 : e_shoff + e_shstrndx * e_shentsize + 32])[0]
        
        versions_offset = None
        versions_size = None
        
        for i in range(e_shnum):
            sh_entry = e_shoff + i * e_shentsize
            sh_name_idx = struct.unpack('<I', data[sh_entry : sh_entry + 4])[0]
            
            # Get section name
            name_offset = shstrtab_offset + sh_name_idx
            section_name = data[name_offset:].split(b'\x00', 1)[0].decode('utf-8', errors='ignore')
            
            if section_name == '__versions':
                versions_offset = struct.unpack('<Q', data[sh_entry + 24 : sh_entry + 32])[0]
                versions_size = struct.unpack('<Q', data[sh_entry + 32 : sh_entry + 40])[0]
                break
                
        if versions_offset is None:
            print("Could not find __versions section!")
            sys.exit(1)
            
        print(f"Found __versions section at offset {hex(versions_offset)}, size {versions_size} bytes")
        
        # Parse and patch version structures
        entry_size = 64
        num_entries = versions_size // entry_size
        
        for i in range(num_entries):
            offset = versions_offset + i * entry_size
            crc, padding = struct.unpack('<II', data[offset : offset + 8])
            name = data[offset + 8 : offset + 64].split(b'\x00', 1)[0].decode('utf-8', errors='ignore')
            
            if name in OFFICIAL_CRCS:
                target_crc = OFFICIAL_CRCS[name]
                if crc != target_crc:
                    print(f"Patching symbol '{name}': {hex(crc)} -> {hex(target_crc)}")
                    f.seek(offset)
                    f.write(struct.pack('<I', target_crc))
                else:
                    print(f"Symbol '{name}' already matches: {hex(crc)}")
            else:
                print(f"Warning: Symbol '{name}' not found in official list (CRC: {hex(crc)})")
                
        print("Versions CRCs patched. Starting KCFI patching...")
        patch_kcfi(f, data, e_shoff, e_shentsize, e_shnum, e_shstrndx)
        print("KCFI patching finished.")

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: patch_module.py <module.ko>")
        sys.exit(1)
    patch_ko(sys.argv[1])
