__int64 __fastcall mhi_sync_power_up(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w20
  __int64 v4; // x0
  unsigned int v5; // w8
  __int64 v6; // x20
  unsigned int v7; // w8
  unsigned int v8; // w8
  bool v9; // cc
  __int64 v10; // x0
  _QWORD v11[6]; // [xsp+0h] [xbp-30h] BYREF

  v11[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = mhi_async_power_up(a1);
  if ( !(_DWORD)result )
  {
    v3 = *(_DWORD *)(a1 + 332);
    if ( !v3 )
      v3 = *(_DWORD *)(a1 + 328);
    v4 = _msecs_to_jiffies(v3);
    v5 = *(_DWORD *)(a1 + 344);
    if ( (v5 > 7 || ((1 << v5) & 0x94) == 0) && *(_DWORD *)(a1 + 336) <= 0x7Fu && v4 )
    {
      memset(v11, 0, 40);
      v6 = _msecs_to_jiffies(v3);
      init_wait_entry(v11, 0);
      while ( 1 )
      {
        prepare_to_wait_event(a1 + 456, v11, 2);
        v7 = *(_DWORD *)(a1 + 344);
        if ( v7 <= 7 && ((1 << v7) & 0x94) != 0 )
          break;
        v8 = *(_DWORD *)(a1 + 336);
        v9 = !v6 && v8 > 0x7F;
        v10 = v9 ? 1LL : v6;
        if ( v8 > 0x7F || !v10 )
          break;
        v6 = schedule_timeout(v10);
      }
      finish_wait(a1 + 456, v11);
      v5 = *(_DWORD *)(a1 + 344);
    }
    if ( v5 <= 7 && ((1 << v5) & 0x94) != 0 )
    {
      result = 0;
    }
    else
    {
      if ( !*(_QWORD *)(a1 + 160) )
        _mhi_power_down(a1, 0, 1);
      result = 4294967186LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
