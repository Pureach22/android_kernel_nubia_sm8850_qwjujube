__int64 __fastcall dp_vdev_get_dp_ext_handle(__int64 a1, unsigned __int8 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x20
  unsigned int v6; // w8
  unsigned int v13; // w10
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  __int64 v24; // x8
  unsigned int v28; // w9
  __int64 v29; // x8

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
            v28 = __ldxr(_X8);
          while ( __stxr(v28 + 1, _X8) );
          v29 = *(_QWORD *)(a1 + 18936);
          if ( (v29 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 18936) = v29 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 18928);
          }
          else
          {
            raw_spin_unlock(a1 + 18928);
          }
          v23 = *(_QWORD *)(v5 + 42504);
          dp_vdev_unref_delete(a1, v5, 7u, v14, v15, v16, v17, v18, v19, v20, v21, v22);
          return v23;
        }
      }
    }
    v24 = *(_QWORD *)(a1 + 18936);
    if ( (v24 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18936) = v24 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18928);
    }
    else
    {
      raw_spin_unlock(a1 + 18928);
    }
  }
  return 0;
}
