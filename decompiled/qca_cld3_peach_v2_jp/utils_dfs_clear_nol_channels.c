__int16 *__fastcall utils_dfs_clear_nol_channels(__int64 a1)
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
  __int64 v11; // x20
  unsigned __int64 StatusReg; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
    return (__int16 *)qdf_trace_msg(
                        0x27u,
                        2u,
                        "WLAN_DEBUG_DFS_ALWAYS : %s: null dfs",
                        v3,
                        v4,
                        v5,
                        v6,
                        v7,
                        v8,
                        v9,
                        v10,
                        "utils_dfs_clear_nol_channels");
  v11 = dfs_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(dfs_obj + 14968);
  }
  else
  {
    raw_spin_lock_bh(dfs_obj + 14968);
    *(_QWORD *)(v11 + 14976) |= 1uLL;
  }
  dfs_print_nol(v11, v13, v14, v15, v16, v17, v18, v19, v20);
  v21 = *(_QWORD *)(v11 + 14976);
  if ( (v21 & 1) != 0 )
  {
    *(_QWORD *)(v11 + 14976) = v21 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v11 + 14968);
  }
  else
  {
    raw_spin_unlock(v11 + 14968);
  }
  dfs_nol_timer_cleanup(v11);
  dfs_nol_update(v11, v22, v23, v24, v25, v26, v27, v28, v29);
  return utils_dfs_save_nol(a1);
}
