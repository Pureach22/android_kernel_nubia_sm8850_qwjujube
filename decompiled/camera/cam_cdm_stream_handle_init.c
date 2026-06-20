__int64 __fastcall cam_cdm_stream_handle_init(__int64 a1, char a2)
{
  __int64 result; // x0
  const char *v3; // x5
  unsigned int v4; // w19
  __int64 v5; // x4

  if ( (a2 & 1) != 0 )
  {
    result = cam_hw_cdm_init(a1, 0, 0);
    if ( !(_DWORD)result )
      return result;
    v3 = "CDM HW init failed";
    v4 = result;
    v5 = 348;
  }
  else
  {
    result = cam_hw_cdm_deinit(a1, 0, 0);
    if ( !(_DWORD)result )
      return result;
    v3 = "Deinit failed in streamoff";
    v4 = result;
    v5 = 354;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    1,
    1,
    "cam_cdm_stream_handle_init",
    v5,
    v3);
  return v4;
}
