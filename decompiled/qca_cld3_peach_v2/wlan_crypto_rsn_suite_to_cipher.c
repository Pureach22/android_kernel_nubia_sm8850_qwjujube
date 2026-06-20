__int64 __fastcall wlan_crypto_rsn_suite_to_cipher(_DWORD *a1)
{
  unsigned int v1; // w8
  unsigned __int64 v2; // t2

  HIDWORD(v2) = *a1 - 11276032;
  LODWORD(v2) = HIDWORD(v2);
  v1 = v2 >> 24;
  if ( v1 > 0xD )
    return 0xFFFFFFFFLL;
  else
    return dword_AD0860[v1];
}
