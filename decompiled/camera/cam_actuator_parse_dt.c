__int64 __fastcall cam_actuator_parse_dt(_QWORD *a1)
{
  __int64 v2; // x20
  int v3; // w0
  __int64 v4; // x8
  __int64 result; // x0
  const char *v6; // x5
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x4
  unsigned int v10; // w19

  v2 = a1[424];
  _mutex_init(a1 + 459, "&(a_ctrl->actuator_mutex)", &cam_actuator_parse_dt___key);
  _mutex_init(a1 + 598, "&(a_ctrl->read_buf_lock)", &cam_actuator_parse_dt___key_1);
  a1[596] = a1 + 596;
  a1[597] = a1 + 596;
  v3 = ((__int64 (__fastcall *)(_QWORD *, _QWORD *))cam_sensor_util_parse_and_request_resources)(a1 + 4, a1 + 12);
  if ( v3 < 0 )
  {
    v10 = v3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_actuator_parse_dt",
      33,
      "Failed in parse_and_request_resources rc : %d",
      v3);
    return v10;
  }
  else
  {
    v4 = a1[413];
    if ( v4 )
    {
      if ( *(_BYTE *)(v4 + 8) )
      {
        result = cam_sensor_util_init_gpio_pin_tbl(a1 + 12, v2 + 48);
        if ( (result & 0x80000000) != 0 || !*(_QWORD *)(v2 + 48) )
        {
          v6 = "No/Error Actuator GPIOs";
          v7 = 0x2000;
          v8 = 1;
          v9 = 51;
LABEL_7:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            v7,
            v8,
            "cam_actuator_parse_dt",
            v9,
            v6);
          return 4294967274LL;
        }
      }
      else
      {
        result = 4294967274LL;
        if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
        {
          v6 = "No GPIO found";
          v7 = debug_mdl & 0x2000;
          v8 = 4;
          v9 = 44;
          goto LABEL_7;
        }
      }
    }
    else
    {
      result = 0;
      if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x2000,
          4,
          "cam_actuator_parse_dt",
          38,
          "No GPIO found");
        return 0;
      }
    }
  }
  return result;
}
