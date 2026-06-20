unsigned __int64 __fastcall clk_rpmh_recalc_rate(__int64 a1, unsigned __int64 a2)
{
  return a2 / *(unsigned __int8 *)(a1 + 32);
}
