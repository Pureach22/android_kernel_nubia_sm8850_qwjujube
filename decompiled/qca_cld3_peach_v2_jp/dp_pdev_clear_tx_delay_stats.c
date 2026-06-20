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
  __int64 v9; // x21
  __int64 result; // x0
  __int64 v11; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x8
  int v14; // w22
  unsigned int v15; // w11
  unsigned int v22; // w13
  unsigned int v25; // w11
  __int64 v26; // x8
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x27
  __int64 v37; // x28
  __int64 v38; // x21
  __int64 v39; // x19
  char *v40; // x22
  char *v41; // x23
  char *v42; // x24
  char *v43; // x25
  char *v44; // x26
  __int64 v45; // x19
  char *v46; // x22
  char *v47; // x23
  char *v48; // x24
  char *v49; // x25
  char *v50; // x26

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
    v15 = *(_DWORD *)(v13 + 42560);
    while ( v15 )
    {
      _X15 = (unsigned int *)(v13 + 42560);
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
        _X10 = (unsigned int *)(v13 + 42596);
        __asm { PRFM            #0x11, [X10] }
        do
          v25 = __ldxr(_X10);
        while ( __stxr(v25 + 1, _X10) );
        *(_QWORD *)(v11 + 8LL * v14++) = v13;
        break;
      }
    }
    v13 = *(_QWORD *)(v13 + 104);
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
      v36 = 0;
      v37 = (unsigned int)v14;
      do
      {
        v38 = *(_QWORD *)(v11 + 8 * v36);
        if ( v38 )
        {
          v39 = 9;
          v40 = (char *)(v38 + 35784);
          v41 = (char *)(v38 + 29016);
          v42 = (char *)(v38 + 22248);
          v43 = (char *)(v38 + 15480);
          v44 = (char *)(v38 + 8712);
          do
          {
            qdf_mem_set(v44, 0x80u, 0);
            qdf_mem_set(v43, 0x80u, 0);
            qdf_mem_set(v42, 0x80u, 0);
            qdf_mem_set(v41, 0x80u, 0);
            qdf_mem_set(v40, 0x80u, 0);
            --v39;
            v40 += 752;
            v41 += 752;
            v42 += 752;
            v43 += 752;
            v44 += 752;
          }
          while ( v39 );
          v45 = 9;
          v46 = (char *)(v38 + 36040);
          v47 = (char *)(v38 + 29272);
          v48 = (char *)(v38 + 22504);
          v49 = (char *)(v38 + 15736);
          v50 = (char *)(v38 + 8968);
          do
          {
            qdf_mem_set(v50, 0x88u, 0);
            qdf_mem_set(v49, 0x88u, 0);
            qdf_mem_set(v48, 0x88u, 0);
            qdf_mem_set(v47, 0x88u, 0);
            qdf_mem_set(v46, 0x88u, 0);
            --v45;
            v46 += 752;
            v47 += 752;
            v48 += 752;
            v49 += 752;
            v50 += 752;
          }
          while ( v45 );
        }
        dp_vdev_unref_delete(a1, v38, 8u, v27, v28, v29, v30, v31, v32, v33, v34, v35);
        ++v36;
      }
      while ( v36 != v37 );
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
