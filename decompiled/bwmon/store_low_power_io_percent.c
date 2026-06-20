__int64 __fastcall store_low_power_io_percent(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w0
  unsigned int v7; // w8
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v6 = kstrtouint(a3, 10, &v9);
  if ( v6 < 0 )
  {
    a4 = v6;
  }
  else
  {
    v7 = v9;
    if ( v9 <= 1 )
      v7 = 1;
    if ( v7 >= 0x190 )
      v7 = 400;
    *(_DWORD *)(a1 - 280) = v7;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
