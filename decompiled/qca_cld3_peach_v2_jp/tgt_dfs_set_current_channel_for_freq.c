__int64 __fastcall tgt_dfs_set_current_channel_for_freq(
        __int64 a1,
        __int16 a2,
        __int64 a3,
        __int16 a4,
        char a5,
        unsigned __int8 a6,
        unsigned __int8 a7,
        __int16 a8,
        __int16 a9,
        __int16 a10,
        _BYTE *a11)
{
  void **dfs_obj; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v29; // [xsp+8h] [xbp-18h]

  if ( (tgt_dfs_is_5ghz_supported_in_pdev(a1) & 1) != 0 )
  {
    dfs_obj = (void **)wlan_pdev_get_dfs_obj(a1);
    if ( !dfs_obj )
    {
      qdf_trace_msg(
        0x27u,
        2u,
        "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "tgt_dfs_set_current_channel_for_freq");
      return 16;
    }
    LOWORD(v29) = a10;
    dfs_set_current_channel_for_freq(
      dfs_obj,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      a9,
      v29,
      a11);
  }
  return 0;
}
