__int64 __fastcall suspend_time_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x20
  __int64 v7; // x21

  v4 = raw_spin_lock(&suspend_lock);
  if ( suspend_start )
  {
    v5 = ktime_get(v4);
    v6 = v5 / 1000000 - suspend_start;
    suspend_start = v5 / 1000000;
  }
  else
  {
    v6 = 0;
  }
  v7 = suspend_time;
  suspend_time = 0;
  raw_spin_unlock(&suspend_lock);
  return snprintf(a3, 0x1000u, "%llu\n", v7 + v6);
}
