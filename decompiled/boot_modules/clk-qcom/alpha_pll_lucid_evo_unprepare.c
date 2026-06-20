__int64 __fastcall alpha_pll_lucid_evo_unprepare(__int64 a1)
{
  __int64 v1; // x19

  if ( (*(_BYTE *)(a1 - 8) & 0x40) != 0 )
  {
    v1 = a1;
    alpha_pll_lucid_evo_disable();
    a1 = v1;
  }
  return clk_unprepare_regmap(a1);
}
