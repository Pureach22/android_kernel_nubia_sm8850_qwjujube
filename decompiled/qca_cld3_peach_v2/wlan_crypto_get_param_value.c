__int64 __fastcall wlan_crypto_get_param_value(int a1, __int64 a2)
{
  bool v3; // cc
  __int64 result; // x0

  v3 = a1 <= 3;
  result = 0xFFFFFFFFLL;
  if ( v3 )
  {
    if ( a1 > 1 )
    {
      if ( a1 == 2 )
      {
        return wlan_crypto_get_mcastcipher(a2);
      }
      else if ( a1 == 3 )
      {
        return wlan_crypto_get_mgmtciphers(a2);
      }
    }
    else if ( a1 )
    {
      if ( a1 == 1 )
        return wlan_crypto_get_ucastciphers(a2);
    }
    else
    {
      return wlan_crypto_get_authmode(a2);
    }
  }
  else if ( a1 > 6 )
  {
    if ( a1 == 7 )
    {
      return wlan_crypto_get_key_mgmt(a2);
    }
    else if ( a1 == 9 )
    {
      return wlan_crypto_get_random_pmkid(a2);
    }
  }
  else if ( a1 == 4 )
  {
    return wlan_crypto_get_cipher_cap(a2);
  }
  else if ( a1 == 5 )
  {
    return wlan_crypto_get_rsn_cap(a2);
  }
  return result;
}
