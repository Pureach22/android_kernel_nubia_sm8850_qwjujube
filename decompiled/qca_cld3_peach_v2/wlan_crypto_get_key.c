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
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  __int64 v26; // x24
  __int64 v27; // x0
  int v28; // w22
  int v29; // w23
  const char *v30; // x2
  const char *v31; // x3
  __int64 comp_private_obj; // x0
  __int16 v33; // w8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w8
  __int64 peer_by_mac; // x0
  int v44; // w20
  int v45; // w2
  unsigned int v46; // w8
  __int64 v47; // x0

  result = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( !result )
  {
    v30 = "%s: crypto_priv NULL";
    v31 = "wlan_crypto_get_key";
LABEL_11:
    qdf_trace_msg(0x1Cu, 2u, v30, v7, v8, v9, v10, v11, v12, v13, v14, v31);
    return 0;
  }
  v15 = a3;
  if ( a3 >= 8u )
  {
    qdf_trace_msg(0x1Cu, 2u, "%s: Invalid Key index %d", v7, v8, v9, v10, v11, v12, v13, v14, "wlan_crypto_get_key", a3);
    return 0;
  }
  if ( *(_DWORD *)(a1 + 16) > 1u )
    goto LABEL_20;
  v16 = result;
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1) & 1) == 0 )
  {
    result = v16;
    if ( a1 )
    {
      comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
      if ( comp_private_obj )
      {
        v33 = *(_WORD *)(comp_private_obj + 152);
        result = v16;
        if ( (v33 & 0xC0) != 0 )
          goto LABEL_5;
      }
      else
      {
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: crypto_priv NULL",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "wlan_crypto_vdev_get_comp_params");
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: crypto_priv NULL",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "wlan_crypto_vdev_is_pmf_enabled");
        result = v16;
      }
    }
LABEL_20:
    v42 = v15 - 4;
    if ( v15 < 4 )
      return *(_QWORD *)(result + 288 + 8LL * v15);
    if ( (v15 & 6) == 4 )
    {
      if ( v42 <= 1 )
        return *(_QWORD *)(result + 8LL * v42 + 320);
    }
    else if ( v15 - 6 <= 1 )
    {
      return *(_QWORD *)(result + 8LL * (v15 - 6) + 336);
    }
LABEL_44:
    __break(0x5512u);
    v47 = MEMORY[0xFFFFFFFFFA618B48](result);
    return wlan_crypto_get_secure_akm_available(v47);
  }
LABEL_5:
  qdf_trace_msg(
    0x1Cu,
    8u,
    "%s: crypto get key index %d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "wlan_crypto_get_ml_keys_from_index",
    v15);
  v25 = *(_QWORD *)(a1 + 216);
  if ( !v25 || (v26 = *(_QWORD *)(v25 + 80)) == 0 )
  {
    v30 = "%s: psoc NULL";
LABEL_18:
    v31 = "wlan_crypto_get_ml_keys_from_index";
    goto LABEL_11;
  }
  v27 = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(v25 + 80), 14);
  if ( !v27 )
  {
    v30 = "%s: crypto_psoc_obj NULL";
    goto LABEL_18;
  }
  v28 = v27;
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1) & 1) != 0 )
    v29 = *(unsigned __int8 *)(a1 + 93);
  else
    v29 = 255;
  if ( a2 )
  {
    peer_by_mac = wlan_objmgr_get_peer_by_mac(v26, a2, 19);
    if ( peer_by_mac )
    {
      if ( *(_DWORD *)(peer_by_mac + 68) == 6 )
      {
        v44 = peer_by_mac + 48;
        wlan_objmgr_peer_release_ref(peer_by_mac, 19);
        v45 = v44;
        goto LABEL_36;
      }
      wlan_objmgr_peer_release_ref(peer_by_mac, 19);
    }
  }
  v45 = a1 + 86;
LABEL_36:
  result = crypto_hash_find_by_linkid_and_macaddr(v28, v29, v45);
  if ( result )
  {
    v46 = v15 - 4;
    if ( v15 < 4 )
      return *(_QWORD *)(result + 8LL * v15 + 16);
    if ( (v15 & 6) == 4 )
    {
      if ( v46 <= 1 )
        return *(_QWORD *)(result + 8LL * v46 + 48);
    }
    else if ( v15 - 6 <= 1 )
    {
      return *(_QWORD *)(result + 8LL * (v15 - 6) + 64);
    }
    goto LABEL_44;
  }
  return result;
}
