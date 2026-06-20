__int64 __fastcall tsens_calibrate_nvmem(__int64 a1, char a2)
{
  __int64 result; // x0
  unsigned int v4; // w17
  int v5; // w11
  __int64 v6; // x16
  int v7; // w0
  unsigned __int64 v8; // x1
  bool v10; // w2
  int v11; // w1
  _QWORD v12[8]; // [xsp+8h] [xbp-88h] BYREF
  _QWORD v13[9]; // [xsp+48h] [xbp-48h] BYREF

  v13[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v13, 0, 64);
  memset(v12, 0, sizeof(v12));
  result = tsens_read_calibration((_QWORD *)a1, a2, (__int64)v13, (__int64)v12, 0);
  if ( (result & 0x80000000) == 0 )
  {
    if ( *(_DWORD *)(a1 + 8) )
    {
      v4 = 0;
      v5 = result & 0x7FFFFFFB;
      do
      {
        v6 = a1 + 2600 + 88LL * (int)v4;
        v7 = *(_DWORD *)(v6 + 72);
        if ( !v7 )
        {
          v7 = 3200;
          *(_DWORD *)(v6 + 72) = 3200;
        }
        v8 = 4LL * (int)v4;
        v10 = v8 > 0x40 || v4 == 16;
        if ( v5 == 3 )
        {
          if ( v10 || v8 > 0x40 )
LABEL_21:
            __break(1u);
          v11 = *((_DWORD *)v13 + (int)v4);
          v7 = 1000 * (*((_DWORD *)v12 + (int)v4) - v11) / 90;
          *(_DWORD *)(v6 + 72) = v7;
        }
        else
        {
          if ( v10 )
            goto LABEL_21;
          v11 = *((_DWORD *)v13 + (int)v4);
        }
        ++v4;
        *(_DWORD *)(v6 + 64) = -30 * v7 + 1000 * v11;
      }
      while ( v4 < *(_DWORD *)(a1 + 8) );
    }
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
