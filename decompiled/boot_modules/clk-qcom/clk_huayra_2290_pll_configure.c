__int64 __fastcall clk_huayra_2290_pll_configure(unsigned int *a1, __int64 a2, unsigned int *a3)
{
  unsigned __int8 *v6; // x9
  unsigned int v7; // w8
  int v8; // w9
  __int64 result; // x0
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *((unsigned __int8 **)a1 + 1);
  v10 = 0;
  v7 = *a1;
  if ( v6[*a1 + v6[8]] )
  {
    regmap_write(a2, v7 + v6[*a1 + v6[8]], a3[5]);
    v7 = *a1;
    v6 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v6[v7 + v6[9]] )
  {
    regmap_write(a2, v7 + v6[v7 + v6[9]], a3[6]);
    v7 = *a1;
    v6 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v6[v7 + v6[10]] )
  {
    regmap_write(a2, v7 + v6[v7 + v6[10]], a3[7]);
    v7 = *a1;
    v6 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v6[v7 + v6[12]] )
  {
    regmap_write(a2, v7 + v6[v7 + v6[12]], a3[12]);
    v7 = *a1;
    v6 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v6[v7 + v6[13]] )
  {
    regmap_write(a2, v7 + v6[v7 + v6[13]], a3[14]);
    v7 = *a1;
    v6 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v6[v7 + v6[14]] )
  {
    regmap_write(a2, v7 + v6[v7 + v6[14]], a3[16]);
    v7 = *a1;
    v6 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v6[v7 + v6[1]] )
  {
    regmap_write(a2, v7 + v6[v7 + v6[1]], *a3);
    v7 = *a1;
    v6 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v6[v7 + v6[3]] )
  {
    regmap_write(a2, v7 + v6[v7 + v6[3]], a3[3]);
    v7 = *a1;
    v6 = *((unsigned __int8 **)a1 + 1);
  }
  v8 = v6[v7 + v6[5]];
  if ( v8 )
  {
    regmap_write(a2, v7 + v8, a3[9]);
    v7 = *a1;
  }
  regmap_update_bits_base(a2, v7, 2, 2, 0, 0, 0);
  regmap_read(a2, *a1, &v10);
  _const_udelay(21475);
  regmap_update_bits_base(a2, *a1, 4, 4, 0, 0, 0);
  regmap_read(a2, *a1, &v10);
  usleep_range_state(50, 55, 2);
  result = regmap_update_bits_base(a2, *a1, 1, 1, 0, 0, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
