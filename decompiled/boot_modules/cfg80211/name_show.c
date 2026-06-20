__int64 __fastcall name_show(const char **a1, int a2, char *s)
{
  const char *v3; // x8

  v3 = a1[14];
  if ( !v3 )
    v3 = *a1;
  return sprintf(s, "%s\n", v3);
}
