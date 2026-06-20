__int64 __fastcall policy_mgr_init_non_dbs_pcl(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  void *v28; // x9
  void *v29; // x8

  if ( !a1 )
    return qdf_trace_msg(
             0x4Fu,
             8u,
             "%s: Invalid WMI handle",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "policy_mgr_init_non_dbs_pcl");
  v9 = *(_QWORD *)(a1 + 2800);
  if ( !v9 )
    return qdf_trace_msg(
             0x4Fu,
             8u,
             "%s: Invalid WMI handle",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "policy_mgr_init_non_dbs_pcl");
  v10 = *(_QWORD *)(v9 + 16);
  if ( !v10 )
    return qdf_trace_msg(
             0x4Fu,
             8u,
             "%s: Invalid WMI handle",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "policy_mgr_init_non_dbs_pcl");
  if ( (wmi_service_enabled(*(_QWORD *)(v9 + 16), 0xD0u, a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0
    && (result = wmi_service_enabled(v10, 0x55u, v11, v12, v13, v14, v15, v16, v17, v18), (result & 1) == 0) )
  {
    second_connection_pcl_non_dbs_table = (__int64)&second_connection_pcl_nodbs_no_interband_mcc_table;
    v29 = &third_connection_pcl_nodbs_no_interband_mcc_table;
  }
  else
  {
    result = wmi_service_enabled(v10, 0xD0u, v11, v12, v13, v14, v15, v16, v17, v18);
    if ( (result & 1) != 0
      || (result = wmi_service_enabled(v10, 0x55u, v20, v21, v22, v23, v24, v25, v26, v27), (result & 1) != 0) )
    {
      v28 = &second_connection_pcl_nodbs_table;
    }
    else
    {
      v28 = &second_connection_pcl_nodbs_interband_mcc_table;
    }
    second_connection_pcl_non_dbs_table = (__int64)v28;
    v29 = &third_connection_pcl_nodbs_table;
  }
  third_connection_pcl_non_dbs_table = (__int64)v29;
  return result;
}
