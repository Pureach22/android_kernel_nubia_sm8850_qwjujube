bool ucfg_pmo_is_vdev_connected()
{
  return (unsigned int)wlan_vdev_is_up() == 0;
}
