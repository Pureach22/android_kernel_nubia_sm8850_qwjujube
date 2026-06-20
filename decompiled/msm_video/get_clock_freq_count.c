__int64 __fastcall get_clock_freq_count(__int64 a1, char *s2)
{
  __int64 v2; // x8
  unsigned __int64 v3; // x20
  unsigned __int64 v4; // x21

  v2 = *(_QWORD *)(a1 + 3904);
  v3 = *(_QWORD *)(v2 + 64);
  v4 = v3 + 72LL * *(unsigned int *)(v2 + 72);
  if ( v3 >= v4 )
    return 0;
  while ( strcmp(*(const char **)(v3 + 8), s2) )
  {
    v3 += 72LL;
    if ( v3 >= v4 )
      return 0;
  }
  return *(unsigned int *)(v3 + 56);
}
