_QWORD *__fastcall cam_i3c_driver_remove_1(__int64 a1)
{
  const char *v2; // x7
  _QWORD *result; // x0
  const char *v4; // x6
  __int64 v5; // x22
  _QWORD *v6; // x0
  const char *v7; // x6
  const char *v8; // x6
  const char *v9; // x6
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  if ( a1 )
  {
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    {
      v8 = *(const char **)(a1 + 112);
      if ( !v8 )
        v8 = *(const char **)a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_i3c_driver_remove",
        631,
        "driver remove for I3C Slave %s",
        v8);
    }
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "cell-index", &v10, 1, 0) & 0x80000000) != 0 )
    {
      v4 = *(const char **)(a1 + 112);
      if ( !v4 )
        v4 = *(const char **)a1;
      result = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                           3,
                           0x20000,
                           1,
                           "cam_i3c_driver_remove",
                           635,
                           "device %s failed to read cell-index",
                           v4);
    }
    else if ( v10 < 0x10 )
    {
      v5 = g_i3c_ois_data[5 * v10];
      if ( v5 )
      {
        if ( (debug_mdl & 0x20) != 0 && !debug_priority )
        {
          v9 = *(const char **)(a1 + 112);
          if ( !v9 )
            v9 = *(const char **)a1;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20,
            4,
            "cam_i3c_driver_remove",
            652,
            "I3C remove invoked for %s",
            v9);
        }
        v6 = *(_QWORD **)(v5 + 3664);
        if ( mem_trace_en == 1 )
          result = cam_mem_trace_free(v6, 0);
        else
          result = (_QWORD *)kvfree(v6);
        *(_QWORD *)(v5 + 3664) = 0;
      }
      else
      {
        v7 = *(const char **)(a1 + 112);
        if ( !v7 )
          v7 = *(const char **)a1;
        result = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                             3,
                             32,
                             1,
                             "cam_i3c_driver_remove",
                             647,
                             "S_ctrl is null. I3C Probe before platfom driver probe for %s",
                             v7);
      }
    }
    else
    {
      v2 = *(const char **)(a1 + 112);
      if ( !v2 )
        v2 = *(const char **)a1;
      result = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                           3,
                           32,
                           1,
                           "cam_i3c_driver_remove",
                           640,
                           "Invalid Cell-Index: %u for %s",
                           v10,
                           v2);
    }
  }
  else
  {
    result = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                         3,
                         32,
                         1,
                         "cam_i3c_driver_remove",
                         625,
                         "I3C Driver Remove: Invalid input args");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
