__int64 __fastcall dp_txrx_get_vdev_stats(__int64 a1, unsigned __int8 a2, __int64 a3, char a4)
{
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x22
  unsigned int v10; // w9
  unsigned int v17; // w11
  unsigned int *v18; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x8
  unsigned int v31; // w9
  __int64 v32; // x8

  if ( a2 > 5u )
    return 1;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 18928);
  }
  else
  {
    raw_spin_lock_bh(a1 + 18928);
    *(_QWORD *)(a1 + 18936) |= 1uLL;
  }
  v9 = *(_QWORD *)(a1 + 8LL * a2 + 12912);
  if ( v9 )
  {
    v10 = *(_DWORD *)(v9 + 42560);
    do
    {
      if ( !v10 )
        goto LABEL_19;
      _X13 = (unsigned int *)(v9 + 42560);
      __asm { PRFM            #0x11, [X13] }
      while ( 1 )
      {
        v17 = __ldxr(_X13);
        if ( v17 != v10 )
          break;
        if ( !__stlxr(v10 + 1, _X13) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v17 == v10;
      v10 = v17;
    }
    while ( !_ZF );
    _X8 = (unsigned int *)(v9 + 42592);
    __asm { PRFM            #0x11, [X8] }
    do
      v31 = __ldxr(_X8);
    while ( __stxr(v31 + 1, _X8) );
    v32 = *(_QWORD *)(a1 + 18936);
    if ( (v32 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18936) = v32 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18928);
      if ( (a4 & 1) == 0 )
        goto LABEL_27;
    }
    else
    {
      raw_spin_unlock(a1 + 18928);
      if ( (a4 & 1) == 0 )
      {
LABEL_27:
        dp_copy_vdev_stats_to_tgt_buf(a3, v9 + 400, 0);
        goto LABEL_28;
      }
    }
    dp_aggregate_vdev_stats(v9, a3, 0);
LABEL_28:
    dp_vdev_unref_delete(a1, v9, 7u, v18, v19, v20, v21, v22, v23, v24, v25, v26);
    return 0;
  }
LABEL_19:
  v27 = *(_QWORD *)(a1 + 18936);
  if ( (v27 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 18928);
    return 1;
  }
  *(_QWORD *)(a1 + 18936) = v27 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 18928);
  return 1;
}
