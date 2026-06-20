__int64 __fastcall cfg80211_get_iftype_ext_capa(__int64 a1, int a2)
{
  int v2; // w8
  __int64 v3; // x9
  int v4; // w10

  v2 = *(_DWORD *)(a1 + 312);
  if ( !v2 )
    return 0;
  v3 = *(_QWORD *)(a1 + 304);
  v4 = 0;
  while ( *(_DWORD *)(v3 + 32LL * v4) != a2 )
  {
    if ( v2 == ++v4 )
      return 0;
  }
  return v3 + 32LL * v4;
}
