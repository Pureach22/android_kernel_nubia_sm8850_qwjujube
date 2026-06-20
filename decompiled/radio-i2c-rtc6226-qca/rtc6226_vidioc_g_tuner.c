__int64 __fastcall rtc6226_vidioc_g_tuner(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x20
  unsigned int v7; // w23
  int v8; // w8
  __int64 v9; // x21
  __int64 v10; // x0
  char *v11; // x1
  int v12; // w22
  char v13; // [xsp+0h] [xbp-10h] BYREF
  char v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = video_devdata();
  if ( *(_DWORD *)a3 )
  {
    result = 4294967274LL;
  }
  else
  {
    v6 = *(_QWORD *)(v4 + 336);
    result = ((__int64 (__fastcall *)(__int64, __int64))rtc6226_get_register)(v6, 11);
    if ( (result & 0x80000000) == 0 )
    {
      strcpy((char *)(a3 + 4), "FM");
      v7 = result;
      *(_QWORD *)(a3 + 36) = 0x19100000001LL;
      *(_DWORD *)(a3 + 48) = 160 * (*(_WORD *)(v6 + 1802) & 0x7FFF);
      *(_DWORD *)(a3 + 44) = 160 * (*(_WORD *)(v6 + 1804) & 0x7FFF);
      if ( (*(_WORD *)(v6 + 1782) & 0x400) != 0 )
        v8 = 19;
      else
        v8 = 17;
      *(_DWORD *)(a3 + 52) = v8;
      if ( (*(_WORD *)(v6 + 1766) & 0x2000) != 0 )
      {
        *(_DWORD *)(a3 + 56) = 0;
        v14 = 11;
        v9 = raw_spin_lock_irqsave(v6 + 1976);
        v10 = v6 + 3160;
        v11 = &v14;
      }
      else
      {
        *(_DWORD *)(a3 + 56) = 1;
        v13 = 10;
        v9 = raw_spin_lock_irqsave(v6 + 1976);
        v10 = v6 + 3160;
        v11 = &v13;
      }
      v12 = _kfifo_in(v10, v11, 1);
      raw_spin_unlock_irqrestore(v6 + 1976, v9);
      if ( v12 )
        _wake_up(v6 + 2520, 1, 1, 0);
      result = v7;
      *(_DWORD *)(a3 + 60) = *(unsigned __int8 *)(v6 + 1784);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
