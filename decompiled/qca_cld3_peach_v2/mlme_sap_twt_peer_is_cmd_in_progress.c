__int64 __fastcall mlme_sap_twt_peer_is_cmd_in_progress(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3, int a4)
{
  __int64 v4; // x27
  char v5; // b12
  _QWORD *peer_by_mac; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x19
  __int64 comp_private_obj; // x0
  __int64 v20; // x1
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w8
  int v30; // w10
  _BOOL4 v31; // w20
  __int64 v32; // x4
  __int64 v33; // x5
  __int64 v34; // x6
  __int64 v35; // x7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  bool v45; // zf

  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, a2, 2u);
  if ( !peer_by_mac )
  {
    if ( a2 )
    {
      v32 = *a2;
      v33 = a2[1];
      v34 = a2[2];
      v35 = a2[5];
    }
    else
    {
      v34 = 0;
      v32 = 0;
      v33 = 0;
      v35 = 0;
    }
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: Peer object not found %02x:%02x:%02x:**:**:%02x",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "mlme_sap_twt_peer_is_cmd_in_progress",
      v32,
      v33,
      v34,
      v35);
    return 0;
  }
  v18 = (__int64)peer_by_mac;
  comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0);
  if ( !comp_private_obj )
  {
    wlan_objmgr_peer_release_ref(v18, 2u, v21, v22, v23, v24, v25, v26, v27, v28);
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s:  peer mlme component object is NULL",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "mlme_sap_twt_peer_is_cmd_in_progress");
    return 0;
  }
  v29 = *(unsigned __int8 *)(comp_private_obj + 41);
  if ( !*(_BYTE *)(comp_private_obj + 41) )
  {
LABEL_8:
    v31 = 0;
LABEL_9:
    wlan_objmgr_peer_release_ref(v18, 2u, v21, v22, v23, v24, v25, v26, v27, v28);
    return v31;
  }
  if ( a3 == 0xFF || (v30 = *(unsigned __int8 *)(comp_private_obj + 44), v30 == a3) || v30 == 255 )
  {
    v45 = *(_DWORD *)(comp_private_obj + 48) == a4;
    v31 = v45;
    if ( a3 != 0xFF || v45 || v29 == 1 )
      goto LABEL_9;
  }
  else if ( v29 == 1 )
  {
    goto LABEL_8;
  }
  __break(0x5512u);
  *(_BYTE *)(v4 + 3176) = v5;
  return mlme_is_twt_notify_in_progress(comp_private_obj, v20);
}
