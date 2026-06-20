__int64 __fastcall mhi_match(__int64 a1, __int64 a2)
{
  __int64 v3; // x19
  const char *v4; // x20
  int v6; // t1

  if ( *(_DWORD *)(a1 + 912) == 1 )
    return 0;
  v3 = *(_QWORD *)(a2 - 48);
  if ( !*(_BYTE *)v3 )
    return 0;
  v4 = *(const char **)(a1 - 32);
  while ( strcmp(v4, (const char *)v3) )
  {
    v6 = *(unsigned __int8 *)(v3 + 40);
    v3 += 40;
    if ( !v6 )
      return 0;
  }
  *(_QWORD *)(a1 - 40) = v3;
  return 1;
}
