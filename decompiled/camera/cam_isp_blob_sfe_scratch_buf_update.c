__int64 __fastcall cam_isp_blob_sfe_scratch_buf_update(unsigned int *a1, __int64 a2)
{
  unsigned int v2; // w8
  __int64 v3; // x24
  unsigned int v5; // w20
  int v6; // w9
  _DWORD *v7; // x25
  unsigned int v8; // w23
  __int64 v10; // x8
  __int64 result; // x0
  const char *v12; // x5
  __int64 v13; // x4

  v2 = *a1;
  v3 = *(_QWORD *)(a2 + 16);
  if ( *a1 )
  {
    v5 = 0;
    v6 = max_sfe_out_res;
    v7 = a1 + 2;
    do
    {
      v8 = v7[12 * v5 + 6];
      if ( v8 >= 0x6000 && v6 + 24576 > v8 )
      {
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_isp_blob_sfe_scratch_buf_update",
            10171,
            "scratch config idx: %d res: 0x%x, ctx_idx: %u",
            v5,
            v8,
            *(_DWORD *)(v3 + 56));
        if ( (unsigned __int8)v8 >= 3u )
        {
          v12 = "invalid out res type: 0x%x, ctx_idx: %u";
          v13 = 10175;
          goto LABEL_23;
        }
        v10 = *(unsigned __int8 *)(*(_QWORD *)(v3 + 8504) + (unsigned __int8)v8);
        if ( v10 == 255 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_isp_blob_sfe_scratch_buf_update",
            10180,
            "Invalid index:%d for out_map",
            (unsigned __int8)v8);
          return 4294967274LL;
        }
        if ( !*(_QWORD *)(*(_QWORD *)(v3 + 280) + (v10 << 7) + 32) )
        {
          v12 = "SFE rsrc_type: 0x%x not acquired, failing scratch config, ctx_idx: %u";
          v13 = 10188;
          goto LABEL_23;
        }
        result = cam_isp_scratch_buf_update_util();
        if ( (_DWORD)result )
          return result;
        v6 = max_sfe_out_res;
        ++**(_DWORD **)(v3 + 9360);
        v2 = *a1;
      }
      ++v5;
    }
    while ( v5 < v2 );
  }
  if ( **(_DWORD **)(v3 + 9360) == *(_DWORD *)(v3 + 9352) )
    return 0;
  v12 = "Mismatch in number of scratch buffers provided: %u expected: %u ctx_idx: %u";
  v13 = 10205;
LABEL_23:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_blob_sfe_scratch_buf_update",
    v13,
    v12);
  return 4294967274LL;
}
