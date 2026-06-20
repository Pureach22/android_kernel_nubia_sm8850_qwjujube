__int64 __fastcall msm_pcie_config_l0s(__int64 a1, __int64 a2, char a3)
{
  int v6; // w24
  __int64 v7; // x0
  const char *v8; // x22
  __int64 v9; // x8
  __int64 v10; // x21
  int v11; // w8
  __int64 result; // x0
  unsigned int v13; // w2
  int v14; // [xsp+0h] [xbp-10h] BYREF
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned __int8 *)(a2 + 108);
  if ( a1 )
  {
    v7 = *(_QWORD *)(a1 + 1704);
    if ( (a3 & 1) != 0 )
      v8 = "enable";
    else
      v8 = "disable";
    ipc_log_string(
      v7,
      "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x %s\n",
      "msm_pcie_config_l0s",
      *(_DWORD *)(a1 + 1348),
      *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 248LL),
      (unsigned __int8)*(_DWORD *)(a2 + 56) >> 3,
      *(_DWORD *)(a2 + 56) & 7,
      v8);
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: PCIe: RC%d: PCI device %02x:%02x.%01x %s\n",
      "msm_pcie_config_l0s",
      *(_DWORD *)(a1 + 1348),
      *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 248LL),
      (unsigned __int8)*(_DWORD *)(a2 + 56) >> 3,
      *(_DWORD *)(a2 + 56) & 7,
      v8);
  }
  if ( (a3 & 1) == 0 )
  {
    v15 = 0;
    pci_read_config_dword(a2, (unsigned int)(v6 + 16), &v15);
    v13 = v15 & 0xFFFFFFFE;
    goto LABEL_14;
  }
  v9 = *(_QWORD *)(a2 + 16);
  v15 = 0;
  v10 = *(_QWORD *)(v9 + 56);
  if ( !v10
    || (v11 = *(unsigned __int8 *)(v10 + 108),
        v14 = 0,
        pci_read_config_dword(v10, (unsigned int)(v11 + 12), &v15),
        result = pci_read_config_dword(v10, (unsigned int)*(unsigned __int8 *)(v10 + 108) + 16, &v14),
        v15 = v14 & ((unsigned __int16)(v15 & 0x400) >> 10),
        (v15 & 1) != 0) )
  {
    result = pci_read_config_dword(a2, (unsigned int)*(unsigned __int8 *)(a2 + 108) + 12, &v15);
    if ( (v15 & 0x400) == 0 )
    {
      if ( a1 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 1704),
          "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x does not support L0s\n",
          "msm_pcie_check_l0s_support",
          *(_DWORD *)(a1 + 1348),
          *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 248LL),
          (unsigned __int8)*(_DWORD *)(a2 + 56) >> 3,
          *(_DWORD *)(a2 + 56) & 7);
        result = ipc_log_string(
                   *(_QWORD *)(a1 + 1696),
                   "%s: PCIe: RC%d: PCI device %02x:%02x.%01x does not support L0s\n",
                   "msm_pcie_check_l0s_support",
                   *(_DWORD *)(a1 + 1348),
                   *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 248LL),
                   (unsigned __int8)*(_DWORD *)(a2 + 56) >> 3,
                   *(_DWORD *)(a2 + 56) & 7);
      }
      goto LABEL_15;
    }
    v15 = 0;
    pci_read_config_dword(a2, (unsigned int)(v6 + 16), &v15);
    v13 = v15 | 1;
LABEL_14:
    v15 = v13;
    result = pci_write_config_dword(a2, (unsigned int)(v6 + 16));
    goto LABEL_15;
  }
  if ( a1 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "DBG1:%s: PCIe: RC%d: Parent PCI device %02x:%02x.%01x does not support L0s\n",
      "msm_pcie_check_l0s_support",
      *(_DWORD *)(a1 + 1348),
      *(unsigned __int8 *)(*(_QWORD *)(v10 + 16) + 248LL),
      (unsigned __int8)*(_DWORD *)(v10 + 56) >> 3,
      *(_DWORD *)(v10 + 56) & 7);
    result = ipc_log_string(
               *(_QWORD *)(a1 + 1696),
               "%s: PCIe: RC%d: Parent PCI device %02x:%02x.%01x does not support L0s\n",
               "msm_pcie_check_l0s_support",
               *(_DWORD *)(a1 + 1348),
               *(unsigned __int8 *)(*(_QWORD *)(v10 + 16) + 248LL),
               (unsigned __int8)*(_DWORD *)(v10 + 56) >> 3,
               *(_DWORD *)(v10 + 56) & 7);
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
