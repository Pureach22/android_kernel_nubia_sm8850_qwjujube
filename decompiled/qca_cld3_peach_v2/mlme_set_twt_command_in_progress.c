__int64 __fastcall mlme_set_twt_command_in_progress(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3, int a4)
{
  _QWORD *peer_by_mac; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x19
  __int64 comp_private_obj; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w8
  __int64 v27; // x4
  __int64 v28; // x5
  __int64 v29; // x6
  __int64 v30; // x7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, a2, 2u);
  if ( peer_by_mac )
  {
    v16 = (__int64)peer_by_mac;
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0);
    if ( comp_private_obj )
    {
      v26 = *(unsigned __int8 *)(comp_private_obj + 41);
      if ( *(_BYTE *)(comp_private_obj + 41) )
      {
        if ( a3 == 0xFF || *(unsigned __int8 *)(comp_private_obj + 44) == a3 )
        {
          *(_DWORD *)(comp_private_obj + 48) = a4;
          if ( v26 != 1 && a3 == 0xFF )
          {
LABEL_17:
            __break(0x5512u);
            JUMPOUT(0x6604F64);
          }
        }
        else if ( v26 != 1 )
        {
          goto LABEL_17;
        }
      }
      wlan_objmgr_peer_release_ref(v16, 2u, v18, v19, v20, v21, v22, v23, v24, v25);
      return 0;
    }
    else
    {
      wlan_objmgr_peer_release_ref(v16, 2u, v18, v19, v20, v21, v22, v23, v24, v25);
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s:  peer mlme component object is NULL",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "mlme_set_twt_command_in_progress");
      return 16;
    }
  }
  else
  {
    if ( a2 )
    {
      v27 = *a2;
      v28 = a2[1];
      v29 = a2[2];
      v30 = a2[5];
    }
    else
    {
      v29 = 0;
      v27 = 0;
      v28 = 0;
      v30 = 0;
    }
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: Peer object not found %02x:%02x:%02x:**:**:%02x",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "mlme_set_twt_command_in_progress",
      v27,
      v28,
      v29,
      v30);
    return 16;
  }
}
