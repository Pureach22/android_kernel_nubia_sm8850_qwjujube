__int64 __fastcall nl80211_remove_link(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x0

  v2 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 2504LL);
  if ( !v2 )
    return 4294967274LL;
  v3 = *(_QWORD *)(*(_QWORD *)(a2 + 56) + 992LL);
  if ( *(_DWORD *)(v3 + 8) != 3 )
    return 4294967274LL;
  cfg80211_remove_link(v3, *(unsigned __int8 *)(v2 + 4));
  return 0;
}
