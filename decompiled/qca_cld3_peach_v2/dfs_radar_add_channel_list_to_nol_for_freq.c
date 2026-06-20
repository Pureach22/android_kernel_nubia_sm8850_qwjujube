__int64 __fastcall dfs_radar_add_channel_list_to_nol_for_freq(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        _BYTE *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned __int64 v16; // x26
  unsigned int v17; // w22
  unsigned int v18; // w25
  unsigned __int64 StatusReg; // x27
  unsigned int v20; // w1
  unsigned int v21; // w24
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x8
  __int64 v31; // x8
  const char *v32; // x2
  double updated; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  if ( (unsigned __int8)*a4 > 0x10u )
  {
    if ( !a1 || (*(_BYTE *)(a1 + 1) & 1) != 0 )
      qdf_trace_msg(
        0x27u,
        2u,
        "WLAN_DEBUG_DFS : %s: Invalid num channels: %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "dfs_radar_add_channel_list_to_nol_for_freq");
    return 16;
  }
  if ( !*a4 )
  {
LABEL_34:
    if ( !a1 || (*(_BYTE *)(a1 + 1) & 1) != 0 )
      qdf_trace_msg(
        0x27u,
        2u,
        "WLAN_DEBUG_DFS : %s: dfs channels not found in channel list",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "dfs_radar_add_channel_list_to_nol_for_freq");
    return 16;
  }
  v16 = 0;
  v17 = 0;
  v18 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  do
  {
    v20 = *(unsigned __int16 *)(a2 + 2 * v16);
    if ( !*(_WORD *)(a2 + 2 * v16) || v20 == v18 )
      goto LABEL_24;
    if ( (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 14936), v20, a5, a6, a7, a8, a9, a10, a11, a12) & 1) == 0 )
    {
      if ( a1 && (*(_BYTE *)(a1 + 1) & 1) == 0 )
        goto LABEL_24;
      v21 = *(unsigned __int16 *)(a2 + 2 * v16);
      v32 = "WLAN_DEBUG_DFS : %s: ch=%d is not dfs, skip";
LABEL_23:
      qdf_trace_msg(
        0x27u,
        4u,
        v32,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "dfs_radar_add_channel_list_to_nol_for_freq",
        v21);
LABEL_24:
      v21 = v18;
      goto LABEL_25;
    }
    v21 = *(unsigned __int16 *)(a2 + 2 * v16);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 14968);
    }
    else
    {
      raw_spin_lock_bh(a1 + 14968);
      *(_QWORD *)(a1 + 14976) |= 1uLL;
    }
    dfs_nol_addchan(a1, *(_WORD *)(a2 + 2 * v16), *(_DWORD *)(a1 + 14632), v22, v23, v24, v25, v26, v27, v28, v29);
    v30 = *(_QWORD *)(a1 + 14976);
    if ( (v30 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 14976) = v30 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 14968);
    }
    else
    {
      raw_spin_unlock(a1 + 14968);
    }
    v31 = (unsigned __int8)v17++;
    *(_WORD *)(a3 + 2 * v31) = v21;
    utils_dfs_deliver_event(*(_QWORD *)(a1 + 14936), *(unsigned __int16 *)(a2 + 2 * v16), 4);
    if ( !a1 )
    {
      v32 = "WLAN_DEBUG_DFS_NOL : %s: ch=%d Added to NOL";
      v18 = v21;
      goto LABEL_23;
    }
    v32 = "WLAN_DEBUG_DFS_NOL : %s: ch=%d Added to NOL";
    v18 = v21;
    if ( (*(_BYTE *)(a1 + 1) & 0x20) != 0 )
      goto LABEL_23;
LABEL_25:
    ++v16;
    v18 = v21;
  }
  while ( v16 < (unsigned __int8)*a4 );
  if ( !(_BYTE)v17 )
    goto LABEL_34;
  *a4 = v17;
  utils_dfs_reg_update_nol_chan_for_freq(*(_QWORD *)(a1 + 14936), a3, v17, 1);
  if ( *(_BYTE *)(a1 + 14988) == 1 && (dfs_mlme_is_opmode_sta(*(_QWORD *)(a1 + 14936)) & 1) != 0 )
    updated = utils_dfs_reg_update_nol_history_chan_for_freq(*(_QWORD *)(a1 + 14936), a3, v17, 1);
  dfs_nol_update(a1, updated, v34, v35, v36, v37, v38, v39, v40);
  utils_dfs_save_nol(*(_QWORD *)(a1 + 14936));
  return 0;
}
