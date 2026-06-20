__int64 __fastcall cam_flash_put_source_node_data(__int64 a1)
{
  __int64 result; // x0
  const char **v3; // x21
  unsigned int v4; // w20
  unsigned int v5; // w22

  if ( !a1 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             4096,
             1,
             "cam_flash_put_source_node_data",
             21,
             "NULL flash control structure");
  result = *(_QWORD *)(a1 + 6136);
  v3 = *(const char ***)(a1 + 3320);
  if ( result )
  {
    if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000,
        4,
        "cam_flash_put_source_node_data",
        29,
        "switch trigger: %s",
        *v3);
      result = *(_QWORD *)(a1 + 6136);
    }
    result = cam_res_mgr_led_trigger_unregister(result);
  }
  v4 = *(_DWORD *)(a1 + 6144);
  if ( v4 )
  {
    if ( v4 > 2 )
      return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               4096,
               1,
               "cam_flash_put_source_node_data",
               35,
               "Invalid LED count: %d",
               0);
    if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000,
        4,
        "cam_flash_put_source_node_data",
        43,
        "Flash default trigger %s",
        v3[1]);
    result = cam_res_mgr_led_trigger_unregister(*(_QWORD *)(a1 + 6240));
    if ( v4 != 1 )
    {
      if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x1000,
          4,
          "cam_flash_put_source_node_data",
          43,
          "Flash default trigger %s",
          v3[2]);
      result = cam_res_mgr_led_trigger_unregister(*(_QWORD *)(a1 + 6248));
    }
  }
  v5 = *(_DWORD *)(a1 + 6148);
  if ( v5 )
  {
    if ( v5 <= 2 )
    {
      if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x1000,
          4,
          "cam_flash_put_source_node_data",
          59,
          "Flash default trigger %s",
          v3[1]);
      result = cam_res_mgr_led_trigger_unregister(*(_QWORD *)(a1 + 6256));
      if ( v5 != 1 )
      {
        if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x1000,
            4,
            "cam_flash_put_source_node_data",
            59,
            "Flash default trigger %s",
            v3[2]);
        return cam_res_mgr_led_trigger_unregister(*(_QWORD *)(a1 + 6264));
      }
    }
    else
    {
      return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               4096,
               1,
               "cam_flash_put_source_node_data",
               51,
               "Invalid LED count: %d",
               v4);
    }
  }
  return result;
}
