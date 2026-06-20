__int64 __fastcall mlme_get_peer_phymode(__int64 a1, _BYTE *a2, _DWORD *a3)
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

  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, a2, 2u);
  if ( !peer_by_mac )
    return 29;
  *a3 = *((_DWORD *)peer_by_mac + 18);
  wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 2u, v5, v6, v7, v8, v9, v10, v11, v12);
  return 0;
}
