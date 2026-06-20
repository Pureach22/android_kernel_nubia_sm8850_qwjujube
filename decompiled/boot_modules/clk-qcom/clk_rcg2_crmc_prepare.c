__int64 __fastcall clk_rcg2_crmc_prepare(__int64 a1)
{
  if ( !*(_QWORD *)(a1 - 24) )
    *(_QWORD *)(a1 - 24) = cxo_f;
  return clk_rcg2_vote_perf_level();
}
