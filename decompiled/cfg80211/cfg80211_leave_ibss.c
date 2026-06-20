__int64 __fastcall cfg80211_leave_ibss(__int64 *a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v4; // x8
  _QWORD *v5; // x0
  __int64 (__fastcall *v6)(_QWORD); // x8
  __int64 result; // x0

  v2 = *(_QWORD *)(a2 + 992);
  if ( !*(_BYTE *)(v2 + 356) )
    return 4294967229LL;
  v4 = *a1;
  v5 = a1 + 124;
  v6 = *(__int64 (__fastcall **)(_QWORD))(v4 + 400);
  if ( *((_DWORD *)v6 - 1) != 1283138139 )
    __break(0x8228u);
  result = v6(v5);
  if ( !(_DWORD)result )
  {
    *(_DWORD *)(v2 + 100) = 0;
    cfg80211_clear_ibss(a2);
    return 0;
  }
  return result;
}
