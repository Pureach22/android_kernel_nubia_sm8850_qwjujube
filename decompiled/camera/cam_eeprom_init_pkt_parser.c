__int64 __fastcall cam_eeprom_init_pkt_parser(__int64 a1, __int64 a2)
{
  __int64 v4; // x28
  __int64 v5; // x0
  unsigned int v6; // w26
  unsigned int v7; // w23
  __int64 v8; // x25
  int *v9; // x19
  __int64 result; // x0
  unsigned __int64 v11; // x25
  unsigned int cpu_buf; // w0
  unsigned __int64 v13; // x9
  unsigned __int64 v14; // x20
  __int16 *v15; // x26
  int v16; // w8
  unsigned int updated; // w0
  unsigned __int64 v18; // x3
  unsigned int v19; // w8
  __int64 v20; // x9
  int v21; // w10
  int v22; // w6
  unsigned __int64 v23; // x11
  signed int v24; // w8
  __int64 v25; // x19
  __int64 v26; // x28
  int v27; // w8
  unsigned __int16 v28; // w10
  int *v29; // x11
  __int64 v30; // x12
  _DWORD *v31; // x13
  int v32; // t1
  int v33; // w14
  int v34; // w8
  _DWORD *v35; // x9
  int v36; // w10
  __int64 v37; // x8
  _DWORD *v38; // x8
  int v39; // w9
  int v40; // w6
  int v41; // w7
  unsigned int v42; // w28
  unsigned int v43; // w19
  const char *v44; // x5
  __int64 v45; // x4
  const char *v46; // x5
  __int64 v47; // x4
  unsigned int v48; // w20
  const char *v49; // x5
  __int64 v50; // x4
  unsigned int v51; // w19
  unsigned __int64 StatusReg; // x19
  __int64 v53; // x20
  __int64 v54; // [xsp+8h] [xbp-48h]
  unsigned int v55; // [xsp+14h] [xbp-3Ch]
  __int64 v56; // [xsp+18h] [xbp-38h]
  int *v57; // [xsp+20h] [xbp-30h]
  __int64 v58; // [xsp+28h] [xbp-28h]
  unsigned __int64 v59; // [xsp+38h] [xbp-18h] BYREF
  _QWORD v60[2]; // [xsp+40h] [xbp-10h] BYREF

  v60[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 3384);
  v59 = 0;
  v60[0] = 0;
  v5 = vzalloc_noprof(800000);
  *(_QWORD *)(a1 + 4304) = v5;
  if ( !v5 )
  {
LABEL_80:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_init_pkt_parser",
      947,
      "failed");
    result = 4294967284LL;
    goto LABEL_81;
  }
LABEL_2:
  if ( *(_DWORD *)(a2 + 28) )
  {
    v6 = 0;
    v7 = -1;
    v58 = v5;
    v54 = a2;
    v8 = a2 + (*(_DWORD *)(a2 + 24) & 0xFFFFFFFC) + 56;
    v56 = v8;
    while ( 1 )
    {
      v9 = (int *)(v8 + 24LL * (int)v6);
      result = cam_packet_util_validate_cmd_desc(v9);
      if ( (_DWORD)result )
        goto LABEL_81;
      v11 = (unsigned int)v9[3];
      if ( (_DWORD)v11 )
        break;
      result = 0;
LABEL_56:
      ++v6;
      v8 = v56;
      if ( v6 >= *(_DWORD *)(a2 + 28) )
        goto LABEL_81;
    }
    cpu_buf = cam_mem_get_cpu_buf(*v9, v60, &v59);
    if ( cpu_buf )
    {
      v51 = cpu_buf;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x10000,
        1,
        "cam_eeprom_init_pkt_parser",
        969,
        "Failed to get cpu buf");
      result = v51;
    }
    else
    {
      if ( v60[0] )
      {
        if ( v59 < 8 || (v13 = (unsigned int)v9[1], v59 - 8 < v13) )
        {
          v49 = "Not enough buffer";
          v50 = 982;
        }
        else
        {
          v14 = v59 - v13;
          if ( v59 - v13 >= v11 )
          {
            v55 = v6;
            v57 = v9;
            a2 = 0;
            v15 = (__int16 *)(v60[0] + ((unsigned int)v13 & 0xFFFFFFFC));
            while ( 1 )
            {
              v18 = v14 - (unsigned int)a2;
              if ( v18 <= 7 )
              {
                v44 = "Not enough buf";
                v45 = 998;
                goto LABEL_63;
              }
              v19 = *((unsigned __int8 *)v15 + 5);
              if ( v19 > 9 )
                goto LABEL_69;
              if ( ((1 << v19) & 0x320) != 0 )
                break;
              if ( ((1 << v19) & 0xC) != 0 )
              {
                updated = cam_sensor_update_power_settings(v15, (unsigned int)v11, v4 + 16);
                if ( updated )
                {
                  v48 = updated;
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    0x10000,
                    1,
                    "cam_eeprom_init_pkt_parser",
                    1043,
                    "Failed");
                  goto LABEL_65;
                }
                v15 += 2 * (v11 >> 2);
                v16 = v11;
              }
              else
              {
                if ( v19 != 4 )
                {
LABEL_69:
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    0x10000,
                    1,
                    "cam_eeprom_init_pkt_parser",
                    1067,
                    "Invalid cmd_type 0x%x",
                    *((unsigned __int8 *)v15 + 5));
                  goto LABEL_64;
                }
                v24 = v7 + 1;
                if ( (int)(v7 + 1) >= 8000 )
                {
                  v44 = "OOB map read error";
                  v45 = 1015;
                  goto LABEL_63;
                }
                if ( (unsigned __int64)(100LL * v24 - 799905) < 0xFFFFFFFFFFF3CAFFLL )
                {
                  __break(1u);
                  StatusReg = _ReadStatusReg(SP_EL0);
                  v53 = *(_QWORD *)(StatusReg + 80);
                  *(_QWORD *)(StatusReg + 80) = &cam_eeprom_init_pkt_parser__alloc_tag;
                  v5 = vzalloc_noprof(800000);
                  *(_QWORD *)(StatusReg + 80) = v53;
                  *(_QWORD *)(a1 + 4304) = v5;
                  if ( !v5 )
                    goto LABEL_80;
                  goto LABEL_2;
                }
                v25 = v4;
                v26 = *(_QWORD *)(a1 + 3384);
                *(_DWORD *)(v58 + 100LL * v24 + 96) = *(_DWORD *)v15;
                *(_WORD *)(v26 + 8) = *(_DWORD *)v15;
                *(_BYTE *)(v26 + 10) = *((_BYTE *)v15 + 4);
                updated = cam_eeprom_update_i2c_info(a1, (unsigned __int16 *)(v26 + 8));
                if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
                {
                  v40 = *(unsigned __int16 *)(v26 + 8);
                  v41 = *(unsigned __int8 *)(v26 + 10);
                  v42 = updated;
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 0x10000,
                    4,
                    "cam_eeprom_update_slaveInfo",
                    405,
                    "Slave addr: 0x%x Freq Mode: %d",
                    v40,
                    v41);
                  updated = v42;
                }
                v15 += 4;
                v16 = 8;
                v4 = v25;
              }
LABEL_14:
              a2 = (unsigned int)(v16 + a2);
              if ( (unsigned int)a2 >= (unsigned int)v11 )
              {
                v43 = updated;
                *(_DWORD *)(a1 + 4312) = v7 + 1;
                cam_mem_put_cpu_buf(*v57);
                a2 = v54;
                v6 = v55;
                result = v43;
                goto LABEL_56;
              }
            }
            v20 = *(_QWORD *)(a1 + 4304);
            v21 = *((unsigned __int8 *)v15 + 4);
            v22 = v7 + 1;
            switch ( v19 )
            {
              case 5u:
                v23 = 16;
                break;
              case 9u:
                v23 = 8;
                break;
              case 8u:
                v23 = 12;
                break;
              default:
                if ( v22 >= 8000 )
                  goto LABEL_60;
                goto LABEL_38;
            }
            if ( v23 > v18 || v22 > 7999 )
            {
LABEL_60:
              v46 = "not enough buffer";
              v47 = 452;
              goto LABEL_61;
            }
LABEL_38:
            switch ( v19 )
            {
              case 9u:
                if ( (v21 & 0xFE) == 2 )
                {
                  if ( v7 >= 0x7FFFFFFF )
                  {
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      0x10000,
                      1,
                      "cam_eeprom_parse_memory_map",
                      525,
                      "invalid map number, num_map=%d",
                      v22);
                    goto LABEL_62;
                  }
                  *(_DWORD *)(v20 + 100LL * (unsigned int)v22 - 8) = *v15;
                  v37 = v20 + 100LL * v7;
                  *(_DWORD *)(v37 + 20) = *v15;
                  *(_DWORD *)(v37 + 44) = *v15;
                  v16 = 8;
                  goto LABEL_13;
                }
                if ( v21 == 1 )
                {
                  v38 = (_DWORD *)(v20 + 100LL * v22);
                  v38[13] = *((_DWORD *)v15 + 2);
                  v38[14] = *((unsigned __int8 *)v15 + 1);
                  v38[15] = *((_DWORD *)v15 + 3);
                  v38[16] = *(unsigned __int8 *)v15;
                  v39 = (unsigned __int16)v15[3];
                  v38[12] = 1;
                  v38[17] = v39;
                  v16 = 20;
                  goto LABEL_13;
                }
                break;
              case 8u:
                v34 = *(_DWORD *)v15;
                if ( *(_DWORD *)v15 >= (unsigned int)~*(_DWORD *)(a1 + 4328) )
                {
                  v46 = "int overflow on eeprom memory block";
                  v47 = 500;
                  goto LABEL_61;
                }
                v35 = (_DWORD *)(v20 + 100LL * v22);
                v35[19] = *((_DWORD *)v15 + 2);
                v35[20] = *((unsigned __int8 *)v15 + 7);
                v36 = *((unsigned __int8 *)v15 + 6);
                v35[18] = v34;
                v35[22] = v36;
                *(_DWORD *)(a1 + 4328) += v34;
                v16 = 12;
                goto LABEL_13;
              case 5u:
                v27 = *(_DWORD *)v15;
                if ( (unsigned int)(*(_DWORD *)v15 - 1) > 0x62 || v22 >= (unsigned int)(8000 - v27) )
                {
                  v46 = "OOB Error";
                  v47 = 465;
                  goto LABEL_61;
                }
                v28 = 8 * (*(_DWORD *)v15 - 1) + 16;
                if ( v18 < (v28 & 0xFFF8u) )
                {
                  v46 = "Not enough buffer remaining";
                  v47 = 473;
LABEL_61:
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    0x10000,
                    1,
                    "cam_eeprom_parse_memory_map",
                    v47,
                    v46);
LABEL_62:
                  v44 = "Parse memory map failed";
                  v45 = 1061;
LABEL_63:
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    0x10000,
                    1,
                    "cam_eeprom_init_pkt_parser",
                    v45,
                    v44);
LABEL_64:
                  v48 = -22;
LABEL_65:
                  v9 = v57;
                  goto LABEL_66;
                }
                v29 = (int *)(v15 + 6);
                v30 = *(unsigned int *)v15;
                do
                {
                  v31 = (_DWORD *)(v20 + 100LL * v22);
                  --v30;
                  ++v22;
                  v31[1] = *(v29 - 1);
                  v31[2] = *((unsigned __int8 *)v15 + 7);
                  v32 = *v29;
                  v29 += 2;
                  v31[3] = v32;
                  v33 = *((unsigned __int8 *)v15 + 6);
                  *v31 = 1;
                  v31[4] = v33;
                }
                while ( v30 );
                v22 = v27 + v7;
                v16 = v28;
                goto LABEL_13;
            }
            v16 = 0;
LABEL_13:
            updated = 0;
            v7 = v22;
            v15 = (__int16 *)((char *)v15 + ((unsigned __int16)v16 & 0xFFFC));
            goto LABEL_14;
          }
          v49 = "Not enough buffer for command";
          v50 = 990;
        }
      }
      else
      {
        v49 = "invalid cmd buf";
        v50 = 974;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x10000,
        1,
        "cam_eeprom_init_pkt_parser",
        v50,
        v49);
      v48 = -22;
LABEL_66:
      cam_mem_put_cpu_buf(*v9);
      result = v48;
    }
  }
  else
  {
    result = 0;
  }
LABEL_81:
  _ReadStatusReg(SP_EL0);
  return result;
}
