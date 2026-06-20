__int64 wlan_hdd_tx_power_boost_dev_destroy()
{
  cdev_del(&tx_pb_cdev);
  return device_destroy(class, minor | (unsigned int)(major << 20));
}
