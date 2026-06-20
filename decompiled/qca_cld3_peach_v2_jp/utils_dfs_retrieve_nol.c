__int64 __fastcall utils_dfs_retrieve_nol(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  void (__fastcall *v12)(__int64, unsigned __int16 *); // x8
  __int64 v13; // x21
  __int64 v14; // x4
  unsigned __int64 StatusReg; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  const char *v25; // x2
  unsigned int v26; // w1
  unsigned __int16 v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  result = wlan_pdev_get_dfs_obj(a1);
  if ( !result )
  {
    v25 = "WLAN_DEBUG_DFS_ALWAYS : %s: null dfs";
    v26 = 2;
LABEL_22:
    result = qdf_trace_msg(0x27u, v26, v25, v3, v4, v5, v6, v7, v8, v9, v10, "utils_dfs_retrieve_nol");
    goto LABEL_23;
  }
  if ( (*(_BYTE *)(result + 80) & 1) == 0 )
  {
    if ( (*(_BYTE *)(result + 1) & 0x20) == 0 )
      goto LABEL_23;
    v25 = "WLAN_DEBUG_DFS_NOL : %s: Store NOL cfg disabled";
    goto LABEL_21;
  }
  v11 = *(_QWORD *)(result + 72);
  if ( !v11 )
    goto LABEL_23;
  if ( !*(_DWORD *)v11 )
  {
    if ( (*(_BYTE *)(result + 1) & 0x20) == 0 )
      goto LABEL_23;
    v25 = "WLAN_DEBUG_DFS_NOL : %s: No NOL Channels";
LABEL_21:
    v26 = 8;
    goto LABEL_22;
  }
  v12 = (void (__fastcall *)(__int64, unsigned __int16 *))off_869118;
  if ( !off_869118 )
  {
    v14 = 0;
    goto LABEL_27;
  }
  v13 = result;
  if ( *((_DWORD *)off_869118 - 1) != -1601810412 )
    __break(0x8228u);
  v12(a1, &v27);
  v14 = v27;
  if ( !v27 )
  {
    result = v13;
    if ( (*(_BYTE *)(v13 + 1) & 0x20) == 0 )
      goto LABEL_23;
    goto LABEL_30;
  }
  result = v13;
  if ( v27 != *(unsigned __int16 *)(v11 + 608) )
  {
LABEL_27:
    if ( (*(_BYTE *)(result + 1) & 0x20) == 0 )
      goto LABEL_23;
LABEL_30:
    result = qdf_trace_msg(
               0x27u,
               8u,
               "WLAN_DEBUG_DFS_NOL : %s: CC Mismatch. Current CC %d CC in NOL %d",
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               "utils_dfs_retrieve_nol",
               v14,
               *(unsigned __int16 *)(v11 + 608));
    goto LABEL_23;
  }
  if ( (*(_BYTE *)(v13 + 1) & 0x20) != 0 )
  {
    qdf_trace_msg(
      0x27u,
      8u,
      "WLAN_DEBUG_DFS_NOL : %s: Initialising stored NOL chans %pK cc %d",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "utils_dfs_retrieve_nol",
      v11,
      v27);
    result = v13;
  }
  dfs_set_nol(result, v11 + 8, *(_DWORD *)v11, v3, v4, v5, v6, v7, v8, v9, v10);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v13 + 14968);
  }
  else
  {
    raw_spin_lock_bh(v13 + 14968);
    *(_QWORD *)(v13 + 14976) |= 1uLL;
  }
  dfs_print_nol(v13, v16, v17, v18, v19, v20, v21, v22, v23);
  v24 = *(_QWORD *)(v13 + 14976);
  if ( (v24 & 1) != 0 )
  {
    *(_QWORD *)(v13 + 14976) = v24 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(v13 + 14968);
  }
  else
  {
    result = raw_spin_unlock(v13 + 14968);
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
