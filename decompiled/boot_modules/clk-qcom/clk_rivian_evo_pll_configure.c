__int64 __fastcall clk_rivian_evo_pll_configure(unsigned int *a1, __int64 a2, unsigned int *a3)
{
  unsigned __int8 *v3; // x8

  v3 = *((unsigned __int8 **)a1 + 1);
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
  if ( v3[10] )
  {
    regmap_write(a2, *a1 + v3[10], a3[7]);
    v3 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v3[11] )
  {
    regmap_write(a2, *a1 + v3[11], a3[8]);
    v3 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v3[12] )
  {
    regmap_write(a2, *a1 + v3[12], a3[12]);
    v3 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v3[13] )
  {
    regmap_write(a2, *a1 + v3[13], a3[14]);
    v3 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v3[1] )
  {
    regmap_write(a2, *a1 + v3[1], *a3);
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
  regmap_write(a2, *a1 + v3[19], 0);
  return regmap_update_bits_base(a2, *a1, 7, 6, 0, 0, 0);
}
