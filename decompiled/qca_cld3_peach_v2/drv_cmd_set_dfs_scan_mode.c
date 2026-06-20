__int64 __fastcall drv_cmd_set_dfs_scan_mode(__int64 a1, __int64 *a2, __int64 a3, unsigned __int8 a4)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  unsigned __int8 v24[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 1;
  if ( (kstrtou8(a3 + a4 + 1, 10, v24) & 0x80000000) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: kstrtou8 failed range [%d - %d]",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "drv_cmd_set_dfs_scan_mode",
      0,
      2);
    result = 4294967274LL;
  }
  else if ( v24[0] >= 3u )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: dfs_scan_mode value %d is out of range (Min: %d Max: %d)",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "drv_cmd_set_dfs_scan_mode");
    result = 4294967274LL;
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Received Command to Set DFS Scan Mode = %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "drv_cmd_set_dfs_scan_mode");
    v14 = wlan_hdd_enable_dfs_chan_scan(a2, v24[0] != 0);
    if ( (v14 & 0x80000000) != 0 )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: disable/enable DFS channel request was denied",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "drv_cmd_set_dfs_scan_mode");
    else
      sme_update_dfs_scan_mode(a2[2], *(unsigned __int8 *)(a1 + 8), v24[0]);
    result = v14;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
