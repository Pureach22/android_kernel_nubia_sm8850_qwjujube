__int64 __fastcall wifi_pos_handle_ranging_peer_create_rsp(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        unsigned __int8 a4)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  __int64 vdev_priv_obj; // x0
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x20
  unsigned __int8 v27; // w9
  int v28; // w8
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x7
  const char *v33; // x2
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned __int8 v52; // w9
  __int64 v53; // x4
  unsigned int *v54; // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7

  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 13);
  if ( !v6 )
  {
    v33 = "%s: Vdev object is null";
LABEL_8:
    qdf_trace_msg(0x25u, 2u, v33, v7, v8, v9, v10, v11, v12, v13, v14, "wifi_pos_handle_ranging_peer_create_rsp");
    return 16;
  }
  v15 = v6;
  vdev_priv_obj = wifi_pos_get_vdev_priv_obj(v6);
  if ( !vdev_priv_obj )
  {
    wlan_objmgr_vdev_release_ref(v15, 0xDu, v17, v18, v19, v20, v21, v22, v23, v24, v25);
    v33 = "%s: Wifi pos vdev priv obj is null";
    goto LABEL_8;
  }
  v26 = vdev_priv_obj;
  if ( !*(_BYTE *)(vdev_priv_obj + 12262) )
  {
    v28 = 0;
    if ( a3 )
      goto LABEL_5;
LABEL_10:
    v31 = 0;
    v29 = 0;
    v30 = 0;
    v32 = 0;
    goto LABEL_11;
  }
  v27 = *(_BYTE *)(vdev_priv_obj + 12262) - 1;
  *(_BYTE *)(vdev_priv_obj + 12262) = v27;
  v28 = v27;
  if ( !a3 )
    goto LABEL_10;
LABEL_5:
  v29 = *a3;
  v30 = a3[1];
  v31 = a3[2];
  v32 = a3[5];
LABEL_11:
  qdf_trace_msg(
    0x25u,
    8u,
    "%s: Received peer create response for %02x:%02x:%02x:**:**:%02x status:%d pending_count:%d",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "wifi_pos_handle_ranging_peer_create_rsp",
    v29,
    v30,
    v31,
    v32,
    a4,
    v28);
  if ( a4 )
  {
    wifi_pos_move_peers_to_fail_list(v15, a3, 2);
    v43 = wifi_pos_get_vdev_priv_obj(v15);
    if ( v43 )
    {
      if ( *(_BYTE *)(v43 + 12264) )
      {
        v52 = *(_BYTE *)(v43 + 12264) - 1;
        *(_BYTE *)(v43 + 12264) = v52;
        v53 = v52;
      }
      else
      {
        v53 = 0;
      }
      qdf_trace_msg(
        0x25u,
        8u,
        "%s: Pasn peer count:%d",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "wifi_pos_update_pasn_peer_count",
        v53);
    }
    else
    {
      qdf_trace_msg(
        0x25u,
        2u,
        "%s: Wifi pos vdev priv obj is null",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "wifi_pos_update_pasn_peer_count");
    }
  }
  wifi_pos_check_and_initiate_pasn_authentication(v15, v26, v35, v36, v37, v38, v39, v40, v41, v42);
  wlan_objmgr_vdev_release_ref(v15, 0xDu, v54, v55, v56, v57, v58, v59, v60, v61, v62);
  return 0;
}
