__int64 __fastcall hdd_send_get_thermal_stats_cmd(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x20

  if ( *a1 )
    return 16 * (unsigned int)((unsigned int)os_if_fwol_get_thermal_stats_req() != 0);
  v10 = jiffies;
  if ( hdd_send_get_thermal_stats_cmd___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: NULL pointer for psoc",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "hdd_send_get_thermal_stats_cmd");
    hdd_send_get_thermal_stats_cmd___last_ticks = v10;
  }
  return 4;
}
