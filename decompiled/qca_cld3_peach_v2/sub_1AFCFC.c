__int64 __fastcall sub_1AFCFC(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        unsigned __int64 *a8)
{
  unsigned __int64 v8; // x16

  atomic_store(v8, a8);
  return wlan_crypto_get_fils_pmksa();
}
