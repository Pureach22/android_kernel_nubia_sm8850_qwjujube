__int16 *__fastcall utils_dfs_save_nol(__int64 a1)
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
  __int64 v11; // x8
  __int64 v12; // x21
  __int64 v13; // x19
  __int16 *result; // x0
  __int16 *v15; // x20
  unsigned __int64 StatusReg; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  __int16 v26; // w8
  const char *v27; // x2
  int v28; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
  {
    v27 = "WLAN_DEBUG_DFS_ALWAYS : %s: null dfs";
LABEL_18:
    result = (__int16 *)qdf_trace_msg(0x27u, 2u, v27, v3, v4, v5, v6, v7, v8, v9, v10, "utils_dfs_save_nol");
    goto LABEL_19;
  }
  v11 = *(_QWORD *)(a1 + 80);
  if ( !v11 )
  {
    v27 = "WLAN_DEBUG_DFS_ALWAYS : %s: null psoc";
    goto LABEL_18;
  }
  v12 = *(_QWORD *)(v11 + 2120);
  if ( !*(_QWORD *)(v12 + 40) )
  {
    v27 = "WLAN_DEBUG_DFS_ALWAYS : %s: null device";
    goto LABEL_18;
  }
  v13 = dfs_obj;
  result = (__int16 *)_qdf_mem_malloc(0x788u, "utils_dfs_save_nol", 1209);
  if ( result )
  {
    v15 = result;
    qdf_mem_set(result, 0x788u, 0);
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
    dfs_get_nol(v13, (__int64)(v15 + 4), &v28, v17, v18, v19, v20, v21, v22, v23, v24);
    v25 = *(_QWORD *)(v13 + 14976);
    if ( (v25 & 1) != 0 )
    {
      *(_QWORD *)(v13 + 14976) = v25 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v13 + 14968);
    }
    else
    {
      raw_spin_unlock(v13 + 14968);
    }
    if ( v28 >= 80 )
      v26 = 80;
    else
      v26 = v28;
    *v15 = v26;
    cnss_utils_wlan_set_dfs_nol(*(_QWORD *)(v12 + 40), v15, 1928);
    result = (__int16 *)_qdf_mem_free((__int64)v15);
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
