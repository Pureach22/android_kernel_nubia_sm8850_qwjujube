__int64 __fastcall cam_sensor_i2c_command_parser(int *a1, __int64 a2, __int64 a3, int a4, int *a5)
{
  int v6; // w20
  __int16 v10; // w9
  int v11; // w8
  _QWORD *v12; // x25
  int v13; // w19
  __int64 v14; // x10
  int *v15; // x24
  int cpu_buf; // w0
  size_t v17; // x8
  size_t v18; // x10
  size_t v19; // x26
  unsigned int v20; // w19
  unsigned int *v21; // x27
  unsigned int v22; // w9
  __int64 v23; // x8
  unsigned __int64 v24; // x9
  unsigned int v25; // w6
  __int64 v26; // x6
  int v27; // w6
  __int64 *v28; // x0
  _DWORD *v29; // x9
  __int64 *v30; // x8
  int v31; // w9
  __int64 v32; // x10
  int v33; // w6
  __int64 v34; // x5
  unsigned int v35; // w0
  _QWORD *v36; // x24
  int v37; // w25
  int *v38; // x20
  __int64 v39; // x23
  int *v40; // x21
  __int64 v41; // x28
  __int64 *i2c_ptr; // x0
  int v43; // w9
  unsigned int *v44; // x11
  __int64 v45; // x13
  int v46; // w9
  __int64 *v47; // x8
  __int16 v48; // t1
  int v49; // w24
  int v50; // w19
  __int64 result; // x0
  const char *v52; // x5
  __int64 v53; // x4
  __int64 v54; // x4
  unsigned int v55; // w19
  __int16 v56; // w19
  __int64 v57; // x6
  const char *v58; // x5
  __int64 v59; // x4
  int *v60; // [xsp+10h] [xbp-40h]
  __int16 v61; // [xsp+18h] [xbp-38h]
  unsigned int v62; // [xsp+24h] [xbp-2Ch] BYREF
  __int64 *v63; // [xsp+28h] [xbp-28h] BYREF
  unsigned int v64; // [xsp+34h] [xbp-1Ch] BYREF
  __int64 v65; // [xsp+38h] [xbp-18h] BYREF
  size_t v66[2]; // [xsp+40h] [xbp-10h] BYREF

  v66[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v66[0] = 0;
  if ( a4 < 1 )
  {
    result = 0;
    goto LABEL_93;
  }
  v6 = a4;
  v10 = 0;
  v11 = 0;
  v12 = &unk_393000;
  v65 = 0;
  while ( 1 )
  {
    v14 = v12[458];
    v13 = v10;
    v64 = 0;
    v63 = nullptr;
    if ( (v14 & 0x800000000LL) != 0 && !debug_priority )
    {
      v49 = v10;
      v50 = v11;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v14 & 0x800000000LL,
        4,
        "cam_sensor_i2c_command_parser",
        659,
        "Total cmd Buf in Bytes: %d",
        *(_DWORD *)(a3 + 24LL * v10 + 12));
      v11 = v50;
      v13 = v49;
    }
    v15 = (int *)(a3 + 24LL * v13);
    if ( !v15[3] )
      goto LABEL_4;
    cpu_buf = cam_mem_get_cpu_buf(*v15, &v65, v66);
    if ( (cpu_buf & 0x8000) != 0 )
    {
      v55 = (__int16)cpu_buf;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x800000000LL,
        1,
        "cam_sensor_i2c_command_parser",
        669,
        "cmd hdl failed:%d, Err: %d, Buffer_len: %zd",
        *v15,
        (__int16)cpu_buf,
        v66[0]);
      result = v55;
      goto LABEL_93;
    }
    if ( v66[0] < 8 || (v17 = (unsigned int)v15[1], v66[0] - 8 < v17) )
    {
      v54 = 677;
LABEL_69:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x800000000LL,
        1,
        "cam_sensor_i2c_command_parser",
        v54,
        "buffer provided too small");
      cam_mem_put_cpu_buf(*v15);
      result = 4294967274LL;
      goto LABEL_93;
    }
    v18 = (unsigned int)v15[3];
    v19 = v66[0] - v17;
    if ( v66[0] - v17 < v18 )
    {
      v54 = 686;
      goto LABEL_69;
    }
    v61 = v13;
    if ( (_DWORD)v18 )
      break;
LABEL_3:
    v13 = cpu_buf;
    *(_DWORD *)(a2 + 16) = 1;
    cam_mem_put_cpu_buf(*v15);
    v11 = v13;
    LOWORD(v13) = v61;
LABEL_4:
    v10 = v13 + 1;
    if ( v6 <= (__int16)(v13 + 1) )
    {
      result = (unsigned int)(__int16)v11;
      goto LABEL_93;
    }
  }
  v20 = 0;
  v60 = v15;
  v21 = (unsigned int *)(v65 + ((unsigned int)v17 & 0xFFFFFFFC));
  while ( 1 )
  {
    v24 = v19 - v20;
    if ( v24 <= 7 )
    {
      v52 = "Not enough buffer";
      v53 = 694;
      goto LABEL_83;
    }
    v25 = *((unsigned __int8 *)v21 + 5);
    if ( v25 > 6 )
      break;
    switch ( v25 )
    {
      case 4u:
        if ( !a1 || !v21 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x800000000LL,
            1,
            "cam_sensor_handle_slave_info",
            566,
            "Invalid args");
          goto LABEL_89;
        }
        v33 = *a1;
        if ( *a1 != 3 )
        {
          if ( v33 == 2 )
          {
            *(_WORD *)(**((_QWORD **)a1 + 1) + 2LL) = *v21;
          }
          else
          {
            if ( v33 != 1 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x800000000LL,
                1,
                "cam_sensor_handle_slave_info",
                585,
                "Invalid master type: %d",
                v33);
LABEL_89:
              v58 = "Handle slave info failed with rc: %d";
              v59 = 847;
              goto LABEL_90;
            }
            *(_WORD *)(*((_QWORD *)a1 + 2) + 20LL) = *v21 >> 1;
            *(_DWORD *)(*((_QWORD *)a1 + 2) + 12LL) = *((unsigned __int8 *)v21 + 4);
          }
        }
        cpu_buf = 0;
        v21 += 2;
        v22 = 8;
        break;
      case 5u:
        if ( v24 <= 0xF )
        {
          v52 = "Not enough buffer provided";
          v53 = 711;
          goto LABEL_83;
        }
        v36 = v12;
        v37 = v6;
        v38 = a1;
        v39 = a3;
        v40 = a5;
        v41 = *v21;
        if ( 8 * v41 + 8 > v24 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x800000000LL,
            1,
            "cam_sensor_i2c_command_parser",
            721,
            "Not enough buffer provided");
          goto LABEL_79;
        }
        i2c_ptr = cam_sensor_get_i2c_ptr((__int64 *)a2, v41);
        if ( !i2c_ptr || !*i2c_ptr )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x800000000LL,
            1,
            "cam_sensor_handle_random_write",
            292,
            "Failed in allocating i2c_list");
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x800000000LL,
            1,
            "cam_sensor_i2c_command_parser",
            732,
            "Failed in random write %d",
            -12);
LABEL_79:
          v15 = v60;
          v56 = -22;
          goto LABEL_92;
        }
        *((_DWORD *)i2c_ptr + 16) = 0;
        *((_DWORD *)i2c_ptr + 3) = *((unsigned __int8 *)v21 + 7);
        *((_DWORD *)i2c_ptr + 4) = *((unsigned __int8 *)v21 + 6);
        if ( (_DWORD)v41 )
        {
          v43 = 0;
          do
          {
            v44 = &v21[2 * v43 + 2];
            v45 = 16LL * v43++;
            *(_DWORD *)(*i2c_ptr + v45) = *v44;
            *(_DWORD *)(*i2c_ptr + v45 + 4) = v44[1];
            *(_DWORD *)(*i2c_ptr + v45 + 12) = 0;
          }
          while ( (_DWORD)v41 != v43 );
        }
        v46 = 8 * v41;
        v64 = v41;
        v47 = i2c_ptr + 9;
        a5 = v40;
        a3 = v39;
        a1 = v38;
        v22 = v46 + 8;
        v6 = v37;
        v12 = v36;
        v15 = v60;
        cpu_buf = 0;
        v21 = (unsigned int *)((char *)v21 + v22);
        v63 = v47;
        break;
      case 6u:
        LOWORD(v62) = 0;
        if ( v24 <= 0xF )
        {
          v52 = "Not enough buffer space";
          v53 = 866;
          goto LABEL_83;
        }
        v26 = *v21;
        if ( 8 * v26 + 8 > v24 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x800000000LL,
            1,
            "cam_sensor_i2c_command_parser",
            878,
            "Not enough buffer provided %d, %d, %d",
            8 * v26 + 8,
            v19,
            v20);
          v56 = -22;
          goto LABEL_92;
        }
        cpu_buf = cam_sensor_handle_random_read((__int64)v21, (__int64 *)a2, &v62, &v64, &v63, (__int64)a5, v26);
        if ( (cpu_buf & 0x8000) != 0 )
        {
          v56 = cpu_buf;
          v57 = (unsigned int)(__int16)cpu_buf;
          v58 = "Failed in random read %d";
          v59 = 890;
          goto LABEL_91;
        }
        goto LABEL_15;
      default:
        goto LABEL_70;
    }
LABEL_17:
    v20 += v22;
    if ( v20 >= v15[3] )
      goto LABEL_3;
  }
  if ( v25 == 7 )
  {
    v62 = 0;
    if ( v24 <= 0x13 )
    {
      v52 = "Not enough buffer provided";
      v53 = 753;
    }
    else
    {
      v34 = *v21;
      if ( 8 * v34 + 12 <= v24 )
      {
        v35 = cam_sensor_handle_continuous_write((__int64)v21, (__int64 *)a2, &v62, &v64, &v63, v34);
        if ( (v35 & 0x80000000) != 0 )
        {
          v57 = v35;
          v58 = "Failed in continuous write %d";
          v59 = 776;
          v56 = v35;
          goto LABEL_91;
        }
        v22 = v62;
        cpu_buf = 0;
        v23 = v62 & 0xFFFFFFFC;
        goto LABEL_16;
      }
      v52 = "Not enough buffer provided";
      v53 = 765;
    }
    goto LABEL_83;
  }
  if ( v25 == 8 )
  {
    LOWORD(v62) = 0;
    if ( v24 <= 0xB )
    {
      v52 = "Not enough buffer space";
      v53 = 908;
      goto LABEL_83;
    }
    cpu_buf = cam_sensor_handle_continuous_read((__int64)v21, (__int64 *)a2, &v62, &v64, &v63, a5);
    if ( (cpu_buf & 0x8000) != 0 )
    {
      v56 = cpu_buf;
      v57 = (unsigned int)(__int16)cpu_buf;
      v58 = "Failed in continuous read %d";
      v59 = 931;
      goto LABEL_91;
    }
LABEL_15:
    v22 = (unsigned __int16)v62;
    v23 = (unsigned __int16)v62 & 0xFFFC;
LABEL_16:
    v21 = (unsigned int *)((char *)v21 + v23);
    goto LABEL_17;
  }
  if ( v25 != 9 )
  {
LABEL_70:
    v52 = "Invalid Command Type:%d";
    v53 = 942;
    goto LABEL_83;
  }
  v27 = *((unsigned __int8 *)v21 + 4);
  if ( v27 == 1 )
  {
    if ( v24 > 0x13 )
    {
      v28 = cam_sensor_get_i2c_ptr((__int64 *)a2, 1u);
      if ( !v28 || (v29 = (_DWORD *)*v28, v30 = v28, !*v28) )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x800000000LL,
          1,
          "cam_sensor_handle_poll",
          253,
          "Failed in allocating mem for list");
        v58 = "Random read fail: %d";
        v59 = 822;
        v57 = 4294967284LL;
        v56 = -12;
        goto LABEL_91;
      }
      cpu_buf = 0;
      *((_DWORD *)v30 + 16) = 5;
      *((_DWORD *)v30 + 4) = *(unsigned __int8 *)v21;
      *((_DWORD *)v30 + 3) = *((unsigned __int8 *)v21 + 1);
      *v29 = v21[2];
      *(_DWORD *)(*v30 + 4) = v21[3];
      v31 = *((unsigned __int16 *)v21 + 3);
      v32 = *v30;
      v21 += 5;
      v63 = v30 + 9;
      *(_DWORD *)(v32 + 8) = v31;
      v64 = 1;
      v22 = 20;
      goto LABEL_17;
    }
    v52 = "Not enough buffer space";
    v53 = 794;
LABEL_83:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_i2c_command_parser",
      v53,
      v52);
    v56 = -22;
    goto LABEL_92;
  }
  if ( (v27 & 0xFE) != 2 )
  {
    v52 = "Wrong Wait Command: %d";
    v53 = 828;
    goto LABEL_83;
  }
  if ( !v63 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_handle_delay",
      201,
      "Invalid list ptr");
    goto LABEL_87;
  }
  if ( v64 )
  {
    v48 = *(_WORD *)v21;
    v21 += 2;
    cpu_buf = 0;
    *((_WORD *)v63 - 26) = v48;
    v22 = 8;
    goto LABEL_17;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x800000000LL,
    1,
    "cam_sensor_handle_delay",
    232,
    "Delay Rxed Before any buffer: %d",
    0);
LABEL_87:
  v58 = "delay hdl failed: %d";
  v59 = 810;
LABEL_90:
  v57 = 4294967274LL;
  v56 = -22;
LABEL_91:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    0x800000000LL,
    1,
    "cam_sensor_i2c_command_parser",
    v59,
    v58,
    v57);
LABEL_92:
  cam_mem_put_cpu_buf(*v15);
  result = (unsigned int)v56;
LABEL_93:
  _ReadStatusReg(SP_EL0);
  return result;
}
