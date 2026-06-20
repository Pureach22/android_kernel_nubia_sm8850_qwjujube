__int64 __fastcall wlan_is_dnw_in_progress(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  return is_dnw_in_progress(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) & 1;
}
