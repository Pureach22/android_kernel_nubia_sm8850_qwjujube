__int64 __fastcall nl80211_stop_ap(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8
  __int64 v3; // x2

  v2 = *(_QWORD *)(a2[4] + 2504LL);
  if ( v2 )
    v3 = *(unsigned __int8 *)(v2 + 4);
  else
    v3 = 0;
  return cfg80211_stop_ap(a2[6], a2[7], v3, 0);
}
