__int64 __fastcall dp_peer_find_hash_find(
        __int64 a1,
        unsigned __int16 *a2,
        int a3,
        unsigned __int8 a4,
        unsigned int a5)
{
  unsigned __int16 *v8; // x22
  int v9; // w8
  unsigned int v10; // w24
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x8
  unsigned int v20; // w11
  __int64 v21; // x8
  __int64 result; // x0
  __int64 v23; // x20
  __int64 v24; // x8
  unsigned int v26; // w10
  _QWORD v27[2]; // [xsp+0h] [xbp-10h] BYREF

  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(a1 + 13104) )
    goto LABEL_26;
  v8 = a2;
  v27[0] = 0;
  if ( !a3 )
  {
    qdf_mem_copy(v27, a2, 6u);
    v8 = (unsigned __int16 *)v27;
  }
  v9 = v8[1] ^ *v8;
  v10 = (((v9 ^ (unsigned int)v8[2]) >> *(_DWORD *)(a1 + 13100)) ^ v9 ^ v8[2]) & *(_DWORD *)(a1 + 13096);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 13240);
  }
  else
  {
    raw_spin_lock_bh(a1 + 13240);
    *(_QWORD *)(a1 + 13248) |= 1uLL;
  }
  v12 = *(_QWORD *)(*(_QWORD *)(a1 + 13104) + 16LL * v10);
  if ( !v12 )
  {
LABEL_24:
    v21 = *(_QWORD *)(a1 + 13248);
    if ( (v21 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 13248) = v21 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 13240);
    }
    else
    {
      raw_spin_unlock(a1 + 13240);
    }
LABEL_26:
    result = 0;
    goto LABEL_27;
  }
  while ( *(_DWORD *)v8 != *(_DWORD *)(v12 + 44)
       || v8[2] != *(unsigned __int16 *)(v12 + 48)
       || a4 != 255 && *(unsigned __int8 *)(*(_QWORD *)(v12 + 24) + 59LL) != a4 )
  {
    v12 = *(_QWORD *)(v12 + 72);
    if ( !v12 )
      goto LABEL_24;
  }
  LODWORD(_X9) = *(_DWORD *)(v12 + 40);
  do
  {
    if ( !(_DWORD)_X9 )
    {
      v12 = 0;
      goto LABEL_31;
    }
    _X13 = (unsigned int *)(v12 + 40);
    __asm { PRFM            #0x11, [X13] }
    while ( 1 )
    {
      v20 = __ldxr(_X13);
      if ( v20 != (unsigned int)_X9 )
        break;
      if ( !__stlxr((_DWORD)_X9 + 1, _X13) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v20 == (_DWORD)_X9;
    _X9 = (unsigned int *)v20;
  }
  while ( !_ZF );
  if ( a5 >= 3 )
  {
    if ( a5 >= 0x20 )
      __break(0x5512u);
    else
      _X9 = (unsigned int *)(v12 + 4LL * a5 + 256);
    __asm { PRFM            #0x11, [X9] }
    do
      v26 = __ldxr(_X9);
    while ( __stxr(v26 + 1, _X9) );
  }
LABEL_31:
  v23 = v12;
  v24 = *(_QWORD *)(a1 + 13248);
  if ( (v24 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13248) = v24 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 13240);
  }
  else
  {
    raw_spin_unlock(a1 + 13240);
  }
  result = v23;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
