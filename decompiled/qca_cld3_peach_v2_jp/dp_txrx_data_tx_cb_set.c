__int64 __fastcall dp_txrx_data_tx_cb_set(__int64 result, unsigned __int8 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x19
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
  unsigned int v30; // w9
  __int64 v31; // x8

  if ( a2 <= 5u )
  {
    v7 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 18928);
    }
    else
    {
      raw_spin_lock_bh(result + 18928);
      *(_QWORD *)(v7 + 18936) |= 1uLL;
    }
    v9 = *(_QWORD *)(v7 + 8LL * a2 + 12912);
    if ( v9 )
    {
      v10 = *(_DWORD *)(v9 + 42560);
      while ( v10 )
      {
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
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v9 + 42592);
          __asm { PRFM            #0x11, [X8] }
          do
            v30 = __ldxr(_X8);
          while ( __stxr(v30 + 1, _X8) );
          v31 = *(_QWORD *)(v7 + 18936);
          if ( (v31 & 1) != 0 )
          {
            *(_QWORD *)(v7 + 18936) = v31 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v7 + 18928);
          }
          else
          {
            raw_spin_unlock(v7 + 18928);
          }
          *(_QWORD *)(v9 + 296) = a3;
          *(_QWORD *)(v9 + 304) = a4;
          return dp_vdev_unref_delete(v7, v9, 7u, v18, v19, v20, v21, v22, v23, v24, v25, v26);
        }
      }
    }
    v27 = *(_QWORD *)(v7 + 18936);
    if ( (v27 & 1) != 0 )
    {
      *(_QWORD *)(v7 + 18936) = v27 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v7 + 18928);
    }
    else
    {
      return raw_spin_unlock(v7 + 18928);
    }
  }
  return result;
}
