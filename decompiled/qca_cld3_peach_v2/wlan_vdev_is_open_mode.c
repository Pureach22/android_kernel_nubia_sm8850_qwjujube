bool __fastcall wlan_vdev_is_open_mode(__int64 a1)
{
  return (wlan_crypto_get_param(a1, 1u) & 0xFFFDFFFF) == 0;
}
