__int64 __fastcall wlan_crypto_demic(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned __int8 a5)
{
  int v9; // w8
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x8
  __int64 v12; // x25
  __int64 v13; // x8
  __int64 peer_by_mac_n_vdev; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x22
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x23
  __int64 comp_private_obj; // x0
  __int64 v36; // x0
  __int64 v37; // x8
  const char *v38; // x2
  __int64 result; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 (__fastcall *v48)(__int64, __int64); // x8
  __int64 v49; // x0
  __int64 v50; // [xsp+0h] [xbp-10h] BYREF
  __int64 v51; // [xsp+8h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_DWORD *)(a1 + 16);
  WORD2(v50) = 0;
  LODWORD(v50) = 0;
  if ( v9 == 6 )
  {
    if ( (**(_BYTE **)(a2 + 224) & 0xF0) == 0x80 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
        goto LABEL_11;
    }
    else if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
    {
      goto LABEL_11;
    }
  }
  else if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    goto LABEL_11;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
  {
    raw_spin_lock_bh(a1 + 1272);
    *(_QWORD *)(a1 + 1280) |= 1uLL;
    goto LABEL_12;
  }
LABEL_11:
  raw_spin_lock(a1 + 1272);
LABEL_12:
  qdf_mem_copy(&v50, (const void *)(a1 + 74), 6u);
  v11 = *(_QWORD *)(a1 + 152);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 80)) == 0 )
  {
    v37 = *(_QWORD *)(a1 + 1280);
    if ( (v37 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1280) = v37 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1272);
    }
    else
    {
      raw_spin_unlock(a1 + 1272);
    }
    v38 = "%s: psoc NULL";
    goto LABEL_28;
  }
  v13 = *(_QWORD *)(a1 + 1280);
  if ( (v13 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1280) = v13 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1272);
  }
  else
  {
    raw_spin_unlock(a1 + 1272);
  }
  if ( *(_DWORD *)a3 == -1 && *(__int16 *)(a3 + 4) == -1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
    if ( comp_private_obj )
    {
      if ( a5 >= 4u )
        goto LABEL_44;
      v36 = *(_QWORD *)(comp_private_obj + 8LL * a5 + 288);
      if ( v36 )
        goto LABEL_34;
LABEL_29:
      result = 4;
LABEL_30:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "wlan_crypto_vdev_get_comp_params",
      v50,
      v51);
    goto LABEL_40;
  }
  peer_by_mac_n_vdev = wlan_objmgr_get_peer_by_mac_n_vdev(
                         v12,
                         *(unsigned __int8 *)(*(_QWORD *)(a1 + 152) + 40LL),
                         &v50,
                         a3,
                         19);
  if ( !peer_by_mac_n_vdev )
  {
    v38 = "%s: peer NULL";
LABEL_28:
    qdf_trace_msg(0x1Cu, 2u, v38, v16, v17, v18, v19, v20, v21, v22, v23, "wlan_crypto_demic", v50);
    goto LABEL_29;
  }
  v24 = peer_by_mac_n_vdev;
  v25 = wlan_objmgr_peer_get_comp_private_obj(peer_by_mac_n_vdev, 14);
  if ( !v25 )
  {
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wlan_crypto_peer_get_comp_params",
      v50,
      v51);
    wlan_objmgr_peer_release_ref(v24, 19);
LABEL_40:
    v38 = "%s: crypto_priv NULL";
    goto LABEL_28;
  }
  v34 = v25;
  comp_private_obj = wlan_objmgr_peer_release_ref(v24, 19);
  if ( a5 <= 3u )
  {
    v36 = *(_QWORD *)(v34 + 8LL * a5 + 288);
    if ( !v36 )
      goto LABEL_29;
LABEL_34:
    v48 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v36 + 32) + 56LL);
    if ( *((_DWORD *)v48 - 1) != -1933021563 )
      __break(0x8228u);
    result = v48(v36, a2);
    goto LABEL_30;
  }
LABEL_44:
  __break(0x5512u);
  v49 = sub_278954(comp_private_obj);
  return wlan_crypto_vdev_is_pmf_enabled(v49);
}
