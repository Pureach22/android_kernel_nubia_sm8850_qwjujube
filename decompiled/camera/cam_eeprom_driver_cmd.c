__int64 __fastcall cam_eeprom_driver_cmd(__int64 a1, __int64 a2)
{
  int v2; // w6
  int v5; // w9
  int v6; // w9
  const char *v7; // x5
  __int64 v8; // x4
  __int64 result; // x0
  int v10; // w6
  __int64 v11; // x0
  unsigned int v12; // w20
  int v13; // w10
  unsigned __int64 StatusReg; // x9
  __int64 v15; // x8
  unsigned __int64 v16; // x10
  unsigned __int64 v17; // x10
  unsigned __int64 v23; // x9
  __int64 v24; // x0
  unsigned __int64 v25; // x8
  unsigned __int64 v27; // x9
  const char *v28; // x5
  __int64 v29; // x4
  __int64 v30; // x1
  __int64 v31; // x21
  unsigned int cpu_buf; // w0
  int device_hdl; // w0
  int v34; // w9
  int v35; // w8
  unsigned __int64 v36; // x9
  __int64 v37; // x8
  unsigned __int64 v38; // x10
  unsigned __int64 v39; // x10
  unsigned __int64 v41; // x9
  __int64 v42; // x0
  unsigned __int64 v43; // x8
  unsigned __int64 v45; // x9
  unsigned int v46; // w0
  unsigned int v47; // w6
  unsigned int inited; // w0
  unsigned int *v49; // x0
  unsigned int v50; // w0
  unsigned int v51; // w0
  const char *v52; // x5
  __int64 v53; // x1
  __int64 v54; // x2
  __int64 v55; // x4
  _QWORD *v56; // x0
  _QWORD *v57; // x0
  unsigned int *v58; // x0
  unsigned int memory_map; // w0
  __int64 v60; // x0
  int v61; // w8
  __int64 v62; // x4
  __int64 v63; // x0
  unsigned int v64; // w0
  unsigned int v65; // w0
  unsigned int v66; // w0
  unsigned int matched; // w0
  unsigned int memory; // w0
  int cal_data; // w0
  __int64 v70; // x0
  __int64 v71; // x0
  _QWORD *v72; // x0
  _QWORD *v73; // x0
  int v74; // [xsp+10h] [xbp-60h]
  __int64 v75; // [xsp+18h] [xbp-58h] BYREF
  unsigned __int64 v76; // [xsp+20h] [xbp-50h]
  __int64 v77; // [xsp+28h] [xbp-48h]
  __int64 v78; // [xsp+30h] [xbp-40h]
  __int64 v79; // [xsp+38h] [xbp-38h]
  _QWORD v80[3]; // [xsp+40h] [xbp-30h] BYREF
  unsigned int *v81; // [xsp+58h] [xbp-18h] BYREF
  _QWORD v82[2]; // [xsp+60h] [xbp-10h] BYREF

  v82[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v2 = *(_DWORD *)(a2 + 8);
    if ( v2 == 1 )
    {
      mutex_lock(a1 + 40);
      v5 = *(_DWORD *)a2;
      if ( *(int *)a2 <= 260 )
      {
        if ( v5 == 257 )
        {
          v13 = *(_DWORD *)(a1 + 108);
          StatusReg = _ReadStatusReg(SP_EL0);
          v15 = *(_QWORD *)(a2 + 16);
          v74 = v13;
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0
            || (v16 = *(_QWORD *)(a2 + 16), (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          {
            v16 = v15 & (v15 << 8 >> 8);
          }
          if ( v16 > 0x7FFFFFFFF8LL )
            goto LABEL_27;
          v17 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v23 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v23);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v17);
          v24 = _arch_copy_to_user(v15 & 0xFF7FFFFFFFFFFFFFLL);
          v25 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v27 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v27 - 4096);
          _WriteStatusReg(TTBR1_EL1, v27);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v25);
          if ( v24 )
          {
LABEL_27:
            v28 = "Failed Copy to User";
            v29 = 1515;
LABEL_58:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x10000,
              1,
              "cam_eeprom_driver_cmd",
              v29,
              v28);
            v12 = -14;
            goto LABEL_59;
          }
          v12 = 0;
          if ( (debug_mdl & 0x10000) == 0 || debug_priority )
            goto LABEL_59;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x10000,
            4,
            "cam_eeprom_driver_cmd",
            1519,
            "eeprom_cap: ID: %d",
            v74);
          goto LABEL_21;
        }
        if ( v5 == 258 )
        {
          v6 = *(_DWORD *)(a1 + 4208);
          memset(v80, 0, sizeof(v80));
          v76 = 0;
          if ( v6 == -1 )
          {
            if ( inline_copy_from_user_9(v80, *(_QWORD *)(a2 + 16)) )
            {
              v7 = "EEPROM:ACQUIRE_DEV: copy from user failed";
              v8 = 352;
            }
            else
            {
              v75 = LODWORD(v80[0]);
              v78 = a1 + 4224;
              v79 = a1;
              v77 = 0x10000;
              device_hdl = cam_create_device_hdl((__int64)&v75);
              HIDWORD(v80[0]) = device_hdl;
              if ( device_hdl )
              {
                v34 = v80[0];
                v35 = debug_mdl;
                *(_DWORD *)(a1 + 4208) = device_hdl;
                *(_DWORD *)(a1 + 4212) = v34;
                if ( (v35 & 0x10000) != 0 && !debug_priority )
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    *(_QWORD *)&v35 & 0x10000LL,
                    4,
                    "cam_eeprom_get_dev_handle",
                    372,
                    "Device Handle: %d",
                    device_hdl);
                v36 = _ReadStatusReg(SP_EL0);
                v37 = *(_QWORD *)(a2 + 16);
                if ( (*(_BYTE *)(v36 + 70) & 0x20) != 0
                  || (v38 = *(_QWORD *)(a2 + 16), (*(_QWORD *)v36 & 0x4000000) != 0) )
                {
                  v38 = v37 & (v37 << 8 >> 8);
                }
                if ( v38 <= 0x7FFFFFFFE8LL )
                {
                  v39 = _ReadStatusReg(DAIF);
                  __asm { MSR             DAIFSet, #3 }
                  v41 = *(_QWORD *)(v36 + 8);
                  _WriteStatusReg(TTBR1_EL1, v41 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                  _WriteStatusReg(TTBR0_EL1, v41);
                  __isb(0xFu);
                  _WriteStatusReg(DAIF, v39);
                  v42 = _arch_copy_to_user(v37 & 0xFF7FFFFFFFFFFFFFLL);
                  v43 = _ReadStatusReg(DAIF);
                  __asm { MSR             DAIFSet, #3 }
                  v45 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                  _WriteStatusReg(TTBR0_EL1, v45 - 4096);
                  _WriteStatusReg(TTBR1_EL1, v45);
                  __isb(0xFu);
                  _WriteStatusReg(DAIF, v43);
                  if ( !v42 )
                  {
                    v12 = 0;
                    *(_DWORD *)(a1 + 4292) = 1;
                    goto LABEL_59;
                  }
                }
                v7 = "EEPROM:ACQUIRE_DEV: copy to user failed";
                v8 = 375;
              }
              else
              {
                v7 = "Can not create device handle";
                v8 = 366;
              }
            }
          }
          else
          {
            v7 = "Device is already acquired";
            v8 = 345;
          }
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x10000,
            1,
            "cam_eeprom_get_dev_handle",
            v8,
            v7);
          v28 = "Failed to acquire dev";
          v29 = 1524;
          goto LABEL_58;
        }
LABEL_18:
        v12 = 0;
        if ( (debug_mdl & 0x10000) == 0 || debug_priority )
          goto LABEL_59;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x10000,
          4,
          "cam_eeprom_driver_cmd",
          1563,
          "invalid opcode");
LABEL_21:
        v12 = 0;
LABEL_59:
        mutex_unlock(a1 + 40);
        result = v12;
        goto LABEL_60;
      }
      if ( v5 != 261 )
      {
        if ( v5 == 262 )
        {
          v10 = *(_DWORD *)(a1 + 4292);
          if ( v10 == 1 )
          {
            v11 = *(unsigned int *)(a1 + 4208);
            if ( (_DWORD)v11 == -1 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x10000,
                1,
                "cam_eeprom_driver_cmd",
                1542,
                "Invalid Handles: link hdl: %d device hdl: %d",
                -1,
                *(_DWORD *)(a1 + 4216));
              v12 = -22;
            }
            else
            {
              v12 = cam_destroy_device_hdl(v11);
              if ( (v12 & 0x80000000) != 0 )
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  0x10000,
                  1,
                  "cam_eeprom_driver_cmd",
                  1549,
                  "failed in destroying the device hdl");
              *(_DWORD *)(a1 + 4292) = 0;
              *(_QWORD *)(a1 + 4208) = -1;
              *(_DWORD *)(a1 + 4216) = -1;
            }
          }
          else
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x10000,
              2,
              "cam_eeprom_driver_cmd",
              1534,
              "Not in right state to release : %d",
              v10);
            v12 = -22;
          }
          goto LABEL_59;
        }
        goto LABEL_18;
      }
      v30 = *(_QWORD *)(a2 + 16);
      v31 = *(_QWORD *)(a1 + 3384);
      v76 = 0;
      v77 = 0;
      v75 = 0;
      v80[0] = 0;
      v81 = nullptr;
      v82[0] = 0;
      if ( inline_copy_from_user_9(&v75, v30) )
      {
        v12 = -14;
LABEL_55:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x10000,
          1,
          "cam_eeprom_driver_cmd",
          1558,
          "Failed in eeprom pkt Parsing");
        goto LABEL_59;
      }
      cpu_buf = cam_mem_get_cpu_buf(v77, v80, v82);
      if ( cpu_buf )
      {
        v12 = cpu_buf;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x10000,
          1,
          "cam_eeprom_pkt_parse",
          1251,
          "error in converting command Handle Error: %d",
          cpu_buf);
        goto LABEL_55;
      }
      if ( v82[0] < 0x40u || v76 >= v82[0] - 64LL )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          0x10000,
          1,
          "cam_eeprom_pkt_parse",
          1261,
          "Inval cam_packet strut size: %zu, len_of_buff: %zu",
          64);
        v12 = -22;
        goto LABEL_54;
      }
      v46 = cam_packet_util_copy_pkt_to_kmd(v80[0] + (unsigned int)v76, &v81, v82[0] - v76);
      if ( v46 )
      {
        v12 = v46;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x10000,
          1,
          "cam_eeprom_pkt_parse",
          1271,
          "Copying packet to KMD failed");
LABEL_54:
        cam_mem_put_cpu_buf(v77);
        goto LABEL_55;
      }
      v47 = *v81 & 0xFFFFFF;
      if ( v47 == 1 )
      {
        v49 = v81;
        *(_DWORD *)(a1 + 4360) = 1;
        v50 = cam_eeprom_parse_write_memory_packet(v49, a1);
        if ( (v50 & 0x80000000) == 0 )
        {
          v51 = cam_eeprom_power_up(a1, v31 + 16);
          if ( v51 )
          {
            v12 = v51;
            v52 = "failed power up rc %d";
            v53 = 0x10000;
            v54 = 1;
            v55 = 1372;
LABEL_70:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              v53,
              v54,
              "cam_eeprom_pkt_parse",
              v55,
              v52,
              v12);
LABEL_71:
            vfree(*(_QWORD *)(a1 + 4320));
            *(_QWORD *)(a1 + 4320) = 0;
LABEL_72:
            v56 = *(_QWORD **)(v31 + 24);
            if ( mem_trace_en == 1 )
              cam_mem_trace_free(v56, 0);
            else
              kvfree(v56);
            v57 = *(_QWORD **)(v31 + 40);
            if ( mem_trace_en == 1 )
              cam_mem_trace_free(v57, 0);
            else
              kvfree(v57);
            *(_QWORD *)(v31 + 24) = 0;
            *(_QWORD *)(v31 + 40) = 0;
            vfree(*(_QWORD *)(a1 + 4304));
            v58 = v81;
            *(_QWORD *)(a1 + 4304) = 0;
            *(_DWORD *)(a1 + 4328) = 0;
            *(_DWORD *)(a1 + 4312) = 0;
            *(_DWORD *)(a1 + 4292) = 1;
            cam_common_mem_free((__int64)v58);
            goto LABEL_54;
          }
          usleep_range_state(10000, 11000, 2);
          if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x10000,
              4,
              "cam_eeprom_pkt_parse",
              1380,
              "Calling Erase : %d start Address: 0x%x size: %d",
              0,
              *(_DWORD *)(a1 + 4392),
              *(_DWORD *)(a1 + 4396));
          v65 = camera_io_dev_erase(a1 + 3664, *(unsigned int *)(a1 + 4392), *(unsigned int *)(a1 + 4396));
          if ( (v65 & 0x80000000) != 0 )
          {
            v12 = v65;
            v52 = "Failed in erase : %d";
            v53 = 0x10000;
            v54 = 1;
            v55 = 1386;
            goto LABEL_70;
          }
          usleep_range_state(10000, 11000, 2);
          v66 = cam_eeprom_write(a1);
          if ( (v66 & 0x80000000) != 0 )
          {
            v12 = v66;
            v52 = "Failed: rc : %d";
            v53 = 0x10000;
            v54 = 1;
            v55 = 1395;
            goto LABEL_70;
          }
          v12 = cam_eeprom_power_down(a1);
          if ( v12 )
          {
            v52 = "failed power down rc %d";
            v53 = 0x10000;
            v54 = 1;
            v55 = 1401;
            goto LABEL_70;
          }
LABEL_99:
          cam_common_mem_free((__int64)v81);
          cam_mem_put_cpu_buf(v77);
          if ( !v12 )
            goto LABEL_59;
          goto LABEL_55;
        }
        v62 = 1365;
        v12 = v50;
      }
      else
      {
        if ( v47 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x10000,
            1,
            "cam_eeprom_pkt_parse",
            1409,
            "Invalid op-code 0x%x",
            v47);
          v12 = -22;
          goto LABEL_99;
        }
        if ( (*(_BYTE *)(a1 + 4296) & 1) != 0 )
        {
          inited = cam_eeprom_init_pkt_parser(a1);
          if ( inited )
          {
            v12 = inited;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x10000,
              1,
              "cam_eeprom_pkt_parse",
              1302,
              "Failed in parsing the pkt");
            goto LABEL_99;
          }
          v63 = vzalloc_noprof(*(unsigned int *)(a1 + 4328));
          *(_QWORD *)(a1 + 4320) = v63;
          if ( !v63 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x10000,
              1,
              "cam_eeprom_pkt_parse",
              1310,
              "failed");
            v12 = -12;
            goto LABEL_72;
          }
          v64 = cam_eeprom_power_up(a1, v31 + 16);
          if ( v64 )
          {
            v12 = v64;
            v52 = "failed rc %d";
            v53 = 0x10000;
            v54 = 1;
            v55 = 1317;
            goto LABEL_70;
          }
          if ( *(_DWORD *)(a1 + 4288) == 2 )
          {
            matched = cam_eeprom_match_id(a1);
            if ( matched )
            {
              v12 = matched;
              if ( (debug_mdl & 0x10000) == 0 || debug_priority )
                goto LABEL_71;
              v52 = "eeprom not matching %d";
              v53 = debug_mdl & 0x10000;
              v54 = 4;
              v55 = 1325;
              goto LABEL_70;
            }
          }
          *(_DWORD *)(a1 + 4292) = 2;
          memory = cam_eeprom_read_memory(a1, (__int64 *)(a1 + 4304));
          if ( memory )
          {
            v12 = memory;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x10000,
              1,
              "cam_eeprom_pkt_parse",
              1334,
              "read_eeprom_memory failed");
            cam_eeprom_power_down(a1);
            goto LABEL_71;
          }
          cal_data = cam_eeprom_get_cal_data(a1, v81);
          if ( cal_data )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x10000,
              2,
              "cam_eeprom_pkt_parse",
              1340,
              "failed to get calibration data rc %d",
              cal_data);
          v12 = cam_eeprom_power_down(a1);
          v70 = *(_QWORD *)(a1 + 4320);
          *(_DWORD *)(a1 + 4292) = 1;
          vfree(v70);
          v71 = *(_QWORD *)(a1 + 4304);
          *(_QWORD *)(a1 + 4320) = 0;
          vfree(v71);
          *(_QWORD *)(a1 + 4304) = 0;
          v72 = *(_QWORD **)(v31 + 24);
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v72, 0);
          else
            kvfree(v72);
          v73 = *(_QWORD **)(v31 + 40);
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v73, 0);
          else
            kvfree(v73);
          *(_QWORD *)(v31 + 24) = 0;
          *(_QWORD *)(v31 + 40) = 0;
          *(_WORD *)(v31 + 32) = 0;
          *(_WORD *)(v31 + 48) = 0;
          *(_DWORD *)(a1 + 4328) = 0;
          *(_DWORD *)(a1 + 4312) = 0;
          goto LABEL_99;
        }
        memory_map = cam_eeprom_parse_read_memory_map(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 744LL), a1);
        if ( (memory_map & 0x80000000) == 0 )
        {
          v12 = cam_eeprom_get_cal_data(a1, v81);
          if ( v12 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x10000,
              2,
              "cam_eeprom_pkt_parse",
              1287,
              "failed to get calibration data rc %d",
              v12);
          vfree(*(_QWORD *)(a1 + 4320));
          v60 = *(_QWORD *)(a1 + 4304);
          *(_QWORD *)(a1 + 4320) = 0;
          vfree(v60);
          *(_QWORD *)(a1 + 4304) = 0;
          v61 = debug_mdl;
          *(_DWORD *)(a1 + 4328) = 0;
          *(_DWORD *)(a1 + 4312) = 0;
          if ( (v61 & 0x10000) != 0 && !debug_priority )
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              *(_QWORD *)&v61 & 0x10000LL,
              4,
              "cam_eeprom_pkt_parse",
              1296,
              "Returning the data using kernel probe");
          goto LABEL_99;
        }
        v12 = memory_map;
        v62 = 1281;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x10000,
        1,
        "cam_eeprom_pkt_parse",
        v62,
        "Failed: rc : %d");
      goto LABEL_99;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_driver_cmd",
      1496,
      "Invalid handle type: %d",
      v2);
    result = 4294967274LL;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_driver_cmd",
      1490,
      "Invalid Arguments");
    result = 4294967274LL;
  }
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}
