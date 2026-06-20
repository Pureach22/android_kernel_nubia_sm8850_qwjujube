__int64 __fastcall cam_handle_cmd_buffers_for_probe(
        _DWORD *a1,
        _QWORD *a2,
        int a3,
        __int64 a4,
        unsigned int a5,
        unsigned __int64 a6,
        int a7,
        __int64 a8)
{
  __int64 result; // x0
  const char *v9; // x5
  unsigned int v10; // w19
  __int64 v11; // x4
  unsigned __int64 v12; // x8
  char v13; // w19
  __int64 v15; // x20
  unsigned int updated; // w0
  __int64 v17; // x1
  _QWORD *v18; // x19
  __int64 v19; // x20
  _QWORD *v20; // x19
  __int64 v21; // x20

  if ( a3 <= 1 )
  {
    if ( a3 )
    {
      if ( a3 == 1 )
      {
        result = cam_sensor_update_power_settings(a1, a5, a2[457] + 112LL);
        if ( (result & 0x80000000) == 0 )
          return result;
        v9 = "Failed in updating power settings";
        v10 = result;
        v11 = 988;
        goto LABEL_29;
      }
      goto LABEL_13;
    }
    v12 = 80;
    if ( a7 != 8 )
      v12 = 0;
    if ( a7 == 3 )
      v12 = 28;
    if ( v12 > a6 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        32,
        1,
        "cam_handle_cmd_buffers_for_probe",
        964,
        "not enough buffer for cam_cmd_i2c_info");
      return 4294967274LL;
    }
    v13 = a7;
    v15 = (__int64)a2;
    updated = cam_sensor_update_i2c_info(a1, (__int64)a2);
    if ( (updated & 0x80000000) == 0 )
    {
      cam_sensor_update_slave_info((__int64)(a1 + 2), v17, v15, v13);
      return 0;
    }
    v9 = "Failed in Updating the i2c Info";
    v10 = updated;
    v11 = 970;
LABEL_29:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      32,
      1,
      "cam_handle_cmd_buffers_for_probe",
      v11,
      v9);
    return v10;
  }
  if ( a3 == 2 )
  {
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    {
      v20 = a2;
      v21 = a8;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_handle_cmd_buffers_for_probe",
        999,
        "reg_bank unlock settings");
      a8 = v21;
      a2 = v20;
    }
    a2[918] = 0;
    result = cam_sensor_i2c_command_parser(a2 + 810, a2 + 915, a8, 1, 0);
    if ( (result & 0x80000000) != 0 )
    {
      v9 = "Failed in updating reg_bank unlock settings";
      v10 = result;
      v11 = 1007;
      goto LABEL_29;
    }
  }
  else
  {
    if ( a3 != 3 )
    {
LABEL_13:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        32,
        1,
        "cam_handle_cmd_buffers_for_probe",
        1032,
        "Invalid command buffer");
      return 0;
    }
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    {
      v18 = a2;
      v19 = a8;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_handle_cmd_buffers_for_probe",
        1017,
        "reg_bank lock settings");
      a8 = v19;
      a2 = v18;
    }
    a2[924] = 0;
    result = cam_sensor_i2c_command_parser(a2 + 810, a2 + 921, a8, 1, 0);
    if ( (result & 0x80000000) != 0 )
    {
      v9 = "Failed in updating reg_bank lock settings";
      v10 = result;
      v11 = 1025;
      goto LABEL_29;
    }
  }
  return result;
}
