__int64 __fastcall sub_19AF4C(
        double a1,
        double a2,
        double a3,
        float a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  int v8; // s31

  *(float *)(a8 + 80) = a4;
  *(_DWORD *)(a8 + 84) = v8;
  return wlan_crypto_get_peer_pmksa();
}
