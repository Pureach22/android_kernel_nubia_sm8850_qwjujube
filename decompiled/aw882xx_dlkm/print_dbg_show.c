__int64 __fastcall print_dbg_show(int a1, int a2, char *s)
{
  return snprintf(s, 0x1000u, "g_print_dbg : %d\n", g_print_dbg);
}
