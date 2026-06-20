__int64 __fastcall clk_trion_pll_postdiv_round_rate(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  unsigned int v4; // w22
  __int64 parent; // x0

  v3 = *(_QWORD *)(a1 + 152);
  v4 = *(unsigned __int8 *)(a1 - 12);
  parent = clk_hw_get_parent(a1);
  return divider_round_rate_parent(a1, parent, a2, a3, v3, v4, 16);
}
