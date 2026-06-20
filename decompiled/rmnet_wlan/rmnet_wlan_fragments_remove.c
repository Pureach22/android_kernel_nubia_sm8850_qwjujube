__int64 rmnet_wlan_fragments_remove()
{
  cancel_delayed_work_sync(&rmnet_wlan_fragment_work);
  byte_CCB0 = 1;
  queue_delayed_work_on(32, system_wq, &rmnet_wlan_fragment_work, 0);
  return cancel_delayed_work_sync(&rmnet_wlan_fragment_work);
}
