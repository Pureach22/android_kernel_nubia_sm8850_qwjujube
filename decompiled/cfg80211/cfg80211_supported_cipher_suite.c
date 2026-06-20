bool __fastcall cfg80211_supported_cipher_suite(__int64 a1, int a2)
{
  unsigned __int64 v2; // x8
  _DWORD *v3; // x9
  __int64 v5; // x11
  unsigned __int64 v6; // x10

  v2 = *(unsigned int *)(a1 + 156);
  if ( (int)v2 < 1 )
    return 0;
  v3 = *(_DWORD **)(a1 + 160);
  if ( *v3 == a2 )
    return 1;
  v5 = 1;
  do
  {
    v6 = v5;
    if ( v2 == v5 )
      break;
  }
  while ( v3[v5++] != a2 );
  return v6 < v2;
}
