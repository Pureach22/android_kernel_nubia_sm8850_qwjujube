__int64 __fastcall debug_value_show(int a1, int a2, char *s)
{
  return snprintf(s, 5u, "%d", debug_value);
}
