_QWORD *__fastcall wma_objmgr_set_peer_mlme_nss(__int64 a1, _BYTE *a2, char a3)
{
  _QWORD *result; // x0
  __int64 v5; // x20
  __int64 comp_private_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  result = wlan_objmgr_get_peer(*(_QWORD *)(a1 + 24), *(_BYTE *)(*(_QWORD *)(a1 + 32) + 40LL), a2, 8u);
  if ( result )
  {
    v5 = (__int64)result;
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)result, 0);
    if ( comp_private_obj )
      *(_BYTE *)(comp_private_obj + 52) = a3;
    return (_QWORD *)wlan_objmgr_peer_release_ref(v5, 8u, v7, v8, v9, v10, v11, v12, v13, v14);
  }
  return result;
}
