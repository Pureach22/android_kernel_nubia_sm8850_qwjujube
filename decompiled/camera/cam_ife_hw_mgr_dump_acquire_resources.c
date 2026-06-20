__int64 __fastcall cam_ife_hw_mgr_dump_acquire_resources(__int64 a1)
{
  unsigned __int64 v1; // x8
  unsigned __int64 v3; // x9
  unsigned __int64 v4; // x11
  unsigned __int64 v5; // x10
  __int64 v6; // x13
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x6
  const char *v9; // x10
  const char *v10; // x14
  __int64 result; // x0
  _QWORD *v12; // x26
  __int64 v13; // x8
  _QWORD *v14; // x25
  __int64 v15; // x9
  __int64 v16; // x11
  const char *v17; // x10
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 v20; // x11
  const char *v21; // x10
  _QWORD *v22; // x26
  __int64 v23; // x8
  _QWORD *v24; // x25
  __int64 v25; // x9
  __int64 v26; // x11
  const char *v27; // x10
  __int64 v28; // x8
  __int64 v29; // x9
  __int64 v30; // x11
  const char *v31; // x10
  _QWORD *v32; // x26
  __int64 v33; // x8
  _QWORD *v34; // x25
  __int64 v35; // x9
  __int64 v36; // x11
  const char *v37; // x10
  __int64 v38; // x8
  __int64 v39; // x9
  __int64 v40; // x11
  const char *v41; // x10
  _QWORD *v42; // x26
  __int64 v43; // x8
  _QWORD *v44; // x25
  __int64 v45; // x9
  __int64 v46; // x11
  const char *v47; // x10
  __int64 v48; // x8
  __int64 v49; // x9
  __int64 v50; // x11
  const char *v51; // x10
  int v52; // w8
  __int64 v53; // x24
  __int64 v54; // x10
  __int64 v55; // x8
  __int64 v56; // x9
  __int64 v57; // x11
  const char *v58; // x10
  __int64 v59; // x8
  __int64 v60; // x9
  __int64 v61; // x11
  const char *v62; // x10
  int v63; // w8
  __int64 v64; // x24
  __int64 v65; // x10
  __int64 v66; // x8
  __int64 v67; // x9
  __int64 v68; // x11
  const char *v69; // x10
  __int64 v70; // x8
  __int64 v71; // x9
  __int64 v72; // x11
  const char *v73; // x10

  v1 = *(_QWORD *)(a1 + 9320);
  v3 = v1 / 0x3C;
  v4 = (v1 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64;
  v5 = v1 / 0xE10;
  v6 = (v1 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64;
  v7 = v1 % 0x3C;
  v8 = v5 - 24 * v6;
  v9 = "false";
  if ( *(_BYTE *)(a1 + 9385) )
    v10 = "true";
  else
    v10 = "false";
  if ( *(_BYTE *)(a1 + 9379) )
    v9 = "true";
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64, unsigned __int64, unsigned __int64, __int64, _DWORD, const char *, const char *))cam_print_log)(
             3,
             8,
             3,
             "cam_ife_hw_mgr_dump_acquire_resources",
             2172,
             "**** %llu:%llu:%llu.%llu ctx_idx: %u rdi_only: %s is_dual: %s acquired ****",
             v8,
             v3 - 60 * (v4 >> 1),
             v7,
             *(_QWORD *)(a1 + 9328) / 1000000LL,
             *(_DWORD *)(a1 + 56),
             v10,
             v9);
  v12 = *(_QWORD **)(a1 + 208);
  if ( v12 != (_QWORD *)(a1 + 208) )
  {
    do
    {
      v13 = v12[4];
      v14 = (_QWORD *)*v12;
      if ( v13 )
      {
        v15 = *(_QWORD *)(v13 + 16);
        if ( v15 )
        {
          v16 = *(unsigned int *)(v13 + 8);
          v17 = "INVALID STATE";
          if ( (unsigned int)v16 <= 4 )
            v17 = off_451508[v16];
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     3,
                     "cam_ife_hw_mgr_dump_acquire_resources",
                     2188,
                     "CSID split_id:%d ctx_idx:%u hw_idx:%u res:%s type:%d res_id:%d state:%s",
                     0,
                     *(_DWORD *)(a1 + 56),
                     *(_DWORD *)(v15 + 4),
                     (const char *)(v13 + 128),
                     *(_DWORD *)v13,
                     *(_DWORD *)(v13 + 4),
                     v17);
        }
      }
      v18 = v12[5];
      if ( v18 )
      {
        v19 = *(_QWORD *)(v18 + 16);
        if ( v19 )
        {
          v20 = *(unsigned int *)(v18 + 8);
          v21 = "INVALID STATE";
          if ( (unsigned int)v20 <= 4 )
            v21 = off_451508[v20];
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     3,
                     "cam_ife_hw_mgr_dump_acquire_resources",
                     2188,
                     "CSID split_id:%d ctx_idx:%u hw_idx:%u res:%s type:%d res_id:%d state:%s",
                     1,
                     *(_DWORD *)(a1 + 56),
                     *(_DWORD *)(v19 + 4),
                     (const char *)(v18 + 128),
                     *(_DWORD *)v18,
                     *(_DWORD *)(v18 + 4),
                     v21);
        }
      }
      v12 = v14;
    }
    while ( v14 != (_QWORD *)(a1 + 208) );
  }
  v22 = *(_QWORD **)(a1 + 224);
  if ( v22 != (_QWORD *)(a1 + 224) )
  {
    do
    {
      v23 = v22[4];
      v24 = (_QWORD *)*v22;
      if ( v23 )
      {
        v25 = *(_QWORD *)(v23 + 16);
        if ( v25 )
        {
          v26 = *(unsigned int *)(v23 + 8);
          v27 = "INVALID STATE";
          if ( (unsigned int)v26 <= 4 )
            v27 = off_451508[v26];
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     3,
                     "cam_ife_hw_mgr_dump_acquire_resources",
                     2206,
                     "IFE src split_id:%d ctx_idx:%u hw_idx:%u res:%s type:%d res_id:%d state:%s",
                     0,
                     *(_DWORD *)(a1 + 56),
                     *(_DWORD *)(v25 + 4),
                     (const char *)(v23 + 128),
                     *(_DWORD *)v23,
                     *(_DWORD *)(v23 + 4),
                     v27);
        }
      }
      v28 = v22[5];
      if ( v28 )
      {
        v29 = *(_QWORD *)(v28 + 16);
        if ( v29 )
        {
          v30 = *(unsigned int *)(v28 + 8);
          v31 = "INVALID STATE";
          if ( (unsigned int)v30 <= 4 )
            v31 = off_451508[v30];
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     3,
                     "cam_ife_hw_mgr_dump_acquire_resources",
                     2206,
                     "IFE src split_id:%d ctx_idx:%u hw_idx:%u res:%s type:%d res_id:%d state:%s",
                     1,
                     *(_DWORD *)(a1 + 56),
                     *(_DWORD *)(v29 + 4),
                     (const char *)(v28 + 128),
                     *(_DWORD *)v28,
                     *(_DWORD *)(v28 + 4),
                     v31);
        }
      }
      v22 = v24;
    }
    while ( v24 != (_QWORD *)(a1 + 224) );
  }
  v32 = *(_QWORD **)(a1 + 240);
  if ( v32 != (_QWORD *)(a1 + 240) )
  {
    do
    {
      v33 = v32[4];
      v34 = (_QWORD *)*v32;
      if ( v33 )
      {
        v35 = *(_QWORD *)(v33 + 16);
        if ( v35 )
        {
          v36 = *(unsigned int *)(v33 + 8);
          v37 = "INVALID STATE";
          if ( (unsigned int)v36 <= 4 )
            v37 = off_451508[v36];
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     3,
                     "cam_ife_hw_mgr_dump_acquire_resources",
                     2224,
                     "SFE src split_id:%d ctx_idx:%u hw_idx:%u res:%s type:%d res_id:%d state:%s",
                     0,
                     *(_DWORD *)(a1 + 56),
                     *(_DWORD *)(v35 + 4),
                     (const char *)(v33 + 128),
                     *(_DWORD *)v33,
                     *(_DWORD *)(v33 + 4),
                     v37);
        }
      }
      v38 = v32[5];
      if ( v38 )
      {
        v39 = *(_QWORD *)(v38 + 16);
        if ( v39 )
        {
          v40 = *(unsigned int *)(v38 + 8);
          v41 = "INVALID STATE";
          if ( (unsigned int)v40 <= 4 )
            v41 = off_451508[v40];
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     3,
                     "cam_ife_hw_mgr_dump_acquire_resources",
                     2224,
                     "SFE src split_id:%d ctx_idx:%u hw_idx:%u res:%s type:%d res_id:%d state:%s",
                     1,
                     *(_DWORD *)(a1 + 56),
                     *(_DWORD *)(v39 + 4),
                     (const char *)(v38 + 128),
                     *(_DWORD *)v38,
                     *(_DWORD *)(v38 + 4),
                     v41);
        }
      }
      v32 = v34;
    }
    while ( v34 != (_QWORD *)(a1 + 240) );
  }
  v42 = *(_QWORD **)(a1 + 256);
  if ( v42 != (_QWORD *)(a1 + 256) )
  {
    do
    {
      v43 = v42[4];
      v44 = (_QWORD *)*v42;
      if ( v43 )
      {
        v45 = *(_QWORD *)(v43 + 16);
        if ( v45 )
        {
          v46 = *(unsigned int *)(v43 + 8);
          v47 = "INVALID STATE";
          if ( (unsigned int)v46 <= 4 )
            v47 = off_451508[v46];
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     3,
                     "cam_ife_hw_mgr_dump_acquire_resources",
                     2242,
                     "src_rd split_id:%d ctx_idx:%u hw_idx:%u res:%s type:%d res_id:%d state:%s",
                     0,
                     *(_DWORD *)(a1 + 56),
                     *(_DWORD *)(v45 + 4),
                     (const char *)(v43 + 128),
                     *(_DWORD *)v43,
                     *(_DWORD *)(v43 + 4),
                     v47);
        }
      }
      v48 = v42[5];
      if ( v48 )
      {
        v49 = *(_QWORD *)(v48 + 16);
        if ( v49 )
        {
          v50 = *(unsigned int *)(v48 + 8);
          v51 = "INVALID STATE";
          if ( (unsigned int)v50 <= 4 )
            v51 = off_451508[v50];
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     3,
                     "cam_ife_hw_mgr_dump_acquire_resources",
                     2242,
                     "src_rd split_id:%d ctx_idx:%u hw_idx:%u res:%s type:%d res_id:%d state:%s",
                     1,
                     *(_DWORD *)(a1 + 56),
                     *(_DWORD *)(v49 + 4),
                     (const char *)(v48 + 128),
                     *(_DWORD *)v48,
                     *(_DWORD *)(v48 + 4),
                     v51);
        }
      }
      v42 = v44;
    }
    while ( v44 != (_QWORD *)(a1 + 256) );
  }
  if ( *(_DWORD *)(a1 + 8512) )
  {
    v52 = 0;
    do
    {
      v53 = v52;
      v54 = *(_QWORD *)(a1 + 272);
      v55 = *(_QWORD *)(v54 + ((__int64)v52 << 7) + 32);
      if ( v55 )
      {
        v56 = *(_QWORD *)(v55 + 16);
        if ( v56 )
        {
          v57 = *(unsigned int *)(v55 + 8);
          v58 = "INVALID STATE";
          if ( (unsigned int)v57 <= 4 )
            v58 = off_451508[v57];
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     3,
                     "cam_ife_hw_mgr_dump_acquire_resources",
                     2260,
                     "IFE out split_id:%d ctx_idx:%u hw_idx:%u res:%s type:%d res_id:%d state:%s",
                     0,
                     *(_DWORD *)(a1 + 56),
                     *(_DWORD *)(v56 + 4),
                     (const char *)(v55 + 128),
                     *(_DWORD *)v55,
                     *(_DWORD *)(v55 + 4),
                     v58);
          v54 = *(_QWORD *)(a1 + 272);
        }
      }
      v59 = *(_QWORD *)(v54 + (v53 << 7) + 40);
      if ( v59 )
      {
        v60 = *(_QWORD *)(v59 + 16);
        if ( v60 )
        {
          v61 = *(unsigned int *)(v59 + 8);
          v62 = "INVALID STATE";
          if ( (unsigned int)v61 <= 4 )
            v62 = off_451508[v61];
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     3,
                     "cam_ife_hw_mgr_dump_acquire_resources",
                     2260,
                     "IFE out split_id:%d ctx_idx:%u hw_idx:%u res:%s type:%d res_id:%d state:%s",
                     1,
                     *(_DWORD *)(a1 + 56),
                     *(_DWORD *)(v60 + 4),
                     (const char *)(v59 + 128),
                     *(_DWORD *)v59,
                     *(_DWORD *)(v59 + 4),
                     v62);
        }
      }
      v52 = v53 + 1;
    }
    while ( (unsigned int)(v53 + 1) < *(_DWORD *)(a1 + 8512) );
  }
  if ( *(_DWORD *)(a1 + 8516) )
  {
    v63 = 0;
    do
    {
      v64 = v63;
      v65 = *(_QWORD *)(a1 + 280);
      v66 = *(_QWORD *)(v65 + ((__int64)v63 << 7) + 32);
      if ( v66 )
      {
        v67 = *(_QWORD *)(v66 + 16);
        if ( v67 )
        {
          v68 = *(unsigned int *)(v66 + 8);
          v69 = "INVALID STATE";
          if ( (unsigned int)v68 <= 4 )
            v69 = off_451508[v68];
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     3,
                     "cam_ife_hw_mgr_dump_acquire_resources",
                     2278,
                     "SFE out split_id:%d ctx_idx:%u hw_idx:%u res:%s type:%d res_id:%d state:%s",
                     0,
                     *(_DWORD *)(a1 + 56),
                     *(_DWORD *)(v67 + 4),
                     (const char *)(v66 + 128),
                     *(_DWORD *)v66,
                     *(_DWORD *)(v66 + 4),
                     v69);
          v65 = *(_QWORD *)(a1 + 280);
        }
      }
      v70 = *(_QWORD *)(v65 + (v64 << 7) + 40);
      if ( v70 )
      {
        v71 = *(_QWORD *)(v70 + 16);
        if ( v71 )
        {
          v72 = *(unsigned int *)(v70 + 8);
          v73 = "INVALID STATE";
          if ( (unsigned int)v72 <= 4 )
            v73 = off_451508[v72];
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     3,
                     "cam_ife_hw_mgr_dump_acquire_resources",
                     2278,
                     "SFE out split_id:%d ctx_idx:%u hw_idx:%u res:%s type:%d res_id:%d state:%s",
                     1,
                     *(_DWORD *)(a1 + 56),
                     *(_DWORD *)(v71 + 4),
                     (const char *)(v70 + 128),
                     *(_DWORD *)v70,
                     *(_DWORD *)(v70 + 4),
                     v73);
        }
      }
      v63 = v64 + 1;
    }
    while ( (unsigned int)(v64 + 1) < *(_DWORD *)(a1 + 8516) );
  }
  return result;
}
