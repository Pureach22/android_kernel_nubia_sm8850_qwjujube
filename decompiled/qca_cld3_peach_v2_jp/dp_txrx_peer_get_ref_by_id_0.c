__int64 __fastcall dp_txrx_peer_get_ref_by_id_0(__int64 a1, unsigned __int16 a2, __int64 *a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x21
  __int64 v8; // x8
  unsigned int v10; // w8
  unsigned int v17; // w10
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v28; // w9
  __int64 v29; // x8

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
  _X8 = (unsigned int *)(v7 + 272);
  __asm { PRFM            #0x11, [X8] }
  do
    v28 = __ldxr(_X8);
  while ( __stxr(v28 + 1, _X8) );
  v29 = *(_QWORD *)(a1 + 13264);
  if ( (v29 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13264) = v29 & 0xFFFFFFFFFFFFFFFELL;
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
  dp_peer_unref_delete(v7, 4u, v18, v19, v20, v21, v22, v23, v24, v25);
  return 0;
}
