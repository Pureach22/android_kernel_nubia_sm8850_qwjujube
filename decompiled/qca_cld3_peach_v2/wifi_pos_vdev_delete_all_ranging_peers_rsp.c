__int64 __fastcall wifi_pos_vdev_delete_all_ranging_peers_rsp(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 vdev_priv_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  unsigned int v23; // w20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x0
  unsigned int *v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  const char *v42; // x2
  unsigned int *v43; // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 legacy_ops; // x0
  unsigned int *v54; // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7

  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 13);
  if ( !v3 )
  {
    v42 = "%s:  VDEV is NULL";
LABEL_10:
    qdf_trace_msg(0x25u, 2u, v42, v4, v5, v6, v7, v8, v9, v10, v11, "wifi_pos_vdev_delete_all_ranging_peers_rsp");
    return 16;
  }
  v12 = v3;
  vdev_priv_obj = wifi_pos_get_vdev_priv_obj(v3);
  if ( !vdev_priv_obj )
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Wifi pos vdev priv obj is null",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wifi_pos_vdev_delete_all_ranging_peers_rsp");
    wlan_objmgr_vdev_release_ref(v12, 0xDu, v43, v44, v45, v46, v47, v48, v49, v50, v51);
    return 16;
  }
  v22 = vdev_priv_obj;
  qdf_trace_msg(
    0x25u,
    8u,
    "%s: Iterate and delete PASN peers",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "wifi_pos_cleanup_pasn_peers");
  v23 = wlan_objmgr_iterate_obj_list(a1, 3, wifi_pos_delete_objmgr_ranging_peer, v12, 0, 0xDu);
  if ( v23 )
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Delete objmgr peers failed",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wifi_pos_cleanup_pasn_peers");
  v32 = wifi_pos_get_vdev_priv_obj(v12);
  if ( v32 )
  {
    v33 = (_DWORD *)&unk_2FE8;
    *(_BYTE *)(v32 + 12264) = 0;
  }
  if ( v23 )
    goto LABEL_8;
  *(_WORD *)(v22 + 12264) = 0;
  legacy_ops = wifi_pos_get_legacy_ops(v32);
  if ( !legacy_ops || (v54 = *(unsigned int **)(legacy_ops + 16)) == nullptr )
  {
    wlan_objmgr_vdev_release_ref(v12, 0xDu, v54, v55, v56, v57, v58, v59, v60, v61, v62);
    v42 = "%s: legacy callbacks is not registered";
    goto LABEL_10;
  }
  if ( *(v54 - 1) != 1263140689 )
    __break(0x8228u);
  v23 = ((__int64 (__fastcall *)(__int64))v54)(v12);
  if ( v23 )
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Delete all PASN peer failed",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "wifi_pos_vdev_delete_all_ranging_peers_rsp");
LABEL_8:
  wlan_objmgr_vdev_release_ref(v12, 0xDu, v33, v34, v35, v36, v37, v38, v39, v40, v41);
  return v23;
}
