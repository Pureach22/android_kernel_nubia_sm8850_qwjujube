__int64 __fastcall wlan_vdev_is_restart_progress(__int64 a1)
{
  if ( *(_DWORD *)(a1 + 24) == 8 && *(_DWORD *)(a1 + 20) == 1 )
    return 0;
  else
    return 16;
}
