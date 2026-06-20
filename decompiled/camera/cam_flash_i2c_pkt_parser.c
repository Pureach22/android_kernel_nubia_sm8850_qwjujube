__int64 __fastcall cam_flash_i2c_pkt_parser(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int cpu_buf; // w0
  unsigned int v5; // w19
  unsigned int v6; // w0
  unsigned int *v7; // x19
  unsigned __int64 v8; // x7
  __int64 v9; // x8
  unsigned int v10; // w9
  unsigned __int64 v11; // x6
  int v12; // w6
  __int64 v13; // x1
  signed int v14; // w27
  __int64 v15; // x24
  __int64 v16; // x21
  unsigned int *v17; // x9
  unsigned int v18; // w0
  const char *v19; // x5
  unsigned int v20; // w6
  __int64 v21; // x4
  __int64 v22; // x10
  unsigned int v23; // w0
  unsigned int v24; // w8
  int v25; // w11
  __int64 v26; // x9
  __int64 v27; // x8
  __int64 (__fastcall *v28)(_QWORD); // x8
  unsigned int v29; // w0
  unsigned int v30; // w0
  int *v31; // x20
  unsigned int v32; // w0
  unsigned int v33; // w19
  unsigned int v34; // w0
  unsigned __int64 v35; // x28
  unsigned __int64 v36; // x21
  __int64 v37; // x8
  __int64 v38; // x1
  int v39; // w9
  unsigned __int64 v40; // x3
  unsigned int updated; // w0
  __int64 v42; // x21
  unsigned __int64 v43; // x28
  unsigned int v44; // w0
  unsigned int v45; // w0
  unsigned int v46; // w0
  _DWORD *v47; // x8
  const char *v48; // x5
  __int64 v49; // x4
  __int64 (__fastcall *v50)(__int64, __int64); // x8
  unsigned int v51; // w0
  _DWORD *v52; // x8
  unsigned int v53; // w0
  const char *v54; // x5
  __int64 v55; // x4
  __int64 v56; // x6
  unsigned int v57; // [xsp+Ch] [xbp-64h]
  __int64 v58; // [xsp+10h] [xbp-60h]
  __int64 v59; // [xsp+18h] [xbp-58h] BYREF
  __int64 v60; // [xsp+20h] [xbp-50h]
  __int64 v61; // [xsp+28h] [xbp-48h]
  __int64 v62; // [xsp+30h] [xbp-40h]
  __int64 v63; // [xsp+38h] [xbp-38h] BYREF
  unsigned __int64 v64; // [xsp+40h] [xbp-30h]
  __int64 v65; // [xsp+48h] [xbp-28h]
  unsigned int *v66; // [xsp+50h] [xbp-20h] BYREF
  unsigned __int64 v67; // [xsp+58h] [xbp-18h] BYREF
  _QWORD v68[2]; // [xsp+60h] [xbp-10h] BYREF

  v68[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v67 = 0;
  v68[0] = 0;
  v66 = nullptr;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v59 = 0;
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_i2c_pkt_parser",
      1273,
      "fctrl/arg is NULL");
    result = 4294967274LL;
    goto LABEL_15;
  }
  if ( !inline_copy_from_user_13(&v63, *(_QWORD *)(a2 + 16)) )
  {
    cpu_buf = cam_mem_get_cpu_buf(v65, v68, &v67);
    if ( cpu_buf )
    {
      v5 = cpu_buf;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_i2c_pkt_parser",
        1288,
        "Failed in getting the packet : %d",
        cpu_buf);
LABEL_14:
      result = v5;
      goto LABEL_15;
    }
    if ( v67 < 0x40 || v64 >= v67 - 64 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_i2c_pkt_parser",
        1297,
        "Inval cam_packet strut size: %zu, len_of_buff: %zu",
        64);
      v5 = -22;
      goto LABEL_13;
    }
    v6 = cam_packet_util_copy_pkt_to_kmd(v68[0] + v64, &v66, v67 - v64);
    if ( v6 )
    {
      v5 = v6;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4096,
        1,
        "cam_flash_i2c_pkt_parser",
        1308,
        "Copying packet to KMD failed");
LABEL_13:
      cam_mem_put_cpu_buf(v65);
      goto LABEL_14;
    }
    v7 = v66;
    v8 = *(unsigned int *)(a1 + 6712);
    v9 = a1;
    v10 = *v66;
    v11 = *((_QWORD *)v66 + 1);
    if ( (*v66 & 0xFFFFFF) != 0 && (_DWORD)v8 && v11 <= v8 )
    {
      v5 = -53;
      if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x1000,
          4,
          "cam_flash_i2c_pkt_parser",
          1318,
          "reject request %lld, last request to flush %lld",
          v11,
          v8);
      goto LABEL_114;
    }
    if ( v11 > v8 )
    {
      *(_DWORD *)(a1 + 6712) = 0;
      v10 = *v7;
    }
    v12 = v10 & 0xFFFFFF;
    if ( (v10 & 0xFFFFFF) > 1 )
    {
      if ( v12 == 2 )
      {
        v16 = v7[6];
        v17 = v7;
        if ( *(_DWORD *)(a1 + 6408) == 1 )
        {
          *(_QWORD *)(a1 + 6416) = 0;
          *(_DWORD *)(a1 + 6408) = 0;
          v18 = delete_request(a1 + 6392);
          if ( v18 )
          {
            v19 = "Failed in Deleting the err: %d";
            v20 = v18;
            v21 = 1521;
LABEL_85:
            v5 = v20;
            goto LABEL_113;
          }
          v17 = v66;
          v9 = a1;
        }
        *(_DWORD *)(v9 + 6408) = 1;
        *(_QWORD *)(v9 + 6416) = *((_QWORD *)v17 + 1);
        v46 = cam_sensor_i2c_command_parser((int *)(v9 + 6280), v9 + 6392, (__int64)v7 + v16 + 56, 1, nullptr);
        if ( v46 )
        {
          v5 = v46;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            4096,
            1,
            "cam_flash_i2c_pkt_parser",
            1534,
            "Failed in parsing i2c NRT packets");
          goto LABEL_114;
        }
        v47 = *(_DWORD **)(a1 + 6216);
        if ( *(v47 - 1) != 1413211269 )
          __break(0x8228u);
        v5 = ((__int64 (__fastcall *)(__int64, _QWORD))v47)(a1, 0);
        if ( !v5 )
          goto LABEL_114;
        v19 = "Apply setting failed: %d";
        v21 = 1540;
LABEL_113:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          4096,
          1,
          "cam_flash_i2c_pkt_parser",
          v21,
          v19);
        goto LABEL_114;
      }
      if ( v12 != 127 )
        goto LABEL_33;
      if ( *(_DWORD *)(a1 + 6200) <= 1u )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          4096,
          2,
          "cam_flash_i2c_pkt_parser",
          1547,
          "Rxed NOP packets without linking");
        v5 = 0;
        *(_DWORD *)(*(_QWORD *)(a1 + 6584) + 48 * (*((_QWORD *)v66 + 1) & 0x1FLL) + 16) = 0;
        goto LABEL_114;
      }
      if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x1000,
          4,
          "cam_flash_i2c_pkt_parser",
          1556,
          "NOP Packet is Received: req_id: %u",
          *((_QWORD *)v7 + 1));
    }
    else
    {
      if ( v12 )
      {
        if ( v12 == 1 )
        {
          v13 = *(_QWORD *)(a1 + 6584) + 48 * (*((_QWORD *)v7 + 1) & 0x1FLL);
          if ( *(_DWORD *)(v13 + 16) == 1 )
          {
            *(_QWORD *)(v13 + 24) = 0;
            *(_DWORD *)(v13 + 16) = 0;
          }
          else
          {
            v22 = v7[6];
            *(_DWORD *)(v13 + 16) = 1;
            *(_QWORD *)(v13 + 24) = *((_QWORD *)v66 + 1);
            v23 = cam_sensor_i2c_command_parser((int *)(a1 + 6280), v13, (__int64)v7 + v22 + 56, 1, nullptr);
            if ( v23 )
            {
              v5 = v23;
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                4096,
                1,
                "cam_flash_i2c_pkt_parser",
                1503,
                "Failed in parsing i2c packets");
              goto LABEL_114;
            }
          }
          goto LABEL_44;
        }
LABEL_33:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4096,
          1,
          "cam_flash_i2c_pkt_parser",
          1561,
          "Wrong Opcode : %d",
          v12);
        v5 = -22;
        goto LABEL_114;
      }
      if ( v7[7] >= 2 )
      {
        v14 = 1;
        v15 = (__int64)v7 + v7[6] + 56;
        do
        {
          v31 = (int *)(v15 + 24LL * v14);
          v32 = cam_packet_util_validate_cmd_desc(v31);
          if ( v32 )
          {
            v5 = v32;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              4096,
              1,
              "cam_flash_i2c_pkt_parser",
              1337,
              "Invalid cmd desc");
            goto LABEL_114;
          }
          v33 = v31[3];
          if ( v33 )
          {
            v34 = cam_mem_get_cpu_buf(*v31, v68, &v67);
            if ( (v34 & 0x80000000) != 0 )
            {
              v5 = v34;
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                4096,
                1,
                "cam_flash_i2c_pkt_parser",
                1347,
                "Failed to get cpu buf");
              goto LABEL_114;
            }
            if ( !v68[0] )
            {
              v48 = "invalid cmd buf";
              v49 = 1352;
              goto LABEL_108;
            }
            v35 = v67;
            if ( v67 < 8 || (v36 = (unsigned int)v31[1], v67 - 8 < v36) )
            {
              v48 = "invalid cmd buf length";
              v49 = 1362;
LABEL_108:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                4096,
                1,
                "cam_flash_i2c_pkt_parser",
                v49,
                v48);
              cam_mem_put_cpu_buf(*v31);
              v5 = -22;
              goto LABEL_114;
            }
            v37 = a1;
            v38 = v68[0] + ((unsigned int)v36 & 0xFFFFFFFC);
            if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
            {
              v58 = v68[0] + ((unsigned int)v36 & 0xFFFFFFFC);
              v57 = v34;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x1000,
                4,
                "cam_flash_i2c_pkt_parser",
                1374,
                "command Type: %d,Total: %d",
                *(unsigned __int8 *)(v38 + 5),
                v33);
              v38 = v58;
              v34 = v57;
              v37 = a1;
            }
            v39 = *(unsigned __int8 *)(v38 + 5);
            v40 = v35 - v36;
            if ( (unsigned int)(v39 - 2) < 2 )
            {
              if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
              {
                v42 = v38;
                v43 = v40;
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  debug_mdl & 0x1000,
                  4,
                  "cam_flash_i2c_pkt_parser",
                  1400,
                  "Received power settings");
                v40 = v43;
                v38 = v42;
                v37 = a1;
              }
              updated = cam_sensor_update_power_settings((__int64 *)v38, v33, v37 + 3608, v40);
              if ( updated )
              {
                v5 = updated;
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  4096,
                  1,
                  "cam_flash_i2c_pkt_parser",
                  1407,
                  "Failed update power settings");
                goto LABEL_120;
              }
LABEL_56:
              cam_mem_put_cpu_buf(*v31);
              goto LABEL_57;
            }
            if ( v39 == 4 )
            {
              v30 = cam_flash_slaveInfo_pkt_parser(v37);
              if ( (v30 & 0x80000000) != 0 )
              {
                v56 = v30;
                v54 = "Failed parsing slave info: rc: %d";
                v55 = 1393;
                v5 = v30;
                goto LABEL_118;
              }
              goto LABEL_56;
            }
            if ( v39 == 10 )
            {
              if ( v67 <= 7 )
              {
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  4096,
                  1,
                  "cam_flash_i2c_pkt_parser",
                  1379,
                  "Not enough buffer");
                v5 = -22;
LABEL_120:
                cam_mem_put_cpu_buf(*v31);
                goto LABEL_114;
              }
              v5 = v34;
              *(_BYTE *)(v37 + 6204) = *(_DWORD *)v38;
            }
            else
            {
              if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
              {
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  debug_mdl & 0x1000,
                  4,
                  "cam_flash_i2c_pkt_parser",
                  1413,
                  "Received initSettings");
                v37 = a1;
              }
              *(_DWORD *)(v37 + 6360) = 1;
              *(_QWORD *)(v37 + 6368) = 0;
              v5 = cam_sensor_i2c_command_parser((int *)(v37 + 6280), v37 + 6344, v15 + 24LL * v14, 1, nullptr);
              if ( (v5 & 0x80000000) != 0 )
              {
                v54 = "pkt parsing failed: %d";
                v55 = 1425;
                v56 = v5;
LABEL_118:
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                  3,
                  4096,
                  1,
                  "cam_flash_i2c_pkt_parser",
                  v55,
                  v54,
                  v56);
                goto LABEL_120;
              }
            }
            cam_mem_put_cpu_buf(*v31);
            if ( v5 )
              goto LABEL_114;
          }
LABEL_57:
          ++v14;
        }
        while ( v14 < v66[7] );
      }
      v44 = msm_camera_fill_vreg_params(a1 + 24, *(char **)(a1 + 3616), *(_WORD *)(a1 + 3624));
      if ( v44 )
      {
        v19 = "failed to fill vreg params for power up rc:%d";
        v20 = v44;
        v21 = 1449;
        goto LABEL_85;
      }
      v45 = msm_camera_fill_vreg_params(a1 + 24, *(char **)(a1 + 3632), *(_WORD *)(a1 + 3640));
      if ( v45 )
      {
        v5 = v45;
        v19 = "failed to fill vreg params power down rc:%d";
        v21 = 1461;
        goto LABEL_113;
      }
      v50 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 6224);
      if ( *((_DWORD *)v50 - 1) != 1815403504 )
        __break(0x8228u);
      v51 = v50(a1, 1);
      if ( v51 )
      {
        v5 = v51;
        v19 = "Enable Regulator Failed rc = %d";
        v21 = 1468;
        goto LABEL_113;
      }
      v52 = *(_DWORD **)(a1 + 6216);
      if ( *(v52 - 1) != 1413211269 )
        __break(0x8228u);
      v53 = ((__int64 (__fastcall *)(__int64, _QWORD))v52)(a1, 0);
      if ( v53 )
      {
        v5 = v53;
        v19 = "cannot apply settings rc = %d";
        v21 = 1474;
        goto LABEL_113;
      }
      *(_DWORD *)(a1 + 6200) = 2;
    }
LABEL_44:
    v24 = *v66 & 0xFFFFF;
    if ( v24 != 127 && v24 != 1 )
      goto LABEL_99;
    v61 = 0;
    v62 = 0;
    v25 = *(_DWORD *)(a1 + 6024);
    v26 = *((_QWORD *)v66 + 1);
    LODWORD(v59) = *(_DWORD *)(a1 + 6032);
    HIDWORD(v59) = v25;
    v60 = v26;
    if ( v24 == 1 )
    {
      LOBYTE(v62) = 1;
      LODWORD(v61) = 1;
    }
    v27 = *(_QWORD *)(a1 + 6096);
    if ( !v27 )
      goto LABEL_99;
    v28 = *(__int64 (__fastcall **)(_QWORD))(v27 + 16);
    if ( !v28 )
      goto LABEL_99;
    if ( *((_DWORD *)v28 - 1) != -1947527126 )
      __break(0x8228u);
    v29 = v28(&v59);
    if ( v29 )
    {
      v5 = v29;
      if ( v29 == -53 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4096,
          3,
          "cam_flash_i2c_pkt_parser",
          1588,
          "Failed in adding request: %llu to request manager, it has been flushed",
          *((_QWORD *)v66 + 1));
      else
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4096,
          1,
          "cam_flash_i2c_pkt_parser",
          1592,
          "Failed in adding request: %llu to request manager",
          *((_QWORD *)v66 + 1));
      goto LABEL_114;
    }
    v5 = 0;
    if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000,
        4,
        "cam_flash_i2c_pkt_parser",
        1597,
        "add req %lld to req_mgr, trigger_eof %d",
        v60,
        (unsigned __int8)v62);
LABEL_99:
      v5 = 0;
    }
LABEL_114:
    cam_common_mem_free((__int64)v66);
    goto LABEL_13;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    4096,
    1,
    "cam_flash_i2c_pkt_parser",
    1281,
    "Copy cmd handle from user failed");
  result = 4294967282LL;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
