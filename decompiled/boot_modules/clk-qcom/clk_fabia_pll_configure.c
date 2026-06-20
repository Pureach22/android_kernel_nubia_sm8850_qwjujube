__int64 __fastcall clk_fabia_pll_configure(unsigned int *a1, __int64 a2, unsigned int *a3)
{
  unsigned __int8 *v3; // x8
  int v7; // w8
  __int64 v8; // x2

  v3 = *((unsigned __int8 **)a1 + 1);
  if ( v3[1] )
  {
    regmap_write(a2, *a1 + v3[1], *a3);
    v3 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v3[20] )
  {
    regmap_write(a2, *a1 + v3[20], a3[3]);
    v3 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v3[8] )
  {
    regmap_write(a2, *a1 + v3[8], a3[5]);
    v3 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v3[9] )
  {
    regmap_write(a2, *a1 + v3[9], a3[6]);
    v3 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v3[5] )
  {
    regmap_write(a2, *a1 + v3[5], a3[9]);
    v3 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v3[6] )
  {
    regmap_write(a2, *a1 + v3[6], a3[10]);
    v3 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v3[12] )
  {
    regmap_write(a2, *a1 + v3[12], a3[12]);
    v3 = *((unsigned __int8 **)a1 + 1);
  }
  v7 = v3[13];
  if ( v7 )
    regmap_write(a2, *a1 + v7, a3[14]);
  v8 = a3[28];
  if ( (_DWORD)v8 )
    regmap_update_bits_base(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 5LL), v8, a3[27], 0, 0, 0);
  if ( (a1[10] & 0x10) != 0 )
    regmap_update_bits_base(a2, *a1, 0x1000000, 0x1000000, 0, 0, 0);
  regmap_update_bits_base(a2, *a1, 0x800000, 0x800000, 0, 0, 0);
  return regmap_update_bits_base(a2, *a1, 4, 4, 0, 0, 0);
}
