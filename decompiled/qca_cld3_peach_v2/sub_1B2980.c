__int64 sub_1B2980()
{
  __int64 v0; // x26

  if ( (v0 & 0x10000000000LL) != 0 )
    JUMPOUT(0x1B1E34);
  return wlan_crypto_is_key_valid();
}
