__int64 __fastcall dfs_remove_from_nol(__int64 a1)
{
  int v1; // w19
  __int64 v2; // x22
  unsigned int v3; // w20
  unsigned __int64 StatusReg; // x8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  int v13; // w21
  __int64 *v14; // x19
  __int64 v15; // x28
  unsigned int v16; // w25
  unsigned int v17; // w26
  unsigned int v18; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _QWORD *v27; // x8
  __int64 v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned __int8 v37; // w20
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned __int16 v47; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v48; // [xsp+8h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(a1 - 24);
  v2 = *(_QWORD *)(a1 - 32);
  v3 = *(unsigned __int16 *)(a1 - 20);
  v47 = v1;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(v2 + 14968);
      *(_QWORD *)(v2 + 14976) |= 1uLL;
      if ( v2 )
        goto LABEL_5;
LABEL_18:
      qdf_trace_msg(
        0x27u,
        2u,
        "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "dfs_nol_delete");
      goto LABEL_19;
    }
  }
  raw_spin_lock(v2 + 14968);
  if ( !v2 )
    goto LABEL_18;
LABEL_5:
  v13 = (unsigned __int16)v1;
  if ( (*(_BYTE *)(v2 + 1) & 0x20) != 0 )
    qdf_trace_msg(
      0x27u,
      8u,
      "WLAN_DEBUG_DFS_NOL : %s: remove channel=%d/%d MHz from NOL",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "dfs_nol_delete",
      (unsigned __int16)v1,
      v3);
  v14 = (__int64 *)(v2 + 64);
  v15 = *(_QWORD *)(v2 + 64);
  while ( v15 )
  {
    if ( *(_DWORD *)(v15 + 24) == v13 && *(_DWORD *)(v15 + 28) == v3 )
    {
      *v14 = *(_QWORD *)(v15 + 136);
      if ( (*(_BYTE *)(v2 + 1) & 0x20) != 0 )
      {
        v16 = *(_DWORD *)(v15 + 24);
        v17 = *(_DWORD *)(v15 + 28);
        v18 = jiffies_to_msecs(jiffies);
        qdf_trace_msg(
          0x27u,
          8u,
          "WLAN_DEBUG_DFS_NOL : %s: removing channel %d/%dMHz from NOL tstamp=%d",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "dfs_nol_delete",
          v16,
          v17,
          v18 / 0x3E8uLL);
      }
      *(_QWORD *)v15 = 0;
      v27 = *(_QWORD **)(v2 + 14648);
      *(_QWORD *)(v15 + 8) = v27;
      *v27 = v15;
      LODWORD(v27) = *(_DWORD *)(v2 + 84);
      *(_QWORD *)(v2 + 14648) = v15;
      v15 = *v14;
      LODWORD(v27) = (_DWORD)v27 - 1;
      *(_DWORD *)(v2 + 84) = (_DWORD)v27;
      if ( (int)v27 < 0 )
      {
        qdf_trace_msg(
          0x27u,
          4u,
          "WLAN_DEBUG_DFS_ALWAYS : %s: dfs_nol_count < 0; eek!",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "dfs_nol_delete");
        *(_DWORD *)(v2 + 84) = 0;
      }
    }
    else
    {
      v14 = (__int64 *)(v15 + 136);
      v15 = *(_QWORD *)(v15 + 136);
    }
  }
LABEL_19:
  queue_work_on(32, system_wq, v2 + 14656);
  v28 = *(_QWORD *)(v2 + 14976);
  if ( (v28 & 1) != 0 )
  {
    *(_QWORD *)(v2 + 14976) = v28 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v2 + 14968);
  }
  else
  {
    raw_spin_unlock(v2 + 14968);
  }
  utils_dfs_reg_update_nol_chan_for_freq(*(_QWORD *)(v2 + 14936), &v47, 1, 0);
  dfs_nol_update(v2, v29, v30, v31, v32, v33, v34, v35, v36);
  dfs_mlme_nol_timeout_notification(*(_QWORD *)(v2 + 14936));
  v37 = utils_dfs_freq_to_chan(v47);
  utils_dfs_deliver_event(*(_QWORD *)(v2 + 14936), v47, 5);
  if ( !v2 || (*(_BYTE *)(v2 + 1) & 0x20) != 0 )
    qdf_trace_msg(
      0x27u,
      8u,
      "WLAN_DEBUG_DFS_NOL : %s: remove channel %d from nol",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "dfs_remove_from_nol",
      v37);
  utils_dfs_unmark_precac_nol_for_freq(*(_QWORD *)(v2 + 14936), v47);
  utils_dfs_save_nol(*(_QWORD *)(v2 + 14936));
  _ReadStatusReg(SP_EL0);
  return 0;
}
