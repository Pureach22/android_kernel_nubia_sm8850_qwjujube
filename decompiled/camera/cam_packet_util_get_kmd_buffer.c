__int64 __fastcall cam_packet_util_get_kmd_buffer(unsigned int *a1, _QWORD *a2)
{
  unsigned int v4; // w8
  __int64 v5; // x6
  _DWORD *v6; // x8
  int *v7; // x22
  unsigned int v8; // w7
  int v9; // w21
  unsigned int cpu_buf; // w0
  const char *v11; // x3
  const char *v12; // x5
  __int64 v13; // x4
  __int64 result; // x0
  size_t v15; // x7
  unsigned __int64 v16; // x9
  size_t v17; // x10
  size_t v18; // x6
  const void *v19; // x21
  int v20; // w8
  __int64 v21; // x1
  size_t v22; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v23[2]; // [xsp+20h] [xbp-10h] BYREF

  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  if ( a1 && a2 )
  {
    v4 = a1[7];
    if ( !v4 )
    {
      v11 = "cam_packet_util_get_kmd_buffer";
      v12 = "Invalid num_cmd_buf = %d";
      v13 = 150;
      v5 = 0;
      goto LABEL_13;
    }
    v5 = a1[12];
    if ( (unsigned int)v5 >= v4 )
    {
      v11 = "cam_packet_util_get_kmd_buffer";
      v12 = "Invalid kmd buf index: %d";
      v13 = 156;
      goto LABEL_13;
    }
    v6 = (unsigned int *)((char *)&a1[6 * (unsigned int)v5] + a1[6]);
    v7 = v6 + 14;
    if ( v6 == (_DWORD *)-56LL )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_packet_util_validate_cmd_desc",
        41,
        "Invalid cmd desc");
      goto LABEL_14;
    }
    v8 = v6[17];
    v9 = *v7;
    if ( v8 > v6[16] || v9 <= 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_packet_util_validate_cmd_desc",
        49,
        "invalid cmd arg %d %d %d %d",
        v6[15],
        v8,
        v9,
        v6[16]);
      goto LABEL_14;
    }
    v23[0] = 0;
    cpu_buf = cam_mem_get_cpu_buf(v9, v23, &v22);
    if ( cpu_buf )
    {
      v5 = cpu_buf;
      v11 = "cam_packet_util_get_cmd_mem_addr";
      v12 = "Unable to get the virtual address %d";
      v13 = 23;
LABEL_13:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        0x20000,
        1,
        v11,
        v13,
        v12,
        v5);
      goto LABEL_14;
    }
    if ( !v23[0] || !v22 )
    {
      cam_mem_put_cpu_buf(v9);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_packet_util_get_cmd_mem_addr",
        30,
        "Invalid addr and length :%zd",
        v22);
      result = 4294967284LL;
      goto LABEL_15;
    }
    v16 = (unsigned int)v7[1];
    v15 = (unsigned int)v7[2];
    v17 = v22 - v16;
    if ( v22 <= v16 || v17 < v15 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_packet_util_get_kmd_buffer",
        178,
        "invalid memory len:%zd and cmd desc size:%d",
        v22,
        v15);
LABEL_23:
      cam_mem_put_cpu_buf(*v7);
      goto LABEL_14;
    }
    v18 = a1[13];
    if ( v17 <= v18 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_packet_util_get_kmd_buffer",
        186,
        "Invalid kmd cmd buf offset: %zu",
        v18);
      goto LABEL_23;
    }
    v19 = (const void *)(v23[0] + 4LL * (((unsigned int)v18 >> 2) + ((unsigned int)v16 >> 2)));
    v20 = debug_priority;
    v21 = debug_mdl & 0x20000;
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v21,
        4,
        "cam_packet_util_get_kmd_buffer",
        194,
        "total size %d, cmd size: %d, KMD buffer size: %d",
        v15,
        v7[3],
        v15 - v7[3]);
      v20 = debug_priority;
      v21 = debug_mdl & 0x20000;
      if ( (debug_mdl & 0x20000) != 0 )
      {
LABEL_29:
        if ( !v20 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v21,
            4,
            "cam_packet_util_get_kmd_buffer",
            197,
            "hdl 0x%x, cmd offset %d, kmd offset %d, addr 0x%pK",
            *v7,
            v7[1],
            a1[13],
            v19);
      }
    }
    else if ( v21 )
    {
      goto LABEL_29;
    }
    a2[1] = v19;
    result = 0;
    *(_DWORD *)a2 = *v7;
    *((_DWORD *)a2 + 4) = a1[13] + v7[1];
    *(_QWORD *)((char *)a2 + 20) = (unsigned int)(v7[2] - v7[3]);
    goto LABEL_15;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_packet_util_get_kmd_buffer",
    145,
    "Invalid arg %pK %pK",
    a1,
    a2);
LABEL_14:
  result = 4294967274LL;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
