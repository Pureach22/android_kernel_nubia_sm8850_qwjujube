__int64 __fastcall clk_alpha_pll_hwfsm_set_rate(__int64 a1, __int64 a2, __int64 a3)
{
  return _clk_alpha_pll_set_rate(a1, a2, a3, clk_alpha_pll_hwfsm_is_enabled);
}
