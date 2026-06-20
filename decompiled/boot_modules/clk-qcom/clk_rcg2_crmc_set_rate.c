__int64 __fastcall clk_rcg2_crmc_set_rate(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a1 - 24) = a2;
  if ( (clk_hw_is_prepared(a1) & 1) != 0 )
    return clk_rcg2_vote_perf_level(a1);
  else
    return 0;
}
