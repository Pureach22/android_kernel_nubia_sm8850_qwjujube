__int64 __fastcall wlan_cfg80211_set_default_key(__int64 a1, unsigned int a2, __int64 a3)
{
  return wlan_crypto_default_key(a1, a3, a2, 1);
}
