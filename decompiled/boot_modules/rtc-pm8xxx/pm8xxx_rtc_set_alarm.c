__int64 __fastcall pm8xxx_rtc_set_alarm(__int64 a1, _BYTE *a2)
{
  __int64 v3; // x21
  unsigned int *v4; // x20
  int v5; // w0
  __int64 v6; // x1
  __int64 v7; // x2
  int v8; // w8
  __int64 v9; // x0
  __int64 result; // x0
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 152);
  v4 = *(unsigned int **)(v3 + 24);
  v5 = rtc_tm_to_time64(a2 + 4);
  v6 = v4[3];
  v7 = v4[6];
  v8 = v5 - *(_DWORD *)(v3 + 48);
  v9 = *(_QWORD *)(v3 + 8);
  v11 = v8;
  result = regmap_update_bits_base(v9, v6, v7, 0, 0, 0, 0);
  if ( !(_DWORD)result )
  {
    result = regmap_bulk_write(*(_QWORD *)(v3 + 8), v4[5], &v11, 4);
    if ( !(_DWORD)result )
    {
      if ( !*a2
        || (result = regmap_update_bits_base(*(_QWORD *)(v3 + 8), v4[3], v4[6], v4[6], 0, 0, 0), !(_DWORD)result) )
      {
        result = 0;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
