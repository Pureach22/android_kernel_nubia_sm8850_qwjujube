__int64 __fastcall mhi_sat_dev_status_cb(__int64 result, int a2)
{
  __int64 v2; // x20
  __int64 v3; // x8
  __int64 v4; // x19

  if ( a2 == 7 )
  {
    v2 = *(_QWORD *)(*(_QWORD *)(result + 192) + 24LL);
    if ( v2 )
    {
      v3 = *(_QWORD *)(v2 + 24);
      if ( v3 )
        ipc_log_string(
          *(_QWORD *)(v3 + 88),
          "%s[I][%s][%x] Device fatal error detected\n",
          (const char *)&unk_8360,
          "mhi_sat_dev_status_cb",
          *(_DWORD *)(v2 + 232));
    }
    v4 = raw_spin_lock_irqsave(v2 + 264);
    if ( *(_DWORD *)(v2 + 260) == 1 )
    {
      queue_work_on(32, system_wq, v2 + 200);
      *(_DWORD *)(v2 + 260) = 3;
    }
    return raw_spin_unlock_irqrestore(v2 + 264, v4);
  }
  return result;
}
