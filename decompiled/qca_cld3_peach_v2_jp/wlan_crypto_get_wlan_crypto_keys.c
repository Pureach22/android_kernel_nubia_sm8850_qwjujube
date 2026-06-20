__int64 __fastcall wlan_crypto_get_wlan_crypto_keys(__int64 a1)
{
  __int64 v1; // x20
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int16 v11; // w8
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x0
  const char *v26; // x2

  if ( !a1 || *(_DWORD *)(a1 + 16) > 1u )
    goto LABEL_12;
  v1 = a1;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_crypto_vdev_get_comp_params");
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
      "wlan_crypto_vdev_is_pmf_enabled");
    a1 = v1;
    goto LABEL_12;
  }
  v11 = *(_WORD *)(comp_private_obj + 152);
  a1 = v1;
  if ( (v11 & 0xC0) == 0 )
  {
LABEL_12:
    v25 = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
    if ( v25 )
      return v25 + 288;
    v26 = "%s: crypto_priv NULL";
    goto LABEL_16;
  }
  v12 = *(_QWORD *)(v1 + 152);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    v26 = "%s: psoc NULL";
LABEL_16:
    qdf_trace_msg(0x1Cu, 2u, v26, v3, v4, v5, v6, v7, v8, v9, v10, "wlan_crypto_get_wlan_crypto_keys");
    return 0;
  }
  v14 = wlan_objmgr_psoc_get_comp_private_obj(v13, 14);
  if ( !v14 )
  {
    v26 = "%s: crypto_psoc_obj NULL";
    goto LABEL_16;
  }
  v15 = crypto_hash_find_by_linkid_and_macaddr(v14, 255, (int)v1 + 86);
  if ( v15 )
    return v15 + 16;
  else
    return 0;
}
