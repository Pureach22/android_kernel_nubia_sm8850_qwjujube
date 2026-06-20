__int64 __fastcall mlme_get_wep_key(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        unsigned int a11,
        void *a12,
        unsigned __int64 *a13)
{
  unsigned __int8 *key; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned __int64 v25; // x8
  const char *v26; // x2

  if ( a11 >= 4 )
  {
    qdf_trace_msg(0x1Fu, 2u, "%s: Incorrect wep key index %d", a2, a3, a4, a5, a6, a7, a8, a9, "mlme_get_wep_key", a11);
    return 4;
  }
  key = (unsigned __int8 *)wlan_crypto_get_key(a1, 0, a11);
  if ( !key )
  {
    v26 = "%s: Crypto KEY not present";
    goto LABEL_7;
  }
  v25 = *key;
  if ( v25 >= 0xE )
  {
    v26 = "%s: Key too large to hold";
LABEL_7:
    qdf_trace_msg(0x1Fu, 2u, v26, v17, v18, v19, v20, v21, v22, v23, v24, "mlme_get_wep_key");
    return 4;
  }
  *a13 = v25;
  qdf_mem_copy(a12, key + 384, *key);
  return 0;
}
