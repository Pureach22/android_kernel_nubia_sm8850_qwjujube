__int64 __fastcall dp_tlmm_isr(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 raw_value_cansleep; // x0
  int v5; // w20
  _BOOL4 v6; // w21
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x22
  __int64 result; // x0
  __int64 v10; // x1

  if ( !a2 )
    return 0;
  usleep_range_state(99000, 100000, 2);
  v3 = gpio_to_desc(*(unsigned int *)(a2 + 96));
  raw_value_cansleep = gpiod_get_raw_value_cansleep(v3);
  v5 = raw_value_cansleep;
  v6 = raw_value_cansleep != 0;
  ipc_log_context = get_ipc_log_context(raw_value_cansleep);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    ipc_log_context,
    "[d][%-4d]lphw_hpd state = %d, new hpd state = %d\n",
    *(_DWORD *)(StatusReg + 1800),
    *(unsigned __int8 *)(a2 + 356),
    v6);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]lphw_hpd state = %d, new hpd state = %d\n",
      *(_DWORD *)(StatusReg + 1800),
      *(unsigned __int8 *)(a2 + 356),
      v6);
  result = 1;
  if ( (*(_BYTE *)(a2 + 356) & 1) == 0 )
  {
    if ( v5 )
    {
      v10 = *(_QWORD *)(a2 + 136);
      *(_BYTE *)(a2 + 356) = 1;
      queue_work_on(32, v10, a2 + 248);
      return 1;
    }
  }
  return result;
}
