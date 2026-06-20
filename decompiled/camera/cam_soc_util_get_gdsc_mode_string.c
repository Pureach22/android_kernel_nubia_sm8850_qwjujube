const char *__fastcall cam_soc_util_get_gdsc_mode_string(int a1)
{
  if ( !a1 )
    return "CAM_GDSC_SW_CONTROL";
  if ( a1 == 1 )
    return "CAM_GDSC_HW_CONTROL";
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_soc_util_get_gdsc_mode_string",
    3548,
    "Invalid GDSC control mode %d",
    a1);
  return (const char *)&unk_3E455A;
}
