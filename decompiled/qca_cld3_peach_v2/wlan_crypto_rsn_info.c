__int64 __fastcall wlan_crypto_rsn_info(__int64 a1, __int64 a2, int *a3)
{
  _DWORD *comp_private_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w8
  int v16; // w9
  const char *v17; // x2
  int v18; // w8
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  comp_private_obj = (_DWORD *)wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( comp_private_obj )
  {
    if ( (comp_private_obj[1] & *(_DWORD *)(a2 + 4)) == 0 )
    {
      v17 = "%s: Unicast cipher match failed";
      if ( a3 )
      {
        v18 = 42;
        goto LABEL_29;
      }
      goto LABEL_30;
    }
    if ( (comp_private_obj[2] & *(_DWORD *)(a2 + 8)) == 0 )
    {
      v17 = "%s: Multicast cipher match failed";
      if ( a3 )
      {
        v18 = 41;
        goto LABEL_29;
      }
      goto LABEL_30;
    }
    v15 = *(_DWORD *)(a2 + 20);
    v16 = comp_private_obj[5];
    if ( (v16 & v15) == 0 && v16 | v15 )
    {
      v17 = "%s: Key mgmt match failed";
      if ( a3 )
      {
        v18 = 43;
LABEL_29:
        *a3 = v18;
        goto LABEL_30;
      }
      goto LABEL_30;
    }
    if ( a1 )
    {
      v19 = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
      if ( v19 )
      {
        if ( (*(_WORD *)(v19 + 152) & 0x40) != 0 && (*(_WORD *)(a2 + 152) & 0x80) == 0 )
        {
          v17 = "%s: Peer is not PMF capable";
          if ( !a3 )
            goto LABEL_30;
          goto LABEL_28;
        }
      }
      else
      {
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: crypto_priv NULL",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "wlan_crypto_vdev_get_comp_params");
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: crypto_priv NULL",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "wlan_crypto_vdev_is_pmf_required");
      }
      v28 = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
      if ( v28 )
      {
        if ( (*(_WORD *)(v28 + 152) & 0xC0) != 0 )
          return 1;
      }
      else
      {
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: crypto_priv NULL",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "wlan_crypto_vdev_get_comp_params");
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: crypto_priv NULL",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "wlan_crypto_vdev_is_pmf_enabled");
      }
    }
    if ( (*(_WORD *)(a2 + 152) & 0x40) != 0 )
    {
      v17 = "%s: Peer needs PMF, but vdev is not capable";
      if ( !a3 )
        goto LABEL_30;
LABEL_28:
      v18 = 45;
      goto LABEL_29;
    }
    return 1;
  }
  qdf_trace_msg(
    0x1Cu,
    2u,
    "%s: crypto_priv NULL",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "wlan_crypto_vdev_get_comp_params");
  v17 = "%s: vdev crypto params is NULL";
  if ( a3 )
  {
    v18 = 1;
    goto LABEL_29;
  }
LABEL_30:
  qdf_trace_msg(0x1Cu, 8u, v17, v7, v8, v9, v10, v11, v12, v13, v14, "wlan_crypto_rsn_info");
  return 0;
}
