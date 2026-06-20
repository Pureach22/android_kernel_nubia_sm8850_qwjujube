__int64 __fastcall wlan_crypto_validate_key_params(
        unsigned int a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        __int64 a13,
        __int64 a14)
{
  __int64 v14; // x4
  const char *v15; // x2

  v14 = a2;
  if ( a2 >= 8u )
  {
    v15 = "%s: Invalid Key index %d";
  }
  else
  {
    a14 = a1;
    if ( a1 == 19 )
    {
      v15 = "%s: Invalid Cipher %d";
      v14 = 19;
    }
    else
    {
      if ( a2 >= 4u && (a1 > 0xC || ((1 << a1) & 0x1940) == 0) )
      {
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: Invalid key index %d for cipher %d",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "wlan_crypto_validate_key_params");
        return 4;
      }
      a14 = a3;
      if ( a3 < 0x31u )
      {
        if ( a4 < 0x11u )
        {
          qdf_trace_msg(
            0x1Cu,
            8u,
            "%s: key: idx:%d, len:%d, seq len:%d",
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            "wlan_crypto_validate_key_params");
          return 0;
        }
        v15 = "%s: Invalid seq length %d";
        v14 = a4;
      }
      else
      {
        v15 = "%s: Invalid key length %d";
        v14 = (unsigned int)a14;
      }
    }
  }
  qdf_trace_msg(0x1Cu, 2u, v15, a5, a6, a7, a8, a9, a10, a11, a12, "wlan_crypto_validate_key_params", v14, a14);
  return 4;
}
