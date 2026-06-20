__int64 __fastcall dp_flush_ring_hptp(__int64 result, __int64 a2)
{
  __int64 v3; // x21
  __int64 v4; // x20
  unsigned __int64 StatusReg; // x8
  int v6; // w10
  int v7; // w9
  __int64 v8; // x8
  __int64 v9; // x10
  _DWORD *v12; // x2
  __int64 v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int64 v28; // x8

  if ( a2 )
  {
    _X9 = (unsigned __int64 *)(a2 + 176);
    __asm { PRFM            #0x11, [X9] }
    do
      v28 = __ldxr(_X9);
    while ( __stlxr(v28 & 0xFFFFFFFFFFFFFFFDLL, _X9) );
    __dmb(0xBu);
    if ( (v28 & 2) != 0 )
    {
      v3 = *(_QWORD *)(result + 1128);
      v4 = result;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a2 + 80);
      }
      else
      {
        raw_spin_lock_bh(a2 + 80);
        *(_QWORD *)(a2 + 88) |= 1uLL;
      }
      v6 = *(_DWORD *)(a2 + 116);
      v7 = **(_DWORD **)(a2 + 128);
      v8 = v4;
      *(_DWORD *)(a2 + 136) = v7;
      if ( v6 )
      {
        if ( (*(_BYTE *)(a2 + 78) & 4) != 0 )
        {
          v9 = *(unsigned int *)(a2 + 120);
          if ( (_DWORD)v9 != v7 )
          {
            if ( *(_QWORD *)(a2 + 16) + 4 * v9 )
            {
              if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v3 + 8) + 40LL) + 844LL) & 0x40) == 0 )
              {
                _dma_sync_single_for_cpu();
                v8 = v4;
              }
              __asm { PRFM            #0, [X22] }
            }
          }
        }
      }
      v12 = *(_DWORD **)(a2 + 144);
      if ( (*(_DWORD *)(a2 + 76) & 0x80000000) != 0 )
      {
        *v12 = *(_DWORD *)(a2 + 120);
        v13 = *(_QWORD *)(a2 + 88);
        if ( (v13 & 1) == 0 )
          goto LABEL_16;
      }
      else
      {
        hal_delayed_reg_write(*(_QWORD *)(v8 + 1128), a2, v12, *(unsigned int *)(a2 + 120));
        v13 = *(_QWORD *)(a2 + 88);
        if ( (v13 & 1) == 0 )
        {
LABEL_16:
          raw_spin_unlock(a2 + 80);
LABEL_17:
          __isb(0xFu);
          *(_QWORD *)(a2 + 184) = _ReadStatusReg(CNTVCT_EL0);
          return qdf_trace_msg(0x45u, 8u, "%s: flushed", v14, v15, v16, v17, v18, v19, v20, v21, "dp_flush_ring_hptp");
        }
      }
      *(_QWORD *)(a2 + 88) = v13 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a2 + 80);
      goto LABEL_17;
    }
  }
  return result;
}
