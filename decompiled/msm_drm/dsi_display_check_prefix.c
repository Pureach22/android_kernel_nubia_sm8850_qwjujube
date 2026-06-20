bool __fastcall dsi_display_check_prefix(__int64 a1, char *s)
{
  size_t v4; // x0

  v4 = strlen(s);
  return strnstr(s, a1, v4) != 0;
}
