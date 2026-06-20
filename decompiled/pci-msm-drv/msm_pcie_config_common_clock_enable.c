__int64 __fastcall msm_pcie_config_common_clock_enable(__int64 a1, __int64 a2)
{
  int v4; // w20
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    ipc_log_string(
      *(_QWORD *)(a2 + 1704),
      "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x\n",
      "msm_pcie_config_common_clock_enable",
      *(_DWORD *)(a2 + 1348),
      *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
      (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
      *(_DWORD *)(a1 + 56) & 7);
    ipc_log_string(
      *(_QWORD *)(a2 + 1696),
      "%s: PCIe: RC%d: PCI device %02x:%02x.%01x\n",
      "msm_pcie_config_common_clock_enable",
      *(_DWORD *)(a2 + 1348),
      *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
      (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
      *(_DWORD *)(a1 + 56) & 7);
  }
  v4 = *(unsigned __int8 *)(a1 + 108);
  v6 = 0;
  pci_read_config_dword(a1, (unsigned int)(v4 + 16), &v6);
  v6 |= 0x40u;
  pci_write_config_dword(a1, (unsigned int)(v4 + 16));
  _ReadStatusReg(SP_EL0);
  return 0;
}
