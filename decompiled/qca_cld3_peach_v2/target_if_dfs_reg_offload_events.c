__int64 __fastcall target_if_dfs_reg_offload_events(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x8
  unsigned int v3; // w19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  __int64 v13; // x0
  unsigned int v14; // w20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  v1 = a1;
  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 2800);
    if ( v2 )
      a1 = *(_QWORD *)(v2 + 16);
    else
      a1 = 0;
  }
  v3 = wmi_unified_register_event(a1, 150, (__int64)target_if_dfs_radar_detection_event_handler);
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: wmi_dfs_radar_detection_event_id ret=%d",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "target_if_dfs_reg_offload_events",
    v3);
  if ( v1 && (v12 = *(_QWORD *)(v1 + 2800)) != 0 )
    v13 = *(_QWORD *)(v12 + 16);
  else
    v13 = 0;
  v14 = wmi_unified_register_event(v13, 149, (__int64)target_if_dfs_cac_complete_event_handler);
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: wmi_dfs_cac_complete_id ret=%d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "target_if_dfs_reg_offload_events",
    v14);
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: wmi_vdev_ocac_complete_event_id ret=%d",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "target_if_dfs_reg_offload_events",
    0);
  return 16 * (unsigned int)((v14 | v3) != 0);
}
