__int64 __fastcall wlan_vdev_mlme_is_csa_restart(__int64 a1)
{
  if ( *(_DWORD *)(a1 + 24) == 14 && *(_DWORD *)(a1 + 20) == 4 )
    return 0;
  else
    return 16;
}
