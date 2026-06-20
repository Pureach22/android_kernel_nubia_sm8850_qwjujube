__int64 __fastcall wlan_crypto_get_key(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w19
  __int64 v16; // x22
  __int64 comp_private_obj; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int16 v26; // w8
  __int64 v27; // x8
  __int64 v28; // x23
  __int64 v29; // x0
  int v30; // w22
  __int64 peer_by_mac; // x0
  int v32; // w20
  int v33; // w2
  const char *v34; // x2
  const char *v35; // x3
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w8
  unsigned int v45; // w8
  __int64 v46; // x0

  result = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( !result )
  {
    v34 = "%s: crypto_priv NULL";
    v35 = "wlan_crypto_get_key";
LABEL_15:
    qdf_trace_msg(0x1Cu, 2u, v34, v7, v8, v9, v10, v11, v12, v13, v14, v35);
    return 0;
  }
  v15 = a3;
  if ( a3 >= 8u )
  {
    qdf_trace_msg(0x1Cu, 2u, "%s: Invalid Key index %d", v7, v8, v9, v10, v11, v12, v13, v14, "wlan_crypto_get_key", a3);
    return 0;
  }
  if ( !a1 || *(_DWORD *)(a1 + 16) > 1u )
  {
LABEL_18:
    v44 = v15 - 4;
    if ( v15 < 4 )
      return *(_QWORD *)(result + 288 + 8LL * v15);
    if ( (v15 & 6) == 4 )
    {
      if ( v44 <= 1 )
        return *(_QWORD *)(result + 8LL * v44 + 320);
    }
    else if ( v15 - 6 <= 1 )
    {
      return *(_QWORD *)(result + 8LL * (v15 - 6) + 336);
    }
LABEL_39:
    __break(0x5512u);
    v46 = MEMORY[0xFFFFFFFFFA603E88](result);
    return wlan_crypto_get_secure_akm_available(v46);
  }
  v16 = result;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_crypto_vdev_get_comp_params");
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
      "wlan_crypto_vdev_is_pmf_enabled");
    result = v16;
    goto LABEL_18;
  }
  v26 = *(_WORD *)(comp_private_obj + 152);
  result = v16;
  if ( (v26 & 0xC0) == 0 )
    goto LABEL_18;
  qdf_trace_msg(
    0x1Cu,
    8u,
    "%s: crypto get key index %d",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "wlan_crypto_get_ml_keys_from_index",
    v15);
  v27 = *(_QWORD *)(a1 + 152);
  if ( !v27 || (v28 = *(_QWORD *)(v27 + 80)) == 0 )
  {
    v34 = "%s: psoc NULL";
LABEL_27:
    v35 = "wlan_crypto_get_ml_keys_from_index";
    goto LABEL_15;
  }
  v29 = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(v27 + 80), 14);
  if ( !v29 )
  {
    v34 = "%s: crypto_psoc_obj NULL";
    goto LABEL_27;
  }
  v30 = v29;
  if ( a2 )
  {
    peer_by_mac = wlan_objmgr_get_peer_by_mac(v28, a2, 19);
    if ( peer_by_mac )
    {
      if ( *(_DWORD *)(peer_by_mac + 68) == 6 )
      {
        v32 = peer_by_mac + 48;
        wlan_objmgr_peer_release_ref(peer_by_mac, 19);
        v33 = v32;
        goto LABEL_31;
      }
      wlan_objmgr_peer_release_ref(peer_by_mac, 19);
    }
  }
  v33 = a1 + 86;
LABEL_31:
  result = crypto_hash_find_by_linkid_and_macaddr(v30, 255, v33);
  if ( result )
  {
    v45 = v15 - 4;
    if ( v15 < 4 )
      return *(_QWORD *)(result + 8LL * v15 + 16);
    if ( (v15 & 6) == 4 )
    {
      if ( v45 <= 1 )
        return *(_QWORD *)(result + 8LL * v45 + 48);
    }
    else if ( v15 - 6 <= 1 )
    {
      return *(_QWORD *)(result + 8LL * (v15 - 6) + 64);
    }
    goto LABEL_39;
  }
  return result;
}
