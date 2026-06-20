__int64 __fastcall cam_isp_blob_bw_limit_update(__int64 a1, unsigned int *a2, __int64 a3, int a4)
{
  int v5; // w6
  unsigned int v6; // w7
  __int64 v7; // x3
  unsigned int *v8; // x25
  __int64 v9; // x16
  __int64 v10; // x23
  const char *v11; // x10
  unsigned __int64 v13; // x26
  __int64 result; // x0
  int v15; // w22
  _DWORD *v16; // x27
  unsigned int v17; // w19
  unsigned int v18; // w8
  int v19; // w9
  unsigned int v20; // w5
  __int64 *v21; // x11
  unsigned int v22; // w8
  unsigned int *v23; // x12
  __int64 v24; // x11
  unsigned int v25; // w7
  __int64 v26; // x6
  unsigned int **v27; // x13
  unsigned __int64 v28; // x14
  unsigned int ***v29; // x13
  __int64 v30; // x12
  __int64 v31; // x8
  __int64 v32; // x19
  __int64 v33; // x21
  char v34; // w4
  int v35; // w8
  unsigned int v36; // w19
  const char *v37; // x5
  __int64 v38; // x4
  __int64 v39; // [xsp+40h] [xbp-40h]
  unsigned int v40; // [xsp+4Ch] [xbp-34h]
  const char *v41; // [xsp+50h] [xbp-30h]
  __int64 *v42; // [xsp+58h] [xbp-28h]
  __int64 *v43; // [xsp+60h] [xbp-20h]
  __int64 v44; // [xsp+68h] [xbp-18h]
  int v45; // [xsp+74h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+78h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a3 + 40);
  v6 = *(_DWORD *)(a3 + 24);
  v7 = *(_QWORD *)(a3 + 16);
  v45 = 0;
  if ( v5 + 1 >= v6 )
  {
    v37 = "Insufficient HW entries: %d max: %d ctx_idx: %u";
    v38 = 11800;
LABEL_41:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_bw_limit_update",
      v38,
      v37);
    result = 4294967274LL;
    goto LABEL_51;
  }
  v8 = a2;
  if ( !*a2 )
  {
    result = 0;
LABEL_51:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v9 = a1;
  v10 = *(_QWORD *)(a1 + 16);
  if ( a4 == 7 )
    v11 = "SFE";
  else
    v11 = "VFE";
  v13 = 0;
  result = 0;
  v15 = 0;
  v43 = (__int64 *)(v7 + 272);
  v44 = v7;
  v16 = a2 + 3;
  v41 = v11;
  v42 = (__int64 *)(v7 + 280);
  while ( 1 )
  {
    v17 = *(v16 - 1);
    if ( a4 == 7 )
    {
      if ( v17 < 0x6000 || v17 >= max_sfe_out_res + 24576 )
        goto LABEL_8;
    }
    else if ( a4 == 2 && (v17 < 0x3000 || v17 >= max_ife_out_res + 12288) )
    {
      goto LABEL_8;
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v40 = result;
      v39 = v9;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_isp_blob_bw_limit_update",
        11829,
        "%s BW limit config idx: %d port: 0x%x enable: %d [0x%x:0x%x] ctx: %u",
        v41,
        v13,
        v17,
        *v16,
        v16[1],
        v16[2],
        *(_DWORD *)(v7 + 56));
      v7 = v44;
      v9 = v39;
      result = v40;
    }
    v18 = *(_DWORD *)(v10 + 20);
    v19 = *(_DWORD *)(v10 + 24);
    v20 = v18 - (v19 + v15);
    if ( v18 <= v19 + v15 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_blob_bw_limit_update",
        11839,
        "No free kmd memory for base idx: %d, ctx_idx: %u",
        **(_DWORD **)(v9 + 8),
        *(_DWORD *)(v7 + 56));
      result = 4294967284LL;
      goto LABEL_51;
    }
    if ( a4 == 7 )
    {
      v21 = v42;
      v22 = *(unsigned __int8 *)(*(_QWORD *)(v7 + 8504) + (unsigned __int8)v17);
      if ( v22 == 255 )
      {
        v37 = "Invalid index:%d for out_map";
        v38 = 11850;
        goto LABEL_41;
      }
    }
    else
    {
      v21 = v43;
      v22 = *(unsigned __int8 *)(*(_QWORD *)(v7 + 8496) + (unsigned __int8)v17);
      if ( v22 == 255 )
      {
        v37 = "Invalid index:%d for out_map";
        v38 = 11857;
        goto LABEL_41;
      }
    }
    v23 = *(unsigned int **)(v9 + 8);
    v24 = *v21;
    v25 = v23[2];
    v26 = *v23;
    if ( v25 == 7 )
      break;
    if ( v25 == 2 )
    {
      if ( (unsigned int)v26 > 7 )
        goto LABEL_53;
      v28 = 8 * v26 + 160;
      v29 = (unsigned int ***)((char *)g_ife_hw_mgr + v28);
      goto LABEL_33;
    }
    if ( v25 )
      goto LABEL_43;
    if ( (unsigned int)v26 >= 8 )
LABEL_53:
      __break(0x5512u);
    v27 = (unsigned int **)&g_ife_hw_mgr[v26 + 12];
LABEL_35:
    a2 = *v27;
    if ( !*v27 || (v30 = v23[1], (unsigned int)v30 >= 2) )
    {
LABEL_43:
      v37 = "Invalid base %u type %u";
      v38 = 11868;
      goto LABEL_41;
    }
    v31 = *(_QWORD *)(v24 + ((unsigned __int64)v22 << 7) + 8 * v30 + 32);
    if ( v31 )
    {
      v32 = v9;
      result = cam_isp_add_cmd_buf_update(
                 v31,
                 (__int64)a2,
                 16,
                 0x40u,
                 (const void *)(*(_QWORD *)(v10 + 8) + (v15 & 0xFFFFFFFC) + (v19 & 0xFFFFFFFC)),
                 v20,
                 (__int64)(v16 - 1),
                 &v45);
      if ( (result & 0x80000000) != 0 )
      {
        v35 = **(_DWORD **)(v32 + 8);
        v36 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_blob_bw_limit_update",
          11893,
          "Failed to update %s BW limiter config for res:0x%x enable:%d [0x%x:0x%x] base_idx:%d bytes_used:%u rc:%d ctx_idx: %u",
          v41,
          *(v16 - 1),
          *v16,
          v16[1],
          v16[2],
          v35,
          v45,
          result,
          *(_DWORD *)(v44 + 56));
LABEL_50:
        result = v36;
        goto LABEL_51;
      }
      v7 = v44;
      v9 = v32;
      v15 += v45;
    }
LABEL_8:
    ++v13;
    v16 += 10;
    if ( v13 >= *v8 )
    {
      if ( !v15 )
        goto LABEL_51;
      v33 = v9;
      v36 = result;
      v34 = *(_BYTE *)(v9 + 24) == 1
         && *(_DWORD *)(*(_QWORD *)(a3 + 32) + 32LL * (unsigned int)(*(_DWORD *)(a3 + 40) - 1) + 12) == 2;
      cam_isp_update_hw_entry(2, a3, v10, v15, v34);
      *(_BYTE *)(v33 + 24) = 1;
      goto LABEL_50;
    }
  }
  if ( (unsigned int)v26 > 2 )
    goto LABEL_53;
  v28 = (8 * v26) | 0xE0;
  v29 = (unsigned int ***)&g_ife_hw_mgr[v26 + 28];
LABEL_33:
  if ( v28 <= 0x13FD8 )
  {
    v27 = *v29;
    goto LABEL_35;
  }
  __break(1u);
  return cam_isp_validate_fcg_configs(result, a2, a3, v7);
}
