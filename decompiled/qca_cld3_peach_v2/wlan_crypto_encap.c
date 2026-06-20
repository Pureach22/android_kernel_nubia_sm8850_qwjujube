__int64 __fastcall wlan_crypto_encap(_QWORD *a1, __int64 a2, _BYTE *a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x8
  __int64 v8; // x23
  __int64 v9; // x8
  __int64 v10; // x8
  unsigned int v11; // w24
  __int64 peer; // x0
  __int64 v13; // x26
  __int64 comp_private_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  __int64 v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x2
  __int64 result; // x0
  __int64 peer_by_mac_n_vdev; // x0
  __int64 v36; // x22
  __int64 v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned __int64 v46; // x8
  __int64 v47; // x0
  const char *v48; // x19
  __int64 v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned __int64 v58; // x8
  __int64 v59; // x8
  __int64 (__fastcall *v60)(__int64, __int64); // x8
  unsigned int v61; // w19
  __int64 v62; // [xsp+0h] [xbp-10h] BYREF
  __int64 v63; // [xsp+8h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v62) = 0;
  LODWORD(v62) = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 168);
  }
  else
  {
    raw_spin_lock_bh(a1 + 168);
    a1[169] |= 1uLL;
  }
  qdf_mem_copy(&v62, (char *)a1 + 74, 6u);
  v7 = a1[27];
  if ( !v7 || (v8 = *(_QWORD *)(v7 + 80)) == 0 )
  {
    v24 = a1[169];
    if ( (v24 & 1) != 0 )
    {
      a1[169] = v24 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 168);
    }
    else
    {
      raw_spin_unlock(a1 + 168);
    }
    v33 = "%s: psoc NULL";
    goto LABEL_17;
  }
  v9 = a1[169];
  if ( (v9 & 1) != 0 )
  {
    a1[169] = v9 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 168);
  }
  else
  {
    raw_spin_unlock(a1 + 168);
  }
  v10 = a1[27];
  v11 = *(unsigned __int8 *)(v10 + 40);
  peer = wlan_objmgr_get_peer(v8, *(unsigned __int8 *)(v10 + 40), a3, 19);
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 224) + 1LL) & 0x40) != 0 || !peer )
  {
    if ( !peer )
      goto LABEL_22;
  }
  else
  {
    v13 = peer;
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(peer, 14);
    if ( !comp_private_obj )
    {
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: crypto_priv NULL",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "wlan_crypto_get_peer_fils_aead",
        v62,
        v63);
      peer = v13;
LABEL_34:
      wlan_objmgr_peer_release_ref(peer, 19);
      goto LABEL_18;
    }
    v23 = *(unsigned __int8 *)(comp_private_obj + 424);
    peer = v13;
    if ( !v23 )
      goto LABEL_34;
  }
  wlan_objmgr_peer_release_ref(peer, 19);
LABEL_22:
  if ( (*a3 & 1) != 0 )
  {
    v49 = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
    if ( v49 )
    {
      v58 = *(unsigned __int8 *)(v49 + 420);
      if ( v58 >= 4 )
        goto LABEL_50;
      v47 = *(_QWORD *)(v49 + 8 * v58 + 288);
      if ( v47 )
      {
        v36 = 0;
        goto LABEL_39;
      }
LABEL_18:
      result = 4;
LABEL_19:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "wlan_crypto_vdev_get_comp_params",
      v62,
      v63);
    v33 = "%s: crypto_priv NULL";
LABEL_17:
    qdf_trace_msg(0x1Cu, 2u, v33, v25, v26, v27, v28, v29, v30, v31, v32, "wlan_crypto_encap", v62);
    goto LABEL_18;
  }
  peer_by_mac_n_vdev = wlan_objmgr_get_peer_by_mac_n_vdev(v8, v11, &v62, a3, 19);
  if ( !peer_by_mac_n_vdev )
  {
    v33 = "%s: crypto_priv NULL";
    goto LABEL_17;
  }
  v36 = peer_by_mac_n_vdev;
  v37 = wlan_objmgr_peer_get_comp_private_obj(peer_by_mac_n_vdev, 14);
  if ( !v37 )
  {
    v48 = "%s: crypto_priv NULL";
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "wlan_crypto_peer_get_comp_params",
      v62,
      v63);
    goto LABEL_38;
  }
  v46 = *(unsigned __int8 *)(v37 + 420);
  if ( v46 <= 3 )
  {
    v47 = *(_QWORD *)(v37 + 8 * v46 + 288);
    if ( !v47 )
    {
      v48 = "%s: Key is NULL";
LABEL_38:
      qdf_trace_msg(0x1Cu, 2u, v48, v38, v39, v40, v41, v42, v43, v44, v45, "wlan_crypto_encap", v62);
      LODWORD(result) = 4;
      goto LABEL_46;
    }
LABEL_39:
    if ( *(_BYTE *)(v47 + 1) == 1 && (v59 = *(_QWORD *)(v47 + 32)) != 0 )
    {
      v60 = *(__int64 (__fastcall **)(__int64, __int64))(v59 + 32);
      if ( *((_DWORD *)v60 - 1) != -1933021563 )
        __break(0x8228u);
      result = v60(v47, a2);
      if ( !v36 )
        goto LABEL_19;
    }
    else
    {
      result = 4;
      if ( !v36 )
        goto LABEL_19;
    }
LABEL_46:
    v61 = result;
    wlan_objmgr_peer_release_ref(v36, 19);
    result = v61;
    goto LABEL_19;
  }
LABEL_50:
  __break(0x5512u);
  return wlan_crypto_get_peer_fils_aead();
}
