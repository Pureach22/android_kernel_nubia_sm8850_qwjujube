__int64 __fastcall qdf_mem_shared_mem_alloc(__int64 a1, unsigned int a2)
{
  __int64 v4; // x19
  __int64 v5; // x21
  __int64 v6; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v8; // x0
  __int64 v9; // x3
  void *v10; // x0
  __int64 v11; // x9
  __int64 v12; // x22
  __int64 v13; // x0
  __int64 v14; // x1
  int v15; // w0
  int v16; // w0
  __int64 v18; // x0
  unsigned int v19; // w20
  unsigned int v22; // w9
  unsigned int v29; // w9
  unsigned int v32; // w9
  unsigned int v35; // w9

  v4 = _qdf_mem_malloc(0x40u, "qdf_mem_shared_mem_alloc", 2433);
  if ( v4 )
  {
    v5 = a2;
    v6 = 8;
    if ( !*(_BYTE *)(a1 + 608) )
      v6 = 0;
    if ( (unsigned __int64)a2 - 4194305 <= 0xFFFFFFFFFFBFFFFFLL )
    {
      qdf_trace_msg(56, 2, "Cannot malloc %zu bytes @ %s:%d", a2, "qdf_mem_shared_mem_alloc", 2439);
LABEL_21:
      *(_QWORD *)(v4 + 32) = 0;
      qdf_trace_msg(56, 2, "%s: Unable to allocate DMA memory for shared resource", "qdf_mem_shared_mem_alloc");
      if ( (unsigned __int64)ksize(v4) > 0x2000 && (unsigned int)wcnss_prealloc_put(v4) )
        return 0;
      v16 = ksize(v4);
      _X8 = &qdf_mem_stat;
      __asm { PRFM            #0x11, [X8] }
      do
        v22 = __ldxr((unsigned int *)&qdf_mem_stat);
      while ( __stxr(v22 - v16, (unsigned int *)&qdf_mem_stat) );
LABEL_24:
      kfree(v4);
      return 0;
    }
    StatusReg = _ReadStatusReg(SP_EL0);
    v8 = *(_QWORD *)(a1 + 40);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 || *(_DWORD *)(StatusReg + 16) )
    {
      v9 = 2080;
    }
    else
    {
      v9 = 2080;
      if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
      {
        if ( *(_DWORD *)(StatusReg + 1412) )
          v9 = 2080;
        else
          v9 = 3264;
      }
    }
    v10 = (void *)dma_alloc_attrs(v8, a2, v4 + v6, v9, 0);
    if ( !v10 )
      goto LABEL_21;
    _X8 = &dword_7CF3B4;
    __asm { PRFM            #0x11, [X8] }
    do
      v29 = __ldxr((unsigned int *)&dword_7CF3B4);
    while ( __stxr(v29 + a2, (unsigned int *)&dword_7CF3B4) );
    *(_QWORD *)(v4 + 32) = v10;
    *(_QWORD *)(v4 + 16) = a2;
    memset(v10, 0, a2);
    v11 = 8;
    if ( !*(_BYTE *)(a1 + 608) )
      v11 = 0;
    v12 = *(_QWORD *)(v4 + v11);
    v13 = v12;
    if ( *(_BYTE *)(a1 + 608) )
    {
      v13 = *(_QWORD *)(v4 + v11);
      if ( *(_QWORD *)(a1 + 616) )
        v13 = iommu_iova_to_phys(*(_QWORD *)(a1 + 616), *(_QWORD *)(v4 + v11));
    }
    *(_QWORD *)v4 = v13;
    if ( (unsigned int)dma_get_sgtable_attrs(*(_QWORD *)(a1 + 40), v4 + 40, *(_QWORD *)(v4 + 32), v12, v5, 0) )
    {
      qdf_trace_msg(56, 2, "%s: Unable to get DMA sgtable", "qdf_mem_shared_mem_alloc");
      v14 = *(_QWORD *)(v4 + 16);
      _X8 = &dword_7CF3B4;
      __asm { PRFM            #0x11, [X8] }
      do
        v32 = __ldxr((unsigned int *)&dword_7CF3B4);
      while ( __stxr(v32 - v14, (unsigned int *)&dword_7CF3B4) );
      dma_free_attrs();
      if ( (unsigned __int64)ksize(v4) > 0x2000 && (unsigned int)wcnss_prealloc_put(v4) )
        return 0;
      v15 = ksize(v4);
      _X8 = &qdf_mem_stat;
      __asm { PRFM            #0x11, [X8] }
      do
        v35 = __ldxr((unsigned int *)&qdf_mem_stat);
      while ( __stxr(v35 - v15, (unsigned int *)&qdf_mem_stat) );
      goto LABEL_24;
    }
    if ( *(_DWORD *)(v4 + 48) )
    {
      v18 = *(_QWORD *)(v4 + 40);
      if ( v18 )
      {
        v19 = 1;
        do
        {
          *(_QWORD *)(v18 + 16) = *(unsigned int *)(v18 + 8)
                                + (((*(_QWORD *)v18 & 0x3FFFFFFFFFFFFFCLL) - -64LL * (memstart_addr >> 12)) << 6)
                                + 0x5000000000LL;
          v18 = sg_next();
          if ( v19 >= *(_DWORD *)(v4 + 48) )
            break;
          ++v19;
        }
        while ( v18 );
      }
    }
  }
  return v4;
}
