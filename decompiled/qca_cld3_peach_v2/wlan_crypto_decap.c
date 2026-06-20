__int64 __fastcall wlan_crypto_decap(__int64 a1, __int64 a2, _BYTE *a3)
{
  int v6; // w24
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x8
  __int64 v9; // x23
  __int64 v10; // x8
  unsigned __int8 *v11; // x8
  int v12; // w9
  unsigned int v13; // w10
  int v14; // w11
  unsigned int v15; // w24
  int v16; // w11
  __int64 v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2
  __int64 result; // x0
  int v28; // w13
  int v29; // w11
  int v30; // w13
  unsigned __int64 v31; // x26
  unsigned int v32; // w25
  __int64 peer; // x0
  __int64 v34; // x27
  __int64 comp_private_obj; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w8
  __int64 peer_by_mac_n_vdev; // x0
  __int64 v46; // x21
  __int64 v47; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x0
  const char *v57; // x19
  __int64 v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x8
  __int64 (__fastcall *v68)(__int64, __int64); // x8
  unsigned int v69; // w19
  __int64 v70; // [xsp+0h] [xbp-10h] BYREF
  __int64 v71; // [xsp+8h] [xbp-8h]

  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_DWORD *)(a1 + 16);
  WORD2(v70) = 0;
  LODWORD(v70) = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1344);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1344);
    *(_QWORD *)(a1 + 1352) |= 1uLL;
  }
  qdf_mem_copy(&v70, (const void *)(a1 + 74), 6u);
  v8 = *(_QWORD *)(a1 + 216);
  if ( !v8 || (v9 = *(_QWORD *)(v8 + 80)) == 0 )
  {
    v17 = *(_QWORD *)(a1 + 1352);
    if ( (v17 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1352) = v17 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1344);
    }
    else
    {
      raw_spin_unlock(a1 + 1344);
    }
    v26 = "%s: psoc NULL";
    goto LABEL_21;
  }
  v10 = *(_QWORD *)(a1 + 1352);
  if ( (v10 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 1344);
    if ( v6 == 6 )
      goto LABEL_9;
LABEL_27:
    v11 = *(unsigned __int8 **)(a2 + 224);
    v12 = (char)v11[1];
    v13 = *v11;
    v28 = v13 & 0xF0;
    if ( (~v12 & 3) != 0 )
      v29 = 24;
    else
      v29 = 30;
    if ( v28 == 208 )
    {
      v30 = ((unsigned int)v12 >> 5) & 4;
    }
    else
    {
      if ( v28 != 128 )
        goto LABEL_37;
      if ( v12 >= 0 )
        v30 = 2;
      else
        v30 = 6;
    }
    v29 += v30;
LABEL_37:
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 216) + 12LL) & 0x20) != 0 )
      v15 = ((_BYTE)v29 + 3) & 0x7C;
    else
      v15 = v29;
    goto LABEL_40;
  }
  *(_QWORD *)(a1 + 1352) = v10 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 1344);
  if ( v6 != 6 )
    goto LABEL_27;
LABEL_9:
  v11 = *(unsigned __int8 **)(a2 + 224);
  v12 = (char)v11[1];
  v13 = *v11;
  v14 = v13 & 0xF0;
  if ( (~v12 & 3) != 0 )
    v15 = 24;
  else
    v15 = 30;
  if ( v14 == 208 )
  {
    v15 += ((unsigned int)v12 >> 5) & 4;
  }
  else if ( v14 == 128 )
  {
    if ( v12 >= 0 )
      v16 = 2;
    else
      v16 = 6;
    v15 += v16;
  }
LABEL_40:
  if ( (v13 & 0xC) != 0 || (v31 = 0, v13 >= 0x10) && (v13 >> 4) - 1 >= 3 )
  {
    if ( (v12 & 0x40) == 0 )
      goto LABEL_22;
    v31 = (unsigned __int64)v11[v15 + 3] >> 6;
  }
  v32 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 216) + 40LL);
  peer = wlan_objmgr_get_peer(v9, *(unsigned __int8 *)(*(_QWORD *)(a1 + 216) + 40LL), a3, 19);
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 224) + 1LL) & 0x40) != 0 || !peer )
  {
    if ( !peer )
      goto LABEL_52;
  }
  else
  {
    v34 = peer;
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(peer, 14);
    if ( !comp_private_obj )
    {
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: crypto_priv NULL",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "wlan_crypto_get_peer_fils_aead",
        v70,
        v71);
      peer = v34;
LABEL_66:
      wlan_objmgr_peer_release_ref(peer, 19);
      goto LABEL_22;
    }
    v44 = *(unsigned __int8 *)(comp_private_obj + 424);
    peer = v34;
    if ( !v44 )
      goto LABEL_66;
  }
  wlan_objmgr_peer_release_ref(peer, 19);
LABEL_52:
  if ( (*a3 & 1) != 0 )
  {
    v58 = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
    if ( v58 )
    {
      v56 = *(_QWORD *)(v58 + 8 * v31 + 288);
      if ( v56 )
      {
        v46 = 0;
        goto LABEL_60;
      }
LABEL_22:
      result = 4;
      goto LABEL_23;
    }
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      "wlan_crypto_vdev_get_comp_params",
      v70,
      v71);
    v26 = "%s: crypto_priv NULL";
LABEL_21:
    qdf_trace_msg(0x1Cu, 2u, v26, v18, v19, v20, v21, v22, v23, v24, v25, "wlan_crypto_decap", v70);
    goto LABEL_22;
  }
  peer_by_mac_n_vdev = wlan_objmgr_get_peer_by_mac_n_vdev(v9, v32, &v70, a3, 19);
  if ( !peer_by_mac_n_vdev )
  {
    v26 = "%s: peer NULL";
    goto LABEL_21;
  }
  v46 = peer_by_mac_n_vdev;
  v47 = wlan_objmgr_peer_get_comp_private_obj(peer_by_mac_n_vdev, 14);
  if ( !v47 )
  {
    v57 = "%s: crypto_priv NULL";
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "wlan_crypto_peer_get_comp_params",
      v70,
      v71);
    goto LABEL_73;
  }
  v56 = *(_QWORD *)(v47 + 8 * v31 + 288);
  if ( !v56 )
  {
    v57 = "%s: Key is NULL";
LABEL_73:
    qdf_trace_msg(0x1Cu, 2u, v57, v48, v49, v50, v51, v52, v53, v54, v55, "wlan_crypto_decap", v70);
    LODWORD(result) = 4;
LABEL_74:
    v69 = result;
    wlan_objmgr_peer_release_ref(v46, 19);
    result = v69;
    goto LABEL_23;
  }
LABEL_60:
  if ( *(_BYTE *)(v56 + 1) == 1 && (v67 = *(_QWORD *)(v56 + 32)) != 0 )
  {
    v68 = *(__int64 (__fastcall **)(__int64, __int64))(v67 + 40);
    if ( *((_DWORD *)v68 - 1) != -1933021563 )
      __break(0x8228u);
    result = v68(v56, a2);
  }
  else
  {
    result = 4;
  }
  if ( v46 )
    goto LABEL_74;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
