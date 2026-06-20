__int64 rmnet_wlan_connection_flush()
{
  cancel_delayed_work_sync(&rmnet_wlan_connection_work);
  byte_CC38 = 1;
  queue_delayed_work_on(32, system_wq, &rmnet_wlan_connection_work, 0);
  return cancel_delayed_work_sync(&rmnet_wlan_connection_work);
}
