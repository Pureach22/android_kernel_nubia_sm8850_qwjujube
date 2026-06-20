__int64 __fastcall tmc_pages_alloc(unsigned int *a1, __int64 a2, unsigned int a3, unsigned int a4, __int64 a5)
{
  __int64 v5; // x20
  __int64 v6; // x23
  __int64 v12; // x0
  __int64 *v13; // x27
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 *v16; // x28
  __int64 v17; // x0
  __int64 v18; // x25
  __int64 v19; // x20
  __int64 v20; // x8
  unsigned __int64 v21; // x26
  __int64 v22; // x8
  unsigned __int64 v23; // x8
  __int64 v24; // x2
  __int64 v25; // x0
  unsigned int v32; // w9
  char v34; // w8
  __int64 v35; // x0
  __int64 v36; // [xsp+18h] [xbp-8h]

  v5 = *a1;
  v6 = *(_QWORD *)(a2 + 96);
  if ( (v5 & 0x80000000) != 0 )
  {
    *((_QWORD *)a1 + 1) = 0;
    v13 = (__int64 *)(a1 + 2);
  }
  else
  {
    v12 = _kmalloc_noprof(8 * v5, 3520);
    *((_QWORD *)a1 + 1) = v12;
    v13 = (__int64 *)(a1 + 2);
    if ( v12 )
      goto LABEL_4;
  }
  v14 = vmalloc_noprof(8LL * (int)v5);
  *v13 = v14;
  if ( !v14 )
    return 4294967284LL;
LABEL_4:
  if ( (v5 & 0x80000000) != 0 )
  {
    *((_QWORD *)a1 + 2) = 0;
    v16 = (__int64 *)(a1 + 4);
  }
  else
  {
    v15 = _kmalloc_noprof(8 * v5, 3520);
    *((_QWORD *)a1 + 2) = v15;
    v16 = (__int64 *)(a1 + 4);
    if ( v15 )
      goto LABEL_7;
  }
  v17 = vmalloc_noprof(8LL * (int)v5);
  *v16 = v17;
  if ( !v17 )
  {
    v34 = is_vmalloc_addr(*v13);
    v35 = *v13;
    if ( (v34 & 1) != 0 )
      vfree(v35);
    else
      kfree(v35);
    *v13 = 0;
    return 4294967284LL;
  }
LABEL_7:
  if ( (int)v5 >= 1 )
  {
    v18 = 8LL * (int)v5;
    v19 = 0;
    _ReadStatusReg(SP_EL0);
    v36 = a2;
    do
    {
      if ( a5 && (v20 = *(_QWORD *)(a5 + v19)) != 0 )
      {
        v21 = ((unsigned __int64)((v20 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL;
        v22 = *(_QWORD *)(((unsigned __int64)((v20 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x13FFFFFF8LL);
        if ( (v22 & 1) != 0 )
          v23 = v22 - 1;
        else
          v23 = v21;
        _X8 = (unsigned int *)(v23 + 52);
        __asm { PRFM            #0x11, [X8] }
        do
          v32 = __ldxr(_X8);
        while ( __stxr(v32 + 1, _X8) );
      }
      else
      {
        v24 = a3;
        if ( a3 == -1 )
          v24 = 0;
        v21 = _alloc_pages_noprof(3520, 0, v24, 0);
        if ( !v21 )
        {
LABEL_24:
          tmc_pages_free((int *)a1, v36, a4);
          return 4294967284LL;
        }
      }
      v25 = dma_map_page_attrs(v6, v21, 0, 4096, a4, 0);
      if ( v25 == -1 )
        goto LABEL_24;
      *(_QWORD *)(*v13 + v19) = v25;
      *(_QWORD *)(*v16 + v19) = v21;
      v19 += 8;
    }
    while ( v18 != v19 );
  }
  return 0;
}
