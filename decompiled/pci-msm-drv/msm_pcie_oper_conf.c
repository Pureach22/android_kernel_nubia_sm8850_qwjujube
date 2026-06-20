__int64 __fastcall msm_pcie_oper_conf(__int64 a1, unsigned int a2, int a3, unsigned int a4, unsigned int a5, int *a6)
{
  __int64 v7; // x26
  unsigned int v9; // w19
  int v10; // w27
  __int64 v15; // x0
  char v16; // w8
  unsigned int v17; // w0
  int v18; // w9
  unsigned int v19; // w21
  void *v20; // x0
  unsigned int v22; // w0
  int v23; // w9
  const char *v24; // x23

  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 232) + 200LL);
  if ( !v7 )
  {
    printk(&unk_26F36);
    *a6 = -1;
    return 134;
  }
  v9 = *(_DWORD *)(v7 + 1348);
  v10 = *(unsigned __int8 *)(a1 + 248);
  v15 = raw_spin_lock_irqsave(v7 + 1060);
  v16 = *(_BYTE *)(v7 + 1056);
  *(_QWORD *)(v7 + 1064) = v15;
  if ( (v16 & 1) == 0 )
  {
    ipc_log_string(
      *(_QWORD *)(v7 + 1696),
      "DBG3:%s: Access denied for RC%d %d:0x%02x + 0x%04x[%d]\n",
      "msm_pcie_oper_conf",
      v9,
      *(unsigned __int8 *)(a1 + 248),
      a2,
      a4,
      a5);
LABEL_11:
    *a6 = -1;
    v19 = 134;
    goto LABEL_12;
  }
  if ( *(_DWORD *)(v7 + 1176) != 1 )
  {
    ipc_log_string(
      *(_QWORD *)(v7 + 1696),
      "DBG3:%s: Access to RC%d %d:0x%02x + 0x%04x[%d] is denied because link is down\n",
      "msm_pcie_oper_conf",
      v9,
      *(unsigned __int8 *)(a1 + 248),
      a2,
      a4,
      a5);
    goto LABEL_11;
  }
  if ( v10 && (readl_relaxed_0((unsigned int *)(*(_QWORD *)(v7 + 904) + 128LL)) & 0x20000000) == 0 )
  {
    if ( a3 )
      v24 = "wr";
    else
      v24 = "rd";
    ipc_log_string(
      *(_QWORD *)(v7 + 1704),
      "ERR:%s: PCIe: RC%d %s fail, link down - bus %d devfn %d\n",
      "msm_pcie_oper_conf",
      v9,
      v24,
      *(unsigned __int8 *)(a1 + 248),
      a2);
    ipc_log_string(
      *(_QWORD *)(v7 + 1696),
      "%s: PCIe: RC%d %s fail, link down - bus %d devfn %d\n",
      "msm_pcie_oper_conf",
      v9,
      v24,
      *(unsigned __int8 *)(a1 + 248),
      a2);
    printk(&unk_28844);
    goto LABEL_11;
  }
  if ( a3 )
  {
    v17 = pci_generic_config_write(a1, a2, a4, a5, (unsigned int)*a6);
    v18 = *a6;
    v19 = v17;
    ipc_log_string(
      *(_QWORD *)(v7 + 1696),
      "DBG3:%s: RC%d %d:0x%02x + 0x%04x[%d] write val 0x%08x\n",
      "msm_pcie_oper_conf",
      v9,
      *(unsigned __int8 *)(a1 + 248),
      a2,
      a4,
      a5,
      v18);
    if ( v19 )
    {
      ipc_log_string(
        *(_QWORD *)(v7 + 1704),
        "ERR:%s: PCIe: RC%d %d: Write operation failed\n",
        "msm_pcie_oper_conf",
        v9,
        *(unsigned __int8 *)(a1 + 248));
      ipc_log_string(
        *(_QWORD *)(v7 + 1696),
        "%s: PCIe: RC%d %d: Write operation failed\n",
        "msm_pcie_oper_conf",
        v9,
        *(unsigned __int8 *)(a1 + 248));
      v20 = &unk_2887B;
LABEL_16:
      printk(v20);
    }
  }
  else
  {
    v22 = pci_generic_config_read(a1, a2, a4, a5, a6);
    v23 = *a6;
    v19 = v22;
    ipc_log_string(
      *(_QWORD *)(v7 + 1696),
      "DBG3:%s: RC%d %d:0x%02x + 0x%04x[%d] read val 0x%08x\n",
      "msm_pcie_oper_conf",
      v9,
      *(unsigned __int8 *)(a1 + 248),
      a2,
      a4,
      a5,
      v23);
    if ( v19 )
    {
      ipc_log_string(
        *(_QWORD *)(v7 + 1704),
        "ERR:%s: PCIe: RC%d %d: Read operation failed\n",
        "msm_pcie_oper_conf",
        v9,
        *(unsigned __int8 *)(a1 + 248));
      ipc_log_string(
        *(_QWORD *)(v7 + 1696),
        "%s: PCIe: RC%d %d: Read operation failed\n",
        "msm_pcie_oper_conf",
        v9,
        *(unsigned __int8 *)(a1 + 248));
      v20 = &unk_25012;
      goto LABEL_16;
    }
  }
LABEL_12:
  raw_spin_unlock_irqrestore(v7 + 1060, *(_QWORD *)(v7 + 1064));
  return v19;
}
