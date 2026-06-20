// attributes: thunk
__int64 sub_1E8B40()
{
  __int64 v0; // x0

  v0 = mlme_set_chan_switch_in_progress();
  return wlan_cm_is_vdev_roam_started(v0);
}
