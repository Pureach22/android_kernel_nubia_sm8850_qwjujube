__int64 __fastcall cam_eeprom_parse_write_memory_packet(__int64 a1, __int64 a2)
{
  __int64 v3; // x23
  int v4; // w19
  int v5; // w22
  __int64 v6; // x25
  __int64 v7; // x26
  int *v8; // x19
  unsigned int v9; // w0
  unsigned __int64 v10; // x27
  unsigned int cpu_buf; // w0
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x21
  int v14; // w22
  unsigned int v15; // w28
  unsigned int v16; // w24
  _QWORD *v17; // x25
  unsigned int *v18; // x19
  unsigned __int64 v19; // x9
  int v20; // w8
  __int64 v21; // x6
  int v22; // w8
  __int64 v23; // x1
  __int64 v24; // x23
  __int64 v25; // x24
  int v26; // w8
  _QWORD *v27; // x1
  _QWORD *v28; // x0
  int v29; // w8
  unsigned int v30; // w23
  int v31; // w8
  int v32; // w8
  unsigned int v33; // w8
  const char *v34; // x5
  __int64 v35; // x4
  _QWORD *v36; // x8
  __int64 v37; // x9
  bool v38; // zf
  const char *v39; // x5
  __int64 v40; // x4
  const char *v41; // x5
  __int64 v42; // x1
  __int64 v43; // x4
  __int64 v44; // x6
  int v46; // w19
  __int64 v47; // [xsp+18h] [xbp-48h]
  __int64 v48; // [xsp+20h] [xbp-40h]
  int v49; // [xsp+2Ch] [xbp-34h]
  __int64 v50; // [xsp+30h] [xbp-30h]
  int *v51; // [xsp+38h] [xbp-28h]
  int v52; // [xsp+44h] [xbp-1Ch]
  unsigned __int64 v53; // [xsp+48h] [xbp-18h] BYREF
  _QWORD v54[2]; // [xsp+50h] [xbp-10h] BYREF

  v3 = a1;
  v54[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 + 24);
  v53 = 0;
  v54[0] = 0;
  if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10000,
      4,
      "cam_eeprom_parse_write_memory_packet",
      732,
      "Number of Command Buffers: %d",
      *(_DWORD *)(a1 + 28));
    if ( *(_DWORD *)(v3 + 28) )
      goto LABEL_4;
LABEL_109:
    v16 = 0;
    goto LABEL_110;
  }
  if ( !*(_DWORD *)(a1 + 28) )
    goto LABEL_109;
LABEL_4:
  v5 = 0;
  v48 = v3;
  v6 = v3 + (v4 & 0xFFFFFFFC) + 56;
  v7 = a2 + 4344;
  _ReadStatusReg(SP_EL0);
  v47 = v6;
  while ( 1 )
  {
    v8 = (int *)(v6 + 24LL * v5);
    v9 = cam_packet_util_validate_cmd_desc(v8);
    if ( v9 )
    {
      v16 = v9;
      goto LABEL_110;
    }
    v10 = (unsigned int)v8[3];
    if ( (_DWORD)v10 )
      break;
    v16 = 0;
LABEL_64:
    if ( (unsigned int)++v5 >= *(_DWORD *)(v3 + 28) )
      goto LABEL_110;
  }
  cpu_buf = cam_mem_get_cpu_buf(*v8, v54, &v53);
  if ( cpu_buf )
  {
    v16 = cpu_buf;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_parse_write_memory_packet",
      753,
      "Failed to get cpu buf");
    goto LABEL_110;
  }
  if ( !v54[0] )
  {
    v39 = "invalid cmd buf";
    v40 = 759;
    goto LABEL_96;
  }
  if ( v53 < 8 || (v12 = (unsigned int)v8[1], v53 - 8 < v12) )
  {
    v39 = "Not enough buffer";
    v40 = 767;
LABEL_96:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_parse_write_memory_packet",
      v40,
      v39);
    goto LABEL_97;
  }
  v13 = v53 - v12;
  if ( v53 - v12 < v10 )
  {
    v39 = "Not enough buffer for command";
    v40 = 776;
    goto LABEL_96;
  }
  v49 = v5;
  v14 = *(_DWORD *)(a2 + 3664);
  v51 = v8;
  v15 = 0;
  v16 = 0;
  v17 = nullptr;
  v18 = (unsigned int *)(v54[0] + ((unsigned int)v12 & 0xFFFFFFFC));
  v50 = *(_QWORD *)(a2 + 3680);
  v52 = v14;
  while ( 1 )
  {
    v19 = v13 - v15;
    if ( v19 <= 7 )
    {
      v34 = "Not Enough buffer";
      v35 = 786;
      goto LABEL_74;
    }
    v20 = *((unsigned __int8 *)v18 + 5);
    v21 = *((unsigned __int8 *)v18 + 4);
    if ( v20 != 4 )
      break;
    switch ( v14 )
    {
      case 3:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x10000,
          1,
          "cam_eeprom_parse_write_memory_packet",
          819,
          "No Need of Slave Info");
        break;
      case 2:
        *(_WORD *)(**(_QWORD **)(a2 + 3672) + 2LL) = *v18;
        if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x10000,
            4,
            "cam_eeprom_parse_write_memory_packet",
            816,
            "Slave addr: 0x%x",
            *v18);
        break;
      case 1:
        *(_DWORD *)(v50 + 12) = v21;
        v26 = debug_mdl;
        *(_WORD *)(v50 + 20) = *v18 >> 1;
        if ( (v26 & 0x10000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            *(_QWORD *)&v26 & 0x10000LL,
            4,
            "cam_eeprom_parse_write_memory_packet",
            810,
            "Slave addr: 0x%x Freq Mode: %d",
            *v18,
            *((unsigned __int8 *)v18 + 4));
        break;
      default:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x10000,
          1,
          "cam_eeprom_parse_write_memory_packet",
          823,
          "Invalid Master type: %d",
          v14);
        goto LABEL_75;
    }
    v15 += 8;
    v18 += 2;
LABEL_15:
    if ( v15 >= (unsigned int)v10 )
    {
      cam_mem_put_cpu_buf(*v51);
      v6 = v47;
      v3 = v48;
      v5 = v49;
      goto LABEL_64;
    }
  }
  if ( v20 != 7 )
  {
    if ( v20 != 9 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x10000,
        1,
        "cam_eeprom_parse_write_memory_packet",
        900,
        "Invalid Cmd_type rxed: %d\n",
        *((unsigned __int8 *)v18 + 5));
      v16 = -22;
      goto LABEL_15;
    }
    if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
    {
      v46 = *((unsigned __int8 *)v18 + 4);
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x10000,
        4,
        "cam_eeprom_parse_write_memory_packet",
        866,
        "CAMERA_SENSOR_CMD_TYPE_WAIT");
      LODWORD(v21) = v46;
    }
    v8 = v51;
    if ( (v21 & 0xFE) == 2 )
    {
      if ( v17 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          32,
          1,
          "cam_eeprom_handle_delay",
          695,
          "Delay Rxed before any buffer: %d",
          0);
      else
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          32,
          1,
          "cam_eeprom_handle_delay",
          674,
          "Invalid list ptr");
      v41 = "delay hdl failed: %d";
      v42 = 0x10000;
      v43 = 881;
      v44 = 4294967274LL;
      v16 = -22;
      goto LABEL_90;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_parse_write_memory_packet",
      891,
      "Wrong Wait Command: %d",
      v21);
LABEL_97:
    v16 = -22;
    goto LABEL_98;
  }
  if ( v19 <= 0x13 )
  {
    v34 = "Not enough buf";
    v35 = 840;
LABEL_74:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_parse_write_memory_packet",
      v35,
      v34);
LABEL_75:
    v8 = v51;
    v16 = -22;
    goto LABEL_98;
  }
  v22 = debug_priority;
  v23 = debug_mdl & 0x10000;
  if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      v23,
      4,
      "cam_eeprom_parse_write_memory_packet",
      846,
      "CAMERA_SENSOR_CMD_TYPE_I2C_CONT_WR",
      v21);
    v22 = debug_priority;
    v23 = debug_mdl & 0x10000;
    if ( (debug_mdl & 0x10000) == 0 )
      goto LABEL_27;
  }
  else if ( !v23 )
  {
    goto LABEL_27;
  }
  if ( !v22 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v23,
      4,
      "cam_eeprom_handle_continuous_write",
      600,
      "Total Size: %d",
      *v18);
LABEL_27:
  v24 = *v18;
  if ( mem_trace_en == 1 )
  {
    v25 = cam_mem_trace_alloc(88, 0xCC0u, 0, "cam_eeprom_get_i2c_ptr", 0x237u);
    if ( !v25 )
      goto LABEL_85;
  }
  else
  {
    v25 = _kvmalloc_node_noprof(88, 0, 3520, 0xFFFFFFFFLL);
    if ( !v25 )
      goto LABEL_85;
  }
  v17 = (_QWORD *)(v25 + 72);
  v27 = *(_QWORD **)(a2 + 4352);
  if ( v25 + 72 == v7 || v27 == v17 || *v27 != v7 )
  {
    _list_add_valid_or_report(v25 + 72);
  }
  else
  {
    *(_QWORD *)(a2 + 4352) = v17;
    *(_QWORD *)(v25 + 72) = v7;
    *(_QWORD *)(v25 + 80) = v27;
    *v27 = v17;
  }
  if ( mem_trace_en == 1 )
    v28 = (_QWORD *)cam_mem_trace_alloc(v24, 0xCC0u, 0, "cam_eeprom_get_i2c_ptr", 0x240u);
  else
    v28 = (_QWORD *)_kvmalloc_node_noprof(v24, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(v25 + 48) = v28;
  if ( v28 )
  {
    *(_DWORD *)(v25 + 56) = v24;
    v29 = *((unsigned __int8 *)v18 + 4);
    v30 = *v18;
    if ( v29 == 3 )
    {
      v31 = 1;
    }
    else
    {
      if ( v29 != 5 )
      {
        if ( (mem_trace_en & 1) != 0 )
          cam_mem_trace_free(v28, 0);
        else
          kvfree(v28);
        v8 = v51;
        if ( mem_trace_en == 1 )
          cam_mem_trace_free((_QWORD *)v25, 0);
        else
          kvfree(v25);
        v16 = -22;
        goto LABEL_89;
      }
      v31 = 2;
    }
    *(_DWORD *)(v25 + 64) = v31;
    *(_DWORD *)(v25 + 60) = *((unsigned __int8 *)v18 + 7);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_handle_continuous_write",
      630,
      "Write Address: 0x%x",
      v18[2]);
    if ( *(_DWORD *)(v25 + 64) == 2 )
    {
      *(_DWORD *)(v25 + 64) = 0;
      *(_DWORD *)(a2 + 4392) = v18[2];
      v32 = debug_mdl;
      *(_DWORD *)(a2 + 4396) = *v18;
      if ( (v32 & 0x10000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          *(_QWORD *)&v32 & 0x10000LL,
          4,
          "cam_eeprom_handle_continuous_write",
          638,
          "Header Count: %d",
          *v18);
      *(_DWORD *)(a2 + 4400) = 1;
      *(_DWORD *)(v25 + 40) = v18[2];
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x10000,
        1,
        "cam_eeprom_handle_continuous_write",
        644,
        "Burst Mode Not Supported\n");
    }
    v14 = v52;
    v16 = 0;
    v33 = 8 * v30 + 12;
    v18 = (unsigned int *)((char *)v18 + v33);
    v15 += v33;
    goto LABEL_15;
  }
  v36 = *(_QWORD **)(v25 + 80);
  if ( (_QWORD *)*v36 == v17 && (v37 = *v17, *(_QWORD **)(*v17 + 8LL) == v17) )
  {
    *(_QWORD *)(v37 + 8) = v36;
    *v36 = v37;
  }
  else
  {
    _list_del_entry_valid_or_report(v25 + 72);
  }
  v38 = mem_trace_en == 1;
  *(_QWORD *)(v25 + 72) = 0xDEAD000000000100LL;
  *(_QWORD *)(v25 + 80) = 0xDEAD000000000122LL;
  if ( v38 )
    cam_mem_trace_free((_QWORD *)v25, 0);
  else
    kvfree(v25);
LABEL_85:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    32,
    1,
    "cam_eeprom_handle_continuous_write",
    606,
    "Failed in allocating i2c_list");
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(nullptr, 0);
  else
    kvfree(0);
  v8 = v51;
  v16 = -12;
LABEL_89:
  v41 = "Failed in continuous write %d";
  v42 = 32;
  v43 = 854;
  v44 = v16;
LABEL_90:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    v42,
    1,
    "cam_eeprom_parse_write_memory_packet",
    v43,
    v41,
    v44);
LABEL_98:
  cam_mem_put_cpu_buf(*v8);
LABEL_110:
  _ReadStatusReg(SP_EL0);
  return v16;
}
