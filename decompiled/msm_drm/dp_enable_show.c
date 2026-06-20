__int64 __fastcall dp_enable_show(int a1, int a2, char *s)
{
  return sprintf(s, "%d\n", *(unsigned __int8 *)(dp_switch + 16));
}
