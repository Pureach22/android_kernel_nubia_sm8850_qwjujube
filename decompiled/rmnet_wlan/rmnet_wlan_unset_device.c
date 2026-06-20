__int64 rmnet_wlan_unset_device()
{
  __int64 result; // x0

  if ( !rmnet_wlan_device )
    return 0;
  result = unregister_netdevice_notifier(&rmnet_wlan_notifier);
  if ( !(_DWORD)result )
    rmnet_wlan_device = 0;
  return result;
}
