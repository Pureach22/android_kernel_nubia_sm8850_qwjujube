__int64 __fastcall wlan_crypto_cipher_to_cdp_sec_type(unsigned int a1)
{
  if ( a1 > 0x10 )
    return 0;
  else
    return dword_9E6D00[a1];
}
