__int64 __fastcall cam_jpeg_add_command_buffers(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x22
  int *v7; // x21
  __int64 v8; // x25
  int kmd_buffer; // w0
  unsigned int v10; // w19
  __int64 result; // x0
  const char *v12; // x5
  __int64 v13; // x4
  int v14; // w8
  __int64 v15; // x23
  __int64 v16; // x9
  __int16 v17; // w8
  unsigned __int64 v18; // x25
  __int64 v19; // x9
  unsigned int v20; // w8
  unsigned int v21; // w20
  _QWORD v22[2]; // [xsp+28h] [xbp-28h] BYREF
  __int64 v23; // [xsp+38h] [xbp-18h]
  __int64 v24; // [xsp+40h] [xbp-10h]
  __int64 v25; // [xsp+48h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24 = 0;
  v22[0] = 0;
  v22[1] = 0;
  if ( !a3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_add_command_buffers",
      125,
      "Invalid args: packet: 0x%p, prepare_args: 0x%p, ctx_data: 0x%p",
      (const void *)a1,
      (const void *)a2,
      nullptr);
    result = 4294967274LL;
    goto LABEL_36;
  }
  v5 = *(_QWORD *)(a2 + 320);
  if ( !v5 )
  {
    v12 = "prepare_args private is null";
    v13 = 132;
LABEL_10:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_add_command_buffers",
      v13,
      v12);
    result = 4294967274LL;
    goto LABEL_36;
  }
  v7 = (int *)(a1 + (*(_DWORD *)(a1 + 24) & 0xFFFFFFFC) + 56);
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200,
      4,
      "cam_jpeg_add_command_buffers",
      146,
      "Pkt: %pK req_id: %u cmd_desc: %pK Size: %lu, num_cmd_buffs: %d dev_type: %u",
      (const void *)a1,
      *(_QWORD *)(a1 + 8),
      v7,
      24,
      *(_DWORD *)(a1 + 28),
      *(_DWORD *)(a3 + 56));
  v8 = *(unsigned int *)(a2 + 40);
  kmd_buffer = cam_packet_util_get_kmd_buffer((unsigned int *)a1, v22);
  if ( kmd_buffer )
  {
    v10 = kmd_buffer;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_add_command_buffers",
      152,
      "get kmd buf failed %d",
      kmd_buffer);
    result = v10;
    goto LABEL_36;
  }
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200,
      4,
      "cam_jpeg_add_command_buffers",
      157,
      "KMD Buffer: used_bytes: %u handle: 0x%x offset: 0x%x",
      v24,
      LODWORD(v22[0]),
      v23);
  *(_DWORD *)(*(_QWORD *)(a2 + 32) + 32 * v8 + 8) = v24;
  *(_DWORD *)(*(_QWORD *)(a2 + 32) + 32 * v8) = v22[0];
  *(_DWORD *)(*(_QWORD *)(a2 + 32) + 32 * v8 + 4) = v23;
  v14 = *(_DWORD *)(a3 + 56);
  v15 = (unsigned int)(v8 + 1);
  *(_DWORD *)v5 = v14;
  v16 = *(_QWORD *)(a1 + 8);
  v17 = debug_mdl;
  *(_QWORD *)(v5 + 16) = 0;
  *(_QWORD *)(v5 + 8) = v16;
  *(_DWORD *)(v5 + 24) = 0;
  if ( (v17 & 0x200) == 0 || debug_priority )
  {
    if ( *(_DWORD *)(a1 + 28) )
      goto LABEL_17;
LABEL_31:
    result = 0;
LABEL_32:
    if ( (debug_mdl & 0x200) != 0 && !debug_priority )
    {
      v21 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x200,
        4,
        "cam_jpeg_add_command_buffers",
        217,
        "num_entry: %u",
        v15);
      result = v21;
    }
    *(_DWORD *)(a2 + 40) = v15;
    goto LABEL_36;
  }
  ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    v17 & 0x200,
    4,
    "cam_jpeg_add_command_buffers",
    176,
    "Change_Base HW_Entry. Offset: 0x%x Length: %u mem_handle: 0x%x num_entry: %d",
    *(_DWORD *)(*(_QWORD *)(a2 + 32) + 32 * v15 + 4),
    *(_DWORD *)(*(_QWORD *)(a2 + 32) + 32 * v15 + 8),
    *(_DWORD *)(*(_QWORD *)(a2 + 32) + 32 * v15),
    v8 + 1);
  if ( !*(_DWORD *)(a1 + 28) )
    goto LABEL_31;
LABEL_17:
  v18 = 0;
  while ( 1 )
  {
    result = cam_packet_util_validate_cmd_desc(v7);
    if ( (_DWORD)result )
      break;
    if ( (debug_mdl & 0x200) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x200,
        4,
        "cam_jpeg_add_command_buffers",
        187,
        "Metadata: %u Offset: 0x%x Length: %u mem_handle: 0x%x num_entry: %d",
        v7[5],
        v7[1],
        v7[3],
        *v7,
        v15);
    v20 = v7[5];
    if ( v20 < 3 )
    {
      v19 = 32LL * (unsigned int)v15;
      result = 0;
      LODWORD(v15) = v15 + 1;
      *(_DWORD *)(*(_QWORD *)(a2 + 32) + v19 + 8) = v7[3];
      *(_DWORD *)(*(_QWORD *)(a2 + 32) + v19) = *v7;
      *(_DWORD *)(*(_QWORD *)(a2 + 32) + v19 + 4) = v7[1];
    }
    else if ( v20 == 3 )
    {
      result = 0;
      *(_DWORD *)(v5 + 20) = *v7;
      *(_DWORD *)(v5 + 24) = v7[1];
    }
    else
    {
      if ( v20 != 4 )
      {
        v12 = "Invalid metadata";
        v13 = 212;
        goto LABEL_10;
      }
      result = cam_packet_util_process_generic_cmd_buffer(v7, cam_jpeg_generic_blob_handler, v5 + 16);
    }
    ++v18;
    v7 += 6;
    if ( v18 >= *(unsigned int *)(a1 + 28) )
      goto LABEL_32;
  }
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
