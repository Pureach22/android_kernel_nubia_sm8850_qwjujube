// attributes: thunk
__int64 sub_1B2838()
{
  __int64 is_sta_active_connection_exists; // x0

  is_sta_active_connection_exists = policy_mgr_is_sta_active_connection_exists();
  return wlan_crypto_vdev_is_pmf_required(is_sta_active_connection_exists);
}
