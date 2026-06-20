__int64 __fastcall i2c_write(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  char *v4; // x24
  char *v8; // x27
  __int64 result; // x0
  char *v10; // x20
  unsigned int *v11; // x2
  unsigned int v12; // w8
  __int64 v13; // x0
  int v14; // w0
  int *v15; // x0
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x6
  int v21; // w0
  const char *v22; // x21
  __int64 v23; // x22
  size_t v24; // x0
  size_t v25; // x2
  __int64 v26; // x19
  __int64 v27; // x22
  size_t v28; // x2
  __int64 v29; // x19
  __int64 v30; // x22
  size_t v31; // x2
  __int64 v32; // x19
  __int64 v33; // x22
  size_t v34; // x2
  __int64 v35; // x19
  __int64 v36; // x22
  size_t v37; // x2
  __int64 v38; // x19
  unsigned int *v39; // x21
  __int64 v40; // [xsp+18h] [xbp-F8h]
  _BYTE v41[4]; // [xsp+24h] [xbp-ECh] BYREF
  _QWORD v42[2]; // [xsp+28h] [xbp-E8h] BYREF
  unsigned int *v43; // [xsp+38h] [xbp-D8h] BYREF
  __int64 v44; // [xsp+40h] [xbp-D0h] BYREF
  __int64 v45; // [xsp+48h] [xbp-C8h] BYREF
  __int64 v46; // [xsp+50h] [xbp-C0h]
  __int64 v47; // [xsp+58h] [xbp-B8h]
  unsigned int v48; // [xsp+64h] [xbp-ACh] BYREF
  char s[8]; // [xsp+68h] [xbp-A8h] BYREF
  __int64 v50; // [xsp+70h] [xbp-A0h]
  __int64 v51; // [xsp+78h] [xbp-98h]
  __int64 v52; // [xsp+80h] [xbp-90h]
  __int64 v53; // [xsp+88h] [xbp-88h]
  __int64 v54; // [xsp+90h] [xbp-80h]
  __int64 v55; // [xsp+98h] [xbp-78h]
  __int64 v56; // [xsp+A0h] [xbp-70h]
  __int64 v57; // [xsp+A8h] [xbp-68h]
  __int64 v58; // [xsp+B0h] [xbp-60h]
  __int64 v59; // [xsp+B8h] [xbp-58h]
  __int64 v60; // [xsp+C0h] [xbp-50h]
  __int64 v61; // [xsp+C8h] [xbp-48h]
  __int64 v62; // [xsp+D0h] [xbp-40h]
  __int64 v63; // [xsp+D8h] [xbp-38h]
  __int64 v64; // [xsp+E0h] [xbp-30h]
  __int64 v65; // [xsp+E8h] [xbp-28h]
  _QWORD v66[4]; // [xsp+F0h] [xbp-20h]

  v4 = (char *)&unk_3C6000;
  v66[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41[0] = 0;
  if ( !display_buf )
  {
    result = -22;
    goto LABEL_115;
  }
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42[1] = 0;
  v43 = nullptr;
  v42[0] = 0;
  if ( mem_trace_en == 1 )
  {
    v8 = (char *)cam_mem_trace_alloc(150, 0xCC0u, 0, "i2c_write", 0xD9u);
    if ( !v8 )
      goto LABEL_27;
  }
  else
  {
    v8 = (char *)_kvmalloc_node_noprof(150, 0, 3520, 0xFFFFFFFFLL);
    if ( !v8 )
    {
LABEL_27:
      result = -12;
      goto LABEL_115;
    }
  }
  if ( mem_trace_en == 1 )
  {
    v10 = (char *)cam_mem_trace_alloc(3000, 0xCC0u, 0, "i2c_write", 0xDCu);
    if ( v10 )
      goto LABEL_9;
LABEL_18:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v8, 0);
    else
      kvfree(v8);
    goto LABEL_27;
  }
  v10 = (char *)_kvmalloc_node_noprof(3000, 0, 3520, 0xFFFFFFFFLL);
  if ( !v10 )
    goto LABEL_18;
LABEL_9:
  memset((void *)display_buf, 0, 0xBB8u);
  v43 = (unsigned int *)v42;
  v40 = simple_write_to_buffer(v10, 2999, a4, a2, a3);
  v10[v40 + 1] = 0;
  v48 = 0;
  *(_DWORD *)s = 0;
  if ( !*v10 )
    goto LABEL_32;
  v11 = v43;
  if ( (debug_mdl & 0x20) != 0 && !debug_priority )
  {
    v39 = v43;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "cam_sensor_module_parse_line",
      107,
      "Sensor debugfs string: %s",
      v10);
    v11 = v39;
  }
  v12 = (unsigned __int8)*v10;
  if ( v12 > 0x71 )
  {
    if ( v12 == 119 )
      goto LABEL_28;
    if ( v12 != 114 )
      goto LABEL_32;
LABEL_22:
    if ( sscanf(v10 + 2, "%x,%d,%d,%d,%d", v11, (char *)&v44 + 4, &v45, s, &v48) != 5 )
      goto LABEL_32;
    v13 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _BYTE *))cam_sensor_module_get_io_master)(
            *(unsigned int *)s,
            v48,
            v41);
    if ( (v41[0] & 1) != 0 )
    {
      v14 = camera_io_dev_read(v13, *v43, (__int64)(v43 + 1), HIDWORD(v44), (unsigned int)v45, 0);
      if ( v14 )
        snprintf(v8, 0x96u, "Error, rc: %zu\n", v14);
      else
        snprintf(v8, 0x96u, "Read data: 0x%X\n", v43[1]);
      goto LABEL_118;
    }
    goto LABEL_116;
  }
  if ( v12 == 82 )
    goto LABEL_22;
  if ( v12 != 87 )
  {
LABEL_32:
    sized_strscpy(
      display_buf,
      "Read format: r/R, reg_addr(hex), addr_type, data_type, device_type, instance_id (ID pair)\n"
      "Write format: w/W, reg_addr(hex), reg_value(hex), delay, addr_type, data_type, device_type, instance_id (ID pair)\n");
    if ( display_buf )
    {
      v22 = (const char *)(display_buf + 204);
      *(_QWORD *)((char *)v66 + 6) = 0;
      v65 = 0;
      v66[0] = 0;
      v63 = 0;
      v64 = 0;
      v61 = 0;
      v62 = 0;
      v59 = 0;
      v60 = 0;
      v57 = 0;
      v58 = 0;
      v55 = 0;
      v56 = 0;
      v53 = 0;
      v54 = 0;
      v51 = 0;
      v52 = 0;
      *(_QWORD *)s = 0;
      v50 = 0;
      if ( dword_3C6460 >= 1 )
      {
        v23 = 0;
        while ( v23 != 16 )
        {
          snprintf(
            s,
            0x96u,
            "Device: %s, \t %u, state: %d, ID(device_type, instance_number): %d, %d\n",
            *((const char **)&devices + v23),
            *(_DWORD *)(*((_QWORD *)&devices + v23) + 116LL),
            *(_DWORD *)(*((_QWORD *)&devices + v23) + 3728LL),
            0,
            v23);
          v4 = (char *)strnlen(v22, 0xAECu);
          if ( v4 == (char *)-1LL )
            goto LABEL_120;
          v24 = strnlen(s, 0x96u);
          if ( v24 >= 0x97 )
            goto LABEL_122;
          if ( v24 == 150 )
            goto LABEL_121;
          if ( (unsigned __int64)v4 <= 0xAEB )
          {
            if ( (unsigned __int64)&v4[v24] >= 0xAEC )
              v25 = 2795LL - (_QWORD)v4;
            else
              v25 = v24;
            if ( (unsigned __int64)&v4[v24] >= 0xAEC )
              v26 = 2795;
            else
              v26 = (__int64)&v4[v24];
            memcpy(&v4[(_QWORD)v22], s, v25);
            v22[v26] = 0;
          }
          if ( ++v23 >= dword_3C6460 )
            goto LABEL_48;
        }
LABEL_119:
        __break(0x5512u);
LABEL_120:
        _fortify_panic(2, -1, v4 + 1);
LABEL_121:
        v24 = _fortify_panic(4, 150, 151);
LABEL_122:
        _fortify_panic(2, 150, v24 + 1);
      }
LABEL_48:
      *(_QWORD *)((char *)v66 + 6) = 0;
      v65 = 0;
      v66[0] = 0;
      v63 = 0;
      v64 = 0;
      v61 = 0;
      v62 = 0;
      v59 = 0;
      v60 = 0;
      v57 = 0;
      v58 = 0;
      v55 = 0;
      v56 = 0;
      v53 = 0;
      v54 = 0;
      v51 = 0;
      v52 = 0;
      *(_QWORD *)s = 0;
      v50 = 0;
      if ( dword_3C6464 >= 1 )
      {
        v27 = 0;
        while ( v27 != 16 )
        {
          snprintf(
            s,
            0x96u,
            "Device: %s, \t\t %u, state: %d, ID(device_type, instance_number): %d, %d\n",
            *((const char **)&devices + v27 + 16),
            *(_DWORD *)(*((_QWORD *)&devices + v27 + 16) + 108LL),
            *(_DWORD *)(*((_QWORD *)&devices + v27 + 16) + 4292LL),
            1,
            v27);
          v4 = (char *)strnlen(v22, 0xAECu);
          if ( v4 == (char *)-1LL )
            goto LABEL_120;
          v24 = strnlen(s, 0x96u);
          if ( v24 >= 0x97 )
            goto LABEL_122;
          if ( v24 == 150 )
            goto LABEL_121;
          if ( (unsigned __int64)v4 <= 0xAEB )
          {
            if ( (unsigned __int64)&v4[v24] >= 0xAEC )
              v28 = 2795LL - (_QWORD)v4;
            else
              v28 = v24;
            if ( (unsigned __int64)&v4[v24] >= 0xAEC )
              v29 = 2795;
            else
              v29 = (__int64)&v4[v24];
            memcpy(&v4[(_QWORD)v22], s, v28);
            v22[v29] = 0;
          }
          if ( ++v27 >= dword_3C6464 )
            goto LABEL_63;
        }
        goto LABEL_119;
      }
LABEL_63:
      *(_QWORD *)((char *)v66 + 6) = 0;
      v65 = 0;
      v66[0] = 0;
      v63 = 0;
      v64 = 0;
      v61 = 0;
      v62 = 0;
      v59 = 0;
      v60 = 0;
      v57 = 0;
      v58 = 0;
      v55 = 0;
      v56 = 0;
      v53 = 0;
      v54 = 0;
      v51 = 0;
      v52 = 0;
      *(_QWORD *)s = 0;
      v50 = 0;
      if ( dword_3C6468 >= 1 )
      {
        v30 = 0;
        while ( v30 != 16 )
        {
          snprintf(
            s,
            0x96u,
            "Device: %s, \t\t %u, state: %d, ID(device_type, instance_number): %d, %d\n",
            *((const char **)&devices + v30 + 32),
            *(_DWORD *)(*((_QWORD *)&devices + v30 + 32) + 44LL),
            *(_DWORD *)(*((_QWORD *)&devices + v30 + 32) + 6200LL),
            2,
            v30);
          v4 = (char *)strnlen(v22, 0xAECu);
          if ( v4 == (char *)-1LL )
            goto LABEL_120;
          v24 = strnlen(s, 0x96u);
          if ( v24 >= 0x97 )
            goto LABEL_122;
          if ( v24 == 150 )
            goto LABEL_121;
          if ( (unsigned __int64)v4 <= 0xAEB )
          {
            if ( (unsigned __int64)&v4[v24] >= 0xAEC )
              v31 = 2795LL - (_QWORD)v4;
            else
              v31 = v24;
            if ( (unsigned __int64)&v4[v24] >= 0xAEC )
              v32 = 2795;
            else
              v32 = (__int64)&v4[v24];
            memcpy(&v4[(_QWORD)v22], s, v31);
            v22[v32] = 0;
          }
          if ( ++v30 >= dword_3C6468 )
            goto LABEL_78;
        }
        goto LABEL_119;
      }
LABEL_78:
      *(_QWORD *)((char *)v66 + 6) = 0;
      v65 = 0;
      v66[0] = 0;
      v63 = 0;
      v64 = 0;
      v61 = 0;
      v62 = 0;
      v59 = 0;
      v60 = 0;
      v57 = 0;
      v58 = 0;
      v55 = 0;
      v56 = 0;
      v53 = 0;
      v54 = 0;
      v51 = 0;
      v52 = 0;
      *(_QWORD *)s = 0;
      v50 = 0;
      if ( dword_3C646C >= 1 )
      {
        v33 = 0;
        while ( v33 != 16 )
        {
          snprintf(
            s,
            0x96u,
            "Device: %s, \t\t %u, state: %d, ID(device_type, instance_number): %d, %d\n",
            *((const char **)&devices + v33 + 48),
            *(_DWORD *)(*((_QWORD *)&devices + v33 + 48) + 100LL),
            *(_DWORD *)(*((_QWORD *)&devices + v33 + 48) + 4512LL),
            3,
            v33);
          v4 = (char *)strnlen(v22, 0xAECu);
          if ( v4 == (char *)-1LL )
            goto LABEL_120;
          v24 = strnlen(s, 0x96u);
          if ( v24 >= 0x97 )
            goto LABEL_122;
          if ( v24 == 150 )
            goto LABEL_121;
          if ( (unsigned __int64)v4 <= 0xAEB )
          {
            if ( (unsigned __int64)&v4[v24] >= 0xAEC )
              v34 = 2795LL - (_QWORD)v4;
            else
              v34 = v24;
            if ( (unsigned __int64)&v4[v24] >= 0xAEC )
              v35 = 2795;
            else
              v35 = (__int64)&v4[v24];
            memcpy(&v4[(_QWORD)v22], s, v34);
            v22[v35] = 0;
          }
          if ( ++v33 >= dword_3C646C )
            goto LABEL_93;
        }
        goto LABEL_119;
      }
LABEL_93:
      *(_QWORD *)((char *)v66 + 6) = 0;
      v65 = 0;
      v66[0] = 0;
      v63 = 0;
      v64 = 0;
      v61 = 0;
      v62 = 0;
      v59 = 0;
      v60 = 0;
      v57 = 0;
      v58 = 0;
      v55 = 0;
      v56 = 0;
      v53 = 0;
      v54 = 0;
      v51 = 0;
      v52 = 0;
      *(_QWORD *)s = 0;
      v50 = 0;
      if ( dword_3C6470 >= 1 )
      {
        v36 = 0;
        while ( v36 != 16 )
        {
          snprintf(
            s,
            0x96u,
            "Device: %s, \t\t %u, state: %d, ID(device_type, instance_number): %d, %d\n",
            (const char *)(*((_QWORD *)&devices + v36 + 64) + 7560LL),
            *(_DWORD *)(*((_QWORD *)&devices + v36 + 64) + 52LL),
            *(_DWORD *)(*((_QWORD *)&devices + v36 + 64) + 6544LL),
            4,
            v36);
          v4 = (char *)strnlen(v22, 0xAECu);
          if ( v4 == (char *)-1LL )
            goto LABEL_120;
          v24 = strnlen(s, 0x96u);
          if ( v24 >= 0x97 )
            goto LABEL_122;
          if ( v24 == 150 )
            goto LABEL_121;
          if ( (unsigned __int64)v4 <= 0xAEB )
          {
            if ( (unsigned __int64)&v4[v24] >= 0xAEC )
              v37 = 2795LL - (_QWORD)v4;
            else
              v37 = v24;
            if ( (unsigned __int64)&v4[v24] >= 0xAEC )
              v38 = 2795;
            else
              v38 = (__int64)&v4[v24];
            memcpy(&v4[(_QWORD)v22], s, v37);
            v22[v38] = 0;
          }
          if ( ++v36 >= dword_3C6470 )
            goto LABEL_108;
        }
        goto LABEL_119;
      }
    }
    goto LABEL_108;
  }
LABEL_28:
  if ( sscanf(v10 + 2, "%x,%x,%d,%d,%d,%d,%d", v11, v11 + 1, v11 + 2, (char *)&v44 + 4, &v45, s, &v48) != 7 )
    goto LABEL_32;
  v15 = (int *)((__int64 (__fastcall *)(_QWORD, _QWORD, _BYTE *))cam_sensor_module_get_io_master)(
                 *(unsigned int *)s,
                 v48,
                 v41);
  if ( (v41[0] & 1) == 0 )
  {
LABEL_116:
    strcpy(v8, "Dev not on");
    goto LABEL_108;
  }
  LODWORD(v44) = 1;
  v21 = camera_io_dev_write(v15, &v43, v16, v17, v18, v19, v20);
  if ( v21 )
  {
    snprintf(v8, 0x96u, "Error: 0x%X, 0x%X, rc: %zu\n", *v43, v43[1], v21);
LABEL_118:
    strlcat(display_buf, v8, 3000);
  }
LABEL_108:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v8, 0);
  else
    kvfree(v8);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v10, 0);
  else
    kvfree(v10);
  result = v40;
LABEL_115:
  _ReadStatusReg(SP_EL0);
  return result;
}
