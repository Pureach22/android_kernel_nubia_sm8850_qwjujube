__int64 __fastcall cam_isp_blob_ife_scratch_buf_update(unsigned int *a1, __int64 a2)
{
  unsigned int v2; // w9
  __int64 v3; // x24
  unsigned int v5; // w10
  int v6; // w20
  _DWORD *v7; // x25
  _DWORD *v8; // x28
  unsigned int *v9; // x0
  unsigned int v10; // w8
  __int64 v12; // x23
  __int64 v13; // x8
  __int64 v14; // x6
  __int64 result; // x0
  __int64 v16; // x7
  const char *v17; // x5
  __int64 v18; // x4
  int v19; // [xsp+0h] [xbp-10h]

  v2 = *a1;
  if ( !*a1 )
    return 0;
  v3 = *(_QWORD *)(a2 + 16);
  v5 = max_ife_out_res;
  v6 = 0;
  v7 = a1 + 2;
  v8 = *(_DWORD **)(v3 + 9368);
  while ( 1 )
  {
    v9 = &v7[12 * v6];
    v10 = v9[6];
    if ( v10 >= 0x3000 && v5 + 12288 > v10 )
      break;
LABEL_3:
    if ( ++v6 >= v2 )
      return 0;
  }
  v12 = (unsigned __int8)v9[6];
  if ( (unsigned __int8)v9[6] >= v5 )
  {
    v16 = *(unsigned int *)(v3 + 56);
    v17 = "Invalid port type:%x ctx_idx: %u";
    v18 = 10110;
    v14 = v10;
    goto LABEL_24;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_blob_ife_scratch_buf_update",
      10116,
      "scratch config idx: %d res: 0x%x ctx_idx: %u",
      v6,
      v10,
      *(_DWORD *)(v3 + 56));
    v9 = &v7[12 * v6];
  }
  v13 = *(unsigned __int8 *)(*(_QWORD *)(v3 + 8496) + v12);
  if ( v13 == 255 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_ife_scratch_buf_update",
      10119,
      "Invalid index:%d for out_map",
      v12);
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(*(_QWORD *)(v3 + 272) + (v13 << 7) + 32) )
  {
    v14 = v9[6];
    v16 = *(unsigned int *)(v3 + 56);
    v17 = "IFE rsrc_type: 0x%x not acquired, failing scratch config, ctx_idx: %u";
    v18 = 10128;
    goto LABEL_24;
  }
  v14 = (unsigned int)*v8;
  if ( (unsigned int)v14 < 2 )
  {
    *v8 = v14 + 1;
    result = cam_isp_scratch_buf_update_util(v9, (__int64)&v8[10 * (unsigned int)v14 + 2]);
    if ( (_DWORD)result )
      return result;
    v5 = max_ife_out_res;
    v2 = *a1;
    goto LABEL_3;
  }
  v17 = "Incoming num of scratch buffers: %u exceeds max: %u, ctx_idx: %u";
  v18 = 10136;
  v16 = 2;
  v19 = *(_DWORD *)(v3 + 56);
LABEL_24:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_blob_ife_scratch_buf_update",
    v18,
    v17,
    v14,
    v16,
    v19);
  return 4294967274LL;
}
