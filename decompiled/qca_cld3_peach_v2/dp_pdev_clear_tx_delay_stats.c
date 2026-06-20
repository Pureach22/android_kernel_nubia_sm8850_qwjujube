__int64 __fastcall dp_pdev_clear_tx_delay_stats(
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
  __int64 v9; // x19
  __int64 result; // x0
  __int64 v11; // x23
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x8
  int v14; // w20
  unsigned int v15; // w11
  unsigned int v22; // w13
  unsigned int v25; // w11
  __int64 v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x24
  unsigned int *v36; // x8
  __int64 v37; // x26
  __int64 v38; // x21
  char *v39; // x22
  char *v40; // x23
  char *v41; // x24
  char *v42; // x25
  char *v43; // x26
  __int64 v44; // x22
  __int64 v45; // x21
  __int64 v46; // [xsp+8h] [xbp-28h]
  __int64 v48; // [xsp+20h] [xbp-10h]
  __int64 v49; // [xsp+28h] [xbp-8h]

  v9 = *(_QWORD *)(a1 + 72);
  if ( !v9 )
    return qdf_trace_msg(0x45u, 2u, "%s: pdev is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "dp_pdev_clear_tx_delay_stats");
  result = _qdf_mem_malloc(0x30u, "dp_pdev_clear_tx_delay_stats", 5934);
  if ( !result )
    return result;
  v11 = result;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v9 + 312);
    v13 = *(_QWORD *)(v9 + 296);
    if ( v13 )
      goto LABEL_7;
LABEL_24:
    v14 = 0;
    goto LABEL_25;
  }
  raw_spin_lock_bh(v9 + 312);
  *(_QWORD *)(v9 + 320) |= 1uLL;
  v13 = *(_QWORD *)(v9 + 296);
  if ( !v13 )
    goto LABEL_24;
LABEL_7:
  v14 = 0;
  do
  {
    v15 = *(_DWORD *)(v13 + 43384);
    while ( v15 )
    {
      _X15 = (unsigned int *)(v13 + 43384);
      __asm { PRFM            #0x11, [X15] }
      while ( 1 )
      {
        v22 = __ldxr(_X15);
        if ( v22 != v15 )
          break;
        if ( !__stlxr(v15 + 1, _X15) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v22 == v15;
      v15 = v22;
      if ( _ZF )
      {
        _X10 = (unsigned int *)(v13 + 43420);
        __asm { PRFM            #0x11, [X10] }
        do
          v25 = __ldxr(_X10);
        while ( __stxr(v25 + 1, _X10) );
        *(_QWORD *)(v11 + 8LL * v14++) = v13;
        break;
      }
    }
    v13 = *(_QWORD *)(v13 + 112);
  }
  while ( v13 );
LABEL_25:
  v26 = *(_QWORD *)(v9 + 320);
  if ( (v26 & 1) != 0 )
  {
    *(_QWORD *)(v9 + 320) = v26 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v9 + 312);
    if ( v14 >= 1 )
    {
LABEL_27:
      v35 = 0;
      v36 = (unsigned int *)(unsigned int)v14;
      v46 = v11;
      do
      {
        v37 = *(_QWORD *)(v11 + 8 * v35);
        if ( v37 )
        {
          v48 = *(_QWORD *)(v11 + 8 * v35);
          v49 = v35;
          v38 = 9;
          v39 = (char *)(v37 + 36608);
          v40 = (char *)(v37 + 29840);
          v41 = (char *)(v37 + 23072);
          v42 = (char *)(v37 + 16304);
          v43 = (char *)(v37 + 9536);
          do
          {
            qdf_mem_set(v43, 0x80u, 0);
            qdf_mem_set(v42, 0x80u, 0);
            qdf_mem_set(v41, 0x80u, 0);
            qdf_mem_set(v40, 0x80u, 0);
            qdf_mem_set(v39, 0x80u, 0);
            --v38;
            v39 += 752;
            v40 += 752;
            v41 += 752;
            v42 += 752;
            v43 += 752;
          }
          while ( v38 );
          v37 = v48;
          v35 = v49;
          v44 = 9;
          v11 = v46;
          v45 = v48;
          do
          {
            qdf_mem_set((void *)(v45 + 9792), 0x88u, 0);
            qdf_mem_set((void *)(v45 + 16560), 0x88u, 0);
            qdf_mem_set((void *)(v45 + 23328), 0x88u, 0);
            qdf_mem_set((void *)(v45 + 30096), 0x88u, 0);
            qdf_mem_set((void *)(v45 + 36864), 0x88u, 0);
            --v44;
            v45 += 752;
          }
          while ( v44 );
        }
        dp_vdev_unref_delete(a1, v37, 8u, v36, v27, v28, v29, v30, v31, v32, v33, v34);
        v36 = (unsigned int *)(unsigned int)v14;
        ++v35;
      }
      while ( v35 != v14 );
    }
  }
  else
  {
    raw_spin_unlock(v9 + 312);
    if ( v14 >= 1 )
      goto LABEL_27;
  }
  return _qdf_mem_free(v11);
}
