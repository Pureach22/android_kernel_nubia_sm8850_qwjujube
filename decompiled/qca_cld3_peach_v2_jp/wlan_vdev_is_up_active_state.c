__int64 __fastcall wlan_vdev_is_up_active_state(__int64 a1)
{
  if ( *(_DWORD *)(a1 + 24) == 19 && *(_DWORD *)(a1 + 20) == 3 )
    return 0;
  else
    return 16;
}
