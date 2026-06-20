__int64 __fastcall qpnp_tm_temp_lite_init(__int64 *a1)
{
  int v2; // w8
  __int64 v3; // x0
  __int64 result; // x0
  unsigned __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x1
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_DWORD *)a1 + 12);
  v3 = *a1;
  v8 = 0;
  result = regmap_read(v3, (unsigned int)(v2 + 80), &v8);
  if ( (result & 0x80000000) == 0 )
  {
    v5 = v8;
    v6 = *a1;
    v8 = 0;
    v7 = (unsigned int)(*((_DWORD *)a1 + 12) + 81);
    a1[18] = temp_map_lite_warning[(v5 >> 2) & 3];
    result = regmap_read(v6, v7, &v8);
    if ( (result & 0x80000000) == 0 )
    {
      result = 0;
      a1[20] = temp_map_lite_shutdown[((unsigned __int64)v8 >> 2) & 3];
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
