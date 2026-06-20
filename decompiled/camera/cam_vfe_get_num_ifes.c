_DWORD *__fastcall cam_vfe_get_num_ifes(_DWORD *result)
{
  if ( !result )
    return (_DWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       8,
                       1,
                       "cam_vfe_get_num_ifes",
                       254,
                       "Invalid argument, g_num_ife_hws: %u",
                       g_num_ife_hws);
  *result = g_num_ife_hws;
  return result;
}
