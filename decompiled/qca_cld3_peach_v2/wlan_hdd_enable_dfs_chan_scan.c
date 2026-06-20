__int64 __fastcall wlan_hdd_enable_dfs_chan_scan(__int64 *a1, char a2)
{
  unsigned int v4; // w21
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  const char *v14; // x4
  __int64 result; // x0
  unsigned int v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w22
  unsigned int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x4
  unsigned int v44; // w19
  unsigned __int8 v45[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+8h] [xbp-8h]

  v4 = a2 & 1;
  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a1;
  v45[0] = 1;
  wlan_scan_cfg_get_dfs_chan_scan_allowed(v5, v45);
  if ( v45[0] == v4 )
  {
    if ( (a2 & 1) != 0 )
      v14 = "enabled";
    else
      v14 = "disabled";
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: DFS channels are already %s",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_hdd_enable_dfs_chan_scan",
      v14);
    result = 0;
  }
  else if ( (a2 & 1) == 0
         && ((wlan_hdd_check_dfs_channel_for_adapter(a1, 0) & 1) != 0
          || (wlan_hdd_check_dfs_channel_for_adapter(a1, 1) & 1) != 0) )
  {
    result = 4294967201LL;
  }
  else
  {
    wlan_scan_cfg_set_dfs_chan_scan_allowed(*a1, a2 & 1);
    v16 = sme_enable_dfs_chan_scan(a1[2], v4);
    if ( v16 )
    {
      v25 = v16;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to set DFS channel scan flag to %d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "wlan_hdd_enable_dfs_chan_scan",
        v4);
      v26 = v25;
    }
    else
    {
      v27 = hdd_abort_mac_scan_all_adapters(a1);
      v26 = ucfg_reg_enable_dfs_channels(a1[1], a2 & 1, v27, v28, v29, v30, v31, v32, v33, v34);
      if ( v26 )
      {
        if ( (a2 & 1) != 0 )
          v43 = "enable";
        else
          v43 = "disable";
        v44 = v26;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to %s DFS channels",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "wlan_hdd_enable_dfs_chan_scan",
          v43);
        v26 = v44;
      }
    }
    result = qdf_status_to_os_return(v26);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
