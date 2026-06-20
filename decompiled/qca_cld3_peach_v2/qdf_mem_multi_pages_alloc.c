__int64 __fastcall qdf_mem_multi_pages_alloc(
        __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        unsigned int a4,
        __int64 a5,
        char a6)
{
  unsigned __int64 v6; // x4
  unsigned int v10; // w8
  unsigned __int16 v11; // w8
  __int64 result; // x0
  __int64 v13; // x22
  __int64 v14; // x24
  unsigned int v15; // w22
  __int64 v16; // x23
  unsigned __int64 StatusReg; // x26
  __int64 v19; // x24
  __int64 v20; // x0
  __int64 v21; // x3
  unsigned int v27; // w8
  __int64 v28; // x23
  unsigned int v29; // w21
  __int64 v31; // x1
  unsigned int v33; // w8
  __int64 v34; // x20
  int v35; // w0
  __int64 v36; // x22
  __int64 v37; // x21
  __int64 v39; // x8
  __int64 v40; // x20
  int v41; // w0
  unsigned int v43; // w8
  int v44; // w0
  unsigned int v47; // w9
  unsigned int v50; // w9

  v6 = *(_QWORD *)(a2 + 24);
  if ( !v6 )
  {
    v6 = 4096;
    *(_QWORD *)(a2 + 24) = 4096;
  }
  *(_WORD *)a2 = v6 / a3;
  if ( !(unsigned __int16)(v6 / a3) )
  {
    result = qdf_trace_msg(56, 2, "%s: Invalid page %d or element size %d", "qdf_mem_multi_pages_alloc", v6, a3);
    goto LABEL_60;
  }
  v10 = (unsigned __int16)(v6 / a3);
  if ( a4 % v10 )
    v11 = a4 / v10 + 1;
  else
    v11 = a4 / v10;
  *(_WORD *)(a2 + 2) = v11;
  if ( (a6 & 1) != 0 )
  {
    result = _qdf_mem_malloc(8LL * v11, "qdf_mem_multi_pages_alloc", 1909);
    *(_QWORD *)(a2 + 16) = result;
    if ( result )
    {
      if ( !*(_WORD *)(a2 + 2) )
      {
LABEL_13:
        *(_QWORD *)(a2 + 8) = 0;
        return result;
      }
      v13 = result;
      v14 = 0;
      while ( 1 )
      {
        result = _qdf_mem_malloc(*(_QWORD *)(a2 + 24), "qdf_mem_multi_pages_alloc", 1916);
        *(_QWORD *)(v13 + 8 * v14) = result;
        if ( !result )
          break;
        if ( ++v14 >= (unsigned __int64)*(unsigned __int16 *)(a2 + 2) )
          goto LABEL_13;
      }
      v15 = (unsigned __int16)v14;
      if ( (a6 & 1) == 0 )
        goto LABEL_33;
      goto LABEL_46;
    }
LABEL_60:
    *(_WORD *)(a2 + 2) = 0;
    *(_QWORD *)(a2 + 8) = 0;
    goto LABEL_61;
  }
  result = _qdf_mem_malloc(24LL * v11, "qdf_mem_multi_pages_alloc", 1923);
  *(_QWORD *)(a2 + 8) = result;
  if ( !result )
    goto LABEL_60;
  if ( *(_WORD *)(a2 + 2) )
  {
    v15 = 0;
    v16 = result + 16;
    _X27 = &dword_7CF3B4;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v19 = *(_QWORD *)(a2 + 24);
      if ( (unsigned __int64)(v19 - 4194305) <= 0xFFFFFFFFFFBFFFFFLL )
        break;
      v20 = *(_QWORD *)(a1 + 40);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0
        || *(_DWORD *)(StatusReg + 16)
        || (_ReadStatusReg(DAIF) & 0x80) != 0 )
      {
        v21 = 2080;
      }
      else if ( *(_DWORD *)(StatusReg + 1412) )
      {
        v21 = 2080;
      }
      else
      {
        v21 = 3264;
      }
      result = dma_alloc_attrs(v20, v19, v16, v21, 0);
      if ( !result )
        goto LABEL_45;
      __asm { PRFM            #0x11, [X27] }
      do
        v27 = __ldxr((unsigned int *)&dword_7CF3B4);
      while ( __stxr(v27 + v19, (unsigned int *)&dword_7CF3B4) );
      *(_QWORD *)(v16 - 16) = result;
      ++v15;
      *(_QWORD *)(v16 - 8) = result + *(_QWORD *)(a2 + 24);
      v16 += 24;
      if ( v15 >= *(unsigned __int16 *)(a2 + 2) )
        goto LABEL_61;
    }
    qdf_trace_msg(56, 2, "Cannot malloc %zu bytes @ %s:%d", *(_QWORD *)(a2 + 24), "qdf_mem_multi_pages_alloc", 1932);
LABEL_45:
    *(_QWORD *)(v16 - 16) = 0;
    result = qdf_trace_msg(56, 2, "%s: dmaable page alloc fail pi %d", "qdf_mem_multi_pages_alloc", v15);
    if ( (a6 & 1) == 0 )
    {
LABEL_33:
      if ( v15 )
      {
        v28 = *(_QWORD *)(a2 + 8);
        v29 = 0;
        _X24 = &dword_7CF3B4;
        do
        {
          v31 = *(_QWORD *)(a2 + 24);
          __asm { PRFM            #0x11, [X24] }
          do
            v33 = __ldxr((unsigned int *)&dword_7CF3B4);
          while ( __stxr(v33 - v31, (unsigned int *)&dword_7CF3B4) );
          result = dma_free_attrs();
          ++v29;
          v28 += 24;
        }
        while ( v29 < v15 );
      }
      v34 = *(_QWORD *)(a2 + 8);
      if ( !v34 )
        goto LABEL_60;
      if ( (unsigned __int64)ksize(*(_QWORD *)(a2 + 8)) > 0x2000 )
      {
        result = wcnss_prealloc_put(v34);
        if ( (_DWORD)result )
          goto LABEL_60;
      }
      v35 = ksize(v34);
      _X8 = &qdf_mem_stat;
      __asm { PRFM            #0x11, [X8] }
      do
        v47 = __ldxr((unsigned int *)&qdf_mem_stat);
      while ( __stxr(v47 - v35, (unsigned int *)&qdf_mem_stat) );
      goto LABEL_59;
    }
LABEL_46:
    if ( v15 )
    {
      v36 = 8LL * v15;
      v37 = 0;
      _X23 = &qdf_mem_stat;
      do
      {
        v39 = *(_QWORD *)(a2 + 16);
        v40 = *(_QWORD *)(v39 + v37);
        if ( v40 )
        {
          if ( (unsigned __int64)ksize(*(_QWORD *)(v39 + v37)) <= 0x2000
            || (result = wcnss_prealloc_put(v40), !(_DWORD)result) )
          {
            v41 = ksize(v40);
            __asm { PRFM            #0x11, [X23] }
            do
              v43 = __ldxr((unsigned int *)&qdf_mem_stat);
            while ( __stxr(v43 - v41, (unsigned int *)&qdf_mem_stat) );
            result = kfree(v40);
          }
        }
        v37 += 8;
      }
      while ( v36 != v37 );
    }
    v34 = *(_QWORD *)(a2 + 16);
    if ( !v34 )
      goto LABEL_60;
    if ( (unsigned __int64)ksize(*(_QWORD *)(a2 + 16)) > 0x2000 )
    {
      result = wcnss_prealloc_put(v34);
      if ( (_DWORD)result )
        goto LABEL_60;
    }
    v44 = ksize(v34);
    _X8 = &qdf_mem_stat;
    __asm { PRFM            #0x11, [X8] }
    do
      v50 = __ldxr((unsigned int *)&qdf_mem_stat);
    while ( __stxr(v50 - v44, (unsigned int *)&qdf_mem_stat) );
LABEL_59:
    result = kfree(v34);
    goto LABEL_60;
  }
LABEL_61:
  *(_QWORD *)(a2 + 16) = 0;
  return result;
}
