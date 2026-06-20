__int64 __fastcall get_clock_freq(__int64 a1, char *s2, int a3)
{
  __int64 v3; // x8
  unsigned __int64 v4; // x21
  unsigned __int64 v5; // x22

  v3 = *(_QWORD *)(a1 + 3904);
  v4 = *(_QWORD *)(v3 + 64);
  v5 = v4 + 72LL * *(unsigned int *)(v3 + 72);
  if ( v4 >= v5 )
    return 0;
  while ( strcmp(*(const char **)(v4 + 8), s2) )
  {
    v4 += 72LL;
    if ( v4 >= v5 )
      return 0;
  }
  return *(_QWORD *)(*(_QWORD *)(v4 + 64) + 8LL * a3);
}
