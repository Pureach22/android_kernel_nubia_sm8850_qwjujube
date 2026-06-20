__int64 __fastcall msm_pcie_register_event(_QWORD *a1)
{
  __int64 v1; // x21
  __int64 v3; // x20
  __int64 v4; // x0
  _QWORD *v5; // x2
  __int64 v6; // x9
  _QWORD *v7; // x8
  _QWORD *v9; // x1
  void *v10; // x0

  if ( !a1 )
  {
    v10 = &unk_2C746;
LABEL_19:
    printk(v10);
    return 4294967277LL;
  }
  v1 = a1[3];
  if ( !v1 )
  {
    v10 = &unk_25C5E;
    goto LABEL_19;
  }
  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 232LL) + 200LL);
  if ( !v3 )
  {
    v10 = &unk_2F4AF;
    goto LABEL_19;
  }
  v4 = raw_spin_lock_irqsave(v3 + 1688);
  v5 = (_QWORD *)(v3 + 1672);
  v6 = v4;
  v7 = (_QWORD *)(v3 + 1672);
  while ( 1 )
  {
    v7 = (_QWORD *)*v7;
    if ( v7 == v5 )
      break;
    if ( v7[3] == a1[3] )
    {
      ipc_log_string(
        *(_QWORD *)(v3 + 1704),
        "ERR:%s: PCIe: RC%d: EP BDF 0x%4x already registered\n",
        "msm_pcie_register_event",
        *(_DWORD *)(v3 + 1348),
        *(_DWORD *)(v1 + 56) | (*(unsigned __int8 *)(*(_QWORD *)(v1 + 16) + 248LL) << 8));
      ipc_log_string(
        *(_QWORD *)(v3 + 1696),
        "%s: PCIe: RC%d: EP BDF 0x%4x already registered\n",
        "msm_pcie_register_event",
        *(_DWORD *)(v3 + 1348),
        *(_DWORD *)(v1 + 56) | (*(unsigned __int8 *)(*(_QWORD *)(v1 + 16) + 248LL) << 8));
      printk(&unk_29E0E);
      raw_spin_unlock(v3 + 1688);
      return 4294967279LL;
    }
  }
  v9 = *(_QWORD **)(v3 + 1680);
  if ( v5 == a1 || v9 == a1 || (_QWORD *)*v9 != v5 )
  {
    _list_add_valid_or_report(a1, v9, v5);
  }
  else
  {
    *(_QWORD *)(v3 + 1680) = a1;
    *a1 = v5;
    a1[1] = v9;
    *v9 = a1;
  }
  raw_spin_unlock_irqrestore(v3 + 1688, v6);
  if ( *(_BYTE *)(v3 + 1992) == 1 )
    queue_work_on(32, mpcie_wq, v3 + 1864);
  return 0;
}
