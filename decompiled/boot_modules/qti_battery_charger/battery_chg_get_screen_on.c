__int64 __fastcall battery_chg_get_screen_on(__int64 a1, __int64 a2)
{
  return scnprintf(a1, 4096, "%d\n", *(unsigned __int8 *)(a2 + 1052));
}
