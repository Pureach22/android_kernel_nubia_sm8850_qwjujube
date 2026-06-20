__int64 cam_tpg_dump_req()
{
  if ( (debug_mdl & 0x200000000LL) == 0 || debug_priority )
    return 0;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    debug_mdl & 0x200000000LL,
    4,
    "cam_tpg_dump_req",
    210,
    "Got dump request from CRM");
  return 0;
}
