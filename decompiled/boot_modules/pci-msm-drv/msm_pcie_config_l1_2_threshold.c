__int64 __fastcall msm_pcie_config_l1_2_threshold(__int64 a1, __int64 a2)
{
  unsigned __int16 ext_capability; // w0
  int v5; // w8
  int v6; // w21
  int v7; // w8
  int v8; // w20
  unsigned int v9; // w21
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a2 + 1228) )
  {
    if ( a2 )
    {
      ipc_log_string(
        *(_QWORD *)(a2 + 1704),
        "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x\n",
        "msm_pcie_config_l1_2_threshold",
        *(_DWORD *)(a2 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7);
      ipc_log_string(
        *(_QWORD *)(a2 + 1696),
        "%s: PCIe: RC%d: PCI device %02x:%02x.%01x\n",
        "msm_pcie_config_l1_2_threshold",
        *(_DWORD *)(a2 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7);
      ext_capability = pci_find_ext_capability(a1, 30);
      if ( !ext_capability )
      {
        ipc_log_string(
          *(_QWORD *)(a2 + 1704),
          "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x could not find L1ss capability register\n",
          "msm_pcie_config_l1_2_threshold",
          *(_DWORD *)(a2 + 1348),
          *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
          (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
          *(_DWORD *)(a1 + 56) & 7);
        ipc_log_string(
          *(_QWORD *)(a2 + 1696),
          "%s: PCIe: RC%d: PCI device %02x:%02x.%01x could not find L1ss capability register\n",
          "msm_pcie_config_l1_2_threshold",
          *(_DWORD *)(a2 + 1348),
          *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
          (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
          *(_DWORD *)(a1 + 56) & 7);
        goto LABEL_7;
      }
    }
    else
    {
      ext_capability = pci_find_ext_capability(a1, 30);
      if ( !ext_capability )
        goto LABEL_7;
    }
    v5 = *(_DWORD *)(a2 + 1224);
    v11 = 0;
    v6 = v5 << 29;
    v7 = *(_DWORD *)(a2 + 1228);
    v8 = ext_capability;
    v9 = v6 & 0xFC00FFFF | ((v7 & 0x3FF) << 16);
    pci_read_config_dword(a1, (unsigned int)ext_capability + 8, &v11);
    v11 |= v9;
    pci_write_config_dword(a1, (unsigned int)(v8 + 8));
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return 0;
}
