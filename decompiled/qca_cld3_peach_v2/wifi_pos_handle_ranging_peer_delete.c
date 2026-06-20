__int64 __fastcall wifi_pos_handle_ranging_peer_delete(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned __int8 a4)
{
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x19
  __int64 vdev_priv_obj; // x0
  unsigned int *v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w23
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  const char *v39; // x2
  __int64 legacy_ops; // x0
  __int64 v41; // x23
  __int64 v42; // x25
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x19
  unsigned int v53; // w28
  unsigned int v54; // w24
  __int64 v55; // x4
  __int64 v56; // x5
  __int64 v57; // x6
  __int64 v58; // x7
  __int16 v59; // w28
  _DWORD *v60; // x8
  _QWORD *peer_by_mac; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x27
  __int64 v71; // x4
  __int64 v72; // x5
  __int64 v73; // x6
  __int64 v74; // x7
  __int64 v75; // x0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x20
  unsigned int *v85; // x8
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7

  v8 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 13);
  if ( !v8 )
  {
    v39 = "%s: Vdev object is null";
LABEL_28:
    qdf_trace_msg(0x25u, 2u, v39, v9, v10, v11, v12, v13, v14, v15, v16, "wifi_pos_handle_ranging_peer_delete");
    return 16;
  }
  v17 = v8;
  vdev_priv_obj = wifi_pos_get_vdev_priv_obj(v8);
  if ( !vdev_priv_obj )
  {
    wlan_objmgr_vdev_release_ref(v17, 0xDu, v19, v20, v21, v22, v23, v24, v25, v26, v27);
    v39 = "%s: Wifi pos vdev priv obj is null";
    goto LABEL_28;
  }
  v28 = *(unsigned __int8 *)(vdev_priv_obj + 12265);
  v29 = wlan_objmgr_vdev_release_ref(v17, 0xDu, dword_2FE9, v20, v21, v22, v23, v24, v25, v26, v27);
  if ( v28 == 1 )
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Vdev delete all peer in progress. Ignore individual peer delete",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wifi_pos_handle_ranging_peer_delete");
    return 0;
  }
  legacy_ops = wifi_pos_get_legacy_ops(v29);
  if ( !legacy_ops || (v41 = legacy_ops, !*(_QWORD *)(legacy_ops + 8)) )
  {
    v39 = "%s: legacy callback is not registered";
    goto LABEL_28;
  }
  v42 = a4;
  v43 = _qdf_mem_malloc(380LL * a4, "wifi_pos_handle_ranging_peer_delete", 550);
  if ( !v43 )
    return 2;
  v52 = v43;
  if ( !a4 )
  {
    v53 = 0;
    goto LABEL_37;
  }
  v53 = 0;
  v54 = 0;
  do
  {
    peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, a2, 0xDu);
    v70 = (__int64)peer_by_mac;
    if ( peer_by_mac && *((_DWORD *)peer_by_mac + 17) == 12 )
    {
      if ( a2 )
      {
        v55 = *a2;
        v56 = a2[1];
        v57 = a2[2];
        v58 = a2[5];
      }
      else
      {
        v57 = 0;
        v55 = 0;
        v56 = 0;
        v58 = 0;
      }
      v59 = *((_WORD *)a2 + 184);
      qdf_trace_msg(
        0x25u,
        8u,
        "%s: Delete PASN Peer: %02x:%02x:%02x:**:**:%02x",
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        "wifi_pos_handle_ranging_peer_delete",
        v55,
        v56,
        v57,
        v58);
      memcpy((void *)(v52 + 380LL * (unsigned __int8)v54), a2, 0x17Cu);
      v60 = *(_DWORD **)(v41 + 8);
      ++v54;
      if ( *(v60 - 1) != 933372279 )
        __break(0x8228u);
      v53 = ((__int64 (__fastcall *)(__int64, unsigned __int8 *, _QWORD, _QWORD))v60)(a1, a2, a3, v59 & 1);
LABEL_17:
      wlan_objmgr_peer_release_ref(v70, 0xDu, v44, v45, v46, v47, v48, v49, v50, v51);
      goto LABEL_18;
    }
    if ( a2 )
    {
      v71 = *a2;
      v72 = a2[1];
      v73 = a2[2];
      v74 = a2[5];
    }
    else
    {
      v73 = 0;
      v71 = 0;
      v72 = 0;
      v74 = 0;
    }
    qdf_trace_msg(
      0x25u,
      8u,
      "%s: PASN Peer: %02x:%02x:%02x:**:**:%02xdoesn't exist",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "wifi_pos_handle_ranging_peer_delete",
      v71,
      v72,
      v73,
      v74);
    if ( v70 )
      goto LABEL_17;
LABEL_18:
    --v42;
    a2 += 380;
  }
  while ( v42 );
  if ( !(_BYTE)v54 )
  {
LABEL_37:
    qdf_trace_msg(
      0x25u,
      8u,
      "%s: No Peers to delete ",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "wifi_pos_handle_ranging_peer_delete");
    goto LABEL_38;
  }
  v75 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 13);
  if ( !v75 )
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Vdev object is null",
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      "wifi_pos_handle_ranging_peer_delete");
    _qdf_mem_free(v52);
    return 16;
  }
  v84 = v75;
  v53 = wifi_pos_request_flush_pasn_keys(v75, v52, v54);
  if ( v53 )
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Failed to indicate peer deauth to userspace",
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      "wifi_pos_handle_ranging_peer_delete");
  wlan_objmgr_vdev_release_ref(v84, 0xDu, v85, v86, v87, v88, v89, v90, v91, v92, v93);
LABEL_38:
  _qdf_mem_free(v52);
  return v53;
}
