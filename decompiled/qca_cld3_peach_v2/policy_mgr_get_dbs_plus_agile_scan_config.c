__int64 __fastcall policy_mgr_get_dbs_plus_agile_scan_config(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  if ( !policy_mgr_is_dual_mac_disabled_in_ini(a1) )
  {
    context = policy_mgr_get_context(a1);
    if ( context )
      return (*(unsigned __int8 *)(context + 1515) >> 6) & 1;
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "policy_mgr_get_dbs_plus_agile_scan_config");
  }
  return 0;
}
