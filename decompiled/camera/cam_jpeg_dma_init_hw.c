__int64 __fastcall cam_jpeg_dma_init_hw(__int64 a1)
{
  __int64 v2; // x20
  int v3; // w8
  bool v4; // nf
  __int64 result; // x0
  unsigned int v6; // w0
  int v7; // w0
  unsigned int v8; // w19
  int v9; // w0
  __int64 v10; // [xsp+8h] [xbp-278h] BYREF
  __int64 v11; // [xsp+10h] [xbp-270h]
  _QWORD s[77]; // [xsp+18h] [xbp-268h] BYREF

  s[76] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  v11 = 0;
  memset(s, 0, 0x260u);
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dma_init_hw",
      48,
      "Invalid cam_dev_info");
    result = 4294967274LL;
    goto LABEL_12;
  }
  v2 = *(_QWORD *)(a1 + 3680);
  if ( !v2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dma_init_hw",
      58,
      "soc_info = %pK core_info = %pK",
      (const void *)(a1 + 96),
      nullptr);
    result = 4294967274LL;
    goto LABEL_12;
  }
  mutex_lock(v2 + 64);
  v3 = *(_DWORD *)(v2 + 56) + 1;
  v4 = *(_DWORD *)(v2 + 56) - 1 < 0;
  *(_DWORD *)(v2 + 56) = v3;
  if ( v4 != __OFSUB__(v3, 2) )
  {
    *(_QWORD *)((char *)&s[1] + 4) = 0x10000000000LL;
    s[3] = 640000000;
    s[4] = 640000000;
    s[5] = 640000000;
    *(_QWORD *)((char *)&s[6] + 4) = 0x10000000001LL;
    s[8] = 640000000;
    s[9] = 640000000;
    s[10] = 640000000;
    v6 = *(_DWORD *)(v2 + 16);
    LODWORD(v10) = 0;
    LODWORD(v11) = 2;
    LODWORD(s[0]) = 2;
    v7 = cam_cpas_start(v6, (__int64)&v10, (__int64)s);
    if ( v7 )
    {
      v8 = v7;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_dma_init_hw",
        86,
        "cpass start failed: %d",
        v7);
    }
    else
    {
      v9 = cam_jpeg_dma_enable_soc_resources(a1 + 96);
      if ( !v9 )
        goto LABEL_4;
      v8 = v9;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_dma_init_hw",
        92,
        "soc enable is failed %d",
        v9);
      cam_cpas_stop(*(_DWORD *)(v2 + 16));
    }
    --*(_DWORD *)(v2 + 56);
    mutex_unlock(v2 + 64);
    result = v8;
    goto LABEL_12;
  }
LABEL_4:
  mutex_unlock(v2 + 64);
  result = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
