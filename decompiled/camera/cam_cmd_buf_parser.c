__int64 __fastcall cam_cmd_buf_parser(__int64 a1, __int64 a2)
{
  int cpu_buf; // w0
  unsigned __int64 v5; // x8
  unsigned int v6; // w0
  unsigned int v7; // w20
  __int64 result; // x0
  unsigned int v9; // w19
  unsigned int *v10; // x22
  unsigned int v11; // w23
  int v12; // w21
  __int64 v13; // x23
  int v14; // w0
  int v15; // w6
  int v16; // [xsp+Ch] [xbp-24h]
  unsigned __int64 v17; // [xsp+10h] [xbp-20h] BYREF
  unsigned int *v18; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v19[2]; // [xsp+20h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[0] = 0;
  v17 = 0;
  v18 = nullptr;
  if ( a1 && a2 )
  {
    cpu_buf = cam_mem_get_cpu_buf(*(_DWORD *)(a2 + 16), v19, &v17);
    if ( cpu_buf < 0 )
    {
      v9 = cpu_buf;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_cmd_buf_parser",
        1397,
        "Failed to get packet Mem address: %d",
        cpu_buf);
      result = v9;
      goto LABEL_12;
    }
    if ( v17 < 0x40 || (v5 = *(_QWORD *)(a2 + 8), v5 >= v17 - 64) )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_cmd_buf_parser",
        1406,
        "Inval cam_packet strut size: %zu, len_of_buff: %zu",
        64);
      cam_mem_put_cpu_buf(*(_DWORD *)(a2 + 16));
      v7 = -22;
      goto LABEL_10;
    }
    v6 = cam_packet_util_copy_pkt_to_kmd(v19[0] + (unsigned int)v5, &v18, v17 - v5);
    if ( v6 )
    {
      v7 = v6;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_cmd_buf_parser",
        1418,
        "Copying packet to KMD failed");
LABEL_10:
      cam_mem_put_cpu_buf(*(_DWORD *)(a2 + 16));
      result = v7;
      goto LABEL_12;
    }
    v10 = v18;
    if ( !v18[7] )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_cmd_buf_parser",
        1427,
        "num_cmd_buffer = %d",
        0);
      v14 = -22;
LABEL_34:
      v7 = v14;
      cam_common_mem_free((__int64)v18);
      goto LABEL_10;
    }
    v11 = v18[6];
    if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        (unsigned __int16)debug_mdl & 0x8000,
        4,
        "cam_cmd_buf_parser",
        1433,
        "CSIPHY:%u num cmd buffers received: %u",
        *(unsigned int *)(a1 + 932));
      if ( !v18[7] )
      {
LABEL_33:
        v14 = 0;
        goto LABEL_34;
      }
    }
    v12 = 0;
    v13 = (__int64)v10 + (v11 & 0xFFFFFFFC) + 56;
    while ( 1 )
    {
      v14 = cam_packet_util_validate_cmd_desc((int *)(v13 + 24LL * v12));
      if ( v14 )
        goto LABEL_34;
      v15 = *(_DWORD *)(v13 + 24LL * v12 + 20);
      if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
      {
        v16 = *(_DWORD *)(v13 + 24LL * v12 + 20);
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          (unsigned __int16)debug_mdl & 0x8000,
          4,
          "cam_cmd_buf_parser",
          1443,
          "CSIPHY:%u cmd_buffer_%d type: %u",
          *(_DWORD *)(a1 + 932),
          v12,
          v15);
        v15 = v16;
        if ( v16 == 2 )
          goto LABEL_25;
      }
      else if ( v15 == 2 )
      {
        goto LABEL_25;
      }
      if ( v15 != 1 )
      {
        if ( v15 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x8000,
            2,
            "cam_cmd_buf_parser",
            1460,
            "Invalid meta type: %u",
            v15);
          goto LABEL_18;
        }
LABEL_25:
        v14 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))_cam_csiphy_parse_lane_info_cmd_buf)(
                *(unsigned int *)(a2 + 4),
                a1,
                v13 + 24LL * v12);
        if ( v14 )
          goto LABEL_34;
        goto LABEL_18;
      }
      v14 = cam_packet_util_process_generic_cmd_buffer((int *)(v13 + 24LL * v12), _cam_csiphy_generic_blob_handler, a1);
      if ( v14 )
        goto LABEL_34;
LABEL_18:
      if ( ++v12 >= v18[7] )
        goto LABEL_33;
    }
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x8000,
    1,
    "cam_cmd_buf_parser",
    1390,
    "Invalid Args");
  result = 4294967274LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
