__int64 __fastcall wlan_vdev_chan_config_valid(__int64 a1)
{
  int v1; // w9
  bool v2; // zf

  v1 = *(_DWORD *)(a1 + 20);
  if ( v1 )
    v2 = v1 == 5;
  else
    v2 = 1;
  if ( v2 )
    return 16;
  else
    return 0;
}
