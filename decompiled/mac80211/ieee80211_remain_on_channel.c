__int64 __fastcall ieee80211_remain_on_channel(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  return ieee80211_start_roc_work(*(_QWORD *)(a2 + 1600), a2 - 16, a3, a4, a5, 0, 0);
}
