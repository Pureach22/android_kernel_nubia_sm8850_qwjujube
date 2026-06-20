__int64 __fastcall cam_eeprom_parse_read_memory_map(__int64 a1, __int64 a2)
{
  __int64 v3; // x22
  unsigned int v4; // w0
  unsigned int v5; // w20
  unsigned int v6; // w0
  const char *v7; // x3
  const char *v8; // x5
  __int64 v9; // x4
  __int64 v10; // x6
  int v12; // w8
  unsigned int matched; // w0
  unsigned int memory; // w0
  __int64 v15; // x8
  unsigned int v16; // w0
  __int64 v17; // x8

  if ( !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_parse_read_memory_map",
      280,
      "failed: e_ctrl is NULL");
    return (unsigned int)-22;
  }
  v3 = *(_QWORD *)(a2 + 3384);
  v4 = cam_eeprom_parse_dt_memory_map(a1, a2 + 4304);
  if ( !v4 )
  {
    v6 = cam_eeprom_power_up(a2, v3 + 16);
    if ( v6 )
    {
      v5 = v6;
      v7 = "cam_eeprom_parse_read_memory_map";
      v8 = "failed: eeprom power up rc %d";
      v9 = 295;
      v10 = v6;
    }
    else
    {
      v12 = *(_DWORD *)(a2 + 4288);
      *(_DWORD *)(a2 + 4292) = 2;
      if ( v12 == 2 && (matched = cam_eeprom_match_id(a2)) != 0 )
      {
        v5 = matched;
        if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x10000,
            4,
            "cam_eeprom_parse_read_memory_map",
            303,
            "eeprom not matching %d",
            matched);
      }
      else
      {
        memory = cam_eeprom_read_memory(a2, a2 + 4304);
        if ( !memory )
        {
          v17 = *(_QWORD *)(a2 + 3384);
          if ( v17 == -16 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x10000,
              1,
              "cam_eeprom_power_down",
              226,
              "failed: power_info %pK",
              nullptr);
            v5 = -22;
          }
          else
          {
            v5 = cam_sensor_util_power_down(v17 + 16, a2 + 88);
            if ( !v5 )
            {
              camera_io_release(a2 + 3664);
              goto LABEL_9;
            }
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x10000,
              1,
              "cam_eeprom_power_down",
              231,
              "power down the core is failed:%d",
              v5);
          }
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x10000,
            1,
            "cam_eeprom_parse_read_memory_map",
            315,
            "failed: eeprom power down rc %d",
            v5);
LABEL_9:
          *(_DWORD *)(a2 + 4292) = 1;
          return v5;
        }
        v5 = memory;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x10000,
          1,
          "cam_eeprom_parse_read_memory_map",
          309,
          "read_eeprom_memory failed");
      }
      v15 = *(_QWORD *)(a2 + 3384);
      if ( v15 == -16 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x10000,
          1,
          "cam_eeprom_power_down",
          226,
          "failed: power_info %pK",
          nullptr);
        goto LABEL_8;
      }
      v16 = cam_sensor_util_power_down(v15 + 16, a2 + 88);
      if ( !v16 )
      {
        camera_io_release(a2 + 3664);
        goto LABEL_8;
      }
      v10 = v16;
      v7 = "cam_eeprom_power_down";
      v8 = "power down the core is failed:%d";
      v9 = 231;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x10000,
      1,
      v7,
      v9,
      v8,
      v10);
LABEL_8:
    vfree(*(_QWORD *)(a2 + 4320));
    vfree(*(_QWORD *)(a2 + 4304));
    *(_DWORD *)(a2 + 4328) = 0;
    *(_DWORD *)(a2 + 4312) = 0;
    goto LABEL_9;
  }
  v5 = v4;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x10000,
    1,
    "cam_eeprom_parse_read_memory_map",
    290,
    "failed: eeprom dt parse rc %d",
    v4);
  return v5;
}
