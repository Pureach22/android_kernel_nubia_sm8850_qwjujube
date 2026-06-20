__int64 __fastcall sde_format_populate_addrs_linear(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // x20
  _DWORD *v4; // x21
  int v5; // w9
  unsigned int v7; // w2
  unsigned int v8; // w3
  int v9; // w1
  _DWORD *v11; // x19
  int v12; // w0
  int v13; // w0
  int v14; // w0
  int v15; // w0
  int v16; // w0
  int v17; // w0
  __int64 v18; // x0
  __int64 v19; // x0

  v5 = a3[2];
  if ( !v5 )
    return 0;
  v7 = a3[14];
  v8 = a2[22];
  if ( v7 > v8 )
  {
    v9 = 0;
LABEL_4:
    _drm_err("plane %u expected pitch %u, fb %u\n", v9, v7, v8);
    return 4294967274LL;
  }
  v11 = a1;
  if ( v5 != 1 )
  {
    v7 = a3[15];
    v8 = a2[23];
    if ( v7 > v8 )
    {
      v9 = 1;
      goto LABEL_4;
    }
    if ( v5 != 2 )
    {
      v7 = a3[16];
      v8 = a2[24];
      if ( v7 > v8 )
      {
        v9 = 2;
        goto LABEL_4;
      }
      if ( v5 != 3 )
      {
        v7 = a3[17];
        v8 = a2[25];
        if ( v7 > v8 )
        {
          v9 = 3;
          goto LABEL_4;
        }
        if ( v5 != 4 )
        {
          __break(0x5512u);
          goto LABEL_33;
        }
      }
    }
  }
  v4 = a3;
  v3 = a2;
  if ( a1 )
  {
    v12 = msm_framebuffer_iova(a2, a1, 0);
    v4[6] = v12;
    if ( !v12 )
      goto LABEL_37;
  }
  else
  {
    v13 = ((__int64 (__fastcall *)(_DWORD *, _QWORD))msm_framebuffer_phys)(a2, 0);
    v4[6] = v13;
    if ( !v13 )
      goto LABEL_37;
  }
  if ( v4[2] < 2u )
    return 0;
  if ( !v11 )
  {
    v15 = ((__int64 (__fastcall *)(_DWORD *, __int64))msm_framebuffer_phys)(v3, 1);
    v4[7] = v15;
    if ( v15 )
      goto LABEL_20;
LABEL_37:
    _drm_err("failed to retrieve base addr\n");
    return 4294967282LL;
  }
  v14 = msm_framebuffer_iova(v3, v11, 1);
  v4[7] = v14;
  if ( !v14 )
    goto LABEL_37;
LABEL_20:
  if ( v4[2] < 3u )
    return 0;
  if ( v11 )
    v16 = msm_framebuffer_iova(v3, v11, 2);
  else
    v16 = ((__int64 (__fastcall *)(_DWORD *, __int64))msm_framebuffer_phys)(v3, 2);
  v4[8] = v16;
  if ( !v16 )
    goto LABEL_37;
  if ( v4[2] < 4u )
    return 0;
  a1 = v3;
  if ( v11 )
  {
    v17 = msm_framebuffer_iova(v3, v11, 3);
    goto LABEL_34;
  }
LABEL_33:
  v17 = ((__int64 (__fastcall *)(_DWORD *, __int64))msm_framebuffer_phys)(a1, 3);
LABEL_34:
  v4[9] = v17;
  if ( !v17 )
    goto LABEL_37;
  if ( v4[2] <= 4u )
    return 0;
  v18 = (__int64)v3;
  if ( !v11 )
  {
    v18 = ((__int64 (__fastcall *)(_DWORD *, __int64))msm_framebuffer_phys)(v3, 4);
    __break(0x5512u);
  }
  v19 = msm_framebuffer_iova(v18, v11, 4);
  __break(0x5512u);
  return sde_format_check_modified_format(v19);
}
