bool __fastcall dp_tx_desc_thresh_reached(__int64 a1, unsigned __int8 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x20
  unsigned int v6; // w8
  unsigned int v13; // w10
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  int v23; // w9
  _BOOL4 v24; // w21
  __int64 v25; // x8
  unsigned int v29; // w9
  __int64 v30; // x8

  if ( a2 > 5u )
  {
    return 0;
  }
  else
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
    v5 = *(_QWORD *)(a1 + 8LL * a2 + 12912);
    if ( v5 )
    {
      v6 = *(_DWORD *)(v5 + 42560);
      while ( v6 )
      {
        _X12 = (unsigned int *)(v5 + 42560);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v13 = __ldxr(_X12);
          if ( v13 != v6 )
            break;
          if ( !__stlxr(v6 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v13 == v6;
        v6 = v13;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v5 + 42592);
          __asm { PRFM            #0x11, [X8] }
          do
            v29 = __ldxr(_X8);
          while ( __stxr(v29 + 1, _X8) );
          v30 = *(_QWORD *)(a1 + 18936);
          if ( (v30 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 18936) = v30 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 18928);
          }
          else
          {
            raw_spin_unlock(a1 + 18928);
          }
          v22 = *(_QWORD *)(v5 + 42432);
          v23 = *(unsigned __int16 *)(v22 + 60);
          if ( *(unsigned __int16 *)(v22 + 72) == v23 && !*(_DWORD *)(v22 + 64)
            || *(unsigned __int16 *)(v22 + 74) == v23 && *(_DWORD *)(v22 + 64) == 2
            || *(unsigned __int16 *)(v22 + 76) == v23 && *(_DWORD *)(v22 + 64) == 3 )
          {
            v24 = 1;
          }
          else if ( *(unsigned __int16 *)(v22 + 78) == v23 )
          {
            v22 = *(unsigned int *)(v22 + 64);
            v24 = v22 == 4;
          }
          else
          {
            v24 = 0;
          }
          dp_vdev_unref_delete(a1, v5, 7u, (unsigned int *)v22, v14, v15, v16, v17, v18, v19, v20, v21);
          return v24;
        }
      }
    }
    v25 = *(_QWORD *)(a1 + 18936);
    if ( (v25 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18936) = v25 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18928);
    }
    else
    {
      raw_spin_unlock(a1 + 18928);
    }
    return 0;
  }
}
