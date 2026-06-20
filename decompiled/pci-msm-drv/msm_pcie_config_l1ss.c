__int64 __fastcall msm_pcie_config_l1ss(__int64 a1, __int64 a2, char a3)
{
  int v6; // w24
  __int64 v7; // x0
  const char *v8; // x22
  __int64 result; // x0
  int v10; // w23
  int v11; // w11
  int v12; // w9
  int v13; // w10
  int v14; // w8
  int v15; // w21
  unsigned int v16; // w2
  unsigned int *v17; // x22
  int v18; // w0
  int v19; // [xsp+Ch] [xbp-14h] BYREF
  int v20; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v21; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned __int8 *)(a2 + 108);
  v19 = 0;
  v20 = 0;
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
      "msm_pcie_config_l1ss",
      *(_DWORD *)(a1 + 1348),
      *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 248LL),
      (unsigned __int8)*(_DWORD *)(a2 + 56) >> 3,
      *(_DWORD *)(a2 + 56) & 7,
      v8);
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: PCIe: RC%d: PCI device %02x:%02x.%01x %s\n",
      "msm_pcie_config_l1ss",
      *(_DWORD *)(a1 + 1348),
      *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 248LL),
      (unsigned __int8)*(_DWORD *)(a2 + 56) >> 3,
      *(_DWORD *)(a2 + 56) & 7,
      v8);
    LOWORD(result) = pci_find_ext_capability(a2, 30);
    if ( !(_WORD)result )
    {
      ipc_log_string(
        *(_QWORD *)(a1 + 1704),
        "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x could not find L1ss capability register\n",
        "msm_pcie_config_l1ss",
        *(_DWORD *)(a1 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a2 + 56) >> 3,
        *(_DWORD *)(a2 + 56) & 7);
      result = ipc_log_string(
                 *(_QWORD *)(a1 + 1696),
                 "%s: PCIe: RC%d: PCI device %02x:%02x.%01x could not find L1ss capability register\n",
                 "msm_pcie_config_l1ss",
                 *(_DWORD *)(a1 + 1348),
                 *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 248LL),
                 (unsigned __int8)*(_DWORD *)(a2 + 56) >> 3,
                 *(_DWORD *)(a2 + 56) & 7);
      goto LABEL_28;
    }
  }
  else
  {
    result = pci_find_ext_capability(a2, 30);
    if ( !(_WORD)result )
      goto LABEL_28;
  }
  v10 = (unsigned __int16)result;
  if ( *(_QWORD *)(*(_QWORD *)(a2 + 16) + 16LL) || (*(_BYTE *)(a1 + 1234) & 1) != 0 )
  {
    if ( (a3 & 1) != 0 )
    {
LABEL_11:
      v21 = 0;
      pci_read_config_dword(a2, (unsigned int)(v6 + 40), &v21);
      v21 |= 0x400u;
      pci_write_config_dword(a2, (unsigned int)(v6 + 40));
      v11 = *(unsigned __int8 *)(a1 + 1221);
      if ( *(_BYTE *)(a1 + 1220) )
        v12 = 2;
      else
        v12 = 0;
      if ( *(_BYTE *)(a1 + 1222) )
        v13 = 8;
      else
        v13 = 0;
      if ( *(_BYTE *)(a1 + 1223) )
        v14 = 4;
      else
        v14 = 0;
      v21 = 0;
      v15 = v12 | v11 | v13 | v14;
      pci_read_config_dword(a2, (unsigned int)(v10 + 8), &v21);
      v16 = v15 | v21;
      goto LABEL_25;
    }
  }
  else
  {
    v17 = *(unsigned int **)(a1 + 872);
    v18 = readl_relaxed_0(v17);
    if ( (a3 & 1) != 0 )
    {
      writel_relaxed_0(v18 & 0xFFFFFFF7, v17);
      readl_relaxed_0(v17);
      goto LABEL_11;
    }
    writel_relaxed_0(v18 | 8u, v17);
    readl_relaxed_0(v17);
  }
  v21 = 0;
  pci_read_config_dword(a2, (unsigned int)(v6 + 40), &v21);
  v21 &= ~0x400u;
  pci_write_config_dword(a2, (unsigned int)(v6 + 40));
  v21 = 0;
  pci_read_config_dword(a2, (unsigned int)(v10 + 8), &v21);
  v16 = v21 & 0xFFFFFFF0;
LABEL_25:
  v21 = v16;
  pci_write_config_dword(a2, (unsigned int)(v10 + 8));
  pci_read_config_dword(a2, (unsigned int)(v10 + 8), &v20);
  if ( a1 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "DBG2:%s: PCIe: RC%d: L1SUB_CONTROL1:0x%x\n",
      "msm_pcie_config_l1ss",
      *(_DWORD *)(a1 + 1348),
      v20);
    pci_read_config_dword(a2, (unsigned int)(v6 + 40), &v19);
    result = ipc_log_string(
               *(_QWORD *)(a1 + 1696),
               "DBG2:%s: PCIe: RC%d: DEVICE_CONTROL2_STATUS2::0x%x\n",
               "msm_pcie_config_l1ss",
               *(_DWORD *)(a1 + 1348),
               v19);
  }
  else
  {
    result = pci_read_config_dword(a2, (unsigned int)(v6 + 40), &v19);
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
