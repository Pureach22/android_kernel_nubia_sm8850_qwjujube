__int64 __fastcall cam_ife_hw_mgr_print_acquire_info(__int64 a1, int a2, int a3, int a4, int a5)
{
  __int64 v8; // x8
  _BYTE *v9; // x27
  __int64 v10; // x9
  __int64 v11; // x9
  unsigned int v12; // w22
  __int64 v13; // x8
  __int64 v14; // x8
  int v15; // w23
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x9
  int v19; // w24
  __int64 v20; // x8
  __int64 v21; // x8
  int v22; // w25
  int v23; // w8
  const char *v24; // x6
  __int64 v25; // x19
  __int64 *v26; // x25
  __int64 v27; // x0
  unsigned int v29; // w23
  int v30; // w0
  __int64 result; // x0
  int v32; // w0
  int v33; // w4
  unsigned int v34; // w22
  int v35; // w4
  int v36; // w4
  unsigned __int64 v37; // x8
  _QWORD v38[17]; // [xsp+38h] [xbp-88h] BYREF

  v38[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 224);
  v9 = (_BYTE *)(a1 + 0x2000);
  memset(v38, 0, 128);
  if ( v8 != a1 + 224 )
  {
    v10 = *(_QWORD *)(v8 + 32);
    if ( v10 && (v11 = *(_QWORD *)(v10 + 16)) != 0 )
    {
      v12 = *(_DWORD *)(v11 + 4);
      v13 = *(_QWORD *)(v8 + 40);
      if ( !v13 )
        goto LABEL_9;
    }
    else
    {
      v12 = -1;
      v13 = *(_QWORD *)(v8 + 40);
      if ( !v13 )
      {
LABEL_9:
        v15 = -1;
        goto LABEL_11;
      }
    }
    v14 = *(_QWORD *)(v13 + 16);
    if ( v14 )
    {
      v15 = *(_DWORD *)(v14 + 4);
      goto LABEL_11;
    }
    goto LABEL_9;
  }
  v15 = -1;
  v12 = -1;
LABEL_11:
  v16 = *(_QWORD *)(a1 + 240);
  if ( v16 == a1 + 240 )
  {
    v22 = -1;
    v19 = -1;
    v23 = *(unsigned __int8 *)(a1 + 9379);
    if ( a5 )
      goto LABEL_21;
    goto LABEL_33;
  }
  v17 = *(_QWORD *)(v16 + 32);
  if ( v17 && (v18 = *(_QWORD *)(v17 + 16)) != 0 )
  {
    v19 = *(_DWORD *)(v18 + 4);
    v20 = *(_QWORD *)(v16 + 40);
    if ( !v20 )
    {
LABEL_20:
      v22 = -1;
      v23 = *(unsigned __int8 *)(a1 + 9379);
      if ( a5 )
        goto LABEL_21;
LABEL_33:
      if ( v23 )
      {
        v29 = scnprintf(v38, 128, "Dual IFE[%d: %d]", v12, v15);
        if ( *(_DWORD *)(a1 + 9312) == 2 )
        {
          if ( v29 > 0x80 )
            goto LABEL_70;
          v30 = scnprintf((char *)v38 + v29, 128 - v29, " SFE[%d: %d]", v19, v22);
LABEL_42:
          v29 += v30;
        }
      }
      else
      {
        v29 = scnprintf(v38, 128, "Single IFE[%d]", v12);
        if ( *(_DWORD *)(a1 + 9312) == 2 )
        {
          if ( v29 > 0x80 )
            goto LABEL_70;
          v30 = scnprintf((char *)v38 + v29, 128 - v29, " SFE[%d]", v19);
          goto LABEL_42;
        }
      }
      if ( v9[1195] == 1 )
      {
        if ( v29 > 0x80 )
          goto LABEL_70;
        v29 += scnprintf((char *)v38 + v29, 128 - v29, " sHDR: Y");
      }
      if ( v9[1196] == 1 )
      {
        if ( v29 > 0x80 )
          goto LABEL_70;
        v29 += scnprintf((char *)v38 + v29, 128 - v29, " SFE_FS: Y");
      }
      if ( v9[1189] == 1 )
      {
        if ( v29 > 0x80 )
          goto LABEL_70;
        v29 += scnprintf((char *)v38 + v29, 128 - v29, " DSP: Y");
      }
      if ( v9[1188] == 1 )
      {
        if ( v29 > 0x80 )
          goto LABEL_70;
        v29 += scnprintf((char *)v38 + v29, 128 - v29, " OFFLINE: Y");
      }
      if ( v9[1210] == 1 )
      {
        if ( v12 > 7 )
          goto LABEL_70;
        if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 36LL * v12 + 80492) & 1) == 0 )
        {
          if ( v29 > 0x80 )
            goto LABEL_70;
          v32 = scnprintf((char *)v38 + v29, 128 - v29, " HW_CTXT [SRC:DST_MASK]");
          v33 = *(_DWORD *)(a1 + 9520);
          v34 = v32 + v29;
          if ( v33 )
          {
            if ( v34 > 0x80 )
              goto LABEL_70;
            v34 += scnprintf((char *)v38 + v34, 128 - v34, " [%d:0x%x]", 0, v33);
          }
          v35 = *(_DWORD *)(a1 + 9524);
          if ( v35 )
          {
            if ( v34 > 0x80 )
              goto LABEL_70;
            v34 += scnprintf((char *)v38 + v34, 128 - v34, " [%d:0x%x]", 1, v35);
          }
          v36 = *(_DWORD *)(a1 + 9528);
          if ( v36 )
          {
            if ( v34 <= 0x80 )
            {
              scnprintf((char *)v38 + v34, 128 - v34, " [%d:0x%x]", 2, v36);
              goto LABEL_68;
            }
LABEL_70:
            __break(0x5512u);
          }
        }
      }
LABEL_68:
      ktime_get_real_ts64(a1 + 9320);
      v37 = *(_QWORD *)(a1 + 9320);
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 8,
                 3,
                 "cam_ife_hw_mgr_print_acquire_info",
                 2394,
                 "%llu:%llu:%llu.%llu Acquired %s with [%u pix] [%u pd] [%u rdi] ports for ctx:%u",
                 (_QWORD)(v37 / 0xE10 - 24 * ((v37 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64)),
                 v37 / 0x3C
               - 60 * ((unsigned __int64)((v37 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1),
                 v37 % 0x3C,
                 *(_QWORD *)(a1 + 9328) / 1000000LL,
                 (const char *)v38,
                 a2,
                 a3,
                 a4,
                 *(_DWORD *)(a1 + 56));
      goto LABEL_69;
    }
  }
  else
  {
    v19 = -1;
    v20 = *(_QWORD *)(v16 + 40);
    if ( !v20 )
      goto LABEL_20;
  }
  v21 = *(_QWORD *)(v20 + 16);
  if ( !v21 )
    goto LABEL_20;
  v22 = *(_DWORD *)(v21 + 4);
  v23 = *(unsigned __int8 *)(a1 + 9379);
  if ( !a5 )
    goto LABEL_33;
LABEL_21:
  if ( v23 )
    v24 = "dual";
  else
    v24 = "single";
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_hw_mgr_print_acquire_info",
    2402,
    "Failed to acquire %s-IFE/SFE with [%u pix] [%u pd] [%u rdi] ports for ctx_idx:%u",
    v24,
    a2,
    a3,
    a4,
    *(_DWORD *)(a1 + 56));
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_ife_hw_mgr_print_acquire_info",
    2406,
    "Previously acquired IFEs[%d %d] SFEs[%d %d], ctx_idx: %u",
    v12,
    v15,
    v19,
    v22,
    *(_DWORD *)(a1 + 56));
  if ( v9[1210] == 1 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_ife_hw_mgr_print_acquire_info",
      2415,
      "HW_CTXT [SRC:DST_MASK] [%d:0x%x] [%d:0x%x] [%d:0x%x]",
      0,
      *(_DWORD *)(a1 + 9520),
      1,
      *(_DWORD *)(a1 + 9524),
      2,
      *(_DWORD *)(a1 + 9528));
  mutex_lock(&unk_394A30);
  v25 = qword_394A78;
  if ( (__int64 *)qword_394A78 == &qword_394A78 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_ife_hw_mgr_dump_acq_rsrc_for_all_ctx",
      2290,
      "Currently no ctx in use");
  }
  else
  {
    do
    {
      v26 = *(__int64 **)v25;
      if ( (unsigned int)__ratelimit(
                           &cam_ife_hw_mgr_dump_acq_rsrc_for_all_ctx__rs,
                           "cam_ife_hw_mgr_dump_acq_rsrc_for_all_ctx") )
        v27 = 3;
      else
        v27 = 2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        v27,
        8,
        3,
        "cam_ife_hw_mgr_dump_acq_rsrc_for_all_ctx",
        2300,
        "ctx id:%u is_dual:%d num_base:%d rdi only:%d",
        *(_DWORD *)(v25 + 56),
        *(unsigned __int8 *)(v25 + 9379),
        *(_DWORD *)(v25 + 8716),
        *(unsigned __int8 *)(v25 + 9385));
      cam_ife_hw_mgr_dump_acquire_resources(v25);
      v25 = (__int64)v26;
    }
    while ( v26 != &qword_394A78 );
  }
  result = mutex_unlock(&unk_394A30);
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return result;
}
