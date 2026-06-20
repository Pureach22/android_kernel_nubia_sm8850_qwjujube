__int64 __fastcall ucfg_twt_get_all_peer_session_params(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int8 v4; // w20
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  int v16; // w24
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
  unsigned __int64 StatusReg; // x25
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
  __int64 v40; // x27
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x23
  __int64 v51; // x8
  int v53; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v54; // [xsp+8h] [xbp-8h]

  v4 = a2;
  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v53 = 0;
  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 38);
  if ( !v6 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: vdev is NULL, vdev_id: %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "ucfg_twt_get_all_peer_session_params",
      v4);
    v27 = 0;
    goto LABEL_31;
  }
  v15 = v6;
  wlan_mlme_get_sap_max_peers(a1, &v53);
  v16 = *(_DWORD *)(v15 + 16);
  v17 = wlan_vdev_peer_list_peek_active_head(v15, (_QWORD *)(v15 + 192), 0x26u);
  if ( !v17 )
    goto LABEL_29;
  v26 = (__int64)v17;
  v27 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(v26, 0x1Bu);
    if ( comp_private_obj )
      v40 = *(_QWORD *)(comp_private_obj + 8);
    else
      v40 = 0;
    v41 = wlan_objmgr_peer_get_comp_private_obj(v26, 0x1Bu);
    if ( !v41 || !v40 )
      goto LABEL_18;
    v50 = v41;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v41 + 24);
    }
    else
    {
      raw_spin_lock_bh(v41 + 24);
      *(_QWORD *)(v50 + 32) |= 1uLL;
    }
    if ( (*(_DWORD *)(v40 + 44) & 0xFFFFFFFD) == 1 )
      qdf_mem_copy((void *)(a3 + 52LL * v27++), (const void *)(v40 + 32), 0x34u);
    v51 = *(_QWORD *)(v50 + 32);
    if ( (v51 & 1) == 0 )
    {
      raw_spin_unlock(v50 + 24);
LABEL_18:
      if ( v16 )
        goto LABEL_20;
      goto LABEL_19;
    }
    *(_QWORD *)(v50 + 32) = v51 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v50 + 24);
    if ( v16 )
      goto LABEL_20;
LABEL_19:
    if ( v27 >= 1 )
    {
      wlan_objmgr_peer_release_ref(v26, 0x26u, v42, v43, v44, v45, v46, v47, v48, v49);
      goto LABEL_30;
    }
LABEL_20:
    if ( v16 == 1 && v27 >= v53 )
      break;
    next_active_peer_of_vdev = wlan_peer_get_next_active_peer_of_vdev(v15, (_QWORD *)(v15 + 192), v26, 0x26u);
    wlan_objmgr_peer_release_ref(v26, 0x26u, v30, v31, v32, v33, v34, v35, v36, v37);
    v26 = next_active_peer_of_vdev;
    if ( !next_active_peer_of_vdev )
      goto LABEL_28;
  }
  wlan_objmgr_peer_release_ref(v26, 0x26u, v42, v43, v44, v45, v46, v47, v48, v49);
LABEL_28:
  if ( !v27 )
  {
LABEL_29:
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
      "ucfg_twt_get_all_peer_session_params");
    v27 = 0;
  }
LABEL_30:
  wlan_objmgr_vdev_release_ref(v15, 0x26u, v38, v18, v19, v20, v21, v22, v23, v24, v25);
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v27;
}
