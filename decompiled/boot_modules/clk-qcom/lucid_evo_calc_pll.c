unsigned __int64 __fastcall lucid_evo_calc_pll(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned __int64 result; // x0
  __int64 rate; // x0

  result = clk_hw_get_parent(a1);
  if ( result )
  {
    rate = clk_hw_get_rate(result);
    return 1000 * ((rate * a2 + ((rate * (unsigned __int64)a3) >> 16) + 999) / 0x3E8);
  }
  return result;
}
