unsigned __int16 *__fastcall utils_dfs_init_nol(__int64 a1)
{
  __int64 dfs_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x5
  __int64 v12; // x19
  __int64 v13; // x21
  unsigned __int16 *result; // x0
  unsigned __int16 *v15; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned __int64 StatusReg; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x8

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  v11 = *(_QWORD *)(a1 + 80);
  v12 = dfs_obj;
  if ( !dfs_obj || !v11 )
    return (unsigned __int16 *)qdf_trace_msg(
                                 0x27u,
                                 2u,
                                 "WLAN_DEBUG_DFS_ALWAYS : %s: dfs %pK, psoc %pK",
                                 v3,
                                 v4,
                                 v5,
                                 v6,
                                 v7,
                                 v8,
                                 v9,
                                 v10,
                                 "utils_dfs_init_nol",
                                 dfs_obj,
                                 v11);
  v13 = *(_QWORD *)(v11 + 2120);
  if ( !*(_QWORD *)(v13 + 40) )
    return (unsigned __int16 *)qdf_trace_msg(
                                 0x27u,
                                 2u,
                                 "WLAN_DEBUG_DFS_ALWAYS : %s: null device",
                                 v3,
                                 v4,
                                 v5,
                                 v6,
                                 v7,
                                 v8,
                                 v9,
                                 v10,
                                 "utils_dfs_init_nol");
  result = (unsigned __int16 *)_qdf_mem_malloc(0x788u, "utils_dfs_init_nol", 1082);
  if ( result )
  {
    v15 = result;
    qdf_mem_set(result, 0x788u, 0);
    if ( (int)cnss_utils_wlan_get_dfs_nol(*(_QWORD *)(v13 + 40), v15, 1928) < 1 )
    {
      qdf_trace_msg(
        0x27u,
        8u,
        "WLAN_DEBUG_DFS_ALWAYS : %s: no nol in pld",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "utils_dfs_init_nol");
    }
    else
    {
      dfs_set_nol(v12, (__int64)(v15 + 4), *v15, v16, v17, v18, v19, v20, v21, v22, v23);
      qdf_trace_msg(
        0x27u,
        4u,
        "WLAN_DEBUG_DFS_ALWAYS : %s: nol channels in pld",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "utils_dfs_init_nol");
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v12 + 14968);
      }
      else
      {
        raw_spin_lock_bh(v12 + 14968);
        *(_QWORD *)(v12 + 14976) |= 1uLL;
      }
      dfs_print_nol(v12, v33, v34, v35, v36, v37, v38, v39, v40);
      v41 = *(_QWORD *)(v12 + 14976);
      if ( (v41 & 1) != 0 )
      {
        *(_QWORD *)(v12 + 14976) = v41 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v12 + 14968);
      }
      else
      {
        raw_spin_unlock(v12 + 14968);
      }
    }
    return (unsigned __int16 *)_qdf_mem_free((__int64)v15);
  }
  return result;
}
