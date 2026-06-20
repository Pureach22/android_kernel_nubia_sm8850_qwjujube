__int64 __fastcall dp_get_opmode(
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
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x21
  unsigned int v14; // w9
  unsigned int v21; // w11
  unsigned int *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w20
  __int64 v32; // x8
  __int64 v33; // x21
  unsigned int v37; // w9
  __int64 v38; // x8

  if ( a2 <= 5u )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 18984);
    }
    else
    {
      raw_spin_lock_bh(a1 + 18984);
      *(_QWORD *)(a1 + 18992) |= 1uLL;
    }
    v13 = *(_QWORD *)(a1 + 8LL * a2 + 12960);
    if ( v13 )
    {
      v14 = *(_DWORD *)(v13 + 43384);
      while ( v14 )
      {
        _X13 = (unsigned int *)(v13 + 43384);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v21 = __ldxr(_X13);
          if ( v21 != v14 )
            break;
          if ( !__stlxr(v14 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v21 == v14;
        v14 = v21;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v13 + 43416);
          __asm { PRFM            #0x11, [X8] }
          do
            v37 = __ldxr(_X8);
          while ( __stxr(v37 + 1, _X8) );
          v38 = *(_QWORD *)(a1 + 18992);
          if ( (v38 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 18992) = v38 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 18984);
          }
          else
          {
            raw_spin_unlock(a1 + 18984);
          }
          v31 = *(_DWORD *)(v13 + 32);
          dp_vdev_unref_delete(a1, v13, 7u, v22, v23, v24, v25, v26, v27, v28, v29, v30);
          return v31;
        }
      }
    }
    v32 = *(_QWORD *)(a1 + 18992);
    if ( (v32 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18992) = v32 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18984);
    }
    else
    {
      raw_spin_unlock(a1 + 18984);
    }
  }
  v33 = jiffies;
  if ( dp_get_opmode___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev for id %d is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "dp_get_opmode", a2);
    dp_get_opmode___last_ticks = v33;
  }
  return (unsigned int)-22;
}
