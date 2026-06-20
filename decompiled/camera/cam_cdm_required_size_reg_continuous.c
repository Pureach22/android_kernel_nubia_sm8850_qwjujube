__int64 __fastcall cam_cdm_required_size_reg_continuous(int a1)
{
  if ( a1 )
    return (unsigned int)(a1 + 2);
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    1,
    2,
    "cam_cdm_required_size_reg_continuous",
    204,
    "numVals cant be 0");
  return 0;
}
