__int64 __fastcall cam_isp_blob_vfe_out_update_v2(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  int v4; // w6
  unsigned int v5; // w8
  __int64 v6; // x27
  unsigned __int64 v9; // x25
  __int64 result; // x0
  __int64 v11; // x22
  int v12; // w5
  __int64 v13; // x26
  unsigned int v14; // w19
  unsigned int v15; // w8
  int v16; // w23
  unsigned int v17; // w28
  __int64 v18; // x2
  __int64 v19; // x8
  unsigned int *v20; // x10
  unsigned int v21; // w7
  __int64 v22; // x6
  __int64 *v23; // x11
  unsigned __int64 v24; // x12
  __int64 **v25; // x11
  __int64 v26; // x10
  __int64 v27; // x8
  const void *v28; // x4
  int v29; // w23
  __int64 v30; // x19
  const char *v31; // x5
  __int64 v32; // x4
  __int64 v33; // x23
  char v34; // w4
  int v35; // w8
  unsigned int v36; // w19
  __int64 v37; // [xsp+28h] [xbp-38h]
  int v38; // [xsp+34h] [xbp-2Ch]
  __int64 v39; // [xsp+38h] [xbp-28h]
  unsigned int v40; // [xsp+44h] [xbp-1Ch]
  unsigned int v42; // [xsp+50h] [xbp-10h]
  int v43; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+58h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a3 + 40);
  v5 = *(_DWORD *)(a3 + 24);
  v6 = *(_QWORD *)(a3 + 16);
  v43 = 0;
  if ( v4 + 1 >= v5 )
  {
    v31 = "Insufficient HW entries :%d, ctx_idx: %u";
    v32 = 11632;
LABEL_31:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_vfe_out_update_v2",
      v32,
      v31);
    result = 4294967274LL;
    goto LABEL_43;
  }
  if ( !*(_DWORD *)(a2 + 4) )
  {
    result = 0;
LABEL_43:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v9 = 0;
  result = 0;
  v11 = *(_QWORD *)(a1 + 16);
  v12 = 0;
  v13 = a2 + 36;
  v42 = a4;
  while ( 1 )
  {
    v14 = *(_DWORD *)(v13 + 4);
    if ( v14 < 0x3000 || max_ife_out_res + 12288 <= v14 )
      goto LABEL_5;
    v15 = *(_DWORD *)(v11 + 20);
    v16 = *(_DWORD *)(v11 + 24);
    v17 = v15 - (v16 + v12);
    if ( v15 <= v16 + v12 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_blob_vfe_out_update_v2",
        11658,
        "No free kmd memory for base idx: %d, ctx_idx: %u",
        **(_DWORD **)(a1 + 8),
        *(_DWORD *)(v6 + 56));
      result = 4294967284LL;
      goto LABEL_43;
    }
    v18 = *(_QWORD *)(v11 + 8);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v40 = result;
      v37 = *(_QWORD *)(v11 + 8);
      v38 = v12;
      v39 = a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_isp_blob_vfe_out_update_v2",
        11672,
        "%s out config idx: %d port: 0x%x, ctx_idx: %u",
        "VFE",
        v9,
        v14,
        *(_DWORD *)(v6 + 56));
      v18 = v37;
      v12 = v38;
      a4 = v42;
      a1 = v39;
      result = v40;
    }
    if ( (unsigned __int8)v14 >= a4 )
    {
      v31 = "Invalid out port:0x%x, ctx_idx: %u";
      v32 = 11676;
      goto LABEL_31;
    }
    v19 = *(unsigned __int8 *)(*(_QWORD *)(v6 + 8496) + (unsigned __int8)v14);
    if ( v19 == 255 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_blob_vfe_out_update_v2",
        11681,
        "Invalid index:%d for out_map",
        (unsigned __int8)v14);
      result = 4294967274LL;
      goto LABEL_43;
    }
    v20 = *(unsigned int **)(a1 + 8);
    v21 = v20[2];
    v22 = *v20;
    if ( v21 == 7 )
    {
      if ( (unsigned int)v22 > 2 )
        goto LABEL_44;
      v24 = (8 * v22) | 0xE0;
      v25 = (__int64 **)&g_ife_hw_mgr[v22 + 28];
    }
    else
    {
      if ( v21 != 2 )
      {
        if ( v21 )
          goto LABEL_33;
        if ( (unsigned int)v22 >= 8 )
LABEL_44:
          __break(0x5512u);
        v23 = &g_ife_hw_mgr[v22 + 12];
        goto LABEL_25;
      }
      if ( (unsigned int)v22 > 7 )
        goto LABEL_44;
      v24 = 8 * v22 + 160;
      v25 = (__int64 **)((char *)g_ife_hw_mgr + v24);
    }
    if ( v24 > 0x13FD8 )
      break;
    v23 = *v25;
LABEL_25:
    if ( !*v23 || (v26 = v20[1], (unsigned int)v26 >= 2) )
    {
LABEL_33:
      v36 = result;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_blob_vfe_out_update_v2",
        11691,
        "Invalid base %u type %u",
        v22);
      goto LABEL_42;
    }
    v27 = *(_QWORD *)(*(_QWORD *)(v6 + 272) + (v19 << 7) + 8 * v26 + 32);
    if ( v27 )
    {
      v28 = (const void *)(v18 + (v12 & 0xFFFFFFFC) + (v16 & 0xFFFFFFFC));
      v29 = v12;
      v30 = a1;
      result = cam_isp_add_cmd_buf_update(v27, *v23, 32, 0x51u, v28, v17, v13, &v43);
      if ( (result & 0x80000000) != 0 )
      {
        v35 = **(_DWORD **)(v30 + 8);
        v36 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_blob_vfe_out_update_v2",
          11712,
          "Failed to update %s Out out_type:0x%X base_idx:%d bytes_used:%u rc:%d ctx_idx: %u",
          "VFE",
          *(_DWORD *)(v13 + 4),
          v35,
          v43,
          result,
          *(_DWORD *)(v6 + 56));
LABEL_42:
        result = v36;
        goto LABEL_43;
      }
      a4 = v42;
      a1 = v30;
      v12 = v43 + v29;
    }
LABEL_5:
    ++v9;
    v13 += 84;
    if ( v9 >= *(unsigned int *)(a2 + 4) )
    {
      if ( !v12 )
        goto LABEL_43;
      v33 = a1;
      v36 = result;
      v34 = *(_BYTE *)(a1 + 24) == 1
         && *(_DWORD *)(*(_QWORD *)(a3 + 32) + 32LL * (unsigned int)(*(_DWORD *)(a3 + 40) - 1) + 12) == 0;
      cam_isp_update_hw_entry(0, a3, v11, v12, v34);
      *(_BYTE *)(v33 + 24) = 1;
      goto LABEL_42;
    }
  }
  __break(1u);
  return cam_isp_blob_sensor_blanking_config(result);
}
