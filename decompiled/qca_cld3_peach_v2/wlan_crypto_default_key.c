__int64 __fastcall wlan_crypto_default_key(
        _QWORD *a1,
        __int64 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x8
  __int64 v16; // x22
  __int64 v17; // x8
  __int64 peer_by_mac_n_vdev; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x21
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x20
  __int64 v39; // x8
  __int64 v40; // x8
  const char *v41; // x2
  __int64 result; // x0
  __int64 comp_private_obj; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // [xsp+0h] [xbp-10h] BYREF
  __int64 v53; // [xsp+8h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v52) = 0;
  LODWORD(v52) = 0;
  if ( !a1 || !a2 || a3 >= 4u )
  {
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: Invalid param vdev %pK macaddr %pK keyidx %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_crypto_default_key",
      a1,
      a2,
      a3,
      v52,
      v53);
    goto LABEL_25;
  }
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
  qdf_mem_copy(&v52, (char *)a1 + 74, 6u);
  v15 = a1[27];
  if ( !v15 || (v16 = *(_QWORD *)(v15 + 80)) == 0 )
  {
    v40 = a1[169];
    if ( (v40 & 1) != 0 )
    {
      a1[169] = v40 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 168);
    }
    else
    {
      raw_spin_unlock(a1 + 168);
    }
    v41 = "%s: psoc NULL";
    goto LABEL_24;
  }
  v17 = a1[169];
  if ( (v17 & 1) != 0 )
  {
    a1[169] = v17 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 168);
  }
  else
  {
    raw_spin_unlock(a1 + 168);
  }
  if ( *(_DWORD *)a2 == -1 && *(__int16 *)(a2 + 4) == -1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
    if ( comp_private_obj )
    {
      v38 = comp_private_obj;
      v39 = *(_QWORD *)(comp_private_obj + 8LL * a3 + 288);
      if ( !v39 )
        goto LABEL_25;
      goto LABEL_29;
    }
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "wlan_crypto_vdev_get_comp_params",
      v52,
      v53);
    goto LABEL_34;
  }
  peer_by_mac_n_vdev = wlan_objmgr_get_peer_by_mac_n_vdev(v16, *(unsigned __int8 *)(a1[27] + 40LL), &v52, a2, 19);
  if ( !peer_by_mac_n_vdev )
  {
    v41 = "%s: peer NULL";
LABEL_24:
    qdf_trace_msg(0x1Cu, 2u, v41, v20, v21, v22, v23, v24, v25, v26, v27, "wlan_crypto_default_key", v52);
    goto LABEL_25;
  }
  v28 = peer_by_mac_n_vdev;
  v29 = wlan_objmgr_peer_get_comp_private_obj(peer_by_mac_n_vdev, 14);
  if ( !v29 )
  {
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wlan_crypto_peer_get_comp_params",
      v52,
      v53);
    wlan_objmgr_peer_release_ref(v28, 19);
LABEL_34:
    v41 = "%s: crypto_priv NULL";
    goto LABEL_24;
  }
  v38 = v29;
  wlan_objmgr_peer_release_ref(v28, 19);
  v39 = *(_QWORD *)(v38 + 8LL * a3 + 288);
  if ( !v39 )
    goto LABEL_25;
LABEL_29:
  if ( *(_BYTE *)(v39 + 1) == 1 )
  {
    result = 0;
    *(_BYTE *)(v38 + 420) = a3;
    goto LABEL_26;
  }
LABEL_25:
  result = 4;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
