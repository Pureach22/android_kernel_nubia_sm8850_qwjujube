__int64 __fastcall dp_enable_disable_vdev_tx_delay_stats(__int64 result, unsigned __int8 a2, char a3)
{
  __int64 v5; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x21
  unsigned int v9; // w8
  unsigned int v15; // w10
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  unsigned int v28; // w9
  __int64 v29; // x8

  if ( a2 <= 5u )
  {
    v5 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 18928);
    }
    else
    {
      raw_spin_lock_bh(result + 18928);
      *(_QWORD *)(v5 + 18936) |= 1uLL;
    }
    v7 = *(_QWORD *)(v5 + 8LL * a2 + 12912);
    if ( v7 )
    {
      _X23 = (unsigned int *)(v7 + 42560);
      v9 = *(_DWORD *)(v7 + 42560);
      while ( v9 )
      {
        __asm { PRFM            #0x11, [X23] }
        while ( 1 )
        {
          v15 = __ldxr(_X23);
          if ( v15 != v9 )
            break;
          if ( !__stlxr(v9 + 1, _X23) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v15 == v9;
        v9 = v15;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v7 + 42592);
          __asm { PRFM            #0x11, [X8] }
          do
            v28 = __ldxr(_X8);
          while ( __stxr(v28 + 1, _X8) );
          v29 = *(_QWORD *)(v5 + 18936);
          if ( (v29 & 1) != 0 )
          {
            *(_QWORD *)(v5 + 18936) = v29 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v5 + 18928);
          }
          else
          {
            raw_spin_unlock(v5 + 18928);
          }
          *(_BYTE *)(v7 + 45317) = a3;
          return dp_vdev_unref_delete(v5, v7, 7u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
        }
      }
    }
    v25 = *(_QWORD *)(v5 + 18936);
    if ( (v25 & 1) != 0 )
    {
      *(_QWORD *)(v5 + 18936) = v25 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v5 + 18928);
    }
    else
    {
      return raw_spin_unlock(v5 + 18928);
    }
  }
  return result;
}
