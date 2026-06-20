__int64 __fastcall clk_rcg2_crmc_unprepare(__int64 a1)
{
  __int64 result; // x0

  result = clk_rcg2_vote_perf_level(a1);
  if ( (_DWORD)result )
  {
    if ( !*(_QWORD *)(a1 + 16) )
      clk_hw_get_name(a1);
    return printk(&unk_281B8);
  }
  return result;
}
