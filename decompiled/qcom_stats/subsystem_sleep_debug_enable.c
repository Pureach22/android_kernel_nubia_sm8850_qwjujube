__int64 __fastcall subsystem_sleep_debug_enable(__int64 result)
{
  subsystem_stats_debug_on = result;
  return result;
}
