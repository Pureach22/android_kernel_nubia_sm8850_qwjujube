__int64 cam_vfe_top_ver4_reset()
{
  if ( (debug_mdl & 8) == 0 || debug_priority )
    return 0;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_vfe_top_ver4_reset",
    1254,
    "Reset not supported");
  return 0;
}
