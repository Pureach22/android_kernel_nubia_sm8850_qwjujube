__int64 __fastcall nl80211_send_auth_timeout(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  return nl80211_send_mlme_timeout(a1, a2, 37, a3, a4);
}
