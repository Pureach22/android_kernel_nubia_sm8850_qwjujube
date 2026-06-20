__int64 __fastcall clk_agera_pll_configure(__int64 result, __int64 a2, unsigned int *a3)
{
  unsigned __int8 *v3; // x8
  __int64 v5; // x21
  int v7; // w8

  v3 = *(unsigned __int8 **)(result + 8);
  v5 = result;
  if ( v3[1] )
  {
    result = regmap_write(a2, *(_DWORD *)result + (unsigned int)v3[1], *a3);
    v3 = *(unsigned __int8 **)(v5 + 8);
  }
  if ( v3[3] )
  {
    result = regmap_write(a2, *(_DWORD *)v5 + (unsigned int)v3[3], a3[3]);
    v3 = *(unsigned __int8 **)(v5 + 8);
  }
  if ( v3[5] )
  {
    result = regmap_write(a2, *(_DWORD *)v5 + (unsigned int)v3[5], a3[9]);
    v3 = *(unsigned __int8 **)(v5 + 8);
  }
  if ( v3[8] )
  {
    result = regmap_write(a2, *(_DWORD *)v5 + (unsigned int)v3[8], a3[5]);
    v3 = *(unsigned __int8 **)(v5 + 8);
  }
  if ( v3[9] )
  {
    result = regmap_write(a2, *(_DWORD *)v5 + (unsigned int)v3[9], a3[6]);
    v3 = *(unsigned __int8 **)(v5 + 8);
  }
  if ( v3[12] )
  {
    result = regmap_write(a2, *(_DWORD *)v5 + (unsigned int)v3[12], a3[12]);
    v3 = *(unsigned __int8 **)(v5 + 8);
  }
  v7 = v3[13];
  if ( v7 )
    return regmap_write(a2, (unsigned int)(*(_DWORD *)v5 + v7), a3[14]);
  return result;
}
