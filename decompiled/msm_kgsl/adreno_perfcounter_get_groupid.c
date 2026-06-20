__int64 __fastcall adreno_perfcounter_get_groupid(__int64 a1, char *s)
{
  int v2; // w19
  __int64 *v3; // x8
  int v4; // w23
  __int64 v5; // x24
  const char *v7; // x21
  size_t v8; // x22

  v2 = -22;
  if ( s )
  {
    v3 = *(__int64 **)(*(_QWORD *)(a1 + 14264) + 48LL);
    if ( v3 )
    {
      v4 = *((_DWORD *)v3 + 2);
      if ( v4 )
      {
        v5 = *v3;
        v2 = 0;
        while ( 1 )
        {
          v7 = *(const char **)(v5 + 56LL * v2 + 16);
          if ( v7 )
          {
            v8 = strlen(s);
            if ( v8 == strlen(v7) && !strcmp(v7, s) )
              break;
          }
          if ( v4 == ++v2 )
            return (unsigned int)-22;
        }
      }
    }
  }
  return (unsigned int)v2;
}
