__int64 __fastcall dfs_nol_update(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 result; // x0
  __int64 v12; // x20
  unsigned __int64 StatusReg; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  int v23; // w21
  __int64 v24; // x10
  __int64 v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x1

  v9 = *(int *)(a1 + 84);
  if ( (_DWORD)v9 )
  {
    result = _qdf_mem_malloc(24 * v9, "dfs_nol_update", 509);
    if ( !result )
      return result;
    v12 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 14968);
      if ( a1 )
        goto LABEL_7;
    }
    else
    {
      raw_spin_lock_bh(a1 + 14968);
      *(_QWORD *)(a1 + 14976) |= 1uLL;
      if ( a1 )
      {
LABEL_7:
        v22 = *(_QWORD *)(a1 + 64);
        if ( v22 )
        {
          v23 = 0;
          do
          {
            v24 = v12 + 24LL * v23++;
            *(_WORD *)v24 = *(_DWORD *)(v22 + 24);
            *(_WORD *)(v24 + 2) = *(_DWORD *)(v22 + 28);
            *(_QWORD *)(v24 + 8) = *(_QWORD *)(v22 + 32);
            *(_DWORD *)(v24 + 16) = *(_DWORD *)(v22 + 40);
            v22 = *(_QWORD *)(v22 + 136);
          }
          while ( v22 );
LABEL_18:
          v25 = *(_QWORD *)(a1 + 14976);
          if ( (v25 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 14976) = v25 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 14968);
          }
          else
          {
            raw_spin_unlock(a1 + 14968);
          }
          if ( v23 != *(_DWORD *)(a1 + 84) )
            qdf_trace_msg(
              0x27u,
              4u,
              "WLAN_DEBUG_DFS_ALWAYS : %s: nlen (%d) != dfs->dfs_nol_count (%d)!",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              "dfs_nol_update",
              (unsigned int)v23);
          if ( v23 <= 0 )
            v34 = 0;
          else
            v34 = v12;
          dfs_mlme_clist_update(*(_QWORD *)(a1 + 14936), v34, (unsigned int)v23);
          return _qdf_mem_free(v12);
        }
LABEL_17:
        v23 = 0;
        goto LABEL_18;
      }
    }
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "dfs_get_nol");
    goto LABEL_17;
  }
  if ( !a1 || (*(_BYTE *)(a1 + 1) & 0x20) != 0 )
    qdf_trace_msg(
      0x27u,
      8u,
      "WLAN_DEBUG_DFS_NOL : %s: dfs_nol_count is zero",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "dfs_nol_update");
  return dfs_mlme_clist_update(*(_QWORD *)(a1 + 14936), 0, 0);
}
