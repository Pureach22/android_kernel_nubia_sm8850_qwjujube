__int64 __fastcall tpg_subdev_handle_message(__int64 a1, int a2, _DWORD *a3)
{
  __int64 result; // x0
  __int64 v4; // x6
  const char *v5; // x5
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x4

  if ( !a3 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             0x200000000LL,
             1,
             "tpg_subdev_handle_message",
             162,
             "Empty Payload");
  result = *(_QWORD *)(a1 + 240);
  if ( !result )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             0x200000000LL,
             1,
             "tpg_subdev_handle_message",
             167,
             "Invalid tpg_dev : NULL");
  if ( *a3 == *(_DWORD *)(result + 4840) )
  {
    if ( a2 == 1 )
      return cam_tpg_trigger_memdump();
    v4 = *(unsigned int *)(result + 564);
    v5 = "TPG[%u] Invalid subdev msg type: %d";
    v6 = 0x200000000LL;
    v7 = 1;
    v8 = 187;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
             3,
             v6,
             v7,
             "tpg_subdev_handle_message",
             v8,
             v5,
             v4);
  }
  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
  {
    v4 = *(unsigned int *)(result + 564);
    v5 = "TPG[%u] Expected IDX: %u, Received IDX: %u";
    v6 = debug_mdl & 0x200000000LL;
    v7 = 4;
    v8 = 176;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
             3,
             v6,
             v7,
             "tpg_subdev_handle_message",
             v8,
             v5,
             v4);
  }
  return result;
}
