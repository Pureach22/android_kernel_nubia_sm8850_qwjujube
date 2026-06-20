__int64 wlan_hdd_create_mib_stats_lock()
{
  __int64 result; // x0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7

  result = qdf_mutex_create((__int64)&mibstats_lock);
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: mibstats lock init failed!",
             v1,
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             "wlan_hdd_create_mib_stats_lock");
  return result;
}
