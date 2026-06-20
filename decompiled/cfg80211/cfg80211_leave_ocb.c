__int64 __fastcall cfg80211_leave_ocb(__int64 *a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 *v4; // x0
  __int64 (__fastcall *v5)(_QWORD); // x8
  __int64 result; // x0

  v2 = *(_QWORD *)(a2 + 992);
  if ( *(_DWORD *)(v2 + 8) != 11 || !*(_QWORD *)(*a1 + 272) )
    return 4294967201LL;
  if ( !*(_QWORD *)(v2 + 280) )
    return 4294967189LL;
  v3 = *a1;
  v4 = a1 + 124;
  v5 = *(__int64 (__fastcall **)(_QWORD))(v3 + 272);
  if ( *((_DWORD *)v5 - 1) != 1283138139 )
    __break(0x8228u);
  result = v5(v4);
  if ( !(_DWORD)result )
  {
    *(_QWORD *)(v2 + 296) = 0;
    *(_QWORD *)(v2 + 304) = 0;
    *(_QWORD *)(v2 + 280) = 0;
    *(_QWORD *)(v2 + 288) = 0;
  }
  return result;
}
