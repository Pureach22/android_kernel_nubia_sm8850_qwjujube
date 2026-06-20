__int64 __fastcall wlan_crypto_get_wlan_crypto_keys(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 comp_private_obj; // x0
  const char *v16; // x2
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x0

  if ( *(_DWORD *)(a1 + 16) > 1u )
    goto LABEL_15;
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1) & 1) == 0 )
  {
    if ( a1 )
    {
      comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
      if ( comp_private_obj )
      {
        if ( (*(_WORD *)(comp_private_obj + 152) & 0xC0) != 0 )
          goto LABEL_3;
      }
      else
      {
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: crypto_priv NULL",
          v2,
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
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
      }
    }
LABEL_15:
    v25 = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
    if ( v25 )
      return v25 + 288;
    v16 = "%s: crypto_priv NULL";
    goto LABEL_18;
  }
LABEL_3:
  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v16 = "%s: psoc NULL";
LABEL_18:
    qdf_trace_msg(0x1Cu, 2u, v16, v2, v3, v4, v5, v6, v7, v8, v9, "wlan_crypto_get_wlan_crypto_keys");
    return 0;
  }
  v12 = wlan_objmgr_psoc_get_comp_private_obj(v11, 14);
  if ( !v12 )
  {
    v16 = "%s: crypto_psoc_obj NULL";
    goto LABEL_18;
  }
  v13 = crypto_hash_find_by_linkid_and_macaddr(v12, *(unsigned __int8 *)(a1 + 93), (int)a1 + 86);
  if ( v13 )
    return v13 + 16;
  else
    return 0;
}
