__int64 __fastcall wmi_interface_logging_init(__int64 a1, int a2)
{
  __int64 v3; // x8
  int v4; // w3
  __int64 dir; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  __int64 entry; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 result; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v41; // [xsp+10h] [xbp-20h]
  __int64 v42; // [xsp+18h] [xbp-18h]
  __int64 v43; // [xsp+20h] [xbp-10h]
  __int64 v44; // [xsp+28h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)(a1 + 424) = &g_wmi_command_buf_idx;
  *(_QWORD *)(a1 + 440) = &wmi_command_tx_cmp_log_buffer;
  *(_QWORD *)(a1 + 448) = 0;
  *(_QWORD *)(a1 + 456) = &g_wmi_command_tx_cmp_buf_idx;
  *(_QWORD *)(a1 + 472) = &wmi_event_log_buffer;
  *(_QWORD *)(a1 + 480) = 0;
  *(_QWORD *)(a1 + 488) = &g_wmi_event_buf_idx;
  *(_QWORD *)(a1 + 504) = &wmi_rx_event_log_buffer;
  *(_QWORD *)(a1 + 512) = 0;
  *(_QWORD *)(a1 + 408) = &wmi_command_log_buffer;
  *(_QWORD *)(a1 + 416) = 0;
  *(_QWORD *)(a1 + 520) = &g_wmi_rx_event_buf_idx;
  *(_DWORD *)(a1 + 432) = 1024;
  *(_DWORD *)(a1 + 464) = 1024;
  *(_DWORD *)(a1 + 496) = 1024;
  *(_DWORD *)(a1 + 528) = 1024;
  *(_QWORD *)(a1 + 568) = &wmi_mgmt_command_tx_cmp_log_buffer;
  *(_QWORD *)(a1 + 536) = &wmi_mgmt_command_log_buffer;
  *(_QWORD *)(a1 + 584) = &g_wmi_mgmt_command_tx_cmp_buf_idx;
  *(_QWORD *)(a1 + 552) = &g_wmi_mgmt_command_buf_idx;
  *(_QWORD *)(a1 + 600) = &wmi_mgmt_rx_event_log_buffer;
  *(_DWORD *)(a1 + 560) = 256;
  *(_DWORD *)(a1 + 592) = 256;
  *(_QWORD *)(a1 + 616) = &g_wmi_mgmt_rx_event_buf_idx;
  *(_DWORD *)(a1 + 624) = 256;
  *(_DWORD *)(a1 + 656) = 256;
  *(_QWORD *)(a1 + 632) = &wmi_diag_rx_event_log_buffer;
  *(_BYTE *)(a1 + 680) = 1;
  v3 = *(_QWORD *)(a1 + 760);
  *(_QWORD *)(a1 + 544) = 0;
  *(_QWORD *)(a1 + 576) = 0;
  *(_QWORD *)(a1 + 608) = 0;
  *(_QWORD *)(a1 + 640) = 0;
  *(_QWORD *)(a1 + 648) = &g_wmi_diag_rx_event_buf_idx;
  *(_DWORD *)(a1 + 664) = 0;
  *(_QWORD *)(a1 + 672) = 0;
  v4 = *(_DWORD *)(v3 + 7696);
  v42 = 0;
  v43 = 0;
  *(_QWORD *)s = 0;
  v41 = 0;
  snprintf(s, 0x20u, "WMI_SOC%u_PDEV%u", v4, a2);
  dir = qdf_debugfs_create_dir(s, 0);
  *(_QWORD *)(a1 + 688) = dir;
  if ( dir )
  {
    v14 = dir;
    entry = qdf_debugfs_create_entry(wmi_debugfs_infos, 420, dir, a1, off_12158);
    *(_QWORD *)(a1 + 776) = entry;
    if ( !entry )
      goto LABEL_11;
    v24 = qdf_debugfs_create_entry(off_12160, 420, v14, a1, off_12168);
    *(_QWORD *)(a1 + 784) = v24;
    if ( !v24 )
      goto LABEL_11;
    v25 = qdf_debugfs_create_entry(off_12170, 420, v14, a1, off_12178);
    *(_QWORD *)(a1 + 792) = v25;
    if ( !v25 )
      goto LABEL_11;
    v26 = qdf_debugfs_create_entry(off_12180, 420, v14, a1, off_12188);
    *(_QWORD *)(a1 + 800) = v26;
    if ( !v26 )
      goto LABEL_11;
    v27 = qdf_debugfs_create_entry(off_12190, 420, v14, a1, off_12198);
    *(_QWORD *)(a1 + 808) = v27;
    if ( !v27 )
      goto LABEL_11;
    v28 = qdf_debugfs_create_entry(off_121A0, 420, v14, a1, off_121A8);
    *(_QWORD *)(a1 + 816) = v28;
    if ( !v28
      || (v29 = qdf_debugfs_create_entry(off_121B0, 420, v14, a1, off_121B8), (*(_QWORD *)(a1 + 824) = v29) == 0)
      || (v30 = qdf_debugfs_create_entry(off_121C0, 420, v14, a1, off_121C8), (*(_QWORD *)(a1 + 832) = v30) == 0)
      || (result = qdf_debugfs_create_entry(off_121D0, 420, v14, a1, off_121D8), (*(_QWORD *)(a1 + 840) = result) == 0) )
    {
LABEL_11:
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: debug Entry creation failed!",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wmi_debugfs_create");
      result = qdf_trace_msg(
                 0x31u,
                 2u,
                 "%s: debug Entry creation failed!",
                 v32,
                 v33,
                 v34,
                 v35,
                 v36,
                 v37,
                 v38,
                 v39,
                 "wmi_debugfs_create");
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x31u,
               2u,
               "%s: error while creating debugfs dir for %s",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "wmi_debugfs_init",
               s);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
