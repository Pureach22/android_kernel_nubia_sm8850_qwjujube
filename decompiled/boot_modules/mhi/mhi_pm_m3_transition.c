__int64 __fastcall mhi_pm_m3_transition(__int64 a1)
{
  __int64 v2; // x21
  int v3; // w20
  __int64 v5; // x19

  v2 = *(_QWORD *)(a1 + 16);
  raw_write_lock_irq(a1 + 320);
  *(_DWORD *)(a1 + 348) = 5;
  v3 = mhi_tryset_pm_state(a1, 0x20u);
  raw_write_unlock_irq(a1 + 320);
  if ( v3 == 32 )
  {
    ++*(_DWORD *)(a1 + 368);
    _wake_up(a1 + 456, 3, 0, 0);
    return 0;
  }
  else
  {
    v5 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v2 + 40, "[E][%s] Unable to transition to M3 state\n", "mhi_pm_m3_transition");
    if ( v5 )
    {
      if ( *(_DWORD *)(v5 + 24) <= 2u )
        ipc_log_string(*(_QWORD *)(v5 + 32), "[E][%s] Unable to transition to M3 state\n", "mhi_pm_m3_transition");
    }
    return 4294967291LL;
  }
}
