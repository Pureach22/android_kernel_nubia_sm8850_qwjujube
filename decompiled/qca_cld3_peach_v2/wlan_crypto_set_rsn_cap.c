__int64 __fastcall wlan_crypto_set_rsn_cap(__int64 a1, __int16 a2)
{
  *(_WORD *)(a1 + 152) = a2;
  return 0;
}
