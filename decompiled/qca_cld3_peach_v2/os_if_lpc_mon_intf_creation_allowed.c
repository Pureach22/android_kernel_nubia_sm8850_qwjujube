__int64 __fastcall os_if_lpc_mon_intf_creation_allowed(__int64 a1)
{
  unsigned int connection_count_with_mlo; // w20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  if ( !ucfg_dp_is_local_pkt_capture_enabled() )
    return 1;
  connection_count_with_mlo = policy_mgr_get_connection_count_with_mlo(a1);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: Total connections %d",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "os_if_local_pkt_capture_concurrency_allowed",
    connection_count_with_mlo);
  if ( !connection_count_with_mlo )
    return 1;
  if ( connection_count_with_mlo == 1 )
  {
    v19 = policy_mgr_mode_specific_connection_count(a1, 0, nullptr);
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: sta_count %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "os_if_local_pkt_capture_concurrency_allowed",
      v19);
    if ( v19 )
      return 1;
  }
  qdf_trace_msg(
    0x48u,
    2u,
    "%s: Concurrency check failed, lpc interface creation not allowed",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "os_if_lpc_mon_intf_creation_allowed");
  return 0;
}
