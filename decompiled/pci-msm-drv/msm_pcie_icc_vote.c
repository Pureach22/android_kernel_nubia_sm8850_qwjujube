__int64 __fastcall msm_pcie_icc_vote(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  int v7; // w21
  __int64 v8; // x0
  int v9; // w3
  unsigned int v10; // w0
  unsigned int v11; // w20
  unsigned int v12; // w20

  result = *(_QWORD *)(a1 + 1208);
  if ( !result )
    return result;
  if ( *(_QWORD *)(a1 + 3128) )
    icc_set_tag();
  if ( a1 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "DBG1:%s: PCIe: RC%d: putting ICC vote ab = %d ib = %d\n",
      "msm_pcie_icc_vote",
      *(_DWORD *)(a1 + 1348),
      a2,
      a3);
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: PCIe: RC%d: putting ICC vote ab = %d ib = %d\n",
      "msm_pcie_icc_vote",
      *(_DWORD *)(a1 + 1348),
      a2,
      a3);
    v7 = icc_set_bw(*(_QWORD *)(a1 + 1208), a2, a3);
    v8 = *(_QWORD *)(a1 + 1704);
    v9 = *(_DWORD *)(a1 + 1348);
    if ( !v7 )
    {
      ipc_log_string(v8, "DBG1:%s: PCIe: RC%d: ICC vote successful\n", "msm_pcie_icc_vote", v9);
      ipc_log_string(
        *(_QWORD *)(a1 + 1696),
        "%s: PCIe: RC%d: ICC vote successful\n",
        "msm_pcie_icc_vote",
        *(_DWORD *)(a1 + 1348));
      result = 0;
      if ( !*(_QWORD *)(a1 + 3128) )
        return result;
      goto LABEL_9;
    }
    ipc_log_string(v8, "ERR:%s: PCIe: RC%d: failed to put the ICC vote %d.\n", "msm_pcie_icc_vote", v9, v7);
    v12 = v7;
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: PCIe: RC%d: failed to put the ICC vote %d.\n",
      "msm_pcie_icc_vote",
      *(_DWORD *)(a1 + 1348),
      v7);
    goto LABEL_15;
  }
  v10 = icc_set_bw(unk_4B8, a2, a3);
  if ( v10 )
  {
    v12 = v10;
LABEL_15:
    printk(&unk_288C3);
    result = v12;
    if ( !*(_QWORD *)(a1 + 3128) )
      return result;
  }
LABEL_9:
  result = crm_write_pwr_states(*(_QWORD *)(a1 + 3120), *(unsigned int *)(a1 + 1348));
  if ( a1 )
  {
    if ( (_DWORD)result )
    {
      v11 = result;
      ipc_log_string(
        *(_QWORD *)(a1 + 1704),
        "DBG1:%s: PCIe: RC%d: pwr_states %d\n",
        "msm_pcie_icc_vote",
        *(_DWORD *)(a1 + 1348),
        result);
      ipc_log_string(
        *(_QWORD *)(a1 + 1696),
        "%s: PCIe: RC%d: pwr_states %d\n",
        "msm_pcie_icc_vote",
        *(_DWORD *)(a1 + 1348),
        v11);
      return v11;
    }
  }
  return result;
}
