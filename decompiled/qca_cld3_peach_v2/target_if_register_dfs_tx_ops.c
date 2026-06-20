__int64 __fastcall target_if_register_dfs_tx_ops(
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
  __int64 v9; // x29
  __int64 v10; // x30

  if ( a1 )
  {
    a1[151] = target_if_dfs_register_event_handler;
    a1[152] = target_process_bang_radar_cmd;
    a1[153] = target_send_agile_ch_cfg_cmd;
    a1[154] = target_send_ocac_abort_cmd;
    a1[155] = target_if_dfs_is_pdev_5ghz;
    a1[160] = target_send_dfs_offload_enable_cmd;
    a1[156] = target_if_dfs_set_phyerr_filter_offload;
    a1[142] = target_if_dfs_get_caps;
    a1[157] = target_if_dfs_offload;
    a1[158] = target_if_dfs_bangradar_320_supp;
    a1[159] = target_if_dfs_is_radar_found_chan_freq_eq_center_freq;
    a1[163] = target_send_usenol_pdev_param;
    a1[164] = target_send_subchan_marking_pdev_param;
    a1[148] = target_if_dfs_get_target_type;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: invalid tx_ops",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_register_dfs_tx_ops",
      v9,
      v10);
    return 16;
  }
}
