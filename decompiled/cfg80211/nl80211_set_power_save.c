__int64 __fastcall nl80211_set_power_save(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8
  __int64 v3; // x21
  __int64 v4; // x1
  int v5; // w8
  __int64 v6; // x19
  int v7; // w20
  __int64 result; // x0
  __int64 v9; // x3
  _BOOL8 v10; // x2
  __int64 (__fastcall *v11)(__int64, __int64, _BOOL8, __int64); // x8

  v2 = *(_QWORD *)(a2[4] + 744LL);
  if ( !v2 )
    return 4294967274LL;
  v3 = a2[6];
  if ( !*(_QWORD *)(*(_QWORD *)v3 + 536LL) )
    return 4294967201LL;
  v4 = a2[7];
  v5 = *(unsigned __int8 *)(v2 + 4);
  v6 = *(_QWORD *)(v4 + 992);
  v7 = v5 == 1;
  if ( *(unsigned __int8 *)(v6 + 165) == v7 )
    return 0;
  v9 = *(unsigned int *)(v6 + 168);
  v10 = v5 == 1;
  v11 = *(__int64 (__fastcall **)(__int64, __int64, _BOOL8, __int64))(*(_QWORD *)v3 + 536LL);
  if ( *((_DWORD *)v11 - 1) != -1867233320 )
    __break(0x8228u);
  result = v11(v3 + 992, v4, v10, v9);
  if ( !(_DWORD)result )
    *(_BYTE *)(v6 + 165) = v7;
  return result;
}
