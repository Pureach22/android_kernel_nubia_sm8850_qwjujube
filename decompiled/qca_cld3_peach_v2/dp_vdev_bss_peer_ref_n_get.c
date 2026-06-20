__int64 __fastcall dp_vdev_bss_peer_ref_n_get(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x8
  __int64 v7; // x8
  unsigned int v16; // w11
  __int64 v17; // x20
  __int64 v18; // x8
  unsigned int v20; // w10

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 144);
    v6 = *(_QWORD *)(a2 + 128);
    if ( v6 )
      goto LABEL_5;
    goto LABEL_7;
  }
  raw_spin_lock_bh(a2 + 144);
  *(_QWORD *)(a2 + 152) |= 1uLL;
  v6 = *(_QWORD *)(a2 + 128);
  if ( !v6 )
  {
LABEL_7:
    v7 = *(_QWORD *)(a2 + 152);
    if ( (v7 & 1) != 0 )
    {
      *(_QWORD *)(a2 + 152) = v7 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a2 + 144);
    }
    else
    {
      raw_spin_unlock(a2 + 144);
    }
    return 0;
  }
LABEL_5:
  while ( (*(_BYTE *)(v6 + 120) & 1) == 0 )
  {
    v6 = *(_QWORD *)(v6 + 56);
    if ( !v6 )
      goto LABEL_7;
  }
  LODWORD(_X9) = *(_DWORD *)(v6 + 40);
  while ( (_DWORD)_X9 )
  {
    _X13 = (unsigned int *)(v6 + 40);
    __asm { PRFM            #0x11, [X13] }
    while ( 1 )
    {
      v16 = __ldxr(_X13);
      if ( v16 != (unsigned int)_X9 )
        break;
      if ( !__stlxr((_DWORD)_X9 + 1, _X13) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v16 == (_DWORD)_X9;
    _X9 = (unsigned int *)v16;
    if ( _ZF )
    {
      if ( a3 >= 3 )
      {
        if ( a3 >= 0x20 )
          __break(0x5512u);
        else
          _X9 = (unsigned int *)(v6 + 4LL * a3 + 264);
        __asm { PRFM            #0x11, [X9] }
        do
          v20 = __ldxr(_X9);
        while ( __stxr(v20 + 1, _X9) );
      }
      break;
    }
  }
  v17 = v6;
  v18 = *(_QWORD *)(a2 + 152);
  if ( (v18 & 1) != 0 )
  {
    *(_QWORD *)(a2 + 152) = v18 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a2 + 144);
  }
  else
  {
    raw_spin_unlock(a2 + 144);
  }
  return v17;
}
