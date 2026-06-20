__int64 __fastcall mhi_dl_xfer_cb(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v6; // x0
  __int64 v7; // x2
  _QWORD *v8; // x10
  __int64 v9; // x9
  _QWORD *v10; // x8
  _QWORD *v11; // x1

  v2 = *(_QWORD *)(a1 + 192);
  if ( *(_QWORD *)(v2 + 352) && !*(_DWORD *)(v2 + 360) )
    ipc_log_string();
  if ( *(_DWORD *)(a2 + 20) == -107 )
    return kfree(*(_QWORD *)a2);
  v6 = raw_spin_lock_irqsave(v2 + 232);
  v7 = v2 + 240;
  v8 = (_QWORD *)(*(_QWORD *)a2 + *(_QWORD *)(v2 + 328));
  v9 = v6;
  *v8 = *(_QWORD *)a2;
  v8[1] = *(_QWORD *)(a2 + 8);
  v10 = v8 + 2;
  v11 = *(_QWORD **)(v2 + 248);
  if ( v8 + 2 == (_QWORD *)(v2 + 240) || v11 == v10 || *v11 != v7 )
  {
    _list_add_valid_or_report(v8 + 2, v11);
  }
  else
  {
    *(_QWORD *)(v2 + 248) = v10;
    v8[2] = v7;
    v8[3] = v11;
    *v11 = v10;
  }
  raw_spin_unlock_irqrestore(v2 + 232, v9);
  if ( *(_QWORD *)(a1 + 368) )
    pm_wakeup_dev_event(a1 + 40, 0, 1);
  return _wake_up(v2 + 208, 3, 1, 0);
}
