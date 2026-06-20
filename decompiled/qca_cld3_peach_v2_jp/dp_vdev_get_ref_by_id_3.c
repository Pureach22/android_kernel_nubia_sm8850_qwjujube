__int64 __fastcall dp_vdev_get_ref_by_id_3(__int64 a1, unsigned __int8 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x20
  unsigned int v6; // w9
  unsigned int v13; // w11
  __int64 v15; // x8
  unsigned int v18; // w9
  __int64 v19; // x8

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
        _X13 = (unsigned int *)(v5 + 42560);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v13 = __ldxr(_X13);
          if ( v13 != v6 )
            break;
          if ( !__stlxr(v6 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v13 == v6;
        v6 = v13;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v5 + 42572);
          __asm { PRFM            #0x11, [X8] }
          do
            v18 = __ldxr(_X8);
          while ( __stxr(v18 + 1, _X8) );
          v19 = *(_QWORD *)(a1 + 18936);
          if ( (v19 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 18936) = v19 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 18928);
          }
          else
          {
            raw_spin_unlock(a1 + 18928);
          }
          return v5;
        }
      }
    }
    v15 = *(_QWORD *)(a1 + 18936);
    if ( (v15 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18936) = v15 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18928);
    }
    else
    {
      raw_spin_unlock(a1 + 18928);
    }
  }
  return 0;
}
