const char *__fastcall i_trim(const char *s)
{
  int v1; // w9
  const char *v2; // x8
  int v3; // t1
  const char *v4; // x19
  size_t v5; // x0
  size_t v6; // x8
  int v7; // w9
  const char *v8; // x8

  v1 = *(unsigned __int8 *)s;
  if ( *s )
  {
    v2 = s;
    while ( (unsigned int)(v1 - 9) < 5 || v1 == 32 )
    {
      v3 = *(unsigned __int8 *)++v2;
      v1 = v3;
    }
    if ( v1 )
    {
      v4 = v2;
      v5 = strlen(v2);
      v6 = v5 - 1;
      if ( v5 == 1 )
      {
        s = v4;
        v8 = &v4[v6];
      }
      else
      {
        s = v4;
        do
        {
          v7 = (unsigned __int8)v4[v6];
          if ( (unsigned int)(v7 - 9) >= 5 && v7 != 32 )
          {
            v8 = &v4[v6];
            goto LABEL_15;
          }
          --v6;
        }
        while ( v6 );
        v8 = v4;
      }
LABEL_15:
      *((_BYTE *)v8 + 1) = 0;
    }
  }
  return s;
}
