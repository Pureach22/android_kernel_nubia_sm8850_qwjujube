char *__fastcall dsi_parser_get_data(char *delim, const char *a2, char *a3)
{
  char *v4; // x19
  int v5; // w0
  unsigned __int64 v6; // x9
  _BYTE *v7; // x8
  char *v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = a3;
  strsep(v9, delim);
  if ( v9[0] )
  {
    v4 = strsep(v9, a2);
    v5 = strlen(v4);
    if ( v5 )
    {
      v6 = (unsigned __int64)&v4[v5 - 1];
      do
      {
        v7 = (_BYTE *)v6;
        if ( v6 < (unsigned __int64)v4 )
          break;
        --v6;
      }
      while ( *v7 == 42 );
      v7[1] = 0;
    }
  }
  else
  {
    v4 = nullptr;
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
