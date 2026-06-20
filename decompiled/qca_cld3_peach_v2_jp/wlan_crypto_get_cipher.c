__int64 __fastcall wlan_crypto_get_cipher(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 key; // x0

  key = wlan_crypto_get_key(a1, a2, a4);
  if ( key )
    return *(unsigned int *)(key + 8);
  else
    return 19;
}
