__int64 __fastcall dp_peer_find_hash_add(__int64 a1, __int64 a2)
{
  unsigned int v3; // w22
  unsigned int v5; // w8
  int v6; // w23
  unsigned __int64 StatusReg; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w9
  unsigned int v23; // w11
  __int64 v24; // x8
  __int64 v25; // x8
  unsigned int v29; // w10

  v3 = *(_DWORD *)(a1 + 13096);
  v5 = *(unsigned __int16 *)(a2 + 46) ^ *(unsigned __int16 *)(a2 + 44) ^ *(unsigned __int16 *)(a2 + 48);
  v6 = (v5 >> *(_DWORD *)(a1 + 13100)) ^ v5;
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
  v16 = *(_DWORD *)(a2 + 40);
  while ( v16 )
  {
    _X13 = (unsigned int *)(a2 + 40);
    __asm { PRFM            #0x11, [X13] }
    while ( 1 )
    {
      v23 = __ldxr(_X13);
      if ( v23 != v16 )
        break;
      if ( !__stlxr(v16 + 1, _X13) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v23 == v16;
    v16 = v23;
    if ( _ZF )
    {
      _X9 = (unsigned int *)(a2 + 304);
      __asm { PRFM            #0x11, [X9] }
      do
        v29 = __ldxr(_X9);
      while ( __stxr(v29 + 1, _X9) );
      v24 = 16LL * (v6 & v3);
      *(_QWORD *)(a2 + 72) = 0;
      *(_QWORD *)(a2 + 80) = *(_QWORD *)(*(_QWORD *)(a1 + 13104) + v24 + 8);
      **(_QWORD **)(*(_QWORD *)(a1 + 13104) + v24 + 8) = a2;
      *(_QWORD *)(*(_QWORD *)(a1 + 13104) + v24 + 8) = a2 + 72;
      v25 = *(_QWORD *)(a1 + 13248);
      if ( (v25 & 1) == 0 )
        return raw_spin_unlock(a1 + 13240);
      goto LABEL_19;
    }
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: unable to get peer ref at MAP mac: %02x:%02x:%02x:**:**:%02x",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "dp_peer_find_hash_add",
    *(unsigned __int8 *)(a2 + 44),
    *(unsigned __int8 *)(a2 + 45),
    *(unsigned __int8 *)(a2 + 46),
    *(unsigned __int8 *)(a2 + 49));
  v25 = *(_QWORD *)(a1 + 13248);
  if ( (v25 & 1) == 0 )
    return raw_spin_unlock(a1 + 13240);
LABEL_19:
  *(_QWORD *)(a1 + 13248) = v25 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 13240);
}
