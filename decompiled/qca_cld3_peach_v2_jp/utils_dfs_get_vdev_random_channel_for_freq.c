__int64 __fastcall utils_dfs_get_vdev_random_channel_for_freq(
        __int64 a1,
        __int64 a2,
        unsigned __int16 a3,
        unsigned int *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        __int64 a13,
        unsigned __int16 *a14,
        __int64 a15)
{
  __int64 v15; // x8
  __int64 dfs_obj; // x0
  __int64 v23; // x23
  __int64 v24; // x19
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned __int16 v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w22
  const char *v43; // x2
  __int64 v45; // [xsp+0h] [xbp-10h] BYREF
  __int64 v46; // [xsp+8h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a14 = 0;
  v15 = *(_QWORD *)(a1 + 80);
  v45 = 102;
  if ( !v15 )
  {
    v43 = "WLAN_DEBUG_DFS_ALWAYS : %s: null psoc";
LABEL_12:
    qdf_trace_msg(
      0x27u,
      2u,
      v43,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "utils_dfs_get_vdev_random_channel_for_freq",
      v45,
      v46);
    v24 = 0;
    goto LABEL_13;
  }
  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
  {
    v43 = "WLAN_DEBUG_DFS_ALWAYS : %s: null dfs";
    goto LABEL_12;
  }
  v23 = dfs_obj;
  wlan_reg_get_dfs_region(a1, (_DWORD *)&v45 + 1, a5, a6, a7, a8, a9, a10, a11, a12);
  v24 = _qdf_mem_malloc(0xCC0u, "utils_dfs_get_vdev_random_channel_for_freq", 933);
  if ( !v24 )
  {
LABEL_13:
    v42 = 16;
    goto LABEL_14;
  }
  utils_dfs_get_channel_list(a1, a2, v24, (unsigned int *)&v45);
  if ( !(_DWORD)v45 )
  {
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: zero channels",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "utils_dfs_get_vdev_random_channel_for_freq");
    goto LABEL_13;
  }
  v33 = dfs_prepare_random_channel_for_freq(
          v23,
          v24,
          v45,
          a3,
          (unsigned __int16 *)a4,
          SHIDWORD(v45),
          a15,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32);
  *a14 = v33;
  if ( (*(_BYTE *)(v23 + 2) & 0x20) != 0 )
  {
    qdf_trace_msg(
      0x27u,
      4u,
      "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: input width=%d",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "utils_dfs_get_vdev_random_channel_for_freq",
      *a4);
    v33 = *a14;
  }
  if ( v33 )
  {
    wlan_reg_set_channel_params_for_pwrmode(a1, v33, 0, (__int64)a4, 0, v34, v35, v36, v37, v38, v39, v40, v41);
    v42 = 0;
    if ( (*(_BYTE *)(v23 + 2) & 0x20) != 0 )
      goto LABEL_17;
  }
  else
  {
    v42 = 16;
    if ( (*(_BYTE *)(v23 + 2) & 0x20) != 0 )
LABEL_17:
      qdf_trace_msg(
        0x27u,
        4u,
        "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: ch=%d, seg0=%d, seg1=%d, width=%d",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "utils_dfs_get_vdev_random_channel_for_freq",
        *a14,
        *((unsigned __int8 *)a4 + 5),
        *((unsigned __int8 *)a4 + 6),
        *a4,
        v45,
        v46);
  }
LABEL_14:
  _qdf_mem_free(v24);
  _ReadStatusReg(SP_EL0);
  return v42;
}
