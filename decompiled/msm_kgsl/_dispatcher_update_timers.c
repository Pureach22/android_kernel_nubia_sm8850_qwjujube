__int64 __fastcall dispatcher_update_timers(__int64 a1)
{
  __int64 v2; // x22
  __int64 result; // x0
  __int64 v4; // x8

  rt_mutex_lock(a1 + 11088);
  kgsl_pwrscale_update(a1);
  if ( (*(_QWORD *)(a1 + 14240) & 0x200) != 0
    && *(_DWORD *)(a1 + 10940)
    && *(_BYTE *)(a1 + 10944)
    && !*(_DWORD *)(a1 + 15584) )
  {
    kgsl_bus_update(a1, 3);
  }
  v2 = jiffies;
  *(_QWORD *)(a1 + 14144) = _msecs_to_jiffies(*(_QWORD *)(a1 + 10080)) + v2;
  mod_timer(a1 + 8792);
  result = rt_mutex_unlock(a1 + 11088);
  if ( !*(_DWORD *)(a1 + 20488) )
  {
    v4 = *(_QWORD *)(a1 + 19640);
    if ( v4 == -208 || *(_DWORD *)(v4 + 1236) != *(_DWORD *)(v4 + 1240) )
      return mod_timer(a1 + 19816);
  }
  return result;
}
