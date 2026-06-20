__int64 __fastcall cam_flash_i2c_apply_setting(
        __int64 a1,
        unsigned __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v8; // x8
  __int64 v9; // x21
  _QWORD *v10; // x23
  unsigned int v11; // w0
  const char *v12; // x5
  unsigned int v13; // w19
  __int64 v14; // x4
  _QWORD *v15; // x24
  _QWORD *v16; // x26
  int v17; // w0
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x4
  __int64 v21; // x5
  _QWORD *v22; // x23
  unsigned int v23; // w0
  __int64 v24; // x10
  unsigned __int64 v25; // x9
  unsigned __int64 v26; // x6
  unsigned __int64 v27; // x11
  __int64 v29; // x7
  unsigned int v30; // w0
  __int64 v31; // x6
  const char *v32; // x5
  __int64 v33; // x4
  __int64 result; // x0

  if ( a2 )
  {
    v8 = *(_QWORD *)(a1 + 6584);
    v9 = v8 + 48 * (a2 & 0x1F);
    if ( *(_DWORD *)(v9 + 16) != 1 || *(_QWORD *)(v9 + 24) != a2 )
      goto LABEL_22;
    v10 = (_QWORD *)(v8 + 48 * (a2 & 0x1F));
    while ( 1 )
    {
      v10 = (_QWORD *)*v10;
      if ( v10 == (_QWORD *)v9 )
        break;
      v11 = cam_sensor_util_i2c_apply_setting((int *)(a1 + 6280), (__int64)(v10 - 9), a3, a4, a5, a6);
      if ( v11 )
      {
        v12 = "Failed to apply settings: %d";
        v13 = v11;
        v14 = 1047;
        goto LABEL_49;
      }
    }
  }
  else
  {
    if ( *(_DWORD *)(a1 + 6360) == 1 )
    {
      v15 = (_QWORD *)(a1 + 6344);
      v16 = (_QWORD *)(a1 + 6344);
      while ( 1 )
      {
        v16 = (_QWORD *)*v16;
        if ( v16 == v15 )
          break;
        v17 = cam_sensor_util_i2c_apply_setting((int *)(a1 + 6280), (__int64)(v16 - 9), a3, a4, a5, a6);
        if ( v17 == -11 )
        {
          if ( *(_DWORD *)(a1 + 6280) != 1 )
          {
            v17 = -11;
LABEL_48:
            v12 = "Failed to apply init settings: %d";
            v13 = v17;
            v14 = 1016;
LABEL_49:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              4096,
              1,
              "cam_flash_i2c_apply_setting",
              v14,
              v12,
              v13);
            return v13;
          }
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            4096,
            2,
            "cam_flash_i2c_apply_setting",
            1007,
            "CCI HW is in reset mode: Reapplying Init settings");
          usleep_range_state(1000, 1010, 2);
          v17 = cam_sensor_util_i2c_apply_setting((int *)(a1 + 6280), (__int64)(v16 - 9), v18, v19, v20, v21);
        }
        if ( v17 )
          goto LABEL_48;
      }
    }
    if ( *(_DWORD *)(a1 + 6408) == 1 )
    {
      v22 = (_QWORD *)(a1 + 6392);
      while ( 1 )
      {
        v22 = (_QWORD *)*v22;
        if ( v22 == (_QWORD *)(a1 + 6392) )
          break;
        v23 = cam_sensor_util_i2c_apply_setting((int *)(a1 + 6280), (__int64)(v22 - 9), a3, a4, a5, a6);
        if ( v23 )
        {
          v12 = "Failed to apply NRT settings: %d";
          v13 = v23;
          v14 = 1030;
          goto LABEL_49;
        }
      }
    }
  }
  if ( !a2 )
    goto LABEL_39;
  v8 = *(_QWORD *)(a1 + 6584);
LABEL_22:
  v24 = 0;
  v25 = 0;
  v26 = 0;
  do
  {
    v27 = *(_QWORD *)(v8 + v24 + 24);
    if ( v27 <= a2 && v26 < v27 )
    {
      if ( *(_DWORD *)(v8 + v24 + 16) == 1 )
        v25 = v26;
      else
        v27 = v26;
      v26 = v27;
    }
    v24 += 48;
  }
  while ( v24 != 1536 );
  if ( v26 >= a2 )
    v29 = v25;
  else
    v29 = a2;
  if ( !v29 )
    return 0;
  if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000,
      4,
      "cam_flash_i2c_delete_req",
      889,
      "top: %llu, del_req_id:%llu",
      v26,
      v29);
LABEL_39:
  if ( *(_DWORD *)(a1 + 6360) == 1 )
  {
    v30 = delete_request(a1 + 6344);
    if ( v30 )
    {
      v31 = v30;
      v32 = "Failed to delete Init i2c_setting: %d";
      v33 = 102;
LABEL_45:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        4096,
        2,
        "cam_flash_i2c_flush_nrt",
        v33,
        v32,
        v31);
      return 0;
    }
  }
  if ( *(_DWORD *)(a1 + 6408) == 1 )
  {
    result = delete_request(a1 + 6392);
    if ( !(_DWORD)result )
      return result;
    v31 = (unsigned int)result;
    v32 = "Failed to delete NRT i2c_setting: %d";
    v33 = 111;
    goto LABEL_45;
  }
  return 0;
}
