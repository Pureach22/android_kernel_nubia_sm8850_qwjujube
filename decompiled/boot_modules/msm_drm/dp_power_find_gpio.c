bool __fastcall dp_power_find_gpio(const char *a1, __int64 a2)
{
  size_t v4; // x0

  v4 = strlen(a1);
  return strnstr(a1, a2, v4) != 0;
}
