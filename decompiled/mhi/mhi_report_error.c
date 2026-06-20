__int64 __fastcall mhi_report_error(__int64 a1)
{
  _QWORD *v1; // x22
  const char **v3; // x21
  __int64 v4; // x20
  __int64 v6; // x23
  const char *v7; // x21
  const char *v8; // x0
  __int64 v9; // x21
  const char *v10; // x22
  const char *v11; // x0
  const char *v12; // x3
  __int64 v13; // x20
  const char *v14; // x3

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD **)(a1 + 16);
  v3 = *(const char ***)(v1[24] + 96LL);
  v4 = raw_write_lock_irqsave(a1 + 320);
  if ( (unsigned int)mhi_tryset_pm_state(a1, 0x100u) == 256 )
  {
    *(_DWORD *)(a1 + 348) = 255;
    _wake_up(a1 + 456, 3, 0, 0);
    raw_write_unlock_irqrestore(a1 + 320, v4);
    if ( v3 && *v3 )
    {
      memcpy((void *)v3[3], *v3, (size_t)v3[2]);
      v12 = (const char *)v1[19];
      v13 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      if ( !v12 )
        v12 = (const char *)v1[5];
      dev_err(v1 + 5, "[E][%s] mhi: %s sfr: %s\n", "mhi_report_error", v12, *v3);
      if ( v13 && *(_DWORD *)(v13 + 24) <= 2u )
      {
        v14 = (const char *)v1[19];
        if ( !v14 )
          v14 = (const char *)v1[5];
        ipc_log_string(*(_QWORD *)(v13 + 32), "[E][%s] mhi: %s sfr: %s\n", "mhi_report_error", v14, *v3);
      }
    }
    device_for_each_child(*(_QWORD *)(a1 + 16) + 40LL, 0, mhi_notify_fatal_cb);
    return 0;
  }
  else
  {
    v6 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    v7 = to_mhi_pm_state_str(0x100u);
    v8 = to_mhi_pm_state_str(*(_DWORD *)(a1 + 336));
    dev_err(v1 + 5, "[E][%s] Failed to move to state: %s from: %s\n", "mhi_report_error", v7, v8);
    if ( v6 && *(_DWORD *)(v6 + 24) <= 2u )
    {
      v9 = *(_QWORD *)(v6 + 32);
      v10 = to_mhi_pm_state_str(0x100u);
      v11 = to_mhi_pm_state_str(*(_DWORD *)(a1 + 336));
      ipc_log_string(v9, "[E][%s] Failed to move to state: %s from: %s\n", "mhi_report_error", v10, v11);
    }
    raw_write_unlock_irqrestore(a1 + 320, v4);
    return 0xFFFFFFFFLL;
  }
}
