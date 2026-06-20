__int64 __fastcall qdf_mem_multi_pages_free(__int64 result, __int64 a2, __int64 a3, char a4)
{
  unsigned __int64 v5; // x21
  __int64 v7; // x8
  __int64 v8; // x20
  int v9; // w0
  unsigned int v15; // w8
  __int64 v16; // x20
  int v17; // w0
  __int64 v18; // x22
  unsigned int v19; // w21
  __int64 v21; // x1
  unsigned int v23; // w8
  int v24; // w0
  unsigned int v27; // w9
  unsigned int v30; // w9

  if ( *(_QWORD *)(a2 + 24) )
  {
    if ( (a4 & 1) != 0 )
      goto LABEL_3;
  }
  else
  {
    *(_QWORD *)(a2 + 24) = 4096;
    if ( (a4 & 1) != 0 )
    {
LABEL_3:
      if ( *(_WORD *)(a2 + 2) )
      {
        v5 = 0;
        _X22 = &qdf_mem_stat;
        do
        {
          v7 = *(_QWORD *)(a2 + 16);
          v8 = *(_QWORD *)(v7 + 8 * v5);
          if ( v8 )
          {
            if ( (unsigned __int64)ksize(*(_QWORD *)(v7 + 8 * v5)) <= 0x2000
              || (result = wcnss_prealloc_put(v8), !(_DWORD)result) )
            {
              v9 = ksize(v8);
              __asm { PRFM            #0x11, [X22] }
              do
                v15 = __ldxr((unsigned int *)&qdf_mem_stat);
              while ( __stxr(v15 - v9, (unsigned int *)&qdf_mem_stat) );
              result = kfree(v8);
            }
          }
          ++v5;
        }
        while ( v5 < *(unsigned __int16 *)(a2 + 2) );
      }
      v16 = *(_QWORD *)(a2 + 16);
      if ( v16 )
      {
        if ( (unsigned __int64)ksize(*(_QWORD *)(a2 + 16)) <= 0x2000
          || (result = wcnss_prealloc_put(v16), !(_DWORD)result) )
        {
          v17 = ksize(v16);
          _X8 = &qdf_mem_stat;
          __asm { PRFM            #0x11, [X8] }
          do
            v27 = __ldxr((unsigned int *)&qdf_mem_stat);
          while ( __stxr(v27 - v17, (unsigned int *)&qdf_mem_stat) );
LABEL_28:
          result = kfree(v16);
          goto LABEL_29;
        }
      }
      goto LABEL_29;
    }
  }
  if ( *(_WORD *)(a2 + 2) )
  {
    v18 = *(_QWORD *)(a2 + 8);
    v19 = 0;
    _X23 = &dword_7CF3B4;
    do
    {
      v21 = *(_QWORD *)(a2 + 24);
      __asm { PRFM            #0x11, [X23] }
      do
        v23 = __ldxr((unsigned int *)&dword_7CF3B4);
      while ( __stxr(v23 - v21, (unsigned int *)&dword_7CF3B4) );
      result = dma_free_attrs();
      ++v19;
      v18 += 24;
    }
    while ( v19 < *(unsigned __int16 *)(a2 + 2) );
  }
  v16 = *(_QWORD *)(a2 + 8);
  if ( v16 )
  {
    if ( (unsigned __int64)ksize(*(_QWORD *)(a2 + 8)) <= 0x2000 || (result = wcnss_prealloc_put(v16), !(_DWORD)result) )
    {
      v24 = ksize(v16);
      _X8 = &qdf_mem_stat;
      __asm { PRFM            #0x11, [X8] }
      do
        v30 = __ldxr((unsigned int *)&qdf_mem_stat);
      while ( __stxr(v30 - v24, (unsigned int *)&qdf_mem_stat) );
      goto LABEL_28;
    }
  }
LABEL_29:
  *(_WORD *)(a2 + 2) = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_QWORD *)(a2 + 16) = 0;
  return result;
}
