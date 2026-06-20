__int64 __fastcall wlan_find_peer_and_get_mac_and_mld_addr(__int64 a1, unsigned __int8 *a2)
{
  _QWORD *peer_by_mac; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  int v13; // w9
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x4
  __int64 v24; // x5
  __int64 v25; // x6
  __int64 v26; // x7

  _ReadStatusReg(SP_EL0);
  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, a2, 7u);
  if ( peer_by_mac )
  {
    v13 = *((_DWORD *)peer_by_mac + 12);
    *((_WORD *)a2 + 5) = *((_WORD *)peer_by_mac + 26);
    *(_DWORD *)(a2 + 6) = v13;
    wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 7u, v5, v6, v7, v8, v9, v10, v11, v12);
    result = 0;
  }
  else
  {
    wlan_objmgr_iterate_obj_list(a1, 3, wlan_peer_find_mld_peer_n_get_mac_info, (__int64)a2, 0, 7u);
    result = 0;
    if ( !(*(_DWORD *)(a2 + 6) | *((unsigned __int16 *)a2 + 5)) )
    {
      if ( a2 )
      {
        v23 = *a2;
        v24 = a2[1];
        v25 = a2[2];
        v26 = a2[5];
      }
      else
      {
        v25 = 0;
        v23 = 0;
        v24 = 0;
        v26 = 0;
      }
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: peer is null for mac:%02x:%02x:%02x:**:**:%02x",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "wlan_find_peer_and_get_mac_and_mld_addr",
        v23,
        v24,
        v25,
        v26);
      result = 14;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
