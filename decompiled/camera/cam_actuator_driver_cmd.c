__int64 __fastcall cam_actuator_driver_cmd(__int64 a1, __int64 a2)
{
  int v2; // w6
  __int64 v3; // x24
  int v6; // w6
  __int64 v7; // x1
  int v8; // w8
  unsigned int v9; // w20
  int v10; // w8
  const char *v11; // x5
  __int64 v12; // x2
  __int64 v13; // x4
  __int64 v14; // x0
  const char *v15; // x5
  __int64 v16; // x4
  __int64 v17; // x23
  __int64 v18; // x24
  int v19; // w6
  unsigned int v20; // w0
  int v21; // w6
  const char *v22; // x5
  __int64 v23; // x4
  int device_hdl; // w0
  int v26; // w9
  __int16 v27; // w8
  unsigned int v28; // w0
  _QWORD *v29; // x0
  _QWORD *v30; // x0
  __int128 v31; // [xsp+8h] [xbp-48h] BYREF
  __int64 v32; // [xsp+18h] [xbp-38h]
  __int64 v33; // [xsp+20h] [xbp-30h]
  __int64 v34; // [xsp+28h] [xbp-28h]
  _QWORD v35[4]; // [xsp+30h] [xbp-20h] BYREF

  v35[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v2 = *(_DWORD *)(a2 + 8);
    if ( v2 == 1 )
    {
      v3 = *(_QWORD *)(a1 + 3392);
      if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x2000,
          4,
          "cam_actuator_driver_cmd",
          1056,
          "Opcode to Actuator: %d",
          *(_DWORD *)a2);
      mutex_lock(a1 + 3672);
      v6 = *(_DWORD *)a2;
      v7 = a2;
      if ( *(int *)a2 <= 259 )
      {
        switch ( v6 )
        {
          case 257:
            v14 = *(_QWORD *)(a2 + 16);
            *(_QWORD *)&v31 = *(unsigned int *)(a1 + 116);
            if ( !inline_copy_to_user_5(v14, &v31, 8) )
            {
LABEL_30:
              v9 = 0;
              goto LABEL_53;
            }
            v15 = "Failed Copy to User";
            v16 = 1180;
            break;
          case 258:
            v19 = *(_DWORD *)(a1 + 3728);
            memset(v35, 0, 24);
            *((_QWORD *)&v31 + 1) = 0;
            if ( v19 && *(_BYTE *)(a1 + 4728) == 1 )
            {
              if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x2000,
                  4,
                  "cam_actuator_driver_cmd",
                  1067,
                  "Wait for park done in state: %d",
                  v19);
              v9 = cam_actuator_wait_for_park_done(a1);
              v7 = a2;
              if ( v9 )
                goto LABEL_53;
            }
            if ( *(_DWORD *)(a1 + 4584) != -1 )
            {
              v11 = "Device is already acquired";
              v12 = 1;
              v13 = 1074;
              goto LABEL_39;
            }
            v9 = inline_copy_from_user_7(v35, *(_QWORD *)(v7 + 16));
            if ( (v9 & 0x80000000) != 0 )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x2000,
                1,
                "cam_actuator_driver_cmd",
                1082,
                "Failed Copying from user\n");
              goto LABEL_53;
            }
            *(_QWORD *)((char *)&v31 + 4) = 0;
            LODWORD(v31) = v35[0];
            v33 = a1 + 4600;
            v34 = a1;
            v32 = 0x2000;
            device_hdl = cam_create_device_hdl((__int64)&v31);
            HIDWORD(v35[0]) = device_hdl;
            if ( device_hdl )
            {
              v26 = v35[0];
              v27 = debug_mdl;
              *(_DWORD *)(a1 + 4584) = device_hdl;
              *(_DWORD *)(a1 + 4588) = v26;
              if ( (v27 & 0x2000) != 0 && !debug_priority )
                ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  v27 & 0x2000,
                  4,
                  "cam_actuator_driver_cmd",
                  1105,
                  "Device Handle: %d",
                  device_hdl);
              if ( !inline_copy_to_user_5(*(_QWORD *)(a2 + 16), v35, 24) )
              {
                *(_BYTE *)(a1 + 4728) = 0;
                *(_DWORD *)(a1 + 3728) = 1;
                goto LABEL_53;
              }
              v15 = "Failed Copy to User";
              v16 = 1109;
            }
            else
            {
              v15 = "Can not create device handle";
              v16 = 1097;
            }
            break;
          case 259:
            if ( *(_DWORD *)(a1 + 3728) == 2 )
            {
              v8 = 3;
              v9 = 0;
LABEL_49:
              *(_DWORD *)(a1 + 4664) = 0;
              *(_DWORD *)(a1 + 3728) = v8;
              goto LABEL_53;
            }
            v22 = "Not in right state to start : %d";
            v23 = 1191;
LABEL_51:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x2000,
              2,
              "cam_actuator_driver_cmd",
              v23,
              v22);
            goto LABEL_52;
          default:
            goto LABEL_29;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x2000,
          1,
          "cam_actuator_driver_cmd",
          v16,
          v15);
        v9 = -14;
        goto LABEL_53;
      }
      if ( v6 == 260 )
      {
        if ( *(_DWORD *)(a1 + 3728) == 3 )
        {
          v17 = 0;
          v9 = 0;
          do
          {
            v18 = *(_QWORD *)(a1 + 4448);
            if ( *(_DWORD *)(v18 + v17 + 16) == 1 )
            {
              v9 = delete_request(v18 + v17);
              if ( (v9 & 0x80000000) != 0 )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  32,
                  1,
                  "cam_actuator_driver_cmd",
                  1218,
                  "delete request: %lld rc: %d",
                  *(_QWORD *)(v18 + v17 + 24),
                  v9);
            }
            v17 += 48;
          }
          while ( v17 != 1536 );
          v8 = 2;
          goto LABEL_49;
        }
        v22 = "Not in right state to stop : %d";
        v23 = 1206;
        goto LABEL_51;
      }
      if ( v6 != 261 )
      {
        if ( v6 != 262 )
        {
LABEL_29:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x2000,
            1,
            "cam_actuator_driver_cmd",
            1268,
            "Invalid Opcode %d",
            v6);
          goto LABEL_30;
        }
        v10 = *(_DWORD *)(a1 + 3728);
        if ( v10 != 3 )
        {
          if ( *(_DWORD *)(a1 + 4584) != -1 )
          {
            if ( v10 == 2 )
            {
              if ( *(_BYTE *)(a1 + 4728) == 1 )
              {
                if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    debug_mdl & 0x2000,
                    4,
                    "cam_actuator_driver_cmd",
                    1136,
                    "Actuator park in deferred task");
              }
              else
              {
                v28 = cam_actuator_power_down(a1);
                if ( (v28 & 0x80000000) != 0 )
                {
                  v9 = v28;
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    0x2000,
                    1,
                    "cam_actuator_driver_cmd",
                    1141,
                    "Actuator Power Down Failed");
                  goto LABEL_53;
                }
                *(_DWORD *)(a1 + 3728) = 0;
                v29 = *(_QWORD **)(v3 + 16);
                if ( mem_trace_en == 1 )
                  cam_mem_trace_free(v29, 0);
                else
                  kvfree(v29);
                v30 = *(_QWORD **)(v3 + 32);
                if ( mem_trace_en == 1 )
                  cam_mem_trace_free(v30, 0);
                else
                  kvfree(v30);
                *(_QWORD *)(v3 + 16) = 0;
                *(_QWORD *)(v3 + 32) = 0;
                *(_WORD *)(v3 + 40) = 0;
                *(_WORD *)(v3 + 24) = 0;
              }
            }
            if ( *(_DWORD *)(a1 + 4592) == -1 )
            {
              v9 = cam_destroy_device_hdl(*(unsigned int *)(a1 + 4584));
              if ( (v9 & 0x80000000) != 0 )
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  0x2000,
                  1,
                  "cam_actuator_driver_cmd",
                  1166,
                  "destroying the device hdl");
              *(_DWORD *)(a1 + 4664) = 0;
              *(_QWORD *)(a1 + 4584) = -1;
              *(_DWORD *)(a1 + 4592) = -1;
            }
            else
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                0x2000,
                1,
                "cam_actuator_driver_cmd",
                1159,
                "Device [%d] still active on link 0x%x",
                *(unsigned int *)(a1 + 3728));
              v9 = -11;
            }
            goto LABEL_53;
          }
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x2000,
            1,
            "cam_actuator_driver_cmd",
            1129,
            "link hdl: %d device hdl: %d",
            -1,
            *(_DWORD *)(a1 + 4592));
          goto LABEL_52;
        }
        v11 = "Cant release actuator: in start state";
        v12 = 2;
        v13 = 1122;
LABEL_39:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x2000,
          v12,
          "cam_actuator_driver_cmd",
          v13,
          v11);
LABEL_52:
        v9 = -22;
        goto LABEL_53;
      }
      *(_DWORD *)(a1 + 3724) = 1;
      v9 = cam_actuator_i2c_pkt_parse(a1, a2);
      if ( (v9 & 0x80000000) != 0 )
      {
        if ( v9 == -53 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x2000,
            3,
            "cam_actuator_driver_cmd",
            1232,
            "Failed in actuator Parsing, it has been flushed");
          v9 = -53;
        }
        else
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x2000,
            1,
            "cam_actuator_driver_cmd",
            1235,
            "Failed in actuator Parsing");
        }
        goto LABEL_53;
      }
      if ( *(_DWORD *)(a1 + 3724) )
      {
LABEL_53:
        mutex_lock(a1 + 4784);
        cam_sensor_util_release_read_buf(a1 + 4768);
        mutex_unlock(a1 + 4784);
        mutex_unlock(a1 + 3672);
        goto LABEL_54;
      }
      v20 = cam_actuator_apply_settings(a1, a1 + 4208);
      v21 = v20;
      if ( v20 == -11 )
      {
        if ( *(_DWORD *)(a1 + 32) != 1 )
        {
          v21 = -11;
LABEL_78:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x2000,
            1,
            "cam_actuator_driver_cmd",
            1255,
            "Failed to apply Init settings: rc = %d",
            v21);
LABEL_79:
          v9 = delete_request(a1 + 4208);
          if ( (v9 & 0x80000000) != 0 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x2000,
              1,
              "cam_actuator_driver_cmd",
              1261,
              "Failed in Deleting the Init Pkt: %d",
              v9);
          goto LABEL_53;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          0x2000,
          2,
          "cam_actuator_driver_cmd",
          1246,
          "CCI HW is in resetting mode:: Reapplying Init settings",
          v20);
        usleep_range_state(1000, 1010, 2);
        v21 = cam_actuator_apply_settings(a1, a1 + 4208);
      }
      if ( (v21 & 0x80000000) == 0 )
        goto LABEL_79;
      goto LABEL_78;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_driver_cmd",
      1052,
      "Invalid handle type: %d",
      v2);
    v9 = -22;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_driver_cmd",
      1041,
      "Invalid Args");
    v9 = -22;
  }
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return v9;
}
