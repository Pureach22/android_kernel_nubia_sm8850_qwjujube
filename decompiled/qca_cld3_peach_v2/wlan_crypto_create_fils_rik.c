__int64 __fastcall wlan_crypto_create_fils_rik(
        __int64 a1,
        unsigned __int8 a2,
        __int64 a3,
        _DWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v12; // w19
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19
  _BYTE v24[4]; // [xsp+4h] [xbp-3Ch] BYREF
  char s[48]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v26; // [xsp+38h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  strcpy(s, "Re-authentication Integrity Key@ietf.org");
  if ( a1 && a3 )
  {
    v12 = a2;
    v24[0] = 2;
    if ( a2 )
    {
      v24[2] = a2;
      v24[1] = 0;
      result = qdf_default_hmac_sha256_kdf(a1, a2, s, (__int64)v24, 3u, a3, a2);
      if ( (_DWORD)result )
      {
        v23 = result;
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: failed to create rik",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "wlan_crypto_create_fils_rik");
        result = v23;
      }
      else
      {
        *a4 = v12;
      }
    }
    else
    {
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: invalid r_rk length %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "wlan_crypto_create_fils_rik",
        0,
        a3);
      result = 16;
    }
  }
  else
  {
    qdf_trace_msg(0x1Cu, 2u, "%s: FILS rrk/rik NULL", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_crypto_create_fils_rik");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
