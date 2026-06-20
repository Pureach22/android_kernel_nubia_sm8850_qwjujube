__int64 __fastcall wma_update_bss_peer_phy_mode(unsigned __int16 *a1, __int64 a2)
{
  __int64 bsspeer; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  unsigned int v14; // w23
  __int64 v16; // x0
  int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v35; // w21
  __int64 cmpt_obj; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v47; // x8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7

  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a2, 8u);
  if ( !bsspeer )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: not able to find bss peer for vdev %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wma_update_bss_peer_phy_mode",
      *(unsigned __int8 *)(a2 + 104));
    return 4;
  }
  v13 = bsspeer;
  v14 = *(_DWORD *)(bsspeer + 72);
  if ( wlan_reg_is_24ghz_ch_freq(*a1) )
  {
    if ( v14 == 2 || *((_DWORD *)a1 + 7) == 2 )
      v16 = 1;
    else
      v16 = 2;
  }
  else
  {
    v16 = 0;
  }
  v17 = wma_peer_phymode(v16, 1, v14 - 5 < 6, *((unsigned int *)a1 + 6), v14 - 11 < 0xA, v14 - 21 < 0xA, 0);
  if ( v17 == v14 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Ignore update, old %d and new %d phymode are same, vdev_id : %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wma_update_bss_peer_phy_mode",
      v14,
      v14,
      *(unsigned __int8 *)(a2 + 104));
    wlan_objmgr_peer_release_ref(v13, 8u, v26, v27, v28, v29, v30, v31, v32, v33);
    return 0;
  }
  v35 = v17;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a2, v18, v19, v20, v21, v22, v23, v24, v25);
  if ( !cmpt_obj )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: not able to get mlme_obj",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "wma_update_bss_peer_phy_mode");
    wlan_objmgr_peer_release_ref(v13, 8u, v56, v57, v58, v59, v60, v61, v62, v63);
    return 4;
  }
  v45 = cmpt_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v13 + 760);
  }
  else
  {
    raw_spin_lock_bh(v13 + 760);
    *(_QWORD *)(v13 + 768) |= 1uLL;
  }
  wlan_peer_set_phymode(v13, v35);
  v47 = *(_QWORD *)(v13 + 768);
  if ( (v47 & 1) != 0 )
  {
    *(_QWORD *)(v13 + 768) = v47 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v13 + 760);
  }
  else
  {
    raw_spin_unlock(v13 + 760);
  }
  wlan_objmgr_peer_release_ref(v13, 8u, v48, v49, v50, v51, v52, v53, v54, v55);
  *(_DWORD *)(v45 + 176) = wmi_host_to_fw_phymode(v35);
  *((_DWORD *)a1 + 7) = v35;
  return 0;
}
