__int64 __fastcall clk_alpha_pll_postdiv_round_rate(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w22
  void *v7; // x23
  __int64 parent; // x0

  v3 = *(unsigned __int8 *)(a1 - 12);
  if ( v3 == 2 )
    v7 = &clk_alpha_2bit_div_table;
  else
    v7 = &clk_alpha_div_table;
  parent = clk_hw_get_parent();
  return divider_round_rate_parent(a1, parent, a2, a3, v7, v3, 2);
}
