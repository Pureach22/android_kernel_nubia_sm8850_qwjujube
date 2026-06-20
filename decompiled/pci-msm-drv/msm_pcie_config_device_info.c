__int64 __fastcall msm_pcie_config_device_info(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x0
  __int64 v5; // x2
  _QWORD *v6; // x1
  unsigned int v7; // w0
  int v8; // w8
  __int64 result; // x0
  unsigned int v10; // w22

  if ( a2 )
  {
    ipc_log_string(
      *(_QWORD *)(a2 + 1704),
      "DBG1:%s: PCI device found: vendor-id:0x%x device-id:0x%x\n",
      "msm_pcie_config_device_info",
      *(unsigned __int16 *)(a1 + 60),
      *(unsigned __int16 *)(a1 + 62));
    ipc_log_string(
      *(_QWORD *)(a2 + 1696),
      "%s: PCI device found: vendor-id:0x%x device-id:0x%x\n",
      "msm_pcie_config_device_info",
      *(unsigned __int16 *)(a1 + 60),
      *(unsigned __int16 *)(a1 + 62));
  }
  if ( (*(_WORD *)(a1 + 114) & 0xF0) == 0 )
  {
    v4 = (_QWORD *)_kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 24);
    if ( !v4 )
      return 4294967284LL;
    v5 = a2 + 1584;
    v6 = *(_QWORD **)(a2 + 1592);
    v4[2] = a1;
    if ( v4 == (_QWORD *)(a2 + 1584) || v6 == v4 || *v6 != v5 )
    {
      _list_add_valid_or_report(v4, v6, v5);
    }
    else
    {
      *(_QWORD *)(a2 + 1592) = v4;
      *v4 = v5;
      v4[1] = v6;
      *v6 = v4;
    }
  }
  if ( (*(_WORD *)(a1 + 114) & 0xF0) == 0x50 )
  {
    v7 = pci_enable_device(a1);
    if ( v7 )
    {
      v10 = v7;
      if ( a2 )
      {
        ipc_log_string(
          *(_QWORD *)(a2 + 1704),
          "ERR:%s: PCIe: BDF 0x%04x pci_enable_device failed\n",
          "msm_pcie_config_device_info",
          *(_DWORD *)(a1 + 56) | (*(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL) << 8));
        ipc_log_string(
          *(_QWORD *)(a2 + 1696),
          "%s: PCIe: BDF 0x%04x pci_enable_device failed\n",
          "msm_pcie_config_device_info",
          *(_DWORD *)(a1 + 56) | (*(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL) << 8));
      }
      printk(&unk_2D8D6);
      return v10;
    }
    pci_set_master(a1);
  }
  if ( *(_BYTE *)(a2 + 1235) != 1 )
    return 0;
  if ( (*(_WORD *)(a1 + 114) & 0xF0) == 0x40 )
    *(_QWORD *)(a2 + 3056) = *(_QWORD *)(a1 + 80);
  if ( !*(_WORD *)(a1 + 74)
    || (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 232LL) + 200LL) + 16LL) + 1016LL) & 8) == 0
    || (v8 = pcie_capability_clear_and_set_word_unlocked(a1, 8, 0, 15), result = 0, v8) )
  {
    if ( a2 )
    {
      ipc_log_string(
        *(_QWORD *)(a2 + 1704),
        "ERR:%s: PCIe: RC%d: PCIE error reporting unavailable on %02x:%02x:%01x\n",
        "msm_pcie_config_device_info",
        *(_DWORD *)(a2 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7);
      ipc_log_string(
        *(_QWORD *)(a2 + 1696),
        "%s: PCIe: RC%d: PCIE error reporting unavailable on %02x:%02x:%01x\n",
        "msm_pcie_config_device_info",
        *(_DWORD *)(a2 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7);
    }
    printk(&unk_25F3E);
    return 0;
  }
  return result;
}
