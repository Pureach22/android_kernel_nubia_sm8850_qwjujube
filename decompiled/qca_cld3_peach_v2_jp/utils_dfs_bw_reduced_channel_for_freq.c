__int64 __fastcall utils_dfs_bw_reduced_channel_for_freq(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        _WORD *a12)
{
  __int64 dfs_obj; // x0
  unsigned __int16 *v16; // x22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v26; // x2

  *a12 = 0;
  if ( !*(_QWORD *)(a1 + 80) )
  {
    v26 = "WLAN_DEBUG_DFS_ALWAYS : %s: null psoc";
LABEL_9:
    qdf_trace_msg(0x27u, 2u, v26, a3, a4, a5, a6, a7, a8, a9, a10, "utils_dfs_bw_reduced_channel_for_freq");
    return 16;
  }
  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
  {
    v26 = "WLAN_DEBUG_DFS_ALWAYS : %s: null dfs";
    goto LABEL_9;
  }
  v16 = *(unsigned __int16 **)(dfs_obj + 14888);
  if ( (wlan_reg_get_channel_state_for_pwrmode(a1, *v16, 0, a3, a4, a5, a6, a7, a8, a9, a10) & 0xFFFFFFFE) != 2 )
    return 16;
  if ( *a2 == 4 )
    *a2 = 2;
  a2[2] = v16[11];
  a2[3] = v16[12];
  wlan_reg_set_channel_params_for_pwrmode(a1, *v16, 0, (__int64)a2, 0, v17, v18, v19, v20, v21, v22, v23, v24);
  *a12 = *v16;
  return 0;
}
