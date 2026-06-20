_QWORD *__fastcall cam_ois_shutdown(_QWORD *result)
{
  int v1; // w8
  __int64 v2; // x23
  _QWORD *v3; // x19
  _QWORD *v4; // x24
  unsigned __int64 v5; // x25
  __int64 v6; // x26
  __int64 v7; // x8
  int v8; // w0
  __int64 v9; // x8
  int v10; // w0
  int v11; // w0
  _QWORD *v12; // x0
  _QWORD *v13; // x0
  _QWORD *v14; // x0
  _QWORD *v15; // x0
  _QWORD *v16; // x0

  v1 = *((_DWORD *)result + 1128);
  if ( v1 )
  {
    v2 = result[422];
    v3 = result;
    v4 = result + 512;
    if ( v1 == 1 )
      goto LABEL_6;
    if ( (cam_ois_power_down(result) & 0x80000000) != 0 )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x100000,
        1,
        "cam_ois_shutdown",
        1888,
        "OIS Power down failed");
    if ( *((_DWORD *)v3 + 1128) )
    {
LABEL_6:
      if ( (cam_destroy_device_hdl(*((unsigned int *)v3 + 1048)) & 0x80000000) != 0 )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x100000,
          1,
          "cam_ois_shutdown",
          1894,
          "destroying the device hdl");
      v3[524] = -1;
      *((_DWORD *)v3 + 1050) = -1;
    }
    if ( *((_DWORD *)v3 + 1072) == 1 )
      delete_request(v3 + 534);
    if ( *((_BYTE *)v4 + 476) )
    {
      v5 = 0;
      v6 = 16;
      do
      {
        v7 = v3[573];
        if ( v7 && *(_DWORD *)(v7 + v6) == 1 && (v8 = delete_request(v7 + v6 - 16), v8 < 0) )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x100000,
            2,
            "cam_ois_shutdown",
            1909,
            "Fail deleting i2c_fw_init_data: rc: %d",
            v8);
          v9 = v3[574];
          if ( v9 )
          {
LABEL_18:
            if ( *(_DWORD *)(v9 + v6) == 1 )
            {
              v10 = delete_request(v9 + v6 - 16);
              if ( v10 < 0 )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  0x100000,
                  2,
                  "cam_ois_shutdown",
                  1916,
                  "Fail deleting i2c_fw_finalize_data: rc: %d",
                  v10);
            }
          }
        }
        else
        {
          v9 = v3[574];
          if ( v9 )
            goto LABEL_18;
        }
        ++v5;
        v6 += 48;
      }
      while ( v5 < *((unsigned __int8 *)v4 + 476) );
    }
    if ( *((_DWORD *)v3 + 1154) == 1 )
    {
      v11 = delete_request(v3 + 575);
      if ( v11 < 0 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x100000,
          2,
          "cam_ois_shutdown",
          1924,
          "Fail deleting i2c_fw_version_data: rc: %d",
          v11);
    }
    if ( *((_DWORD *)v3 + 1108) == 1 )
      delete_request(v3 + 552);
    if ( *((_DWORD *)v3 + 1096) == 1 )
      delete_request(v3 + 546);
    if ( *((_DWORD *)v3 + 1084) == 1 )
      delete_request(v3 + 540);
    v12 = (_QWORD *)v3[573];
    if ( v12 )
    {
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v12, 0);
      else
        kvfree(v12);
      v3[573] = 0;
    }
    v13 = (_QWORD *)v3[574];
    if ( v13 )
    {
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v13, 0);
      else
        kvfree(v13);
      v3[574] = 0;
    }
    v14 = *(_QWORD **)((char *)v4 + 478);
    if ( v14 )
    {
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v14, 0);
      else
        kvfree(v14);
      *(_QWORD *)((char *)v4 + 478) = 0;
    }
    v15 = *(_QWORD **)(v2 + 24);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v15, 0);
    else
      kvfree(v15);
    v16 = *(_QWORD **)(v2 + 40);
    if ( mem_trace_en == 1 )
      result = cam_mem_trace_free(v16, 0);
    else
      result = (_QWORD *)kvfree(v16);
    *(_QWORD *)(v2 + 24) = 0;
    *(_QWORD *)(v2 + 40) = 0;
    *(_WORD *)(v2 + 48) = 0;
    *(_WORD *)(v2 + 32) = 0;
    *((_DWORD *)v3 + 1128) = 0;
  }
  return result;
}
