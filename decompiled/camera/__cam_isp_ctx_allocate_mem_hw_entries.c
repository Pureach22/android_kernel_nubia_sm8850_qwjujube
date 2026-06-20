__int64 __fastcall _cam_isp_ctx_allocate_mem_hw_entries(__int64 a1, __int64 a2)
{
  int v2; // w7
  int v5; // w6
  __int64 v6; // x22
  char v7; // w8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x23
  __int64 *v12; // x28
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x7
  int v19; // w8
  const char *v20; // x5
  __int64 v21; // x1
  __int64 v22; // x4
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 result; // x0
  __int64 v27; // x7
  const char *v28; // x5
  __int64 v29; // x4
  __int64 *v30; // x21
  unsigned int *v31; // x27
  __int64 v32; // x10
  __int64 *v33; // x8
  _QWORD *v34; // x28
  __int64 v35; // x24
  __int64 v36; // x23
  __int64 v37; // x0
  int v38; // w8
  __int64 v39; // x22
  int v40; // w25
  __int64 v41; // x23
  __int64 v42; // x0
  __int64 v43; // x24
  __int64 v44; // x23
  __int64 v45; // x0
  __int64 v46; // x22
  int v47; // w28
  __int64 v48; // x23
  __int64 v49; // x0
  int v50; // [xsp+8h] [xbp-38h]
  int v51; // [xsp+8h] [xbp-38h]
  int v52; // [xsp+30h] [xbp-10h]

  v2 = *(_DWORD *)(a2 + 164);
  if ( v2 )
  {
    if ( (*(_BYTE *)(a2 + 60) & 0x10) != 0 )
    {
      v5 = 40;
      v2 += *(_DWORD *)(a2 + 168);
    }
    else
    {
      v5 = 30;
    }
  }
  else
  {
    v2 = 24;
    v5 = 30;
  }
  v6 = *(_QWORD *)(a1 + 256);
  v7 = debug_mdl;
  *(_DWORD *)(a1 + 472) = v2;
  *(_DWORD *)(a1 + 476) = v2;
  *(_DWORD *)(a1 + 468) = v5;
  if ( (v7 & 8) != 0 && !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v7 & 8,
      4,
      "__cam_isp_ctx_allocate_mem_hw_entries",
      8297,
      "Allocate max_entries: 0x%x max_res: 0x%x is_sfe_en: %d, ctx: %u, link: 0x%x",
      v5,
      v2,
      *(_DWORD *)(a2 + 60) & 0x10,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  if ( mem_trace_en == 1 )
  {
    v8 = cam_mem_trace_alloc(64, 0xCC0u, 0, "__cam_isp_ctx_allocate_mem_hw_entries", 0x206Du);
    *(_QWORD *)(a1 + 480) = v8;
    if ( v8 )
      goto LABEL_11;
LABEL_34:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, _DWORD, int))cam_print_log)(
      3,
      0x80000,
      1,
      "__cam_isp_ctx_allocate_mem_hw_entries",
      8305,
      "%s[%u] no memory, link: 0x%x",
      a1,
      *(unsigned int *)(a1 + 32),
      *(_DWORD *)(a1 + 64),
      v50);
    return 4294967284LL;
  }
  v23 = _kvmalloc_node_noprof(64, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(a1 + 480) = v23;
  if ( !v23 )
    goto LABEL_34;
LABEL_11:
  if ( mem_trace_en == 1 )
  {
    v9 = cam_mem_trace_alloc(64, 0xCC0u, 0, "__cam_isp_ctx_allocate_mem_hw_entries", 0x2077u);
    *(_QWORD *)(a1 + 488) = v9;
    if ( v9 )
      goto LABEL_13;
LABEL_36:
    v18 = *(unsigned int *)(a1 + 32);
    v19 = *(_DWORD *)(a1 + 64);
    v20 = "%s[%u] no memory for in_map_entries, link: 0x%x";
    v21 = 0x80000;
    v22 = 8315;
    goto LABEL_39;
  }
  v24 = _kvmalloc_node_noprof(64, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(a1 + 488) = v24;
  if ( !v24 )
    goto LABEL_36;
LABEL_13:
  if ( mem_trace_en != 1 )
  {
    v25 = _kvmalloc_node_noprof(64, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(a1 + 496) = v25;
    if ( v25 )
      goto LABEL_15;
LABEL_38:
    v18 = *(unsigned int *)(a1 + 32);
    v19 = *(_DWORD *)(a1 + 64);
    v20 = "%s[%u] no memory for out_map_entries, link: 0x%x";
    v21 = 0x80000;
    v22 = 8326;
    goto LABEL_39;
  }
  v10 = cam_mem_trace_alloc(64, 0xCC0u, 0, "__cam_isp_ctx_allocate_mem_hw_entries", 0x2082u);
  *(_QWORD *)(a1 + 496) = v10;
  if ( !v10 )
    goto LABEL_38;
LABEL_15:
  v11 = 0;
  v12 = (__int64 *)(v6 + 1264);
  _ReadStatusReg(SP_EL0);
  do
  {
    if ( mem_trace_en == 1 )
      v14 = cam_mem_trace_alloc(
              32LL * *(unsigned int *)(a1 + 468),
              0xCC0u,
              0,
              "__cam_isp_ctx_allocate_mem_hw_entries",
              0x208Fu);
    else
      v14 = _kvmalloc_node_noprof(32LL * *(unsigned int *)(a1 + 468), 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(*(_QWORD *)(a1 + 480) + 8 * v11) = v14;
    if ( !*(_QWORD *)(*(_QWORD *)(a1 + 480) + 8 * v11) )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, _DWORD, _DWORD))cam_print_log)(
        3,
        0x80000,
        1,
        "__cam_isp_ctx_allocate_mem_hw_entries",
        8338,
        "%s[%u] no memory for hw_update_entry: %u, link: 0x%x",
        a1,
        *(unsigned int *)(a1 + 32),
        v11,
        *(_DWORD *)(a1 + 64));
      return 4294967284LL;
    }
    if ( mem_trace_en == 1 )
      v15 = cam_mem_trace_alloc(
              (unsigned __int64)*(unsigned int *)(a1 + 472) << 6,
              0xCC0u,
              0,
              "__cam_isp_ctx_allocate_mem_hw_entries",
              0x2098u);
    else
      v15 = _kvmalloc_node_noprof((unsigned __int64)*(unsigned int *)(a1 + 472) << 6, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(*(_QWORD *)(a1 + 488) + 8 * v11) = v15;
    if ( !*(_QWORD *)(*(_QWORD *)(a1 + 488) + 8 * v11) )
    {
      v27 = *(unsigned int *)(a1 + 32);
      v28 = "%s[%u] no memory for in_map_entries: %u, link: 0x%x";
      v29 = 8348;
      v51 = *(_DWORD *)(a1 + 64);
LABEL_46:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, _DWORD, int))cam_print_log)(
        3,
        0x80000,
        1,
        "__cam_isp_ctx_allocate_mem_hw_entries",
        v29,
        v28,
        a1,
        v27,
        v11,
        v51);
      goto LABEL_40;
    }
    if ( mem_trace_en == 1 )
      v16 = cam_mem_trace_alloc(
              (unsigned __int64)*(unsigned int *)(a1 + 476) << 6,
              0xCC0u,
              0,
              "__cam_isp_ctx_allocate_mem_hw_entries",
              0x20A3u);
    else
      v16 = _kvmalloc_node_noprof((unsigned __int64)*(unsigned int *)(a1 + 476) << 6, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(*(_QWORD *)(a1 + 496) + 8 * v11) = v16;
    if ( !*(_QWORD *)(*(_QWORD *)(a1 + 496) + 8 * v11) )
    {
      v27 = *(unsigned int *)(a1 + 32);
      v28 = "%s[%u] no memory for out_map_entries: %u, link: 0x%x";
      v51 = *(_DWORD *)(a1 + 64);
      v29 = 8359;
      goto LABEL_46;
    }
    if ( mem_trace_en == 1 )
    {
      v13 = cam_mem_trace_alloc(
              4LL * *(unsigned int *)(a2 + 148),
              0xCC0u,
              0,
              "__cam_isp_ctx_allocate_mem_hw_entries",
              0x20AEu);
      *v12 = v13;
      if ( !v13 )
        goto LABEL_32;
    }
    else
    {
      v17 = _kvmalloc_node_noprof(4LL * *(unsigned int *)(a2 + 148), 0, 3520, 0xFFFFFFFFLL);
      *v12 = v17;
      if ( !v17 )
      {
LABEL_32:
        v18 = *(unsigned int *)(a1 + 32);
        v19 = *(_DWORD *)(a2 + 148);
        v20 = "%s[%d] no memory for defer fence map idx arr, ports:%u";
        v21 = 8;
        v22 = 8369;
        goto LABEL_39;
      }
    }
    ++v11;
    v12 += 564;
  }
  while ( v11 != 8 );
  v30 = *(__int64 **)(a1 + 176);
  v31 = *(unsigned int **)(v6 + 45704);
  if ( v30 == (__int64 *)(a1 + 176) )
  {
LABEL_81:
    if ( v31 )
    {
      result = 0;
      if ( (debug_mdl & 8) == 0 || debug_priority )
        return result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_allocate_mem_hw_entries",
        8407,
        "Finish allocating FCG related structure, ctx_id: %u, FCG IFE/MC_TFE supported: %d, FCG SFE supported: %d, SFE_EN: %d",
        *(_DWORD *)(a1 + 32),
        *((unsigned __int8 *)v31 + 16),
        *((unsigned __int8 *)v31 + 17),
        (*(_DWORD *)(a2 + 60) >> 4) & 1);
    }
    return 0;
  }
  _ReadStatusReg(SP_EL0);
  while ( 2 )
  {
    v32 = *((unsigned int *)v30 + 23);
    v33 = v30;
    v34 = (_QWORD *)v30[4];
    v30 = (__int64 *)*v30;
    v34[1] = *(_QWORD *)(*(_QWORD *)(a1 + 480) + 8 * v32);
    v34[5] = *(_QWORD *)(*(_QWORD *)(a1 + 488) + 8LL * *((unsigned int *)v33 + 23));
    v34[3] = *(_QWORD *)(*(_QWORD *)(a1 + 496) + 8LL * *((unsigned int *)v33 + 23));
    if ( !v31 )
      goto LABEL_49;
    if ( (v31[4] & 1) == 0 )
    {
      if ( *((_BYTE *)v31 + 17) == 1 )
      {
        v38 = *(_DWORD *)(a2 + 60);
        goto LABEL_66;
      }
LABEL_49:
      if ( v30 == (__int64 *)(a1 + 176) )
        goto LABEL_81;
      continue;
    }
    break;
  }
  v35 = *v31;
  v36 = v31[2];
  v52 = *(_DWORD *)(a2 + 60);
  if ( mem_trace_en == 1 )
    v37 = cam_mem_trace_alloc(16 * v35, 0xCC0u, 0, "__cam_isp_ctx_allocate_mem_fcg_config", 0x2023u);
  else
    v37 = _kvmalloc_node_noprof(16 * v35, 0, 3520, 0xFFFFFFFFLL);
  v39 = v37;
  v34[554] = v37;
  if ( !v37 )
    goto LABEL_80;
  if ( !(_DWORD)v35 )
  {
LABEL_65:
    LOBYTE(v38) = v52;
LABEL_66:
    if ( (v38 & 0x10) != 0 && (*((_BYTE *)v31 + 17) & 1) != 0 )
    {
      v43 = v31[1];
      v44 = v31[3];
      if ( mem_trace_en == 1 )
        v45 = cam_mem_trace_alloc(16 * v43, 0xCC0u, 0, "__cam_isp_ctx_allocate_mem_fcg_config", 0x2039u);
      else
        v45 = _kvmalloc_node_noprof(16 * v43, 0, 3520, 0xFFFFFFFFLL);
      v46 = v45;
      v34[550] = v45;
      if ( !v45 )
        goto LABEL_80;
      if ( (_DWORD)v43 )
      {
        v47 = 0;
        v48 = 24 * v44;
        while ( 1 )
        {
          v49 = mem_trace_en == 1
              ? cam_mem_trace_alloc(v48, 0xCC0u, 0, "__cam_isp_ctx_allocate_mem_fcg_config", 0x2042u)
              : _kvmalloc_node_noprof(v48, 0, 3520, 0xFFFFFFFFLL);
          *(_QWORD *)(v46 + 16LL * v47 + 8) = v49;
          if ( !v49 )
            goto LABEL_80;
          if ( (_DWORD)v43 == ++v47 )
            goto LABEL_49;
        }
      }
    }
    goto LABEL_49;
  }
  v40 = 0;
  v41 = 24 * v36;
  while ( 1 )
  {
    v42 = mem_trace_en == 1
        ? cam_mem_trace_alloc(v41, 0xCC0u, 0, "__cam_isp_ctx_allocate_mem_fcg_config", 0x202Cu)
        : _kvmalloc_node_noprof(v41, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(v39 + 16LL * v40 + 8) = v42;
    if ( !v42 )
      break;
    if ( (_DWORD)v35 == ++v40 )
      goto LABEL_65;
  }
LABEL_80:
  v18 = *(unsigned int *)(a1 + 32);
  v19 = *(_DWORD *)(a1 + 64);
  v20 = "No sufficient memory for FCG channel/context in %s, ctx_id: %u, link: 0x%x";
  v21 = 0x80000;
  v22 = 8396;
LABEL_39:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, int))cam_print_log)(
    3,
    v21,
    1,
    "__cam_isp_ctx_allocate_mem_hw_entries",
    v22,
    v20,
    a1,
    v18,
    v19,
    v50);
LABEL_40:
  _cam_isp_ctx_free_mem_hw_entries(a1);
  return 4294967284LL;
}
