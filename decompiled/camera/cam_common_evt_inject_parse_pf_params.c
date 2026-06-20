__int64 __fastcall cam_common_evt_inject_parse_pf_params(__int64 a1, int a2, __int64 a3)
{
  const char *v4; // x5
  __int64 v5; // x4
  __int64 result; // x0

  if ( a2 )
  {
    v4 = "Invalid extra parameters %s";
    v5 = 540;
  }
  else
  {
    result = kstrtobool(a3, a1 + 36);
    if ( !(_DWORD)result )
      return result;
    v4 = "Invalid context found value %s";
    v5 = 535;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_common_evt_inject_parse_pf_params",
    v5,
    v4,
    a3);
  return 4294967274LL;
}
