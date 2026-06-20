__int64 __fastcall nl80211_leave_mesh(__int64 a1, __int64 a2)
{
  return cfg80211_leave_mesh(*(__int64 **)(a2 + 48), *(_QWORD *)(a2 + 56));
}
