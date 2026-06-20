__int64 __fastcall msm_pcie_config_clock_power_management_enable(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  int v5; // w20
  int v7; // [xsp+0h] [xbp-10h] BYREF
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 16);
  if ( *(_QWORD *)(v2 + 16) )
  {
    v7 = 0;
    if ( a2 )
    {
      ipc_log_string(
        *(_QWORD *)(a2 + 1704),
        "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x\n",
        "msm_pcie_config_clock_power_management_enable",
        *(_DWORD *)(a2 + 1348),
        *(unsigned __int8 *)(v2 + 248),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7);
      ipc_log_string(
        *(_QWORD *)(a2 + 1696),
        "%s: PCIe: RC%d: PCI device %02x:%02x.%01x\n",
        "msm_pcie_config_clock_power_management_enable",
        *(_DWORD *)(a2 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7);
    }
    pci_read_config_dword(a1, (unsigned int)*(unsigned __int8 *)(a1 + 108) + 12, &v7);
    if ( (v7 & 0x40000) != 0 )
    {
      v5 = *(unsigned __int8 *)(a1 + 108);
      v8 = 0;
      pci_read_config_dword(a1, (unsigned int)(v5 + 16), &v8);
      v8 |= 0x100u;
      pci_write_config_dword(a1, (unsigned int)(v5 + 16));
    }
    else if ( a2 )
    {
      ipc_log_string(
        *(_QWORD *)(a2 + 1704),
        "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x does not support clock power management\n",
        "msm_pcie_config_clock_power_management_enable",
        *(_DWORD *)(a2 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7);
      ipc_log_string(
        *(_QWORD *)(a2 + 1696),
        "%s: PCIe: RC%d: PCI device %02x:%02x.%01x does not support clock power management\n",
        "msm_pcie_config_clock_power_management_enable",
        *(_DWORD *)(a2 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7);
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
