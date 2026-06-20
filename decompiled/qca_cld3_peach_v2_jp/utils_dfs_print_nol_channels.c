__int64 __fastcall utils_dfs_print_nol_channels(__int64 a1)
{
  __int64 dfs_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  unsigned __int64 StatusReg; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
    return qdf_trace_msg(
             0x27u,
             2u,
             "WLAN_DEBUG_DFS_ALWAYS : %s: null dfs",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "utils_dfs_print_nol_channels");
  v10 = dfs_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(dfs_obj + 14968);
  }
  else
  {
    raw_spin_lock_bh(dfs_obj + 14968);
    *(_QWORD *)(v10 + 14976) |= 1uLL;
  }
  dfs_print_nol(v10, v12, v13, v14, v15, v16, v17, v18, v19);
  v20 = *(_QWORD *)(v10 + 14976);
  if ( (v20 & 1) == 0 )
    return raw_spin_unlock(v10 + 14968);
  *(_QWORD *)(v10 + 14976) = v20 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v10 + 14968);
}
