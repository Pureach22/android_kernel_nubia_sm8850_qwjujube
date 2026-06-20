__int64 __fastcall wlan_cp_stats_twt_get_all_peer_session_params(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int8 v4; // w20
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w24
  int v15; // w25
  __int64 v16; // x19
  _QWORD *v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x22
  int v27; // w20
  unsigned __int64 StatusReg; // x26
  __int64 next_active_peer_of_vdev; // x23
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int *v38; // x8
  __int64 comp_private_obj; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x23
  __int64 v49; // x8

  v4 = a2;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 38);
  if ( !v5 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: vdev is NULL, vdev_id: %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_cp_stats_twt_get_all_peer_session_params",
      v4);
    return 0;
  }
  v14 = *(unsigned __int16 *)(v5 + 224);
  v15 = *(_DWORD *)(v5 + 16);
  v16 = v5;
  v17 = wlan_vdev_peer_list_peek_active_head(v5, (_QWORD *)(v5 + 192), 0x26u);
  if ( !v17 )
    goto LABEL_25;
  v26 = (__int64)v17;
  v27 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    wlan_objmgr_peer_get_comp_private_obj(v26, 0x1Bu);
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(v26, 0x1Bu);
    if ( !comp_private_obj )
      goto LABEL_14;
    v48 = comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 24);
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 24);
      *(_QWORD *)(v48 + 32) |= 1uLL;
    }
    if ( (*(_DWORD *)(v48 + 60) & 0xFFFFFFFD) == 1 )
      qdf_mem_copy((void *)(a3 + 52LL * v27++), (const void *)(v48 + 48), 0x34u);
    v49 = *(_QWORD *)(v48 + 32);
    if ( (v49 & 1) == 0 )
    {
      raw_spin_unlock(v48 + 24);
LABEL_14:
      if ( v15 )
        goto LABEL_16;
      goto LABEL_15;
    }
    *(_QWORD *)(v48 + 32) = v49 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v48 + 24);
    if ( v15 )
      goto LABEL_16;
LABEL_15:
    if ( v27 >= 1 )
    {
      wlan_objmgr_peer_release_ref(v26, 0x26u, v40, v41, v42, v43, v44, v45, v46, v47);
      goto LABEL_26;
    }
LABEL_16:
    if ( v15 == 1 && v27 >= v14 )
      break;
    next_active_peer_of_vdev = wlan_peer_get_next_active_peer_of_vdev(v16, (_QWORD *)(v16 + 192), v26, 0x26u);
    wlan_objmgr_peer_release_ref(v26, 0x26u, v30, v31, v32, v33, v34, v35, v36, v37);
    v26 = next_active_peer_of_vdev;
    if ( !next_active_peer_of_vdev )
      goto LABEL_24;
  }
  wlan_objmgr_peer_release_ref(v26, 0x26u, v40, v41, v42, v43, v44, v45, v46, v47);
LABEL_24:
  if ( !v27 )
  {
LABEL_25:
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: Unable to find a peer with twt session established",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_cp_stats_twt_get_all_peer_session_params");
    v27 = 0;
  }
LABEL_26:
  wlan_objmgr_vdev_release_ref(v16, 0x26u, v38, v18, v19, v20, v21, v22, v23, v24, v25);
  return (unsigned int)v27;
}
