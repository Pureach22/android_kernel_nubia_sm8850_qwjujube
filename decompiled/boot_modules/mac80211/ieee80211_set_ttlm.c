__int64 __fastcall ieee80211_set_ttlm(__int64 a1, __int64 a2, __int64 a3)
{
  return ieee80211_req_neg_ttlm(a2 + 2688, a3);
}
