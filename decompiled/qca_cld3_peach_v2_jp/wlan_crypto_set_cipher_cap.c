__int64 __fastcall wlan_crypto_set_cipher_cap(__int64 a1, int a2)
{
  *(_DWORD *)(a1 + 16) = a2;
  return 0;
}
