__int64 __fastcall stm_heartbeat_link(__int64 a1)
{
  __int64 v1; // x1

  v1 = 1000000LL * interval_ms;
  *(_DWORD *)(a1 + 112) = 1;
  hrtimer_start_range_ns(a1 + 48, v1, 0, 0);
  return 0;
}
