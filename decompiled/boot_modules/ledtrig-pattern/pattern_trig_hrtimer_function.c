bool __fastcall pattern_trig_hrtimer_function(__int64 a1)
{
  pattern_trig_timer_common_function(a1 - 8328);
  return (*(_BYTE *)(a1 - 48) & 1) != 0 || *(_DWORD *)(a1 - 60);
}
