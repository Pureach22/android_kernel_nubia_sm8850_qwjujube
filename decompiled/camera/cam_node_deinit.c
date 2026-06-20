__int64 __fastcall cam_node_deinit(void *a1)
{
  if ( a1 )
    memset(a1, 0, 0x158u);
  if ( (debug_mdl & 2) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 2,
      4,
      "cam_node_deinit",
      717,
      "deinit complete");
  return 0;
}
