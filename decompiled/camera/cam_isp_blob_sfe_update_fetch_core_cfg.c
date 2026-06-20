__int64 __fastcall cam_isp_blob_sfe_update_fetch_core_cfg(__int64 a1, __int64 a2)
{
  int v2; // w6
  unsigned int v3; // w8
  __int64 v4; // x25
  __int64 *v5; // x26
  __int64 *v6; // x12
  __int64 v7; // x22
  int v10; // w21
  unsigned int v11; // w8
  int v12; // w24
  unsigned int v13; // w5
  unsigned int *v14; // x8
  unsigned int v15; // w7
  __int64 v16; // x6
  __int64 v17; // x1
  unsigned __int64 v18; // x10
  __int64 **v19; // x9
  __int64 v20; // x8
  int v21; // w23
  _BOOL4 v22; // w9
  __int64 v23; // x27
  int v24; // w0
  const char *v25; // x5
  __int64 v26; // x4
  __int64 result; // x0
  char v28; // w4
  int v29; // w7
  const char *v30; // x6
  unsigned int v31; // w19
  unsigned int v32; // [xsp+2Ch] [xbp-24h]
  __int64 v33; // [xsp+30h] [xbp-20h]
  char v34[4]; // [xsp+40h] [xbp-10h] BYREF
  int v35; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+48h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a2 + 40);
  v3 = *(_DWORD *)(a2 + 24);
  v4 = *(_QWORD *)(a2 + 16);
  v35 = 0;
  v34[0] = 1;
  if ( v2 + 1 >= v3 )
  {
LABEL_30:
    v25 = "Insufficient HW entries :%d, ctx_idx: %u";
    v26 = 10513;
LABEL_32:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_sfe_update_fetch_core_cfg",
      v26,
      v25);
    result = 4294967274LL;
    goto LABEL_38;
  }
  v5 = *(__int64 **)(v4 + 256);
  v6 = (__int64 *)(v4 + 256);
  if ( v5 == (__int64 *)(v4 + 256) )
  {
LABEL_37:
    result = 0;
    goto LABEL_38;
  }
  v7 = *(_QWORD *)(a1 + 16);
  v10 = 0;
  do
  {
    v11 = *(_DWORD *)(v7 + 20);
    v12 = *(_DWORD *)(v7 + 24);
    v13 = v11 - (v12 + v10);
    if ( v11 <= v12 + v10 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_blob_sfe_update_fetch_core_cfg",
        10527,
        "No free kmd memory for base idx: %d, ctx_idx: %u",
        **(_DWORD **)(a1 + 8),
        *(_DWORD *)(v4 + 56));
      result = 4294967284LL;
      goto LABEL_38;
    }
    v14 = *(unsigned int **)(a1 + 8);
    v15 = v14[2];
    v16 = *v14;
    if ( v15 == 7 )
    {
      if ( (unsigned int)v16 > 2 )
        goto LABEL_29;
      v18 = (8 * v16) | 0xE0;
      v19 = (__int64 **)&g_ife_hw_mgr[v16 + 28];
    }
    else
    {
      if ( v15 != 2 )
      {
        if ( v15 )
          goto LABEL_31;
        if ( (unsigned int)v16 >= 8 )
        {
LABEL_29:
          __break(0x5512u);
          goto LABEL_30;
        }
        v17 = g_ife_hw_mgr[v16 + 12];
        if ( !v17 )
          goto LABEL_31;
        goto LABEL_18;
      }
      if ( (unsigned int)v16 > 7 )
        goto LABEL_29;
      v18 = 8 * v16 + 160;
      v19 = (__int64 **)((char *)g_ife_hw_mgr + v18);
    }
    if ( v18 > 0x13FD8 )
      __break(1u);
    v17 = **v19;
    if ( !v17 )
    {
LABEL_31:
      v25 = "Invalid base %u type %u";
      v26 = 10537;
      goto LABEL_32;
    }
LABEL_18:
    v20 = v14[1];
    if ( (unsigned int)v20 >= 2 )
      goto LABEL_31;
    if ( v5[v20 + 4] )
    {
      v21 = *((_DWORD *)v5 + 5);
      v22 = (*(_BYTE *)(v4 + 9316) & 4) == 0 || (unsigned int)(v21 - 20481) < *(_DWORD *)(*(_QWORD *)(v4 + 9360) + 8LL);
      v23 = *(_QWORD *)(v7 + 8);
      v34[0] = v22;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v33 = v17;
        v32 = v13;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_isp_blob_sfe_update_fetch_core_cfg",
          10563,
          "SFE:%u RM: %u res_id: 0x%x enable: %u num_exp: %u ctx_idx: %u",
          v16,
          v21 - 20481,
          v21,
          v22,
          *(_DWORD *)(*(_QWORD *)(v4 + 9360) + 8LL),
          *(_DWORD *)(v4 + 56));
        v17 = v33;
        v13 = v32;
        v20 = *(unsigned int *)(*(_QWORD *)(a1 + 8) + 4LL);
        if ( (unsigned int)v20 > 1 )
          goto LABEL_29;
      }
      v24 = cam_isp_add_cmd_buf_update(
              v5[v20 + 4],
              v17,
              15,
              0x41u,
              (const void *)(v23 + (v10 & 0xFFFFFFFC) + (v12 & 0xFFFFFFFC)),
              v13,
              (__int64)v34,
              &v35);
      if ( v24 < 0 )
      {
        v29 = **(_DWORD **)(a1 + 8);
        if ( v34[0] )
          v30 = "enable";
        else
          v30 = "disable";
        v31 = v24;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_blob_sfe_update_fetch_core_cfg",
          10577,
          "Failed to dynamically %s SFE: %u RM: %u bytes_used: %u rc: %d ctx_idx: %u",
          v30,
          v29,
          v21,
          v35,
          v24,
          *(_DWORD *)(v4 + 56));
        result = v31;
        goto LABEL_38;
      }
      v6 = (__int64 *)(v4 + 256);
      v10 += v35;
    }
    v5 = (__int64 *)*v5;
  }
  while ( v5 != v6 );
  if ( !v10 )
    goto LABEL_37;
  v28 = *(_BYTE *)(a1 + 24) == 1
     && *(_DWORD *)(*(_QWORD *)(a2 + 32) + 32LL * (unsigned int)(*(_DWORD *)(a2 + 40) - 1) + 12) == 2;
  cam_isp_update_hw_entry(2, a2, v7, v10, v28);
  result = 0;
  *(_BYTE *)(a1 + 24) = 1;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
