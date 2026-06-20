__int64 __fastcall dp_vdev_get_ref_by_id_5(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x21
  unsigned int v9; // w9
  unsigned int v15; // w11
  __int64 v17; // x8
  unsigned int v20; // w9
  __int64 v21; // x8

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
    v7 = *(_QWORD *)(a1 + 8LL * a2 + 12912);
    if ( v7 )
    {
      _X8 = (unsigned int *)(v7 + 42560);
      v9 = *(_DWORD *)(v7 + 42560);
      while ( v9 )
      {
        __asm { PRFM            #0x11, [X8] }
        while ( 1 )
        {
          v15 = __ldxr(_X8);
          if ( v15 != v9 )
            break;
          if ( !__stlxr(v9 + 1, _X8) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v15 == v9;
        v9 = v15;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v7 + 4LL * a3 + 42564);
          __asm { PRFM            #0x11, [X8] }
          do
            v20 = __ldxr(_X8);
          while ( __stxr(v20 + 1, _X8) );
          v21 = *(_QWORD *)(a1 + 18936);
          if ( (v21 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 18936) = v21 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 18928);
          }
          else
          {
            raw_spin_unlock(a1 + 18928);
          }
          return v7;
        }
      }
    }
    v17 = *(_QWORD *)(a1 + 18936);
    if ( (v17 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18936) = v17 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18928);
    }
    else
    {
      raw_spin_unlock(a1 + 18928);
    }
  }
  return 0;
}
