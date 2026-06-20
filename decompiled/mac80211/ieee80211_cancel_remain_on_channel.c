__int64 __fastcall ieee80211_cancel_remain_on_channel(__int64 a1, __int64 a2, __int64 a3)
{
  return ieee80211_cancel_roc(*(_QWORD *)(a2 + 1600), a3, 0);
}
