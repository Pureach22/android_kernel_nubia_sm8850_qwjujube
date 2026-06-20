__int64 wlan_crypto_aquire_lock()
{
  return qdf_mutex_acquire((__int64)&crypto_lock);
}
