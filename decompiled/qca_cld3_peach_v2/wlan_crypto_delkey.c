__int64 __fastcall wlan_crypto_delkey(
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
  __int64 v16; // x23
  __int64 v17; // x8
  __int64 peer_by_mac_n_vdev; // x0
  __int64 v20; // x19
  __int64 comp_private_obj; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 result; // x0
  __int64 v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  const char *v49; // x2
  unsigned __int8 v50; // w8
  __int64 v51; // x9
  __int64 v52; // x8
  __int64 v53; // x22
  __int64 v54; // x24
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x8
  __int64 v64; // x0
  __int64 v65; // x9
  unsigned int v66; // w20
  _DWORD *v67; // x8
  __int64 v72; // [xsp+0h] [xbp-10h] BYREF
  __int64 v73; // [xsp+8h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v72) = 0;
  LODWORD(v72) = 0;
  if ( !a1 || !a2 || a3 >= 8u )
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
      "wlan_crypto_delkey",
      a1,
      a2,
      a3,
      v72,
      v73);
    result = 4;
    goto LABEL_49;
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
  qdf_mem_copy(&v72, (char *)a1 + 74, 6u);
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
    v49 = "%s: psoc NULL";
    goto LABEL_23;
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
      v20 = 0;
      goto LABEL_26;
    }
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wlan_crypto_vdev_get_comp_params",
      v72,
      v73);
    v49 = "%s: crypto_priv NULL";
LABEL_23:
    qdf_trace_msg(0x1Cu, 2u, v49, v41, v42, v43, v44, v45, v46, v47, v48, "wlan_crypto_delkey", v72);
    result = 4;
    goto LABEL_49;
  }
  peer_by_mac_n_vdev = wlan_objmgr_get_peer_by_mac_n_vdev(v16, *(unsigned __int8 *)(a1[27] + 40LL), &v72, a2, 19);
  if ( !peer_by_mac_n_vdev )
  {
    result = 4;
    goto LABEL_49;
  }
  v20 = peer_by_mac_n_vdev;
  comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(peer_by_mac_n_vdev, 14);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wlan_crypto_peer_get_comp_params",
      v72,
      v73);
    qdf_trace_msg(0x1Cu, 2u, "%s: crypto_priv NULL", v31, v32, v33, v34, v35, v36, v37, v38, "wlan_crypto_delkey");
    LODWORD(result) = 4;
LABEL_48:
    v66 = result;
    wlan_objmgr_peer_release_ref(v20, 19);
    result = v66;
    goto LABEL_49;
  }
LABEL_26:
  if ( a3 < 4u )
  {
    v52 = comp_private_obj + 8LL * a3;
    v53 = *(_QWORD *)(v52 + 288);
    *(_QWORD *)(v52 + 288) = 0;
    if ( v53 )
    {
      if ( (*(_BYTE *)(v53 + 1) & 1) == 0 )
      {
LABEL_43:
        qdf_mem_set((void *)v53, 0x1B0u, 0);
        _qdf_mem_free(v53);
        result = 0;
        goto LABEL_47;
      }
      v54 = *(_QWORD *)(v53 + 32);
      qdf_mem_set((void *)(v53 + 384), 0x30u, 0);
      v63 = *(_QWORD *)(v16 + 2128);
      if ( v63 )
      {
        if ( *(_DWORD *)(v54 + 8) == 14 )
        {
          v64 = *(_QWORD *)(v53 + 40);
          if ( v64 )
            _qdf_mem_free(v64);
        }
        else
        {
          v67 = *(_DWORD **)(v63 + 720);
          if ( v67 )
          {
            if ( *(v67 - 1) != -871156935 )
              __break(0x8228u);
            ((void (__fastcall *)(_QWORD *, __int64, __int64))v67)(a1, v53, a2);
          }
        }
        goto LABEL_43;
      }
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: tx_ops is NULL",
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "wlan_crypto_delkey",
        v72,
        v73);
    }
LABEL_46:
    result = 4;
LABEL_47:
    if ( v20 )
      goto LABEL_48;
LABEL_49:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( (a3 & 6) == 6 )
  {
    v50 = a3 - 6;
    if ( (unsigned __int8)(a3 - 6) <= 1u )
    {
      v51 = 336;
LABEL_41:
      v65 = comp_private_obj + v51;
      v53 = *(_QWORD *)(v65 + 8LL * v50);
      *(_QWORD *)(v65 + 8LL * v50) = 0;
      if ( v53 )
      {
        *(_BYTE *)(v53 + 1) = 0;
        goto LABEL_43;
      }
      goto LABEL_46;
    }
  }
  else
  {
    if ( (a3 & 6) != 4 )
    {
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: igtk/bigtk key invalid keyid %d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "wlan_crypto_delkey",
        v72,
        v73);
      goto LABEL_46;
    }
    v50 = a3 - 4;
    if ( (unsigned __int8)(a3 - 4) < 2u )
    {
      v51 = 320;
      goto LABEL_41;
    }
  }
  __break(0x5512u);
  __asm { STGP            X5, X22, [X10,#0x88]! }
  return wlan_crypto_encap();
}
