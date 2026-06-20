__int64 __fastcall ieee80211_tx_h_encrypt(__int64 a1)
{
  __int64 v1; // x9
  int v2; // w9
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x1

  v1 = *(_QWORD *)(a1 + 56);
  if ( !v1 )
    return 0;
  v2 = *(_DWORD *)(v1 + 544);
  result = 1;
  if ( v2 <= 1027079 )
  {
    if ( v2 <= 1027075 )
    {
      if ( v2 != 1027073 )
      {
        if ( v2 == 1027074 )
          return ieee80211_crypto_tkip_encrypt(a1);
        return result;
      }
    }
    else
    {
      if ( v2 == 1027076 )
      {
        v5 = a1;
        v6 = 8;
        return ieee80211_crypto_ccmp_encrypt(v5, v6);
      }
      if ( v2 != 1027077 )
      {
        if ( v2 == 1027078 )
          return ieee80211_crypto_aes_cmac_encrypt(a1);
        return result;
      }
    }
    return ieee80211_crypto_wep_encrypt(a1);
  }
  if ( v2 <= 1027082 )
  {
    if ( (unsigned int)(v2 - 1027080) < 2 )
      return ieee80211_crypto_gcmp_encrypt(a1);
    v5 = a1;
    v6 = 16;
    return ieee80211_crypto_ccmp_encrypt(v5, v6);
  }
  if ( (unsigned int)(v2 - 1027083) < 2 )
    return ieee80211_crypto_aes_gmac_encrypt(a1);
  if ( v2 == 1027085 )
    return ieee80211_crypto_aes_cmac_256_encrypt(a1);
  return result;
}
