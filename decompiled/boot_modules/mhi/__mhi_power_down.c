__int64 __fastcall _mhi_power_down(__int64 a1, char a2, char a3)
{
  __int64 v4; // x23
  __int64 result; // x0
  unsigned int v8; // w21
  int v9; // w1
  __int64 v10; // x24
  const char *v11; // x22
  const char *v12; // x0
  __int64 v13; // x22
  const char *v14; // x21
  const char *v15; // x0

  v4 = *(_QWORD *)(a1 + 16);
  mutex_lock(a1 + 272);
  raw_write_lock_irq(a1 + 320);
  if ( *(_DWORD *)(a1 + 336) == 1 )
  {
    raw_write_unlock_irq(a1 + 320);
    return mutex_unlock(a1 + 272);
  }
  else
  {
    if ( (a2 & 1) != 0 )
      v8 = 2048;
    else
      v8 = 4096;
    if ( (unsigned int)mhi_tryset_pm_state(a1, v8) != v8 )
    {
      v10 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      v11 = to_mhi_pm_state_str(v8);
      v12 = to_mhi_pm_state_str(*(_DWORD *)(a1 + 336));
      dev_err(v4 + 40, "[E][%s] Failed to move to state: %s from: %s\n", "__mhi_power_down", v11, v12);
      if ( v10 && *(_DWORD *)(v10 + 24) <= 2u )
      {
        v13 = *(_QWORD *)(v10 + 32);
        v14 = to_mhi_pm_state_str(v8);
        v15 = to_mhi_pm_state_str(*(_DWORD *)(a1 + 336));
        ipc_log_string(v13, "[E][%s] Failed to move to state: %s from: %s\n", "__mhi_power_down", v14, v15);
      }
      *(_DWORD *)(a1 + 336) = 4096;
    }
    *(_QWORD *)(a1 + 344) = 8;
    _wake_up(a1 + 456, 3, 0, 0);
    raw_write_unlock_irq(a1 + 320);
    mutex_unlock(a1 + 272);
    if ( (a3 & 1) != 0 )
      v9 = 7;
    else
      v9 = 6;
    mhi_queue_state_transition(a1, v9);
    flush_work(a1 + 416);
    result = disable_irq(**(unsigned int **)(a1 + 200));
    if ( *(_QWORD *)(a1 + 152) )
      return mhi_free_bhie_table(a1, (_QWORD *)(a1 + 152));
  }
  return result;
}
