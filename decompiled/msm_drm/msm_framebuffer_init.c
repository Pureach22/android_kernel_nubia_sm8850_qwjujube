_DWORD *__fastcall msm_framebuffer_init(_QWORD *a1, __int64 a2, _QWORD *a3)
{
  __int64 format_info; // x24
  __int64 v7; // x22
  long double v8; // q0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x25
  __int64 (__fastcall *v12)(__int64, __int64, __int64, long double); // x8
  __int64 v13; // x0
  __int64 v14; // x24
  _QWORD *v15; // x0
  char v16; // w8
  _QWORD *v17; // x24
  __int64 v18; // x0
  unsigned __int8 *v19; // x8
  unsigned int v20; // w9
  unsigned int v21; // w10
  _QWORD *v22; // x23
  _DWORD *v23; // x8
  int v24; // w22
  _DWORD *v25; // x21
  int v26; // w0
  __int64 v28; // x12
  unsigned int v29; // w13
  unsigned int v30; // w9
  unsigned __int8 *v31; // x8
  _QWORD *v32; // x11
  int v33; // w9
  _DWORD *v34; // x10
  unsigned int v35; // w13

  format_info = drm_get_format_info(a1, a2);
  v7 = *(_QWORD *)(a1[7] + 8LL);
  *(double *)&v8 = _drm_dev_dbg(
                     0,
                     0,
                     1,
                     "create framebuffer: dev=%pK, mode_cmd=%pK (%dx%d@%4.4s)\n",
                     a1,
                     (const void *)a2,
                     *(_DWORD *)(a2 + 4),
                     *(_DWORD *)(a2 + 8),
                     (const char *)(a2 + 12));
  v9 = *(unsigned int *)(a2 + 12);
  v10 = *(_QWORD *)(a2 + 72);
  v11 = *(unsigned __int8 *)(format_info + 5);
  v12 = *(__int64 (__fastcall **)(__int64, __int64, __int64, long double))(*(_QWORD *)v7 + 104LL);
  if ( *((_DWORD *)v12 - 1) != 1894143755 )
    __break(0x8228u);
  v13 = v12(v7, v9, v10, v8);
  if ( !v13 )
  {
    dev_err(a1[1], "[%s:%d] unsupported pixel format: %4.4s\n", "msm_framebuffer_init", 200, (const char *)(a2 + 12));
    v15 = nullptr;
    goto LABEL_30;
  }
  v14 = v13;
  v15 = (_QWORD *)_kmalloc_cache_noprof(drm_dp_dpcd_read, 3520, 216);
  if ( !v15 )
  {
    v24 = -12;
    goto LABEL_40;
  }
  v16 = *(_BYTE *)(a2 + 16);
  v15[24] = v14;
  if ( (v16 & 2) != 0 && (*(_QWORD *)(a2 + 72) || *(_QWORD *)(a2 + 80) || *(_QWORD *)(a2 + 88) || *(_QWORD *)(a2 + 96)) )
  {
    if ( (unsigned int)v11 <= 4 )
    {
      v22 = v15;
      v23 = *(_DWORD **)(*(_QWORD *)v7 + 112LL);
      if ( !v23 )
      {
        dev_err(a1[1], "[%s:%d] can't check modified fb format\n", "msm_framebuffer_init", 231);
        v24 = -22;
        v15 = v22;
        goto LABEL_40;
      }
      if ( *(v23 - 1) != 743366126 )
        __break(0x8228u);
      v24 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD *))v23)(v7, v14, a2, a3);
      v15 = v22;
      if ( v24 )
        goto LABEL_40;
LABEL_22:
      if ( (_DWORD)v11 )
      {
        v15[20] = *a3;
        if ( (_DWORD)v11 != 1 )
        {
          v15[21] = a3[1];
          if ( (_DWORD)v11 != 2 )
          {
            v15[22] = a3[2];
            if ( (_DWORD)v11 != 3 )
              v15[23] = a3[3];
          }
        }
      }
      goto LABEL_27;
    }
LABEL_30:
    v24 = -22;
    goto LABEL_40;
  }
  if ( (unsigned int)v11 > 4 )
    goto LABEL_30;
  v17 = v15;
  v18 = drm_format_info(*(unsigned int *)(a2 + 12));
  if ( !v18 )
  {
    v24 = -22;
    v15 = v17;
    goto LABEL_40;
  }
  v19 = (unsigned __int8 *)v18;
  v15 = v17;
  if ( !(_DWORD)v11 )
    goto LABEL_27;
  if ( !*a3 )
    goto LABEL_30;
  v21 = *(_DWORD *)(a2 + 4);
  v20 = *(_DWORD *)(a2 + 8);
  if ( *(_QWORD *)(*a3 + 216LL) < (unsigned __int64)(*(_DWORD *)(a2 + 52)
                                                   + (v20 - 1) * *(_DWORD *)(a2 + 36)
                                                   + v21 * v19[6]) )
    goto LABEL_30;
  if ( (_DWORD)v11 != 1 )
  {
    v28 = v11 - 1;
    v29 = v20 / v19[19];
    v30 = v19[18];
    v31 = v19 + 7;
    v32 = a3 + 1;
    v33 = v21 / v30;
    v34 = (_DWORD *)(a2 + 56);
    v35 = v29 - 1;
    while ( *v32 && *(_QWORD *)(*v32 + 216LL) >= (unsigned __int64)(*v34 + v35 * *(v34 - 4) + v33 * *v31) )
    {
      --v28;
      ++v34;
      ++v31;
      ++v32;
      if ( !v28 )
        goto LABEL_22;
    }
    goto LABEL_30;
  }
  v17[20] = *a3;
LABEL_27:
  v25 = v15;
  drm_helper_mode_fill_fb_struct(a1, v15, a2);
  v26 = drm_framebuffer_init(a1, v25, &msm_framebuffer_funcs);
  if ( !v26 )
  {
    _drm_dev_dbg(0, 0, 1, "create: FB ID: %d (%pK)\n", v25[6], v25);
    return v25;
  }
  v24 = v26;
  dev_err(a1[1], "[%s:%d] framebuffer init failed: %d\n", "msm_framebuffer_init", 274, v26);
  v15 = v25;
LABEL_40:
  kfree(v15);
  return (_DWORD *)v24;
}
