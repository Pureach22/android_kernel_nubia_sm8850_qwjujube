__int64 __fastcall cam_common_evt_inject_parse_node_evt_params(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  const char *v5; // x5
  __int64 v6; // x4

  if ( (_DWORD)a2 == 1 )
  {
    result = kstrtouint(a3, 0, a1 + 40);
    if ( !(_DWORD)result )
      return result;
    v5 = "Invalid event cause %s";
    v6 = 512;
  }
  else if ( (_DWORD)a2 )
  {
    v5 = "Invalid extra parameters: %s";
    v6 = 517;
  }
  else
  {
    result = kstrtouint(a3, a2, a1 + 36);
    if ( !(_DWORD)result )
      return result;
    v5 = "Invalid event type %s";
    v6 = 506;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_common_evt_inject_parse_node_evt_params",
    v6,
    v5,
    a3);
  return 4294967274LL;
}
