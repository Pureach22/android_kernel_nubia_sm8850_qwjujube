__int64 __fastcall qpnp_tm_temp_dac_init(__int64 *a1)
{
  int v2; // w8
  __int64 v3; // x0
  __int64 result; // x0
  int v5; // w9
  __int64 v6; // x0
  __int64 v7; // x8
  int v8; // w8
  int v9; // w9
  __int64 v10; // x0
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_DWORD *)a1 + 12);
  v3 = *a1;
  v11 = 0;
  result = regmap_read(v3, (unsigned int)(v2 + 71), &v11);
  if ( (result & 0x80000000) == 0 )
  {
    v5 = *((_DWORD *)a1 + 12);
    v6 = *a1;
    v7 = 625 * (unsigned int)(unsigned __int8)v11 + 80000;
    v11 = 0;
    a1[18] = v7;
    result = regmap_read(v6, (unsigned int)(v5 + 72), &v11);
    if ( (result & 0x80000000) == 0 )
    {
      v8 = (unsigned __int8)v11;
      v9 = *((_DWORD *)a1 + 12);
      v10 = *a1;
      v11 = 0;
      a1[19] = (unsigned int)(625 * v8 + 80000);
      result = regmap_read(v10, (unsigned int)(v9 + 73), &v11);
      if ( (result & 0x80000000) == 0 )
      {
        result = 0;
        a1[20] = 625 * (unsigned int)(unsigned __int8)v11 + 80000;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
