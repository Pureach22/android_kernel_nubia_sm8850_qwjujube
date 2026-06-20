__int64 __fastcall dp_softap_check_wait_for_tx_eap_pkt(__int64 result, unsigned __int8 *a2)
{
  __int64 v2; // x29
  __int64 v3; // x30
  __int64 v4; // x21
  _QWORD *peer_by_mac; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  __int64 comp_private_obj; // x20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x4
  __int64 v26; // x5
  __int64 v27; // x6
  __int64 v28; // x7
  __int64 v29; // [xsp+0h] [xbp-30h]
  __int64 v30; // [xsp+8h] [xbp-28h]

  if ( *(_DWORD *)(result + 28) == 3 )
  {
    v29 = v2;
    v30 = v3;
    v4 = result;
    peer_by_mac = wlan_objmgr_get_peer_by_mac(**(_QWORD **)result, a2, 0x61u);
    if ( peer_by_mac )
    {
      v15 = (__int64)peer_by_mac;
      comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0x2Eu);
      if ( !comp_private_obj )
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: peer is null",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "dp_get_peer_priv_obj",
          v2,
          v30);
      if ( (*(_QWORD *)(comp_private_obj + 8) & 1) != 0 )
      {
        if ( a2 )
        {
          v25 = *a2;
          v26 = a2[1];
          v27 = a2[2];
          v28 = a2[5];
        }
        else
        {
          v27 = 0;
          v25 = 0;
          v26 = 0;
          v28 = 0;
        }
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: eap_failure frm pending%02x:%02x:%02x:**:**:%02x",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "dp_softap_check_wait_for_tx_eap_pkt",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30);
        if ( (unsigned int)qdf_wait_for_event_completion(v4 + 3616, 0x50u) )
          qdf_trace_msg(
            0x45u,
            8u,
            "%s: eap_failure tx timeout",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "dp_softap_check_wait_for_tx_eap_pkt");
      }
      return wlan_objmgr_peer_release_ref(v15, 0x61u, v17, v18, v19, v20, v21, v22, v23, v24);
    }
    else
    {
      return qdf_trace_msg(
               0x45u,
               2u,
               "%s: Peer object not found",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "dp_softap_check_wait_for_tx_eap_pkt",
               v2,
               v30);
    }
  }
  return result;
}
