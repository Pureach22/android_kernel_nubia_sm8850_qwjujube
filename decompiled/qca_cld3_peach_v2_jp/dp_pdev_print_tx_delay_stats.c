__int64 __fastcall dp_pdev_print_tx_delay_stats(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x21
  __int64 result; // x0
  __int64 v12; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x8
  __int64 v15; // x22
  unsigned int v16; // w11
  unsigned int v23; // w13
  unsigned int v26; // w11
  __int64 v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 *v36; // x24
  __int64 v37; // x1
  unsigned int *v38; // x8
  __int64 v39; // x21

  v9 = *(_QWORD *)(a1 + 72);
  if ( !v9 )
    return qdf_trace_msg(0x45u, 2u, "%s: pdev is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "dp_pdev_print_tx_delay_stats");
  result = _qdf_mem_malloc(0x30u, "dp_pdev_print_tx_delay_stats", 5819);
  if ( !result )
    return result;
  v12 = result;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v9 + 312);
    v14 = *(_QWORD *)(v9 + 296);
    if ( v14 )
      goto LABEL_7;
LABEL_24:
    LODWORD(v15) = 0;
    goto LABEL_25;
  }
  raw_spin_lock_bh(v9 + 312);
  *(_QWORD *)(v9 + 320) |= 1uLL;
  v14 = *(_QWORD *)(v9 + 296);
  if ( !v14 )
    goto LABEL_24;
LABEL_7:
  LODWORD(v15) = 0;
  do
  {
    v16 = *(_DWORD *)(v14 + 42560);
    while ( v16 )
    {
      _X15 = (unsigned int *)(v14 + 42560);
      __asm { PRFM            #0x11, [X15] }
      while ( 1 )
      {
        v23 = __ldxr(_X15);
        if ( v23 != v16 )
          break;
        if ( !__stlxr(v16 + 1, _X15) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v23 == v16;
      v16 = v23;
      if ( _ZF )
      {
        _X10 = (unsigned int *)(v14 + 42596);
        __asm { PRFM            #0x11, [X10] }
        do
          v26 = __ldxr(_X10);
        while ( __stxr(v26 + 1, _X10) );
        *(_QWORD *)(v12 + 8LL * (int)v15) = v14;
        LODWORD(v15) = v15 + 1;
        break;
      }
    }
    v14 = *(_QWORD *)(v14 + 104);
  }
  while ( v14 );
LABEL_25:
  v27 = *(_QWORD *)(v9 + 320);
  if ( (v27 & 1) != 0 )
  {
    *(_QWORD *)(v9 + 320) = v27 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v9 + 312);
    if ( (int)v15 >= 1 )
    {
LABEL_27:
      v15 = (unsigned int)v15;
      v36 = (__int64 *)v12;
      do
      {
        v37 = *v36;
        v38 = (unsigned int *)*(unsigned __int8 *)(*v36 + 45317);
        if ( *(_BYTE *)(*v36 + 45317) )
        {
          v39 = *v36;
          dp_vdev_print_tx_delay_stats(*v36);
          dp_vdev_print_tx_delay_jitter_stats(v39);
          v37 = v39;
        }
        dp_vdev_unref_delete(a1, v37, 8u, v38, v28, v29, v30, v31, v32, v33, v34, v35);
        --v15;
        ++v36;
      }
      while ( v15 );
    }
  }
  else
  {
    raw_spin_unlock(v9 + 312);
    if ( (int)v15 >= 1 )
      goto LABEL_27;
  }
  return _qdf_mem_free(v12);
}
