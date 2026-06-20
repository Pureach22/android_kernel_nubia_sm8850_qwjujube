__int64 __fastcall dsi_parser_count(char *s, unsigned int a2)
{
  unsigned int v4; // w20
  size_t v5; // x0
  __int64 v6; // x0

  v4 = -1;
  do
  {
    v5 = strlen(s);
    v6 = strnchr(s, v5, a2);
    ++v4;
    s = (char *)(v6 + 1);
  }
  while ( v6 );
  return v4;
}
