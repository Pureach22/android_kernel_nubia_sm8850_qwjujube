__int64 wlan_crypto_release_lock()
{
  return qdf_mutex_release((__int64)&crypto_lock);
}
