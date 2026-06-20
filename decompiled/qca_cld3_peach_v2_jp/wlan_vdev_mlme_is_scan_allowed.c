__int64 __fastcall wlan_vdev_mlme_is_scan_allowed(__int64 a1)
{
  int v1; // w8

  v1 = *(_DWORD *)(a1 + 20);
  if ( !v1 )
    return 0;
  if ( *(_DWORD *)(a1 + 24) == 19 && v1 == 3 || v1 == 5 )
    return 0;
  else
    return 16;
}
