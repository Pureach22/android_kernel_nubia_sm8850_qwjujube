__int64 __fastcall wlan_crypto_set_random_pmkid(__int64 a1, char a2)
{
  *(_BYTE *)(a1 + 280) = a2;
  return 0;
}
