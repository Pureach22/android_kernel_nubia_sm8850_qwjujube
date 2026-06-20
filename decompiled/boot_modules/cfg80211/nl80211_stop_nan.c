__int64 __fastcall nl80211_stop_nan(__int64 a1, __int64 a2)
{
  __int64 v3; // x1

  v3 = *(_QWORD *)(a2 + 56);
  if ( *(_DWORD *)(v3 + 8) != 12 )
    return 4294967201LL;
  cfg80211_stop_nan(*(_QWORD *)(a2 + 48), v3);
  return 0;
}
