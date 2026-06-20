__int64 __fastcall cali_time_show(int a1, int a2, char *s)
{
  return snprintf(s, 0x1000u, "time: %d\n", g_cali_re_time);
}
