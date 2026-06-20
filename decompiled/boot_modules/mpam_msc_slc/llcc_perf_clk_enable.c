__int64 __fastcall llcc_perf_clk_enable(char a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = llcc_perfmon_clock;
  if ( !llcc_perfmon_clock )
    return 4294967294LL;
  if ( (a1 & 1) == 0 )
  {
    clk_disable(llcc_perfmon_clock);
    goto LABEL_8;
  }
  if ( (unsigned int)clk_prepare(llcc_perfmon_clock) )
    return 0;
  result = clk_enable(v1);
  if ( (_DWORD)result )
  {
LABEL_8:
    clk_unprepare(v1);
    return 0;
  }
  return result;
}
