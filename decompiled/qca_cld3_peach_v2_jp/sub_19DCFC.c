__int64 sub_19DCFC()
{
  __int64 v0; // x26

  if ( (v0 & 0x10000000000LL) != 0 )
    JUMPOUT(0x19D1B0);
  return wlan_crypto_is_key_valid();
}
