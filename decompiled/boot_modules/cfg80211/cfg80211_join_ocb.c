__int64 __fastcall cfg80211_join_ocb(__int64 *a1, __int64 a2, __int64 *a3)
{
  __int64 v3; // x20
  __int64 v5; // x8
  __int64 *v6; // x0
  __int64 (__fastcall *v7)(_QWORD); // x8
  __int64 result; // x0
  __int64 v9; // x8
  __int64 v10; // x10
  __int64 v11; // x11

  v3 = *(_QWORD *)(a2 + 992);
  if ( *(_DWORD *)(v3 + 8) != 11 || !*(_QWORD *)(*a1 + 264) )
    return 4294967201LL;
  if ( *a3 )
  {
    v5 = *a1;
    v6 = a1 + 124;
    v7 = *(__int64 (__fastcall **)(_QWORD))(v5 + 264);
    if ( *((_DWORD *)v7 - 1) != -1204709169 )
      __break(0x8228u);
    result = v7(v6);
    if ( !(_DWORD)result )
    {
      v9 = a3[3];
      v10 = *a3;
      v11 = a3[1];
      *(_QWORD *)(v3 + 296) = a3[2];
      *(_QWORD *)(v3 + 304) = v9;
      *(_QWORD *)(v3 + 280) = v10;
      *(_QWORD *)(v3 + 288) = v11;
    }
  }
  else
  {
    __break(0x800u);
    return 4294967274LL;
  }
  return result;
}
