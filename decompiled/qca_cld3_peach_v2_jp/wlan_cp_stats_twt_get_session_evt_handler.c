__int64 __fastcall wlan_cp_stats_twt_get_session_evt_handler(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _QWORD *peer_by_mac; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  _DWORD *comp_private_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w20

  result = 4;
  if ( a1 && a2 )
  {
    peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, (_BYTE *)(a2 + 4), 0x26u);
    if ( !peer_by_mac )
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: peer is NULL",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "wlan_cp_stats_twt_get_session_evt_handler");
      return 4;
    }
    v14 = (__int64)peer_by_mac;
    comp_private_obj = (_DWORD *)wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0x1Bu);
    if ( comp_private_obj )
    {
      v24 = *(_DWORD *)(a2 + 12);
      if ( (unsigned int)(v24 - 2) >= 2 )
      {
        if ( v24 == 1 && (comp_private_obj[15] & 0xFFFFFFFD) != 1 )
          goto LABEL_13;
      }
      else if ( comp_private_obj[17] == *(_DWORD *)(a2 + 20) )
      {
LABEL_13:
        qdf_mem_copy(comp_private_obj + 12, (const void *)a2, 0x34u);
        v33 = 0;
        goto LABEL_14;
      }
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: Unable to save twt session params with dialog id %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wlan_cp_stats_twt_get_session_evt_handler",
        *(unsigned int *)(a2 + 20));
      v33 = 4;
    }
    else
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: peer_cp_stats_priv is null",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wlan_cp_stats_twt_get_session_evt_handler");
      v33 = 4;
    }
LABEL_14:
    wlan_objmgr_peer_release_ref(v14, 0x26u, v25, v26, v27, v28, v29, v30, v31, v32);
    return v33;
  }
  return result;
}
