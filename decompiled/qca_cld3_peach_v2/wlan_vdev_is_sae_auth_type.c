bool __fastcall wlan_vdev_is_sae_auth_type(__int64 a1)
{
  int param; // w19
  int v3; // w8
  _BOOL8 result; // x0

  param = wlan_crypto_get_param(a1, 0);
  v3 = wlan_crypto_get_param(a1, 7u);
  result = 0;
  if ( param != -1 && v3 != -1 )
    return (param & 0x200 | v3 & 0x18000C00) != 0;
  return result;
}
