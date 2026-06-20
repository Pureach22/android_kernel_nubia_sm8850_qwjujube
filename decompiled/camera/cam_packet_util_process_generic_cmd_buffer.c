__int64 __fastcall cam_packet_util_process_generic_cmd_buffer(int *a1, _DWORD *a2, __int64 a3)
{
  int v5; // w6
  int v6; // w7
  int cpu_buf; // w0
  unsigned __int64 v9; // x6
  unsigned __int64 v10; // x22
  const char *v11; // x5
  __int64 v12; // x4
  __int64 result; // x0
  unsigned int v14; // w19
  unsigned int v15; // w20
  unsigned int v16; // w0
  _DWORD *v17; // [xsp+10h] [xbp-20h] BYREF
  unsigned __int64 v18; // [xsp+18h] [xbp-18h] BYREF
  const void *v19[2]; // [xsp+20h] [xbp-10h] BYREF

  v19[1] = *(const void **)(_ReadStatusReg(SP_EL0) + 1808);
  v19[0] = nullptr;
  v17 = nullptr;
  v18 = 0;
  if ( a1 && a2 )
  {
    v6 = a1[2];
    v5 = a1[3];
    if ( v5 && v6 )
    {
      cpu_buf = cam_mem_get_cpu_buf(*a1, v19, &v18);
      if ( !cpu_buf && v19[0] && v18 )
      {
        v9 = (unsigned int)a1[1];
        if ( v18 < 4 || v18 - 4 < v9 )
        {
          v11 = "Invalid offset for cmd buf: %zu";
          v12 = 743;
        }
        else
        {
          v10 = (unsigned int)a1[3];
          if ( v18 - v9 >= v10 )
          {
            v16 = cam_common_mem_kdup(&v17, (char *)v19[0] + v9, (unsigned int)a1[3]);
            if ( v16 )
            {
              v15 = v16;
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x20000,
                1,
                "cam_packet_util_process_generic_cmd_buffer",
                756,
                "Alloc and copy blob buffer failed");
            }
            else
            {
              if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x20000,
                  4,
                  "cam_packet_util_process_generic_cmd_buffer",
                  767,
                  "GenericCmdBuffer cpuaddr=%pK, blobptr=%pK, len=%d",
                  v19[0],
                  v17,
                  v10);
              v15 = cam_packet_util_process_generic_blob(v10, v17, a2, a3);
              if ( v15 )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  0x20000,
                  1,
                  "cam_packet_util_process_generic_cmd_buffer",
                  773,
                  "Error in parse of blob type blob data %d",
                  v15);
              cam_common_mem_free(v17);
            }
            goto LABEL_17;
          }
          v11 = "Invalid blob size %u";
          v12 = 760;
          v9 = (unsigned int)a1[3];
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_packet_util_process_generic_cmd_buffer",
          v12,
          v11,
          v9);
        v15 = -22;
LABEL_17:
        cam_mem_put_cpu_buf(*a1);
        result = v15;
        goto LABEL_18;
      }
      v14 = cpu_buf;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_packet_util_process_generic_cmd_buffer",
        735,
        "Failed in Get cpu addr, rc=%d, cpu_addr=%pK",
        cpu_buf,
        v19[0]);
      result = v14;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_packet_util_process_generic_cmd_buffer",
        728,
        "Invalid cmd buf size %d %d",
        v5,
        v6);
      result = 4294967274LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_packet_util_process_generic_cmd_buffer",
      722,
      "Invalid args %pK %pK",
      a1,
      a2);
    result = 4294967274LL;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
