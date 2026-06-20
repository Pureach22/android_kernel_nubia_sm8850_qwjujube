__int64 __fastcall dbglog_init(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  qdf_mem_set(mod_print, 0x4E8u, 0);
  if ( qword_925D80 )
  {
    if ( (dword_183E4 & 4) != 0 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: module print is already registered for this module %d\n",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "dbglog_reg_modprint",
        2);
  }
  else
  {
    qword_925D80 = (__int64)dbglog_sta_powersave_print_handler;
  }
  if ( qword_925DC8 )
  {
    if ( (dword_183E4 & 4) != 0 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: module print is already registered for this module %d\n",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "dbglog_reg_modprint",
        11);
  }
  else
  {
    qword_925DC8 = (__int64)dbglog_ap_powersave_print_handler;
  }
  if ( qword_925E08 )
  {
    if ( (dword_183E4 & 4) != 0 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: module print is already registered for this module %d\n",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "dbglog_reg_modprint",
        19);
  }
  else
  {
    qword_925E08 = (__int64)dbglog_wal_print_handler;
  }
  if ( qword_925DB8 )
  {
    if ( (dword_183E4 & 4) != 0 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: module print is already registered for this module %d\n",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "dbglog_reg_modprint",
        9);
  }
  else
  {
    qword_925DB8 = (__int64)dbglog_scan_print_handler;
  }
  if ( qword_925DC0 )
  {
    if ( (dword_183E4 & 4) != 0 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: module print is already registered for this module %d\n",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "dbglog_reg_modprint",
        10);
  }
  else
  {
    qword_925DC0 = (__int64)dbglog_ratectrl_print_handler;
  }
  if ( qword_925E40 )
  {
    if ( (dword_183E4 & 4) != 0 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: module print is already registered for this module %d\n",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "dbglog_reg_modprint",
        26);
  }
  else
  {
    qword_925E40 = (__int64)dbglog_ani_print_handler;
  }
  if ( qword_925D90 )
  {
    if ( (dword_183E4 & 4) != 0 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: module print is already registered for this module %d\n",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "dbglog_reg_modprint",
        4);
  }
  else
  {
    qword_925D90 = (__int64)dbglog_coex_print_handler;
  }
  if ( qword_925DF8 )
  {
    if ( (dword_183E4 & 4) != 0 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: module print is already registered for this module %d\n",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "dbglog_reg_modprint",
        17);
  }
  else
  {
    qword_925DF8 = (__int64)dbglog_beacon_print_handler;
  }
  if ( qword_925E68 )
  {
    if ( (dword_183E4 & 4) != 0 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: module print is already registered for this module %d\n",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "dbglog_reg_modprint",
        31);
  }
  else
  {
    qword_925E68 = (__int64)dbglog_wow_print_handler;
  }
  if ( qword_925DE0 )
  {
    if ( (dword_183E4 & 4) != 0 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: module print is already registered for this module %d\n",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "dbglog_reg_modprint",
        14);
  }
  else
  {
    qword_925DE0 = (__int64)dbglog_data_txrx_print_handler;
  }
  if ( qword_925E88 )
  {
    if ( (dword_183E4 & 4) != 0 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: module print is already registered for this module %d\n",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "dbglog_reg_modprint",
        35);
  }
  else
  {
    qword_925E88 = (__int64)dbglog_smps_print_handler;
  }
  if ( qword_925E48 )
  {
    if ( (dword_183E4 & 4) != 0 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: module print is already registered for this module %d\n",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "dbglog_reg_modprint",
        27);
  }
  else
  {
    qword_925E48 = (__int64)dbglog_p2p_print_handler;
  }
  if ( qword_925E18 )
  {
    if ( (dword_183E4 & 4) != 0 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: module print is already registered for this module %d\n",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "dbglog_reg_modprint",
        21);
  }
  else
  {
    qword_925E18 = (__int64)dbglog_pcielp_print_handler;
  }
  if ( qword_925EE8 )
  {
    if ( (dword_183E4 & 4) != 0 )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: module print is already registered for this module %d\n",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "dbglog_reg_modprint",
        47);
  }
  else
  {
    qword_925EE8 = (__int64)dbglog_ibss_powersave_print_handler;
  }
  tgt_assert_enable = *(_BYTE *)(a1 + 721);
  if ( (unsigned int)wmi_unified_register_event_handler(
                       (_QWORD *)a1,
                       2u,
                       (__int64)dbglog_parse_debug_logs,
                       3u,
                       v2,
                       v3,
                       v4,
                       v5,
                       v6,
                       v7,
                       v8,
                       v9)
    || (unsigned int)wmi_unified_register_event_handler(
                       (_QWORD *)a1,
                       0x64u,
                       (__int64)fw_diag_data_event_handler,
                       3u,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17)
    || (unsigned int)wmi_unified_register_event_handler(
                       (_QWORD *)a1,
                       0x68u,
                       (__int64)diag_fw_handler,
                       3u,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23,
                       v24,
                       v25)
    || (unsigned int)wmi_unified_register_event_handler(
                       (_QWORD *)a1,
                       0x11Bu,
                       (__int64)fw_opt_dp_diag_handler,
                       3u,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30,
                       v31,
                       v32,
                       v33) )
  {
    return 0xFFFFFFFFLL;
  }
  dbglog_debugfs_init(a1);
  return 0;
}
