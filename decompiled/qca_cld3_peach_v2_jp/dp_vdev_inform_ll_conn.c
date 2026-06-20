__int64 __fastcall dp_vdev_inform_ll_conn(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w21
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x22
  unsigned int v17; // w8
  unsigned int v24; // w10
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int *v33; // x8
  __int64 v34; // x8
  unsigned int v38; // w9
  __int64 v39; // x8

  v11 = a2;
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
    v16 = *(_QWORD *)(a1 + 8LL * a2 + 12912);
    if ( v16 )
    {
      v17 = *(_DWORD *)(v16 + 42560);
      do
      {
        if ( !v17 )
          goto LABEL_20;
        _X12 = (unsigned int *)(v16 + 42560);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v24 = __ldxr(_X12);
          if ( v24 != v17 )
            break;
          if ( !__stlxr(v17 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v24 == v17;
        v17 = v24;
      }
      while ( !_ZF );
      _X8 = (unsigned int *)(v16 + 42592);
      __asm { PRFM            #0x11, [X8] }
      do
        v38 = __ldxr(_X8);
      while ( __stxr(v38 + 1, _X8) );
      v39 = *(_QWORD *)(a1 + 18936);
      if ( (v39 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 18936) = v39 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 18928);
        if ( a3 == 1 )
          goto LABEL_29;
      }
      else
      {
        raw_spin_unlock(a1 + 18928);
        if ( a3 == 1 )
        {
LABEL_29:
          v33 = (unsigned int *)((unsigned int)*(unsigned __int8 *)(v16 + 42688) - 1);
          goto LABEL_30;
        }
      }
      if ( a3 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: LL connection action invalid %d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "dp_vdev_inform_ll_conn",
          a3);
LABEL_31:
        dp_vdev_unref_delete(a1, v16, 7u, v33, v25, v26, v27, v28, v29, v30, v31, v32);
        return 0;
      }
      v33 = (unsigned int *)((unsigned int)*(unsigned __int8 *)(v16 + 42688) + 1);
LABEL_30:
      *(_BYTE *)(v16 + 42688) = (_BYTE)v33;
      goto LABEL_31;
    }
LABEL_20:
    v34 = *(_QWORD *)(a1 + 18936);
    if ( (v34 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18936) = v34 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18928);
    }
    else
    {
      raw_spin_unlock(a1 + 18928);
    }
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: LL connection action for invalid vdev %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "dp_vdev_inform_ll_conn",
    v11);
  return 16;
}
