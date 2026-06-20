__int64 __fastcall cam_ois_parse_fw_setting(__int64 a1, unsigned int a2, __int64 a3)
{
  unsigned int v5; // w8
  __int64 v6; // x26
  __int64 v7; // x1
  __int64 v8; // x6
  __int64 v9; // x7
  __int64 result; // x0
  unsigned int v11; // w8
  __int64 v12; // x6
  unsigned int v13; // w8
  __int64 v14; // x9
  unsigned __int64 v15; // x6
  unsigned int v16; // w23
  const char *v17; // x5
  __int64 v18; // x4
  __int64 v19; // x4
  __int64 v20; // x6
  __int64 v21; // x4
  const char *v22; // x5
  unsigned int v23; // w19
  __int64 v24; // x4
  int v25; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v26; // [xsp+10h] [xbp-20h] BYREF
  unsigned int v27; // [xsp+18h] [xbp-18h] BYREF
  unsigned int v28; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v29[2]; // [xsp+20h] [xbp-10h] BYREF

  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29[0] = a1;
  v28 = 0;
  v27 = 0;
  v26 = 0;
  if ( !a2 )
  {
    result = 0;
    goto LABEL_62;
  }
  v5 = 0;
  while ( 1 )
  {
    if ( a2 - v5 <= 7 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x100000,
        1,
        "cam_ois_parse_fw_setting",
        439,
        "Not enough buffer");
      goto LABEL_60;
    }
    v6 = v29[0];
    v7 = *(unsigned __int8 *)(v29[0] + 4LL);
    if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
    {
      v16 = *(unsigned __int8 *)(v29[0] + 4LL);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100000,
        4,
        "cam_ois_parse_fw_setting",
        446,
        "Command Type:%d, Op code:%d",
        *(unsigned __int8 *)(v29[0] + 5LL),
        v7);
      v7 = v16;
    }
    v8 = *(unsigned __int8 *)(v6 + 5);
    if ( *(unsigned __int8 *)(v6 + 5) <= 6u )
      break;
    if ( (_DWORD)v8 == 7 )
    {
      v11 = v28;
      v25 = 0;
      if ( a2 - v28 > 0x13 )
      {
        v15 = 8LL * *(unsigned int *)v29[0] + 12;
        if ( v15 > a2 - v28 )
        {
          v21 = 511;
          goto LABEL_51;
        }
        result = cam_sensor_handle_continuous_write();
        if ( (result & 0x80000000) != 0 )
        {
          v22 = "Failed in continuous write %d";
          v23 = result;
          v24 = 521;
          goto LABEL_61;
        }
        v13 = v28 + 20;
        v14 = v29[0] + 20LL;
        goto LABEL_32;
      }
      v19 = 499;
LABEL_46:
      v20 = a2;
      v9 = v11;
      goto LABEL_59;
    }
    if ( (_DWORD)v8 == 8 )
    {
      v9 = v28;
      LOWORD(v25) = 0;
      if ( a2 - v28 <= 0xB )
      {
        v19 = 627;
        goto LABEL_58;
      }
      result = cam_sensor_handle_continuous_read(v29[0], a3, &v25, &v27, &v26, 0);
      if ( (result & 0x80000000) != 0 )
      {
        v22 = "Failed in continuous read %d";
        v23 = result;
        v24 = 639;
        goto LABEL_61;
      }
      v13 = v28 + 12;
      v14 = v29[0] + 12LL;
      goto LABEL_32;
    }
    if ( (_DWORD)v8 != 9 )
      goto LABEL_41;
    if ( (v7 & 0xFE) == 2 )
    {
      v9 = v28;
      if ( a2 - v28 <= 7 )
      {
        v19 = 537;
        goto LABEL_58;
      }
      result = cam_sensor_handle_delay(v29, v7, a3, v27, &v28, v26);
      if ( (result & 0x80000000) != 0 )
      {
        v22 = "delay hdl failed: %d";
        v23 = result;
        v24 = 549;
        goto LABEL_61;
      }
    }
    else
    {
      if ( (_DWORD)v7 != 1 )
      {
        v17 = "Wrong Wait Command: %d";
        v8 = (unsigned int)v7;
        v18 = 573;
        goto LABEL_56;
      }
      v9 = v28;
      if ( a2 - v28 <= 0x13 )
      {
        v19 = 557;
LABEL_58:
        v20 = a2;
LABEL_59:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
          3,
          0x100000,
          1,
          "cam_ois_parse_fw_setting",
          v19,
          "Not enough buffer provided,size %d,byte_cnt %d",
          v20,
          v9);
LABEL_60:
        result = 4294967274LL;
        goto LABEL_62;
      }
      result = cam_sensor_handle_poll(v29, a3, &v28, &v27, &v26);
      if ( (result & 0x80000000) != 0 )
      {
        v22 = "parsing POLL fail: %d";
        v23 = result;
        v24 = 567;
        goto LABEL_61;
      }
    }
LABEL_33:
    v5 = v28;
    if ( v28 >= a2 )
      goto LABEL_62;
  }
  if ( (_DWORD)v8 != 5 )
  {
    if ( (_DWORD)v8 != 6 )
    {
LABEL_41:
      v17 = "Invalid Command Type:%d";
      v18 = 650;
LABEL_56:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        0x100000,
        1,
        "cam_ois_parse_fw_setting",
        v18,
        v17,
        v8);
      goto LABEL_60;
    }
    v11 = v28;
    LOWORD(v25) = 0;
    if ( a2 - v28 <= 0xF )
    {
      v19 = 587;
      goto LABEL_46;
    }
    v12 = *(unsigned int *)v29[0];
    if ( 8 * v12 + 8 > (unsigned __int64)(a2 - v28) )
    {
      v21 = 598;
      v15 = 8 * v12 + 8;
      goto LABEL_51;
    }
    result = cam_sensor_handle_random_read();
    if ( (result & 0x80000000) != 0 )
    {
      v22 = "Failed in random read %d";
      v23 = result;
      v24 = 609;
      goto LABEL_61;
    }
LABEL_27:
    v13 = v28 + 16;
    v14 = v29[0] + 16LL;
LABEL_32:
    v28 = v13;
    v29[0] = v14;
    goto LABEL_33;
  }
  v11 = v28;
  v25 = 0;
  if ( a2 - v28 <= 0xF )
  {
    v19 = 459;
    goto LABEL_46;
  }
  v15 = 8LL * *(unsigned int *)v29[0] + 8;
  if ( v15 > a2 - v28 )
  {
    v21 = 470;
LABEL_51:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64, _QWORD, unsigned int))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_ois_parse_fw_setting",
      v21,
      "Not enough buffer provided %d, %d, %d",
      v15,
      a2,
      v11);
    goto LABEL_60;
  }
  result = cam_sensor_handle_random_write();
  if ( (result & 0x80000000) == 0 )
    goto LABEL_27;
  v22 = "Failed in random write %d";
  v23 = result;
  v24 = 481;
LABEL_61:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    0x100000,
    1,
    "cam_ois_parse_fw_setting",
    v24,
    v22,
    v23);
  result = v23;
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return result;
}
