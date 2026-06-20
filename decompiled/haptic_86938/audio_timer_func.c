__int64 __fastcall audio_timer_func(__int64 a1)
{
  queue_work_on(32, *(_QWORD *)(a1 - 216), a1 + 64);
  hrtimer_start_range_ns(
    a1,
    1000 * (*(_DWORD *)(a1 - 68) % 1000000) + 1000000000LL * (*(_DWORD *)(a1 - 68) / 1000000),
    0,
    1);
  return 0;
}
