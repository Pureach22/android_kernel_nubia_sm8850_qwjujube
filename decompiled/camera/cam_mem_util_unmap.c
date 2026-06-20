__int64 __fastcall cam_mem_util_unmap(unsigned int a1, __int64 a2)
{
  const void **v3; // x23
  unsigned int v4; // w21
  char v5; // w8
  const void *v6; // x22
  const void *v7; // x1
  __int64 v8; // x1
  int v9; // w8
  const void *v10; // x0
  __int64 v11; // x21
  void *v12; // x0
  __int64 v13; // x9
  __int64 v14; // x10
  __int64 v15; // x8
  unsigned __int64 v23; // x10

  if ( a1 > 0x7FF )
  {
    __break(1u);
    goto LABEL_27;
  }
  v3 = (const void **)((char *)&tbl + 296 * a1 + 64);
  v4 = *((_DWORD *)&tbl + 74 * a1 + 53);
  if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x400000,
      4,
      "cam_mem_util_unmap",
      2795,
      "Flags = %X idx %d",
      *((_DWORD *)&tbl + 74 * a1 + 38),
      a1);
    if ( ((_BYTE)v3[15] & 1) != 0 )
      goto LABEL_5;
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x400000,
             2,
             "cam_mem_util_unmap",
             2798,
             "Buffer at idx=%d is already unmapped",
             a1);
  }
  if ( (*((_BYTE *)&tbl + 296 * a1 + 184) & 1) == 0 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x400000,
             2,
             "cam_mem_util_unmap",
             2798,
             "Buffer at idx=%d is already unmapped",
             a1);
LABEL_5:
  raw_spin_lock_bh(v3 + 36);
  *((_BYTE *)v3 + 120) = 0;
  *((_DWORD *)v3 + 18) = -1;
  raw_spin_unlock_bh(v3 + 36);
  v5 = *((_BYTE *)v3 + 88);
  *((_BYTE *)v3 + 121) = 0;
  if ( (v5 & 8) != 0 )
  {
    v6 = *v3;
    if ( *v3 )
    {
      v7 = v3[12];
      if ( v7 )
      {
        cam_compat_util_put_dmabuf_va(*v3, v7);
        if ( (unsigned int)dma_buf_end_cpu_access(v6, 0) )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x400000,
            1,
            "cam_mem_util_unmap_cpu_va",
            237,
            "Failed in end cpu access, dmabuf=%pK",
            v6);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x400000,
            1,
            "cam_mem_util_unmap",
            2817,
            "Failed, dmabuf=%pK, kmdvaddr=%pK",
            *v3,
            v3[12]);
        }
      }
    }
  }
  if ( ((_DWORD)v3[11] & 0x821) != 0 )
  {
    if ( ((_DWORD)v3[11] & 0x801) == 1 )
      v8 = 3;
    else
      v8 = 1;
    if ( (unsigned int)cam_mem_util_unmap_hw_va(a1, v8, v4, 0) )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000,
        1,
        "cam_mem_util_unmap",
        2835,
        "Failed, dmabuf=%pK",
        *v3);
  }
  v9 = debug_mdl;
  v10 = *v3;
  *((_DWORD *)v3 + 22) = 0;
  if ( (v9 & 0x400000) == 0 || debug_priority )
  {
    v11 = -296LL * a1;
    if ( !v10 )
      goto LABEL_20;
    goto LABEL_19;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    *(_QWORD *)&v9 & 0x400000LL,
    4,
    "cam_mem_util_unmap",
    2843,
    "Ion buf at idx = %d freeing fd = %d, imported %d, dma_buf %pK, i_ino %lu",
    a1,
    *((_DWORD *)v3 + 14),
    *((unsigned __int8 *)v3 + 122),
    v10,
    v3[8]);
  v10 = *v3;
  v11 = -296LL * a1;
  if ( *v3 )
LABEL_19:
    dma_buf_put(v10);
LABEL_20:
  v3[8] = nullptr;
  v12 = (void *)v3[14];
  *((_DWORD *)v3 + 14) = -1;
  *v3 = nullptr;
  *((_WORD *)v3 + 61) = 0;
  v3[10] = nullptr;
  *((_DWORD *)v3 + 26) = 0;
  memset(v12, 0, qword_391BB0);
  a2 = v11 + 606184;
  if ( (unsigned __int64)(v11 + 606184) > 0xF )
  {
    v3[16] = nullptr;
    v3[17] = nullptr;
    *((_DWORD *)v3 + 36) = 0;
    *((_DWORD *)v3 + 71) = 0;
    mutex_lock(&tbl);
    v13 = qword_2FDB90;
    v14 = a1 >> 6;
    v15 = 1LL << a1;
    goto LABEL_28;
  }
LABEL_27:
  _fortify_panic(15, a2, 16);
LABEL_28:
  _X9 = (unsigned __int64 *)(v13 + 8 * v14);
  __asm { PRFM            #0x11, [X9] }
  do
    v23 = __ldxr(_X9);
  while ( __stxr(v23 & ~v15, _X9) );
  return mutex_unlock(&tbl);
}
