__int64 __fastcall wma_objmgr_get_peer_mlme_nss(__int64 a1, _BYTE *a2)
{
  _QWORD *peer; // x0
  __int64 v3; // x19
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w20

  peer = wlan_objmgr_get_peer(*(_QWORD *)(a1 + 24), *(_BYTE *)(*(_QWORD *)(a1 + 32) + 40LL), a2, 8u);
  if ( peer )
  {
    v3 = (__int64)peer;
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer, 0);
    if ( comp_private_obj )
      v13 = *(unsigned __int8 *)(comp_private_obj + 52);
    else
      v13 = 0;
    wlan_objmgr_peer_release_ref(v3, 8u, v5, v6, v7, v8, v9, v10, v11, v12);
  }
  else
  {
    return 0;
  }
  return v13;
}
