__int64 __fastcall nl80211_leave_ibss(__int64 a1, __int64 a2)
{
  __int64 *v2; // x0
  __int64 v3; // x1

  v2 = *(__int64 **)(a2 + 48);
  if ( *(_QWORD *)(*v2 + 400) && (v3 = *(_QWORD *)(a2 + 56), *(_DWORD *)(*(_QWORD *)(v3 + 992) + 8LL) == 1) )
    return cfg80211_leave_ibss(v2, v3);
  else
    return 4294967201LL;
}
