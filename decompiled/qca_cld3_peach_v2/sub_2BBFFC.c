// attributes: thunk
__int64 sub_2BBFFC()
{
  __int64 v0; // x0

  v0 = hdd_softap_tx_timeout();
  return wlan_vdev_is_sae_auth_type(v0);
}
