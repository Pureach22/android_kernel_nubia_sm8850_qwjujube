__int64 __fastcall name_show(__int64 a1, int a2, char *s)
{
  return sprintf(s, "%s\n", *(const char **)(a1 - 16));
}
