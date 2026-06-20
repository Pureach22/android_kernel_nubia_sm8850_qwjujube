__int64 __fastcall wlan_crypto_cipher_to_wmi_cipher(unsigned int a1)
{
  if ( a1 > 0x10 )
    return 0;
  else
    return byte_AD8B38[a1];
}
