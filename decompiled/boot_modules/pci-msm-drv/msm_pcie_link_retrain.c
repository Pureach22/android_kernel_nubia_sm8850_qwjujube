__int64 __fastcall msm_pcie_link_retrain(__int64 a1, __int64 a2)
{
  __int64 v4; // x22
  __int64 v5; // x21
  int v6; // w0
  __int64 v7; // x22
  int v8; // w0
  __int64 v9; // x22
  int v10; // w0
  int v11; // w0
  int v12; // w21
  unsigned int v13; // w8
  __int64 result; // x0
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 904);
  v5 = *(_QWORD *)(a1 + 8);
  v6 = readl_relaxed_0((unsigned int *)(v4 + 4));
  writel_relaxed_0(v6 & 0xFFFFFBFF, v4 + 4);
  readl_relaxed_0((unsigned int *)(v4 + 4));
  v7 = *(_QWORD *)(a1 + 904);
  v8 = readl_relaxed_0((unsigned int *)(v7 + 80));
  writel_relaxed_0(v8 & 0xFFFEFFFF, v7 + 80);
  readl_relaxed_0((unsigned int *)(v7 + 80));
  v9 = *(_QWORD *)(a1 + 872);
  v10 = readl_relaxed_0((unsigned int *)(v9 + 1288));
  writel_relaxed_0(v10 | 0x2000000u, v9 + 1288);
  readl_relaxed_0((unsigned int *)(v9 + 1288));
  LODWORD(v9) = *(unsigned __int8 *)(v5 + 108);
  v15 = 0;
  pci_read_config_dword(v5, (unsigned int)(v9 + 16), &v15);
  v15 |= 0x400u;
  pci_write_config_dword(v5, (unsigned int)(v9 + 16));
  *(_DWORD *)(a1 + 1952) = 0;
  LODWORD(v5) = *(unsigned __int8 *)(a2 + 108);
  v15 = 0;
  pci_read_config_dword(a2, (unsigned int)(v5 + 16), &v15);
  v15 |= 0x20u;
  pci_write_config_dword(a2, (unsigned int)(v5 + 16));
  if ( (unsigned int)wait_for_completion_timeout(a1 + 1952, 25) )
  {
LABEL_7:
    v13 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + 128LL));
    result = 0;
    *(_DWORD *)(a1 + 1252) = HIWORD(v13) & 0xF;
    *(_DWORD *)(a1 + 1260) = (v13 >> 20) & 0x3F;
    goto LABEL_8;
  }
  if ( a1 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "DBG1:%s: PCIe: RC%d: Bandwidth int: completion timeout\n",
      "msm_pcie_link_retrain",
      *(_DWORD *)(a1 + 1348));
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: PCIe: RC%d: Bandwidth int: completion timeout\n",
      "msm_pcie_link_retrain",
      *(_DWORD *)(a1 + 1348));
  }
  if ( (readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + *(unsigned __int8 *)(a2 + 108) + 16LL)) & 0x40000000) != 0 )
  {
    v11 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + *(unsigned __int8 *)(a2 + 108) + 16LL));
    if ( a1 )
    {
      v12 = v11;
      ipc_log_string(
        *(_QWORD *)(a1 + 1704),
        "DBG1:%s: PCIe: RC%d: Status set 0x%x\n",
        "msm_pcie_link_retrain",
        *(_DWORD *)(a1 + 1348),
        v11 & 0x40000000);
      ipc_log_string(
        *(_QWORD *)(a1 + 1696),
        "%s: PCIe: RC%d: Status set 0x%x\n",
        "msm_pcie_link_retrain",
        *(_DWORD *)(a1 + 1348),
        v12 & 0x40000000);
    }
    goto LABEL_7;
  }
  if ( a1 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "ERR:%s: PCIe: RC%d: failed to retrain\n",
      "msm_pcie_link_retrain",
      *(_DWORD *)(a1 + 1348));
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: PCIe: RC%d: failed to retrain\n",
      "msm_pcie_link_retrain",
      *(_DWORD *)(a1 + 1348));
  }
  printk(&unk_2B55B);
  result = 4294967291LL;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
