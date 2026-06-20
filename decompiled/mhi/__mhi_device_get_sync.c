__int64 __fastcall _mhi_device_get_sync(__int64 a1)
{
  void (__fastcall *v2)(__int64, __int64); // x8
  void (__fastcall *v3)(_QWORD); // x8
  void (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x0
  unsigned int v6; // w8
  bool v8; // w9
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x20
  unsigned int v12; // w8
  bool v14; // w8
  __int64 v15; // x0
  __int64 v16; // x20
  unsigned int v17; // w8
  bool v19; // w8
  int v20; // w20
  _DWORD *v21; // x8
  __int64 result; // x0
  _QWORD v23[6]; // [xsp+0h] [xbp-30h] BYREF

  v23[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  raw_read_lock_bh(a1 + 320);
  if ( *(_DWORD *)(a1 + 336) <= 0x7Fu )
  {
    v2 = *(void (__fastcall **)(__int64, __int64))(a1 + 488);
    if ( *((_DWORD *)v2 - 1) != 598874997 )
      __break(0x8228u);
    v2(a1, 1);
    if ( (*(_BYTE *)(a1 + 336) & 0x30) != 0 )
    {
      pm_wakeup_dev_event(*(_QWORD *)(a1 + 16) + 40LL, 0, 0);
      v3 = *(void (__fastcall **)(_QWORD))(a1 + 512);
      if ( *((_DWORD *)v3 - 1) != -700558418 )
        __break(0x8228u);
      v3(a1);
      v4 = *(void (__fastcall **)(_QWORD))(a1 + 528);
      if ( *((_DWORD *)v4 - 1) != -2145957670 )
        __break(0x8228u);
      v4(a1);
    }
    raw_read_unlock_bh(a1 + 320);
    mhi_force_reg_write(a1);
    v5 = _msecs_to_jiffies(*(unsigned int *)(a1 + 328));
    v6 = *(_DWORD *)(a1 + 336);
    v8 = v6 == 4 || v6 > 0x7F;
    if ( v8 && v5 == 0 )
      v9 = 1;
    else
      v9 = v5;
    if ( !v8 && v9 )
    {
      v10 = *(unsigned int *)(a1 + 328);
      memset(v23, 0, 40);
      v11 = _msecs_to_jiffies(v10);
      init_wait_entry(v23, 0);
      prepare_to_wait_event(a1 + 456, v23, 2);
      v12 = *(_DWORD *)(a1 + 336);
      v14 = v12 == 4 || v12 > 0x7F;
      if ( v14 && v11 == 0 )
        v15 = 1;
      else
        v15 = v11;
      if ( !v14 && v15 )
      {
        do
        {
          v16 = schedule_timeout(v15);
          prepare_to_wait_event(a1 + 456, v23, 2);
          v17 = *(_DWORD *)(a1 + 336);
          v19 = v17 == 4 || v17 > 0x7F;
          if ( v19 && v16 == 0 )
            v15 = 1;
          else
            v15 = v16;
        }
        while ( !v19 && v15 );
      }
      v20 = v15;
      finish_wait(a1 + 456, v23);
      LODWORD(v9) = v20;
    }
    if ( (_DWORD)v9 && *(_DWORD *)(a1 + 336) < 0x80u )
    {
      result = 0;
      goto LABEL_50;
    }
    raw_read_lock_bh(a1 + 320);
    v21 = *(_DWORD **)(a1 + 496);
    if ( *(v21 - 1) != 598874997 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v21)(a1, 0);
  }
  raw_read_unlock_bh(a1 + 320);
  result = 4294967291LL;
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
