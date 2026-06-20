__int64 __fastcall cam_actuator_i2c_pkt_parse(__int64 a1, __int64 a2)
{
  __int64 v3; // x26
  __int64 result; // x0
  int cpu_buf; // w0
  unsigned int v6; // w0
  unsigned int v7; // w20
  unsigned int v8; // w19
  unsigned int *v9; // x1
  unsigned __int64 v10; // x7
  __int64 v11; // x0
  unsigned int v12; // w8
  unsigned __int64 v13; // x6
  int v14; // w6
  const char *v15; // x5
  __int64 v16; // x2
  __int64 v17; // x4
  signed int v18; // w21
  __int64 v19; // x24
  unsigned int v20; // w0
  int *v21; // x20
  unsigned int v22; // w0
  unsigned int v23; // w25
  unsigned int v24; // w0
  unsigned __int64 v25; // x10
  unsigned __int64 v26; // x3
  __int64 v27; // x1
  int v28; // w9
  __int64 v29; // x0
  unsigned int v30; // w0
  unsigned int v31; // w0
  unsigned __int64 v32; // x25
  unsigned int v33; // w6
  int v34; // w6
  unsigned int *v35; // x21
  unsigned int v36; // w9
  unsigned int v37; // w0
  unsigned int buf_to_list; // w0
  unsigned int data; // w0
  unsigned int current_qtimer_ns; // w0
  int v41; // w6
  unsigned int v42; // w0
  __int64 v43; // x12
  __int64 v44; // x9
  __int64 v45; // x1
  unsigned int v46; // w0
  unsigned int v47; // w0
  unsigned int v48; // w0
  __int64 v49; // x8
  unsigned int v50; // w0
  unsigned int updated; // w0
  __int64 v52; // x0
  unsigned int v53; // w0
  unsigned int v54; // w0
  unsigned int *v55; // x9
  unsigned int v56; // w0
  const char *v57; // x5
  __int64 v58; // x4
  __int64 v59; // x6
  const char *v60; // x5
  unsigned int v61; // w6
  __int64 v62; // x4
  const char *v63; // x5
  __int64 v64; // x4
  const char *v65; // x5
  __int64 v66; // x4
  const char *v67; // x5
  unsigned int v68; // w6
  __int64 v69; // x4
  __int64 v70; // [xsp+10h] [xbp-80h]
  __int64 v71; // [xsp+10h] [xbp-80h]
  _QWORD v72[2]; // [xsp+18h] [xbp-78h] BYREF
  __int64 v73; // [xsp+28h] [xbp-68h]
  __int64 v74; // [xsp+30h] [xbp-60h]
  __int64 v75; // [xsp+38h] [xbp-58h]
  __int64 v76; // [xsp+40h] [xbp-50h]
  __int64 v77; // [xsp+48h] [xbp-48h] BYREF
  __int64 v78; // [xsp+50h] [xbp-40h] BYREF
  unsigned __int64 v79; // [xsp+58h] [xbp-38h]
  __int64 v80; // [xsp+60h] [xbp-30h]
  unsigned int *v81; // [xsp+68h] [xbp-28h] BYREF
  __int64 v82; // [xsp+70h] [xbp-20h] BYREF
  __int64 v83; // [xsp+78h] [xbp-18h] BYREF
  _QWORD v84[2]; // [xsp+80h] [xbp-10h] BYREF

  v84[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v83 = 0;
  v84[0] = 0;
  v81 = nullptr;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  v78 = 0;
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_i2c_pkt_parse",
      562,
      "Invalid Args");
    result = 4294967274LL;
    goto LABEL_6;
  }
  v3 = *(_QWORD *)(a1 + 3392);
  if ( !inline_copy_from_user_7(&v78, *(_QWORD *)(a2 + 16)) )
  {
    cpu_buf = cam_mem_get_cpu_buf(v80, &v82, v84);
    if ( cpu_buf < 0 )
    {
      v8 = cpu_buf;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x2000,
        1,
        "cam_actuator_i2c_pkt_parse",
        580,
        "Error in converting command Handle %d",
        cpu_buf);
      result = v8;
      goto LABEL_6;
    }
    if ( v84[0] < 0x40u || v79 >= v84[0] - 64LL )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        0x2000,
        1,
        "cam_actuator_i2c_pkt_parse",
        590,
        "Inval cam_packet strut size: %zu, len_of_buff: %zu",
        64);
      v7 = -22;
      goto LABEL_70;
    }
    v6 = cam_packet_util_copy_pkt_to_kmd(v82 + (unsigned int)v79, &v81, v84[0] - v79);
    if ( v6 )
    {
      v7 = v6;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x2000,
        1,
        "cam_actuator_i2c_pkt_parse",
        600,
        "Copying packet to KMD failed");
      goto LABEL_69;
    }
    if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000,
        4,
        "cam_actuator_i2c_pkt_parse",
        604,
        "Pkt opcode: %d",
        *v81);
    v9 = v81;
    v10 = *(unsigned int *)(a1 + 4664);
    v11 = a1;
    v12 = *v81;
    v13 = *((_QWORD *)v81 + 1);
    if ( (*v81 & 0xFFFFFF) != 0 && (_DWORD)v10 && v13 <= v10 )
    {
      v7 = -53;
      if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x2000,
          4,
          "cam_actuator_i2c_pkt_parse",
          612,
          "reject request %lld, last request to flush %lld",
          v13,
          v10);
      goto LABEL_69;
    }
    if ( v13 > v10 )
    {
      *(_DWORD *)(a1 + 4664) = 0;
      v12 = *v9;
    }
    v14 = v12 & 0xFFFFFF;
    if ( (v12 & 0xFFFFFF) <= 2 )
    {
      if ( v14 )
      {
        if ( v14 == 1 )
        {
          if ( *(_DWORD *)(a1 + 3728) <= 1u )
          {
            v15 = "Not in right state to move lens: %d";
            v16 = 2;
            v17 = 745;
            goto LABEL_67;
          }
          *(_DWORD *)(a1 + 3724) = 0;
          v49 = *((_QWORD *)v9 + 1);
          *(_DWORD *)(a1 + 4224) = 1;
          *(_QWORD *)(a1 + 4232) = v49;
          v50 = cam_sensor_i2c_command_parser(a1 + 32, a1 + 4208, (char *)v9 + (v9[6] & 0xFFFFFFFC) + 56, 1, 0);
          if ( (v50 & 0x80000000) == 0 )
          {
            updated = cam_actuator_update_req_mgr(a1);
            if ( updated )
            {
              v7 = updated;
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x2000,
                1,
                "cam_actuator_i2c_pkt_parse",
                771,
                "Failed in adding request to request manager");
              goto LABEL_69;
            }
            goto LABEL_105;
          }
          v60 = "Auto move lens parsing failed: %d";
          v61 = v50;
          v62 = 765;
          goto LABEL_123;
        }
        if ( v14 == 2 )
        {
          if ( *(_DWORD *)(a1 + 3728) <= 1u )
          {
            v15 = "Not in right state to move lens: %d";
            v16 = 2;
            v17 = 780;
LABEL_67:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x2000,
              v16,
              "cam_actuator_i2c_pkt_parse",
              v17,
              v15);
LABEL_68:
            v7 = -22;
            goto LABEL_69;
          }
          v43 = *(_QWORD *)(a1 + 4448);
          *(_DWORD *)(a1 + 3724) = 1;
          v44 = *((_QWORD *)v9 + 1);
          v45 = v43 + 48 * (v44 & 0x1F);
          *(_QWORD *)(v45 + 24) = v44;
          *(_DWORD *)(v45 + 16) = 1;
          v46 = cam_sensor_i2c_command_parser(a1 + 32, v45, (char *)v81 + (v81[6] & 0xFFFFFFFC) + 56, 1, 0);
          if ( (v46 & 0x80000000) == 0 )
          {
            v47 = cam_actuator_update_req_mgr(a1);
            if ( v47 )
            {
              v7 = v47;
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x2000,
                1,
                "cam_actuator_i2c_pkt_parse",
                808,
                "Failed in adding request to request manager");
              goto LABEL_69;
            }
            goto LABEL_105;
          }
          v60 = "Manual move lens parsing failed: %d";
          v61 = v46;
          v62 = 801;
LABEL_123:
          v7 = v61;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x2000,
            1,
            "cam_actuator_i2c_pkt_parse",
            v62,
            v60);
          goto LABEL_69;
        }
LABEL_64:
        v15 = "Wrong Opcode: %d";
        v16 = 1;
        v17 = 973;
        goto LABEL_67;
      }
      if ( v9[7] )
      {
        v18 = 0;
        v19 = (__int64)v9 + (v9[6] & 0xFFFFFFFC) + 56;
        do
        {
          v21 = (int *)(v19 + 24LL * v18);
          v22 = cam_packet_util_validate_cmd_desc(v21);
          if ( v22 )
          {
            v7 = v22;
            goto LABEL_69;
          }
          v23 = v21[3];
          if ( v23 )
          {
            v24 = cam_mem_get_cpu_buf(*v21, &v83, v84);
            if ( (v24 & 0x80000000) != 0 )
            {
              v7 = v24;
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x2000,
                1,
                "cam_actuator_i2c_pkt_parse",
                638,
                "Failed to get cpu buf");
              goto LABEL_69;
            }
            if ( !v83 )
            {
              v63 = "invalid cmd buf";
              v64 = 643;
              goto LABEL_121;
            }
            if ( v84[0] < 8u || (v25 = (unsigned int)v21[1], v84[0] - 8LL < v25) )
            {
              v63 = "Invalid length for sensor cmd";
              v64 = 652;
LABEL_121:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x2000,
                1,
                "cam_actuator_i2c_pkt_parse",
                v64,
                v63);
              cam_mem_put_cpu_buf(*v21);
              goto LABEL_68;
            }
            v26 = v84[0] - v25;
            v27 = v83 + ((unsigned int)v25 & 0xFFFFFFFC);
            v28 = *(unsigned __int8 *)(v27 + 5);
            if ( (unsigned int)(v28 - 2) >= 2 )
            {
              v29 = a1;
              if ( v28 == 4 )
              {
                if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
                {
                  v71 = v83 + ((unsigned int)v25 & 0xFFFFFFFC);
                  v32 = v84[0] - v25;
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    debug_mdl & 0x2000,
                    4,
                    "cam_actuator_i2c_pkt_parse",
                    664,
                    "Received slave info buffer");
                  v27 = v71;
                  v26 = v32;
                  v29 = a1;
                }
                v30 = cam_actuator_slaveInfo_pkt_parser(v29, (_DWORD *)v27, v26);
                if ( (v30 & 0x80000000) != 0 )
                {
                  v67 = "Failed to parse slave info: %d";
                  v68 = v30;
                  v69 = 669;
                  goto LABEL_128;
                }
              }
              else
              {
                if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
                {
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    debug_mdl & 0x2000,
                    4,
                    "cam_actuator_i2c_pkt_parse",
                    692,
                    "Received initSettings buffer");
                  v29 = a1;
                }
                *(_QWORD *)(v29 + 4232) = 0;
                *(_DWORD *)(v29 + 4224) = 1;
                v31 = cam_sensor_i2c_command_parser(v29 + 32, v29 + 4208, v19 + 24LL * v18, 1, 0);
                if ( (v31 & 0x80000000) != 0 )
                {
                  v67 = "Failed:parse init settings: %d";
                  v68 = v31;
                  v69 = 706;
                  goto LABEL_128;
                }
              }
            }
            else
            {
              if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
              {
                v70 = v83 + ((unsigned int)v25 & 0xFFFFFFFC);
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  debug_mdl & 0x2000,
                  4,
                  "cam_actuator_i2c_pkt_parse",
                  677,
                  "Received power settings buffer");
                v27 = v70;
              }
              v20 = cam_sensor_update_power_settings(v27, v23, v3 + 8);
              if ( v20 )
              {
                v67 = "Failed:parse power settings: %d";
                v68 = v20;
                v69 = 685;
LABEL_128:
                v7 = v68;
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  0x2000,
                  1,
                  "cam_actuator_i2c_pkt_parse",
                  v69,
                  v67);
                cam_mem_put_cpu_buf(*(_DWORD *)(v19 + 24LL * v18));
                goto LABEL_69;
              }
            }
            cam_mem_put_cpu_buf(*v21);
          }
          ++v18;
        }
        while ( v18 < v81[7] );
      }
      v52 = a1;
      if ( *(_DWORD *)(a1 + 3728) == 1 )
      {
        v53 = cam_actuator_power_up(a1);
        if ( (v53 & 0x80000000) != 0 )
        {
          v7 = v53;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x2000,
            1,
            "cam_actuator_i2c_pkt_parse",
            719,
            " Actuator Power up failed");
          goto LABEL_69;
        }
        v52 = a1;
        *(_DWORD *)(a1 + 3728) = 2;
      }
      v54 = cam_actuator_apply_settings(v52, v52 + 4208);
      if ( (v54 & 0x80000000) != 0 )
      {
        v7 = v54;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x2000,
          1,
          "cam_actuator_i2c_pkt_parse",
          728,
          "Cannot apply Init settings");
      }
      else
      {
        v7 = delete_request(a1 + 4208);
        if ( (v7 & 0x80000000) != 0 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x2000,
            2,
            "cam_actuator_i2c_pkt_parse",
            736,
            "Fail in deleting the Init settings");
          v7 = 0;
        }
      }
LABEL_69:
      cam_common_mem_free((__int64)v81);
LABEL_70:
      cam_mem_put_cpu_buf(v80);
      result = v7;
      goto LABEL_6;
    }
    if ( v14 != 3 )
    {
      if ( v14 != 4 )
      {
        if ( v14 == 127 )
        {
          if ( *(_DWORD *)(a1 + 3728) <= 1u )
          {
            v15 = "Received NOP packets in invalid state: %d";
            v16 = 2;
            v17 = 816;
            goto LABEL_67;
          }
          v48 = cam_actuator_update_req_mgr(a1);
          if ( v48 )
          {
            v7 = v48;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x2000,
              1,
              "cam_actuator_i2c_pkt_parse",
              823,
              "Failed in adding request to request manager");
            goto LABEL_69;
          }
LABEL_105:
          v7 = 0;
          goto LABEL_69;
        }
        goto LABEL_64;
      }
      mutex_lock(a1 + 4680);
      if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x2000,
          4,
          "cam_actuator_i2c_pkt_parse",
          922,
          "Receive park lens settings buffer in state: %d",
          *(_DWORD *)(a1 + 3728));
      v34 = *(_DWORD *)(a1 + 3728);
      if ( v34 != 2 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x2000,
          2,
          "cam_actuator_i2c_pkt_parse",
          926,
          "Not in right state to park lens cam_act_state: %d",
          v34);
        goto LABEL_98;
      }
      if ( *(_BYTE *)(a1 + 4728) == 1 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x2000,
          2,
          "cam_actuator_i2c_pkt_parse",
          934,
          "Park lens inprogress and receive unexpected park lens settings");
LABEL_98:
        mutex_unlock(a1 + 4680);
        goto LABEL_68;
      }
      v55 = v81;
      *(_QWORD *)(a1 + 4280) = 0;
      *(_DWORD *)(a1 + 4272) = 1;
      v56 = cam_sensor_i2c_command_parser(a1 + 32, a1 + 4256, (char *)v55 + (v55[6] & 0xFFFFFFFC) + 56, 1, 0);
      if ( (v56 & 0x80000000) != 0 )
      {
        v59 = v56;
        v57 = "Park lens parsing failed: %d";
        v58 = 955;
        v7 = v56;
      }
      else
      {
        *(_BYTE *)(a1 + 4728) = 1;
        *(_DWORD *)(a1 + 4736) = 0;
        v7 = cam_actuator_schedule_park_lens_task(a1);
        if ( !v7 )
        {
LABEL_117:
          mutex_unlock(a1 + 4680);
          goto LABEL_69;
        }
        v57 = "Worker task scheduling failed %d";
        v58 = 964;
        v59 = v7;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        0x2000,
        1,
        "cam_actuator_i2c_pkt_parse",
        v58,
        v57,
        v59);
      goto LABEL_117;
    }
    v33 = *(_DWORD *)(a1 + 3728);
    v76 = 0;
    v77 = 0;
    v74 = 0;
    v75 = 0;
    v73 = 0;
    if ( v33 <= 1 )
    {
      v15 = "Not in right state to read actuator: %d";
      v16 = 2;
      v17 = 836;
      goto LABEL_67;
    }
    if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000,
        4,
        "cam_actuator_i2c_pkt_parse",
        840,
        "number of I/O configs: %d:",
        v9[9]);
      v9 = v81;
      v11 = a1;
      if ( v81[9] )
      {
LABEL_80:
        v72[0] = v72;
        v72[1] = v72;
        v35 = (unsigned int *)((char *)v9 + v9[8] + 56);
        if ( !v35 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x2000,
            1,
            "cam_actuator_i2c_pkt_parse",
            854,
            "I/O config is invalid(NULL)");
          goto LABEL_68;
        }
        v36 = v9[6];
        LODWORD(v73) = 1;
        v74 = 0;
        v37 = cam_sensor_i2c_command_parser(v11 + 32, v72, (char *)v9 + (v36 & 0xFFFFFFFC) + 56, 1, v35);
        if ( (v37 & 0x80000000) != 0 )
        {
          v60 = "actuator read pkt parsing failed: %d";
          v61 = v37;
          v62 = 869;
          goto LABEL_123;
        }
        mutex_lock(a1 + 4784);
        buf_to_list = cam_sensor_util_add_read_buf_to_list(a1 + 4768, *v35);
        if ( (buf_to_list & 0x80000000) != 0 )
        {
          v7 = buf_to_list;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x2000,
            1,
            "cam_actuator_i2c_pkt_parse",
            877,
            "Add read buf to list failed rc:%d",
            buf_to_list);
          mutex_unlock(a1 + 4784);
          goto LABEL_69;
        }
        mutex_unlock(a1 + 4784);
        data = cam_sensor_i2c_read_data(v72, a1 + 32);
        if ( (data & 0x80000000) != 0 )
        {
          v7 = data;
          v65 = "cannot read data, rc:%d";
          v66 = 887;
        }
        else
        {
          if ( v81[9] < 2 )
            goto LABEL_87;
          current_qtimer_ns = cam_sensor_util_get_current_qtimer_ns(&v77);
          if ( (current_qtimer_ns & 0x80000000) != 0 )
          {
            v7 = current_qtimer_ns;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              32,
              1,
              "cam_actuator_i2c_pkt_parse",
              895,
              "failed to get qtimer rc:%d",
              v41);
            goto LABEL_130;
          }
          v42 = cam_sensor_util_write_qtimer_to_io_buffer(v77, v35 + 64);
          if ( (v42 & 0x80000000) == 0 )
          {
LABEL_87:
            v7 = delete_request(v72);
            if ( (v7 & 0x80000000) != 0 )
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x2000,
                1,
                "cam_actuator_i2c_pkt_parse",
                913,
                "Failed in deleting the read settings");
            goto LABEL_69;
          }
          v7 = v42;
          v65 = "write qtimer failed rc: %d";
          v66 = 904;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          0x2000,
          1,
          "cam_actuator_i2c_pkt_parse",
          v66,
          v65,
          v7);
LABEL_130:
        delete_request(v72);
        goto LABEL_69;
      }
    }
    else if ( v9[9] )
    {
      goto LABEL_80;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_i2c_pkt_parse",
      842,
      "No I/O configs to process");
    goto LABEL_68;
  }
  result = 4294967282LL;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
