__int64 __fastcall msm_pcie_deregister_event(_QWORD *a1)
{
  __int64 v1; // x20
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 v5; // x9
  _QWORD *v6; // x10
  _QWORD *v7; // x8
  __int64 v8; // x10
  void *v10; // x0

  if ( !a1 )
  {
    v10 = &unk_24F76;
LABEL_14:
    printk(v10);
    return 4294967277LL;
  }
  v1 = a1[3];
  if ( !v1 )
  {
    v10 = &unk_2763F;
    goto LABEL_14;
  }
  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 232LL) + 200LL);
  if ( !v3 )
  {
    printk(&unk_2667A);
    return 4294967277LL;
  }
  v4 = raw_spin_lock_irqsave(v3 + 1688);
  v5 = v4;
  v6 = (_QWORD *)(v3 + 1672);
  do
  {
    v6 = (_QWORD *)*v6;
    if ( v6 == (_QWORD *)(v3 + 1672) )
    {
      raw_spin_unlock_irqrestore(v3 + 1688, v4);
      ipc_log_string(
        *(_QWORD *)(v3 + 1704),
        "DBG1:%s: PCIe: RC%d: Failed to deregister event for BDF 0x%04x\n",
        "msm_pcie_deregister_event",
        *(_DWORD *)(v3 + 1348),
        *(_DWORD *)(v1 + 56) | (*(unsigned __int8 *)(*(_QWORD *)(v1 + 16) + 248LL) << 8));
      ipc_log_string(
        *(_QWORD *)(v3 + 1696),
        "%s: PCIe: RC%d: Failed to deregister event for BDF 0x%04x\n",
        "msm_pcie_deregister_event",
        *(_DWORD *)(v3 + 1348),
        *(_DWORD *)(v1 + 56) | (*(unsigned __int8 *)(*(_QWORD *)(v1 + 16) + 248LL) << 8));
      return 4294967274LL;
    }
  }
  while ( v6[3] != a1[3] );
  v7 = (_QWORD *)a1[1];
  if ( (_QWORD *)*v7 == a1 && (v8 = *a1, *(_QWORD **)(*a1 + 8LL) == a1) )
  {
    *(_QWORD *)(v8 + 8) = v7;
    *v7 = v8;
  }
  else
  {
    _list_del_entry_valid_or_report(a1);
  }
  *a1 = 0xDEAD000000000100LL;
  a1[1] = 0xDEAD000000000122LL;
  raw_spin_unlock_irqrestore(v3 + 1688, v5);
  ipc_log_string(
    *(_QWORD *)(v3 + 1704),
    "DBG1:%s: PCIe: RC%d: Event deregistered for BDF 0x%04x\n",
    "msm_pcie_deregister_event",
    *(_DWORD *)(v3 + 1348),
    *(_DWORD *)(v1 + 56) | (*(unsigned __int8 *)(*(_QWORD *)(v1 + 16) + 248LL) << 8));
  ipc_log_string(
    *(_QWORD *)(v3 + 1696),
    "%s: PCIe: RC%d: Event deregistered for BDF 0x%04x\n",
    "msm_pcie_deregister_event",
    *(_DWORD *)(v3 + 1348),
    *(_DWORD *)(v1 + 56) | (*(unsigned __int8 *)(*(_QWORD *)(v1 + 16) + 248LL) << 8));
  return 0;
}
