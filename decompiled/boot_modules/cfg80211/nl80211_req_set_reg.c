__int64 __fastcall nl80211_req_set_reg(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x9
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v6; // x1
  _BOOL8 v7; // x0

  if ( !cfg80211_regdomain )
    return 4294967181LL;
  v2 = *(_QWORD **)(a2 + 32);
  v3 = v2[154];
  if ( !v3 || (LODWORD(v3) = *(_DWORD *)(v3 + 4), (unsigned int)v3 < 2) )
  {
    v4 = v2[33];
    if ( v4 )
      return regulatory_hint_user(v4 + 4, (unsigned int)v3);
    return 4294967274LL;
  }
  if ( (_DWORD)v3 != 2 )
    return 4294967274LL;
  if ( v2[204] )
  {
    v6 = *(unsigned int *)(a2 + 4);
    v7 = v2[221] != 0;
  }
  else
  {
    v6 = 0;
    v7 = 1;
  }
  regulatory_hint_indoor(v7, v6);
  return 0;
}
