__int64 __fastcall nla_put_string(__int64 a1, unsigned int a2, char *s)
{
  int v6; // w0

  v6 = strlen(s);
  return nla_put(a1, a2, (unsigned int)(v6 + 1), s);
}
