__int64 __fastcall dp_tx_get_success_ack_stats(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w21
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x20
  unsigned int v15; // w9
  unsigned int v22; // w11
  void *v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x22
  unsigned int v33; // w21
  unsigned int *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x8
  unsigned int *v44; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v56; // w9
  __int64 v57; // x8

  v10 = a2;
  if ( a2 <= 5u )
  {
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
    v14 = *(_QWORD *)(a1 + 8LL * a2 + 12912);
    if ( v14 )
    {
      v15 = *(_DWORD *)(v14 + 42560);
      while ( v15 )
      {
        _X13 = (unsigned int *)(v14 + 42560);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v22 = __ldxr(_X13);
          if ( v22 != v15 )
            break;
          if ( !__stlxr(v15 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v22 == v15;
        v15 = v22;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v14 + 42592);
          __asm { PRFM            #0x11, [X8] }
          do
            v56 = __ldxr(_X8);
          while ( __stxr(v56 + 1, _X8) );
          v57 = *(_QWORD *)(a1 + 18936);
          if ( (v57 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 18936) = v57 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 18928);
          }
          else
          {
            raw_spin_unlock(a1 + 18928);
          }
          v23 = qdf_mem_malloc_atomic_fl(0xA428u, (__int64)"dp_tx_get_success_ack_stats", 0x391Fu);
          if ( v23 )
          {
            v32 = (__int64)v23;
            dp_aggregate_vdev_stats(v14, (__int64)v23, 2u);
            v33 = *(_DWORD *)(v32 + 2552);
            _qdf_mem_free(v32);
            dp_vdev_unref_delete(a1, v14, 7u, v34, v35, v36, v37, v38, v39, v40, v41, v42);
            return v33;
          }
          qdf_trace_msg(
            0x89u,
            2u,
            "%s: %pK: DP alloc failure - unable to get alloc vdev stats",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "dp_tx_get_success_ack_stats",
            a1);
          dp_vdev_unref_delete(a1, v14, 7u, v44, v45, v46, v47, v48, v49, v50, v51, v52);
          return 0;
        }
      }
    }
    v43 = *(_QWORD *)(a1 + 18936);
    if ( (v43 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18936) = v43 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18928);
    }
    else
    {
      raw_spin_unlock(a1 + 18928);
    }
  }
  qdf_trace_msg(
    0x89u,
    2u,
    "%s: %pK: Invalid vdev id %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dp_tx_get_success_ack_stats",
    a1,
    v10);
  return 0;
}
