__int64 __fastcall msm_pcie_check_l1ss_support(__int64 a1, __int64 a2)
{
  unsigned __int16 ext_capability; // w0
  __int64 result; // x0
  int v6; // w13
  char v7; // w10
  int v8; // w9
  int v9; // w8
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a2 + 1219) != 1 )
    goto LABEL_12;
  v10 = 0;
  ext_capability = pci_find_ext_capability(a1, 30);
  if ( !ext_capability )
  {
    if ( a2 )
    {
      ipc_log_string(
        *(_QWORD *)(a2 + 1704),
        "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x could not find L1ss capability register\n",
        "msm_pcie_check_l1ss_support",
        *(_DWORD *)(a2 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7);
      ipc_log_string(
        *(_QWORD *)(a2 + 1696),
        "%s: PCIe: RC%d: PCI device %02x:%02x.%01x could not find L1ss capability register\n",
        "msm_pcie_check_l1ss_support",
        *(unsigned int *)(a2 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7);
    }
    goto LABEL_11;
  }
  pci_read_config_dword(a1, (unsigned int)ext_capability + 4, &v10);
  result = 0;
  v6 = *(unsigned __int8 *)(a2 + 1220) & (v10 >> 1);
  v7 = *(_BYTE *)(a2 + 1221) & v10;
  v8 = *(unsigned __int8 *)(a2 + 1222) & (v10 >> 3);
  v9 = *(unsigned __int8 *)(a2 + 1223) & (v10 >> 2);
  *(_BYTE *)(a2 + 1221) = v7;
  *(_BYTE *)(a2 + 1220) = v6;
  *(_BYTE *)(a2 + 1222) = v8;
  *(_BYTE *)(a2 + 1223) = v9;
  if ( (v6 & 1) == 0 && (v7 & 1) == 0 && (v8 & 1) == 0 && !v9 )
  {
    if ( a2 )
    {
      ipc_log_string(
        *(_QWORD *)(a2 + 1704),
        "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x does not support any L1ss\n",
        "msm_pcie_check_l1ss_support",
        *(_DWORD *)(a2 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7);
      ipc_log_string(
        *(_QWORD *)(a2 + 1696),
        "%s: PCIe: RC%d: PCI device %02x:%02x.%01x does not support any L1ss\n",
        "msm_pcie_check_l1ss_support",
        *(unsigned int *)(a2 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7);
    }
LABEL_11:
    *(_BYTE *)(a2 + 1219) = 0;
LABEL_12:
    result = 4294967290LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
