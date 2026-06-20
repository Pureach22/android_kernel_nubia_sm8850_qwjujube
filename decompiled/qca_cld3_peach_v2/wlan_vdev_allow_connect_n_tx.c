__int64 __fastcall wlan_vdev_allow_connect_n_tx(__int64 a1)
{
  int v1; // w9
  int v2; // w10
  _BOOL4 v4; // w11

  v1 = *(_DWORD *)(a1 + 20);
  v2 = *(_DWORD *)(a1 + 24);
  v4 = v1 == 3 && v2 == 19;
  if ( v1 == 4 && v2 == 14 || v4 )
    return 0;
  else
    return 16;
}
