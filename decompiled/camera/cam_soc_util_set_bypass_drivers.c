__int64 __fastcall cam_soc_util_set_bypass_drivers(int a1)
{
  debug_bypass_drivers = a1;
  return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
           3,
           0x20000,
           3,
           "cam_soc_util_set_bypass_drivers",
           634,
           "bypass drivers %d",
           a1);
}
