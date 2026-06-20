__int64 __fastcall mhi_device_get_sync_atomic(__int64 a1, int a2, char a3)
{
  __int64 v3; // x19
  __int64 lock_irqsave; // x23
  void (__fastcall *v9)(__int64, __int64); // x8
  void (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x21
  unsigned int i; // w8
  unsigned int v13; // w22
  void (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x23
  const char *v16; // x21
  const char *v17; // x0
  __int64 v18; // x21
  const char *v19; // x22
  const char *v20; // x0
  __int64 v21; // x0
  _DWORD *v22; // x8
  __int64 v23; // x21
  void (__fastcall *v24)(_QWORD); // x8

  v3 = *(_QWORD *)(a1 + 16);
  lock_irqsave = raw_read_lock_irqsave(v3 + 320);
  if ( *(_DWORD *)(v3 + 336) >= 0x80u )
  {
    raw_read_unlock_irqrestore(v3 + 320, lock_irqsave);
    return 4294967291LL;
  }
  v9 = *(void (__fastcall **)(__int64, __int64))(v3 + 488);
  if ( *((_DWORD *)v9 - 1) != 598874997 )
    __break(0x8228u);
  v9(v3, 1);
  raw_read_unlock_irqrestore(v3 + 320, lock_irqsave);
  ++*(_DWORD *)(a1 + 972);
  pm_wakeup_dev_event(*(_QWORD *)(v3 + 16) + 40LL, 0, 0);
  v10 = *(void (__fastcall **)(_QWORD))(v3 + 512);
  if ( *((_DWORD *)v10 - 1) != -700558418 )
    __break(0x8228u);
  v10(v3);
  if ( !a2 )
  {
    if ( *(_DWORD *)(v3 + 336) != 4 )
    {
      v11 = *(_QWORD *)(*(_QWORD *)(v3 + 16) + 192LL);
      dev_err(a1 + 40, "[E][%s] Return without waiting for M0\n", "mhi_device_get_sync_atomic");
      if ( v11 )
      {
        if ( *(_DWORD *)(v11 + 24) <= 2u )
          ipc_log_string(*(_QWORD *)(v11 + 32), "[E][%s] Return without waiting for M0\n", "mhi_device_get_sync_atomic");
      }
    }
    goto LABEL_23;
  }
  if ( (a3 & 1) != 0 )
  {
    while ( (unsigned int)mhi_get_mhi_state(v3) != 2 && *(_DWORD *)(v3 + 336) <= 0x7Fu && a2 >= 1 )
    {
      _const_udelay(429500);
      a2 -= 100;
    }
  }
  else
  {
    for ( i = *(_DWORD *)(v3 + 336); i != 4; a2 -= 100 )
    {
      if ( i > 0x7F )
        break;
      if ( a2 < 1 )
        break;
      _const_udelay(429500);
      i = *(_DWORD *)(v3 + 336);
    }
  }
  v13 = *(_DWORD *)(v3 + 336);
  if ( v13 <= 0x7F && a2 > 0 )
  {
LABEL_23:
    v14 = *(void (__fastcall **)(_QWORD))(v3 + 528);
    if ( *((_DWORD *)v14 - 1) != -2145957670 )
      __break(0x8228u);
    v14(v3);
    return 0;
  }
  v15 = *(_QWORD *)(*(_QWORD *)(v3 + 16) + 192LL);
  v16 = mhi_state_str_1(*(_DWORD *)(v3 + 348));
  v17 = to_mhi_pm_state_str(v13);
  dev_err(a1 + 40, "[E][%s] Did not enter M0, cur_state: %s pm_state: %s\n", "mhi_device_get_sync_atomic", v16, v17);
  if ( v15 && *(_DWORD *)(v15 + 24) <= 2u )
  {
    v18 = *(_QWORD *)(v15 + 32);
    v19 = mhi_state_str_1(*(_DWORD *)(v3 + 348));
    v20 = to_mhi_pm_state_str(*(_DWORD *)(v3 + 336));
    ipc_log_string(
      v18,
      "[E][%s] Did not enter M0, cur_state: %s pm_state: %s\n",
      "mhi_device_get_sync_atomic",
      v19,
      v20);
  }
  v21 = raw_read_lock_irqsave(v3 + 320);
  v22 = *(_DWORD **)(v3 + 496);
  v23 = v21;
  if ( *(v22 - 1) != 598874997 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD))v22)(v3, 0);
  raw_read_unlock_irqrestore(v3 + 320, v23);
  --*(_DWORD *)(a1 + 972);
  v24 = *(void (__fastcall **)(_QWORD))(v3 + 528);
  if ( *((_DWORD *)v24 - 1) != -2145957670 )
    __break(0x8228u);
  v24(v3);
  return 4294967186LL;
}
