__int64 __fastcall qdf_aligned_mem_alloc_consistent_fl(
        __int64 a1,
        unsigned int *a2,
        __int64 *a3,
        __int64 *a4,
        __int64 *a5,
        unsigned int a6,
        __int64 a7,
        unsigned int a8)
{
  __int64 v8; // x26
  unsigned __int64 StatusReg; // x28
  __int64 v15; // x0
  __int64 v19; // x3
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x3
  unsigned int v23; // w1
  __int64 v24; // x26
  __int64 v26; // x0
  __int64 v27; // x3
  __int64 v28; // x0
  __int64 v29; // x8
  unsigned int v36; // w9
  unsigned int v39; // w9
  unsigned int v42; // w9

  v8 = *a2;
  if ( (unsigned __int64)(v8 - 4194305) > 0xFFFFFFFFFFBFFFFFLL )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v15 = *(_QWORD *)(a1 + 40);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 || *(_DWORD *)(StatusReg + 16) )
    {
      v19 = 2080;
    }
    else
    {
      v19 = 2080;
      if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
      {
        if ( *(_DWORD *)(StatusReg + 1412) )
          v19 = 2080;
        else
          v19 = 3264;
      }
    }
    v20 = dma_alloc_attrs(v15, v8, a4, v19, 0);
    if ( !v20 )
      goto LABEL_12;
    _X8 = &dword_716984;
    __asm { PRFM            #0x11, [X8] }
    do
      v36 = __ldxr((unsigned int *)&dword_716984);
    while ( __stxr(v36 + v8, (unsigned int *)&dword_716984) );
    *a3 = v20;
    v21 = a6 - 1;
    v22 = *a4;
    if ( (*a4 & v21) != 0 )
    {
      v23 = *a2;
      v24 = (unsigned int)v21 + *a2;
      _X8 = &dword_716984;
      __asm { PRFM            #0x11, [X8] }
      do
        v39 = __ldxr((unsigned int *)&dword_716984);
      while ( __stxr(v39 - v23, (unsigned int *)&dword_716984) );
      dma_free_attrs();
      if ( (unsigned __int64)(v24 - 4194305) <= 0xFFFFFFFFFFBFFFFFLL )
      {
        qdf_trace_msg(56, 2, "Cannot malloc %zu bytes @ %s:%d", v24, "qdf_aligned_mem_alloc_consistent_fl", 2881);
LABEL_21:
        *a3 = 0;
        qdf_trace_msg(
          56,
          3,
          "%s: Failed to alloc %uB @ %s:%d",
          "qdf_aligned_mem_alloc_consistent_fl",
          (unsigned int)v24,
          a7,
          a8);
        return 0;
      }
      v26 = *(_QWORD *)(a1 + 40);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 || *(_DWORD *)(StatusReg + 16) )
      {
        v27 = 2080;
      }
      else
      {
        v27 = 2080;
        if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
        {
          if ( *(_DWORD *)(StatusReg + 1412) )
            v27 = 2080;
          else
            v27 = 3264;
        }
      }
      v28 = dma_alloc_attrs(v26, v24, a4, v27, 0);
      if ( !v28 )
        goto LABEL_21;
      _X8 = &dword_716984;
      __asm { PRFM            #0x11, [X8] }
      do
        v42 = __ldxr((unsigned int *)&dword_716984);
      while ( __stxr(v42 + v24, (unsigned int *)&dword_716984) );
      *a3 = v28;
      *a2 = v24;
      v22 = *a4;
    }
    v29 = (a6 + v22 - 1) & -(__int64)a6;
    *a5 = v29;
    return v29 - *a4 + *a3;
  }
  qdf_trace_msg(56, 2, "Cannot malloc %zu bytes @ %s:%d", v8, "qdf_aligned_mem_alloc_consistent_fl", 2856);
LABEL_12:
  *a3 = 0;
  qdf_trace_msg(56, 3, "%s: Failed to alloc %uB @ %s:%d", "qdf_aligned_mem_alloc_consistent_fl", *a2, a7, a8);
  return 0;
}
