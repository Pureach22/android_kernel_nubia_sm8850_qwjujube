__int64 __fastcall kgsl_allocate_user(__int64 a1, _QWORD *a2, __int64 a3, unsigned __int64 a4, int a5)
{
  unsigned __int64 v6; // x20
  __int64 v9; // x8
  __int64 v10; // x21
  __int64 v11; // x0
  unsigned __int64 v12; // x1
  __int64 v13; // x22
  unsigned int v14; // w0
  unsigned int v15; // w19
  __int64 result; // x0
  unsigned __int64 v17; // x20
  unsigned int v25; // w9
  unsigned int v28; // w9
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x8
  unsigned __int64 v35; // x8
  unsigned __int64 v36; // x8
  _QWORD v37[2]; // [xsp+0h] [xbp-10h] BYREF

  v37[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 64) != 1 )
  {
    if ( (a4 & 8) != 0 )
    {
      result = kgsl_allocate_secure();
      goto LABEL_24;
    }
    v17 = (a3 + 4095) & 0xFFFFFFFFFFFFF000LL;
    if ( v17 - 0x100000000LL >= 0xFFFFFFFF00000001LL )
    {
      kgsl_memdesc_init(a1, (__int64)a2, a4);
      _X8 = (unsigned int *)(a2 + 6);
      __asm { PRFM            #0x11, [X8] }
      do
        v28 = __ldxr(_X8);
      while ( __stxr(v28 | a5, _X8) );
      v37[0] = 0;
      a2[5] = v17;
      if ( (a5 & 0x200) != 0 )
      {
        a2[8] = &kgsl_system_ops;
        result = kgsl_system_alloc_pages(a2, v37);
        if ( (result & 0x80000000) != 0 )
          goto LABEL_24;
      }
      else
      {
        a2[8] = &kgsl_page_ops;
        result = kgsl_alloc_pages(a2, v37);
        if ( (result & 0x80000000) != 0 )
          goto LABEL_24;
      }
      a2[12] = v37[0];
      _X9 = &qword_3A8B8;
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v31 = __ldxr((unsigned __int64 *)&qword_3A8B8);
        v32 = v31 + v17;
      }
      while ( __stlxr(v32, (unsigned __int64 *)&qword_3A8B8) );
      __dmb(0xBu);
      if ( v32 > qword_3A8C0 )
      {
        result = 0;
        qword_3A8C0 = v32;
        goto LABEL_24;
      }
LABEL_23:
      result = 0;
      goto LABEL_24;
    }
LABEL_9:
    result = 4294967274LL;
    goto LABEL_24;
  }
  v6 = (a3 + 4095) & 0xFFFFFFFFFFFFF000LL;
  if ( v6 - 0x100000000LL < 0xFFFFFFFF00000001LL )
    goto LABEL_9;
  kgsl_memdesc_init(a1, (__int64)a2, a4);
  _X8 = (unsigned int *)(a2 + 6);
  __asm { PRFM            #0x11, [X8] }
  do
    v25 = __ldxr(_X8);
  while ( __stxr(v25 | a5, _X8) );
  a2[8] = &kgsl_contiguous_ops;
  v9 = *(_QWORD *)(a1 + 11168);
  v37[0] = 0;
  v10 = v9 + 16;
  v11 = dma_alloc_attrs(v9 + 16, v6, v37, 3264, 0);
  if ( !v11 )
  {
    result = 4294967284LL;
    goto LABEL_24;
  }
  v12 = v37[0];
  v13 = v11;
  a2[1] = v11;
  a2[10] = v10;
  a2[11] = 0;
  a2[4] = v12;
  a2[5] = v6;
  a2[3] = v12;
  v14 = kgsl_memdesc_sg_dma((__int64)a2, v12, v6);
  if ( !v14 )
  {
    _X9 = &qword_3A8C8;
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v35 = __ldxr((unsigned __int64 *)&qword_3A8C8);
      v36 = v35 + v6;
    }
    while ( __stlxr(v36, (unsigned __int64 *)&qword_3A8C8) );
    __dmb(0xBu);
    if ( v36 > qword_3A8D0 )
    {
      result = 0;
      qword_3A8D0 = v36;
      goto LABEL_24;
    }
    goto LABEL_23;
  }
  v15 = v14;
  dma_free_attrs(v10, v6, v13, v37[0], 0);
  result = v15;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
