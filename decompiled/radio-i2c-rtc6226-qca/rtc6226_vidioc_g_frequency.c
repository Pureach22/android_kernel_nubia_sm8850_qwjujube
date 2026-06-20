__int64 __fastcall rtc6226_vidioc_g_frequency(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  __int64 result; // x0
  int v6; // w9
  unsigned int v7; // w19
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(video_devdata() + 336);
  v8 = 0;
  *(_DWORD *)(a3 + 4) = 1;
  result = rtc6226_get_freq(v4, &v8);
  v6 = 10 * v8;
  *(_DWORD *)(a3 + 8) = 16 * v8;
  *(_DWORD *)(v4 + 1860) = v6;
  if ( (result & 0x80000000) != 0 )
  {
    v7 = result;
    printk(&unk_CD15, "rtc6226_vidioc_g_frequency");
    result = v7;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
