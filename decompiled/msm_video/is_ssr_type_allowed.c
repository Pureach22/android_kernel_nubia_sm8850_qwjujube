bool __fastcall is_ssr_type_allowed(__int64 a1, int a2)
{
  __int64 v2; // x9
  unsigned __int64 v3; // x8
  _DWORD *v4; // x9
  __int64 v6; // x11
  unsigned __int64 v7; // x10

  v2 = *(_QWORD *)(a1 + 3912);
  v3 = *(unsigned int *)(v2 + 640);
  if ( !(_DWORD)v3 )
    return 0;
  v4 = *(_DWORD **)(v2 + 632);
  if ( *v4 == a2 )
    return 1;
  v6 = 1;
  do
  {
    v7 = v6;
    if ( v3 == v6 )
      break;
  }
  while ( v4[v6++] != a2 );
  return v7 < v3;
}
