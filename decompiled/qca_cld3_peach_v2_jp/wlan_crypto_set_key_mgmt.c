__int64 __fastcall wlan_crypto_set_key_mgmt(__int64 a1, int a2)
{
  *(_DWORD *)(a1 + 20) = a2;
  return 0;
}
