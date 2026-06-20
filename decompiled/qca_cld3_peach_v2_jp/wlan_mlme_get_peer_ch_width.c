__int64 __fastcall wlan_mlme_get_peer_ch_width(__int64 a1, unsigned __int8 *a2)
{
  _QWORD *peer_by_mac; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w20
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7
  int v25; // w8

  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, a2, 2u);
  if ( peer_by_mac )
  {
    v12 = *((_DWORD *)peer_by_mac + 18);
    wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 2u, v4, v5, v6, v7, v8, v9, v10, v11);
    if ( v12 - 7 > 0x17 )
      v21 = 0;
    else
      v21 = dword_9FDB70[v12 - 7];
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: phymode: %d, ch_width: %d ",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_mlme_get_ch_width_from_phymode",
      v12,
      v21);
  }
  else
  {
    if ( a2 )
    {
      v22 = *a2;
      v23 = a2[1];
      v24 = a2[2];
      v25 = a2[5];
    }
    else
    {
      v24 = 0;
      v22 = 0;
      v23 = 0;
      v25 = 0;
    }
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: failed to fetch phy_mode status: %d for mac: %02x:%02x:%02x:**:**:%02x",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_mlme_get_peer_ch_width",
      29,
      v22,
      v23,
      v24,
      v25);
    return 0;
  }
  return v21;
}
