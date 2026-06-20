__int64 __fastcall os_if_fwol_get_thermal_stats_req(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  unsigned int thermal_stats_cmd; // w19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  thermal_stats_cmd = ucfg_fwol_send_get_thermal_stats_cmd(a1, a2, a3, a4);
  if ( thermal_stats_cmd )
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Failed to send get thermal stats cmd to FW, %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "os_if_fwol_get_thermal_stats_req",
      thermal_stats_cmd);
  return qdf_status_to_os_return(thermal_stats_cmd);
}
