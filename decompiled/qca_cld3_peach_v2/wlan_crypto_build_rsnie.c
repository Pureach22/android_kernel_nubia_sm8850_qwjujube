char *__fastcall wlan_crypto_build_rsnie(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x20
  __int64 v12; // x19
  __int64 pmksa; // x0

  if ( a3 )
  {
    v11 = a2;
    v12 = a1;
    pmksa = wlan_crypto_get_pmksa(a1, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    a2 = v11;
    a3 = pmksa;
    a1 = v12;
  }
  return wlan_crypto_build_rsnie_with_pmksa(a1, a2, a3);
}
