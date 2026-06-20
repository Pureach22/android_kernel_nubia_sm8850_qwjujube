__int64 __fastcall wlan_vdev_is_going_down(__int64 a1)
{
  int v1; // w10

  v1 = *(_DWORD *)(a1 + 20);
  if ( *(_DWORD *)(a1 + 24) == 11 && v1 == 4 || v1 == 5 )
    return 0;
  else
    return 16;
}
