__int64 __fastcall wlan_crypto_get_keyid(unsigned __int8 *a1, int a2)
{
  unsigned int v2; // w9
  unsigned int v3; // w8

  v2 = *a1;
  if ( (v2 & 0xC) != 0 || (v3 = 0, v2 >= 0x10) && (v2 >> 4) - 1 >= 3 )
  {
    if ( (a1[1] & 0x40) == 0 )
      return 0xFFFF;
    return a1[a2 + 3] >> 6;
  }
  return v3;
}
