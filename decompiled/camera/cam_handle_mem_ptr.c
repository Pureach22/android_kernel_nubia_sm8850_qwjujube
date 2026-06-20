__int64 __fastcall cam_handle_mem_ptr(int a1, __int64 a2, _QWORD *a3)
{
  unsigned int v5; // w0
  unsigned int v6; // w21
  unsigned __int64 v7; // x10
  char *v8; // x9
  char *v9; // x24
  int v10; // w25
  int v11; // w23
  const char *v12; // x5
  __int64 v13; // x4
  char *v15; // x22
  unsigned int v16; // w0
  unsigned int cpu_buf; // w0
  __int64 v18; // x3
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x5
  unsigned __int64 v21; // x4
  const char *v22; // x5
  __int64 v23; // x4
  __int64 v24; // [xsp+8h] [xbp-28h] BYREF
  __int64 v25; // [xsp+10h] [xbp-20h] BYREF
  unsigned int *v26; // [xsp+18h] [xbp-18h] BYREF
  unsigned __int64 v27[2]; // [xsp+20h] [xbp-10h] BYREF

  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = 0;
  v25 = 0;
  v26 = nullptr;
  v24 = 0;
  if ( (cam_mem_get_cpu_buf(a1, &v24, v27) & 0x80000000) == 0 )
  {
    if ( !v24 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        32,
        1,
        "cam_handle_mem_ptr",
        1062,
        "packet pos is invalid");
      v6 = -22;
      goto LABEL_18;
    }
    v5 = cam_packet_util_copy_pkt_to_kmd(v24, &v26, v27[0]);
    if ( v5 )
    {
      v6 = v5;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        32,
        1,
        "cam_handle_mem_ptr",
        1069,
        "Copying packet to KMD failed");
LABEL_18:
      cam_mem_put_cpu_buf(a1);
      goto LABEL_19;
    }
    if ( v27[0] < 0x40 || (v7 = v26[6], v27[0] - 64 <= v7) )
    {
      v12 = "Not enough buf provided";
      v13 = 1075;
    }
    else
    {
      v8 = (char *)v26 + ((unsigned int)v7 & 0xFFFFFFFC);
      v9 = v8 + 56;
      if ( v8 != (char *)-56LL )
      {
        v10 = *v26;
        if ( (debug_mdl & 0x20) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x20,
            4,
            "cam_handle_mem_ptr",
            1089,
            "Received Header opcode: %u",
            v10 & 0xFFFFFF);
          if ( v26[7] )
            goto LABEL_13;
        }
        else if ( v26[7] )
        {
LABEL_13:
          v11 = 0;
          while ( 1 )
          {
            v15 = &v9[24 * v11];
            v16 = cam_packet_util_validate_cmd_desc((int *)v15);
            if ( v16 )
            {
              v6 = v16;
              goto LABEL_17;
            }
            if ( *((_DWORD *)v15 + 3) )
            {
              cpu_buf = cam_mem_get_cpu_buf(*(_DWORD *)v15, &v25, v27);
              if ( (cpu_buf & 0x80000000) != 0 )
              {
                v6 = cpu_buf;
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  32,
                  1,
                  "cam_handle_mem_ptr",
                  1102,
                  "Failed to parse the command Buffer Header");
                goto LABEL_17;
              }
              v19 = *((unsigned int *)v15 + 1);
              v20 = v27[0] - v19;
              if ( v27[0] <= v19 )
              {
                v22 = "offset past length of buffer";
                v23 = 1107;
LABEL_34:
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  32,
                  1,
                  "cam_handle_mem_ptr",
                  v23,
                  v22);
                cam_mem_put_cpu_buf(*(_DWORD *)v15);
                goto LABEL_16;
              }
              v21 = *((unsigned int *)v15 + 3);
              if ( v20 < v21 )
              {
                v22 = "Not enough buffer provided for cmd";
                v23 = 1115;
                goto LABEL_34;
              }
              v6 = cam_handle_cmd_buffers_for_probe(
                     (_DWORD *)(v25 + ((unsigned int)v19 & 0xFFFFFFFC)),
                     a3,
                     v11,
                     v18,
                     v21,
                     v20,
                     v10 & 0xFFFFFF,
                     (__int64)&v9[24 * v11]);
              if ( (v6 & 0x80000000) != 0 )
              {
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  32,
                  1,
                  "cam_handle_mem_ptr",
                  1129,
                  "Failed to parse the command Buffer Header");
                cam_mem_put_cpu_buf(*(_DWORD *)v15);
                goto LABEL_17;
              }
              cam_mem_put_cpu_buf(*(_DWORD *)v15);
            }
            else
            {
              v6 = 0;
            }
            if ( ++v11 >= v26[7] )
              goto LABEL_17;
          }
        }
        v6 = 0;
LABEL_17:
        cam_common_mem_free((__int64)v26);
        goto LABEL_18;
      }
      v12 = "command descriptor pos is invalid";
      v13 = 1083;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      32,
      1,
      "cam_handle_mem_ptr",
      v13,
      v12);
LABEL_16:
    v6 = -22;
    goto LABEL_17;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    32,
    1,
    "cam_handle_mem_ptr",
    1056,
    "Failed to get the command Buffer");
  v6 = -22;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return v6;
}
