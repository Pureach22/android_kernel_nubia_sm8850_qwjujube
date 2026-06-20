__int64 __fastcall cam_jpeg_mgr_prepare_hw_update(__int64 a1, unsigned int **a2)
{
  unsigned int *v4; // x22
  unsigned int *v5; // x21
  unsigned int v6; // w6
  unsigned int v7; // w0
  unsigned int v8; // w19
  const char *v9; // x5
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x4
  __int64 v13; // x6
  __int64 result; // x0
  unsigned int v15; // w6
  unsigned int v16; // w7
  void *v17; // x0
  void *v18; // x0
  __int64 v19; // x6
  unsigned int v20; // w0
  char *v21; // x8
  unsigned int **v22; // x9
  unsigned int v23; // w10
  __int64 v24; // x11
  __int64 v25; // x12
  unsigned int **v26; // x13
  char *v27; // x14
  unsigned int v28; // w15
  __int64 v29; // x17
  unsigned int **v30; // x16
  __int64 v31; // x17
  __int16 v32; // w15
  __int64 v33; // x0
  unsigned int v34; // w22
  unsigned int **v35; // [xsp+20h] [xbp-30h]
  __int64 v36; // [xsp+28h] [xbp-28h]
  unsigned int **v37; // [xsp+30h] [xbp-20h]
  __int64 v38; // [xsp+38h] [xbp-18h]
  char *v39; // [xsp+40h] [xbp-10h]
  __int64 v40; // [xsp+40h] [xbp-10h]
  unsigned int v41; // [xsp+48h] [xbp-8h]

  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_prepare_hw_update",
      1017,
      "Invalid args %pK %pK",
      a2,
      (const void *)a1);
    return 4294967274LL;
  }
  mutex_lock(a1);
  v4 = a2[2];
  if ( (v4[26] & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_prepare_hw_update",
      1024,
      "ctx is not in use");
    mutex_unlock(a1);
    return 4294967274LL;
  }
  mutex_unlock(a1);
  v5 = *a2;
  if ( !*a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_prepare_hw_update",
      1032,
      "received packet is NULL");
    return 4294967274LL;
  }
  v6 = *(unsigned __int8 *)v5;
  if ( v6 >= 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_prepare_hw_update",
      1040,
      "Invalid Opcode in pkt: %d",
      v6);
    return 4294967274LL;
  }
  v7 = cam_packet_util_validate_packet(*a2, (unsigned __int64)a2[1]);
  if ( v7 )
  {
    v8 = v7;
    v9 = "invalid packet %d";
    v10 = 512;
    v11 = 1;
    v12 = 1046;
LABEL_8:
    v13 = v8;
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      v10,
      v11,
      "cam_jpeg_mgr_prepare_hw_update",
      v12,
      v9,
      v13);
    return v8;
  }
  v15 = v5[7];
  v16 = v5[11];
  if ( v15 - 6 < 0xFFFFFFFB || !v16 || v5[9] - 3 <= 0xFFFFFFFD )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_prepare_hw_update",
      1057,
      "wrong number of cmd/patch/io_configs info: %u %u %u",
      v15,
      v16,
      v5[9]);
    return 4294967274LL;
  }
  v17 = *((void **)v4 + 24);
  if ( v17 )
    memset(v17, 0, 0x640u);
  v18 = *((void **)v4 + 25);
  if ( v18 )
  {
    memset(v18, 0, 0x640u);
    v19 = *((_QWORD *)v4 + 25);
  }
  else
  {
    v19 = 0;
  }
  v20 = cam_packet_util_process_patches(
          (__int64)v5,
          (__int64)a2[41],
          *(_DWORD *)(a1 + 5120),
          0xFFFFFFFF,
          0,
          *((_QWORD **)v4 + 24),
          v19);
  if ( v20 )
  {
    v8 = v20;
    v9 = "Patch processing failed %d";
    v10 = 512;
    v11 = 1;
    v12 = 1072;
    goto LABEL_8;
  }
  v21 = (char *)v5 + (v5[8] & 0xFFFFFFFC) + 56;
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
  {
    v40 = (__int64)v5 + (v5[8] & 0xFFFFFFFC) + 56;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200,
      4,
      "cam_jpeg_mgr_prepare_hw_update",
      1083,
      "Packet: %pK, io_cfg_ptr: %pK size: %lu req_id: %u dev_type: %d",
      v5,
      v21,
      256,
      *((_QWORD *)v5 + 1),
      v4[14]);
    v21 = (char *)v40;
  }
  *((_DWORD *)a2 + 14) = 0;
  v22 = a2 + 7;
  if ( v5[9] )
  {
    v23 = 0;
    v24 = 0;
    v25 = 0;
    v26 = a2 + 9;
    do
    {
      v27 = &v21[256 * (__int64)(int)v23];
      v28 = *((_DWORD *)v27 + 47);
      if ( *((_DWORD *)v27 + 56) == 1 )
      {
        v29 = (__int64)(int)v24 << 6;
        v24 = (unsigned int)(v24 + 1);
        *(unsigned int *)((char *)a2[8] + v29) = v28;
        *(unsigned int *)((char *)a2[8] + v29 + 16) = *((_DWORD *)v27 + 48);
        v30 = v26;
      }
      else
      {
        v31 = (__int64)(int)v25 << 6;
        v25 = (unsigned int)(v25 + 1);
        *(unsigned int *)((char *)a2[6] + v31) = v28;
        *(unsigned int *)((char *)a2[6] + v31 + 16) = *((_DWORD *)v27 + 48);
        v30 = v22;
      }
      v32 = debug_mdl;
      ++*(_DWORD *)v30;
      if ( (v32 & 0x200) != 0 && !debug_priority )
      {
        v39 = v21;
        v41 = v23;
        v37 = v22;
        v36 = v24;
        v38 = v25;
        v35 = v26;
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v32 & 0x200,
          4,
          "cam_jpeg_mgr_prepare_hw_update",
          1103,
          "dir[%d]: %u, fence: %u resource_type %d ",
          v23,
          *((_DWORD *)v27 + 56),
          *((_DWORD *)v27 + 48),
          *((_DWORD *)v27 + 47));
        v26 = v35;
        v24 = v36;
        v22 = v37;
        v25 = v38;
        v21 = v39;
        v23 = v41;
      }
      ++v23;
    }
    while ( v23 < v5[9] );
  }
  v33 = cam_jpeg_add_command_buffers(v5, a2, v4);
  v34 = v33;
  if ( (cam_presil_mode_enabled(v33) & 1) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      3,
      "cam_jpeg_mgr_prepare_hw_update",
      1110,
      "Sending relevant buffers for request:%llu to presil",
      *((_QWORD *)v5 + 1));
    result = cam_presil_send_buffers_from_packet(v5, *(_DWORD *)(a1 + 5120), *(_DWORD *)(a1 + 5160));
    if ( (_DWORD)result )
    {
      v8 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_mgr_prepare_hw_update",
        1115,
        "Error sending buffers for request:%llu to presil",
        *((_QWORD *)v5 + 1));
      return v8;
    }
  }
  else
  {
    result = v34;
  }
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
  {
    v9 = "will wait on input sync sync_id %d";
    v10 = debug_mdl & 0x200;
    v13 = a2[8][4];
    v8 = result;
    v11 = 4;
    v12 = 1121;
    goto LABEL_9;
  }
  return result;
}
