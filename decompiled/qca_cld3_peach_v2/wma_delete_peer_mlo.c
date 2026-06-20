_QWORD *__fastcall wma_delete_peer_mlo(__int64 a1, _BYTE *a2)
{
  _QWORD *result; // x0
  __int64 v3; // x19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  result = wlan_objmgr_get_peer_by_mac(a1, a2, 8u);
  if ( result )
  {
    v3 = (__int64)result;
    v4 = wlan_mlo_link_peer_delete();
    return (_QWORD *)wlan_objmgr_peer_release_ref(v3, 8u, v4, v5, v6, v7, v8, v9, v10, v11);
  }
  return result;
}
