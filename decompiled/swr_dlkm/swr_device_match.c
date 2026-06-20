__int64 __fastcall swr_device_match(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  const char *v4; // x19
  __int64 v5; // x20
  int v6; // t1
  const char *v7; // x1

  result = 4294967274LL;
  if ( a2 && a2 != 72 )
  {
    if ( *(_UNKNOWN **)(a1 + 120) != &swr_dev_type )
      return 0;
    if ( a1 )
    {
      v4 = (const char *)(a1 - 72);
      if ( a1 != 72 )
      {
        v5 = *(_QWORD *)(a2 + 176);
        if ( v5 )
        {
          if ( *(_BYTE *)v5 )
          {
            while ( strcmp(v4, (const char *)v5) )
            {
              v6 = *(unsigned __int8 *)(v5 + 40);
              v5 += 40;
              if ( !v6 )
              {
                v5 = 0;
                return v5 != 0;
              }
            }
            return v5 != 0;
          }
        }
        else
        {
          v7 = *(const char **)a2;
          if ( v7 )
            return strcmp((const char *)(a1 - 72), v7) == 0;
        }
        return 0;
      }
    }
  }
  return result;
}
