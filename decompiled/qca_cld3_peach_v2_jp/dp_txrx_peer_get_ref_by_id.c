__int64 __fastcall dp_txrx_peer_get_ref_by_id(__int64 a1, unsigned __int16 a2, _QWORD *a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x21
  __int64 v8; // x8
  unsigned int v10; // w8
  unsigned int v17; // w10
  unsigned int v20; // w9
  __int64 v21; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 13256);
  }
  else
  {
    raw_spin_lock_bh(a1 + 13256);
    *(_QWORD *)(a1 + 13264) |= 1uLL;
  }
  if ( *(_DWORD *)(a1 + 13276) <= (unsigned int)a2
    || (v7 = *(_QWORD *)(*(_QWORD *)(a1 + 13088) + 8LL * a2)) == 0
    || *(unsigned __int8 *)(v7 + 380) > 2u )
  {
LABEL_8:
    v8 = *(_QWORD *)(a1 + 13264);
    if ( (v8 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 13264) = v8 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 13256);
    }
    else
    {
      raw_spin_unlock(a1 + 13256);
    }
    return 0;
  }
  v10 = *(_DWORD *)(v7 + 40);
  do
  {
    if ( !v10 )
      goto LABEL_8;
    _X12 = (unsigned int *)(v7 + 40);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v17 = __ldxr(_X12);
      if ( v17 != v10 )
        break;
      if ( !__stlxr(v10 + 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v17 == v10;
    v10 = v17;
  }
  while ( !_ZF );
  _X8 = (unsigned int *)(v7 + 268);
  __asm { PRFM            #0x11, [X8] }
  do
    v20 = __ldxr(_X8);
  while ( __stxr(v20 + 1, _X8) );
  v21 = *(_QWORD *)(a1 + 13264);
  if ( (v21 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13264) = v21 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 13256);
    if ( !*(_QWORD *)v7 )
      goto LABEL_29;
LABEL_23:
    *a3 = v7;
    return *(_QWORD *)v7;
  }
  raw_spin_unlock(a1 + 13256);
  if ( *(_QWORD *)v7 )
    goto LABEL_23;
LABEL_29:
  dp_peer_unref_delete(v7, 3);
  return 0;
}
