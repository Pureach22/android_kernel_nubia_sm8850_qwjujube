__int64 __fastcall cam_vfe_core_debug_handler(__int64 result, int a2)
{
  if ( !result )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             8,
             1,
             "cam_vfe_core_debug_handler",
             32,
             "Invalid arguments");
  if ( a2 == 1 )
    return cam_vfe_bus_debug_handler(
             **(_QWORD **)(*(_QWORD *)(result + 3680) + 24LL),
             *(unsigned int *)(**(_QWORD **)(result + 3680) + 8LL));
  return result;
}
