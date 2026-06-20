__int64 __fastcall sub_6BA188(int a1)
{
  int v1; // w9
  __int64 v2; // x25

  *(_DWORD *)(v2 + 84) = v1;
  *(_DWORD *)(v2 + 88) = a1;
  return wlan_mlo_peer_get_primary_peer_link_id_by_ml_peer();
}
