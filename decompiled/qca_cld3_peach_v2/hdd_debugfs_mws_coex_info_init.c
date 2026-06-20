unsigned __int64 __fastcall hdd_debugfs_mws_coex_info_init(__int64 a1)
{
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned __int64 result; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  qword_68A00 = a1;
  qword_68A18 = a1;
  qword_68A30 = a1;
  qword_689E8 = a1;
  qword_68A48 = a1;
  if ( !qdf_debugfs_create_file((__int64)"mws_coex_state", 292, 0, (__int64)&hdd_mws_debugfs_coex_state_fops) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to create the mws coex state file",
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      "hdd_debugfs_mws_coex_info_init");
  if ( !qdf_debugfs_create_file((__int64)"mws_coex_dpwb_state", 292, 0, (__int64)&hdd_mws_debugfs_fops_coex_dpwb_fops) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to create the mws coex dpwb file",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "hdd_debugfs_mws_coex_info_init");
  if ( !qdf_debugfs_create_file((__int64)"mws_coex_tdm_state", 292, 0, (__int64)&hdd_mws_debugfs_tdm_state_fpos) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to create the mws coex tdm file",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "hdd_debugfs_mws_coex_info_init");
  if ( !qdf_debugfs_create_file((__int64)"mws_coex_idrx", 292, 0, (__int64)&hdd_mws_debugfs_idrx_state_fpos) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to create the mws coex idrx file",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "hdd_debugfs_mws_coex_info_init");
  result = qdf_debugfs_create_file(
             (__int64)"mws_coex_antenna_sharing",
             292,
             0,
             (__int64)&hdd_mws_debugfs_antenna_sharing_fpos);
  if ( !result )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Failed to create the mws coex antenna sharing file",
             v34,
             v35,
             v36,
             v37,
             v38,
             v39,
             v40,
             v41,
             "hdd_debugfs_mws_coex_info_init");
  return result;
}
