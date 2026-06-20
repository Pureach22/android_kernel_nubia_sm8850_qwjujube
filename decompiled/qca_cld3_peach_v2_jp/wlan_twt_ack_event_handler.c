__int64 __fastcall wlan_twt_ack_event_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  int v13; // w23
  _QWORD *peer_by_mac; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  __int64 comp_private_obj; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x22
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7

  qdf_trace_msg(
    0x96u,
    8u,
    "%s: TWT ack status: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_twt_ack_event_handler",
    *(unsigned int *)(a2 + 20));
  if ( !*(_DWORD *)(a2 + 20)
    || (result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))wlan_twt_set_command_in_progress)(
                   a1,
                   a2 + 4,
                   *(unsigned int *)(a2 + 12),
                   0),
        !(_DWORD)result) )
  {
    v13 = *(unsigned __int8 *)(a2 + 12);
    peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, (_BYTE *)(a2 + 4), 0x5Eu);
    if ( peer_by_mac )
    {
      v23 = (__int64)peer_by_mac;
      comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0x2Cu);
      if ( comp_private_obj )
      {
        v33 = comp_private_obj;
        qdf_mutex_acquire(comp_private_obj);
        if ( *(_BYTE *)(v33 + 65) && v13 != 255 && *(unsigned __int8 *)(v33 + 72) != v13 && *(_BYTE *)(v33 + 65) != 1 )
        {
          __break(0x5512u);
          JUMPOUT(0x650F84);
        }
        qdf_mutex_release(v33);
        wlan_objmgr_peer_release_ref(v23, 0x5Eu, v42, v43, v44, v45, v46, v47, v48, v49);
        return mlme_twt_osif_ack_complete_ind();
      }
      else
      {
        wlan_objmgr_peer_release_ref(v23, 0x5Eu, v25, v26, v27, v28, v29, v30, v31, v32);
        qdf_trace_msg(
          0x96u,
          2u,
          "%s: peer twt component object is NULL",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "wlan_twt_get_ack_context");
        return 16;
      }
    }
    else
    {
      qdf_trace_msg(
        0x96u,
        2u,
        "%s: Peer object not found %02x:%02x:%02x:**:**:%02x",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "wlan_twt_get_ack_context",
        *(unsigned __int8 *)(a2 + 4),
        *(unsigned __int8 *)(a2 + 5),
        *(unsigned __int8 *)(a2 + 6),
        *(unsigned __int8 *)(a2 + 9));
      return 16;
    }
  }
  return result;
}
