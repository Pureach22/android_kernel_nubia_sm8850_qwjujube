_DWORD *__fastcall cam_sfe_get_num_hws(_DWORD *result)
{
  if ( !result )
    return (_DWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       0x40000000,
                       1,
                       "cam_sfe_get_num_hws",
                       235,
                       "Invalid argument, g_num_sfe_hws: %u",
                       g_num_sfe_hws);
  *result = g_num_sfe_hws;
  return result;
}
