__int64 __fastcall cfg80211_set_mesh_channel(__int64 *a1, __int64 a2, __int64 *a3)
{
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v5; // x8
  __int64 *v6; // x19
  __int64 v7; // x8
  __int64 *v8; // x0
  __int64 (__fastcall *v9)(_QWORD); // x8
  __int64 v10; // x9
  __int64 v11; // x11
  __int64 v12; // x12
  _QWORD *v13; // x8

  if ( !*(_QWORD *)(*a1 + 304) )
  {
    if ( *(_BYTE *)(a2 + 384) )
      return 4294967280LL;
    v5 = 288;
    goto LABEL_13;
  }
  if ( *((_DWORD *)a3 + 2) )
    return 4294967274LL;
  v4 = a2;
  if ( (*(_QWORD *)(*(_QWORD *)(a2 + 32) + 168LL) & 1) == 0 )
    return 4294967196LL;
  v6 = a3;
  v7 = *a1;
  v8 = a1 + 124;
  v9 = *(__int64 (__fastcall **)(_QWORD))(v7 + 304);
  if ( *((_DWORD *)v9 - 1) != -1568202802 )
    __break(0x8228u);
  result = v9(v8);
  if ( !(_DWORD)result )
  {
    a2 = v4;
    v5 = 320;
    a3 = v6;
LABEL_13:
    v10 = a3[3];
    v11 = *a3;
    v12 = a3[1];
    v13 = (_QWORD *)(a2 + v5);
    v13[2] = a3[2];
    v13[3] = v10;
    *v13 = v11;
    v13[1] = v12;
    return 0;
  }
  return result;
}
