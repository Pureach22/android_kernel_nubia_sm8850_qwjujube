__int64 __fastcall mhi_ctrl_ev_task(_QWORD *a1)
{
  _QWORD *v1; // x19
  _DWORD *v2; // x8
  _QWORD *v4; // x0
  __int64 result; // x0
  __int64 v6; // x8
  _DWORD *v7; // x9
  __int64 v8; // x8
  int v9; // w20
  void (__fastcall *v10)(_QWORD); // x8
  __int64 (__fastcall *v11)(_QWORD); // x8
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = (_QWORD *)*a1;
  if ( (*(_WORD *)(*a1 + 336LL) & 0xFDE) != 0 )
  {
    v2 = (_DWORD *)a1[31];
    v4 = (_QWORD *)*a1;
    if ( *(v2 - 1) != 1550939421 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(_QWORD *, _QWORD *, __int64))v2)(v4, a1, 0xFFFFFFFFLL);
    if ( !(_DWORD)result )
    {
      raw_write_lock_irq(v1 + 40);
      v6 = v1[4];
      v7 = (_DWORD *)v1[71];
      v12 = 0;
      if ( *(v7 - 1) != -748163823 )
        __break(0x8229u);
      if ( ((unsigned int (__fastcall *)(_QWORD *, __int64, int *))v7)(v1, v6 + 72, &v12) || BYTE1(v12) << 8 != 65280 )
      {
        result = raw_write_unlock_irq(v1 + 40);
      }
      else
      {
        v8 = *(_QWORD *)(v1[2] + 192LL);
        if ( v8 && !*(_DWORD *)(v8 + 24) )
          ipc_log_string(*(_QWORD *)(v8 + 32), "[D][%s] System error detected\n", "mhi_ctrl_ev_task");
        v9 = mhi_tryset_pm_state(v1, 256);
        result = raw_write_unlock_irq(v1 + 40);
        if ( v9 == 256 )
          result = mhi_pm_sys_err_handler(v1);
      }
    }
  }
  else
  {
    pm_wakeup_dev_event(v1[2] + 40LL, 0, 0);
    v10 = (void (__fastcall *)(_QWORD))v1[64];
    if ( *((_DWORD *)v10 - 1) != -700558418 )
      __break(0x8228u);
    v10(v1);
    v11 = (__int64 (__fastcall *)(_QWORD))v1[66];
    if ( *((_DWORD *)v11 - 1) != -2145957670 )
      __break(0x8228u);
    result = v11(v1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
