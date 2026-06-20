__int64 __fastcall cam_common_evt_inject_parse_buffer_error_evt_params(__int64 a1, __int64 a2, __int64 a3)
{
  const char *v4; // x5
  __int64 v5; // x4
  __int64 result; // x0

  if ( (_DWORD)a2 )
  {
    v4 = "Invalid extra parameters: %s";
    v5 = 488;
  }
  else
  {
    result = kstrtouint(a3, a2, a1 + 32);
    if ( !(_DWORD)result )
      return result;
    v4 = "Invalid event type %s";
    v5 = 483;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_common_evt_inject_parse_buffer_error_evt_params",
    v5,
    v4,
    a3);
  return 4294967274LL;
}
