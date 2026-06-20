__int64 __fastcall wlan_crypto_set_param(
        __int64 a1,
        int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0

  qdf_trace_msg(
    0x1Cu,
    8u,
    "%s: param %d, value %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_crypto_set_param",
    (unsigned int)a2,
    a3);
  result = 4;
  if ( a2 <= 3 )
  {
    if ( a2 > 1 )
    {
      if ( a2 == 2 )
        return wlan_crypto_set_mcastcipher(a1, a3);
      else
        return wlan_crypto_set_mgmtcipher(a1, a3);
    }
    else if ( a2 )
    {
      if ( a2 == 1 )
        return wlan_crypto_set_ucastciphers(a1, a3);
    }
    else
    {
      return wlan_crypto_set_authmode(a1, a3);
    }
  }
  else if ( a2 <= 5 )
  {
    if ( a2 == 4 )
      return wlan_crypto_set_cipher_cap(a1, a3);
    else
      return wlan_crypto_set_rsn_cap(a1, a3);
  }
  else
  {
    switch ( a2 )
    {
      case 6:
        return wlan_crypto_set_rsnx_cap(a1, a3);
      case 7:
        return wlan_crypto_set_key_mgmt(a1, a3);
      case 9:
        return wlan_crypto_set_random_pmkid(a1, a3);
    }
  }
  return result;
}
