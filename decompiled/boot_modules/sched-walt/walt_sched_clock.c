__int64 __fastcall walt_sched_clock(__int64 a1, __int64 a2)
{
  if ( walt_clock_suspended == 1 )
    return sched_clock_last;
  else
    return sched_clock(a1, a2);
}
