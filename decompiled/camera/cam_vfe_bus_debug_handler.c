__int64 __fastcall cam_vfe_bus_debug_handler(__int64 result, int a2)
{
  if ( !result )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             8,
             1,
             "cam_vfe_bus_debug_handler",
             86,
             "Bus version %u, invalid bus",
             a2);
  if ( a2 == 12288 )
    return cam_vfe_bus_ver3_debug_handler();
  return result;
}
