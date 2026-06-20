__int64 __fastcall kgsl_start_idle_timer_1(__int64 a1)
{
  __int64 v2; // x20

  v2 = jiffies;
  *(_QWORD *)(a1 + 14144) = _msecs_to_jiffies(*(_QWORD *)(a1 + 10080)) + v2;
  return mod_timer(a1 + 8792);
}
