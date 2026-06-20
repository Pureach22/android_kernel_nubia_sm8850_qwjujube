__int64 __fastcall wlan_vdev_get_active_channel(__int64 a1)
{
  int is_active; // w0
  __int64 v4; // x8

  if ( (unsigned int)wlan_vdev_chan_config_valid(a1) )
    return 0;
  is_active = wlan_vdev_mlme_is_active(a1);
  v4 = 40;
  if ( !is_active )
    v4 = 32;
  return *(_QWORD *)(a1 + v4);
}
