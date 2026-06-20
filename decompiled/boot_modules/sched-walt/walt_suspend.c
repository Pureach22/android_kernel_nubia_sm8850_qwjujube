__int64 __fastcall walt_suspend(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = sched_clock(a1, a2);
  sched_clock_last = v2;
  walt_clock_suspended = 1;
  return 0;
}
