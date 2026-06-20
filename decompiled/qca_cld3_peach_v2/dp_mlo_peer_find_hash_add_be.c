__int64 __fastcall dp_mlo_peer_find_hash_add_be(__int64 result, __int64 a2)
{
  unsigned int v2; // w22
  __int64 v3; // x19
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
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x8
  unsigned int v37; // w10

  if ( result )
  {
    v2 = *(_DWORD *)(result + 23440);
    v3 = result;
    v5 = *(unsigned __int16 *)(a2 + 46) ^ *(unsigned __int16 *)(a2 + 44) ^ *(unsigned __int16 *)(a2 + 48);
    v6 = (v5 >> *(_DWORD *)(result + 23444)) ^ v5;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 23424);
    }
    else
    {
      raw_spin_lock_bh(result + 23424);
      *(_QWORD *)(v3 + 23432) |= 1uLL;
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
        _X9 = (unsigned int *)(a2 + 312);
        __asm { PRFM            #0x11, [X9] }
        do
          v37 = __ldxr(_X9);
        while ( __stxr(v37 + 1, _X9) );
        v24 = 16LL * (v6 & v2);
        *(_QWORD *)(a2 + 72) = 0;
        *(_QWORD *)(a2 + 80) = *(_QWORD *)(*(_QWORD *)(v3 + 23448) + v24 + 8);
        **(_QWORD **)(*(_QWORD *)(v3 + 23448) + v24 + 8) = a2;
        *(_QWORD *)(*(_QWORD *)(v3 + 23448) + v24 + 8) = a2 + 72;
        v25 = *(_QWORD *)(v3 + 23432);
        if ( (v25 & 1) != 0 )
        {
          *(_QWORD *)(v3 + 23432) = v25 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v3 + 23424);
        }
        else
        {
          raw_spin_unlock(v3 + 23424);
        }
        return qdf_trace_msg(
                 0x45u,
                 5u,
                 "%s: Peer %pK (%02x:%02x:%02x:**:**:%02x) added",
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 "dp_mlo_peer_find_hash_add_be",
                 a2,
                 *(unsigned __int8 *)(a2 + 44),
                 *(unsigned __int8 *)(a2 + 45),
                 *(unsigned __int8 *)(a2 + 46),
                 *(unsigned __int8 *)(a2 + 49));
      }
    }
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: fail to get peer ref:%02x:%02x:%02x:**:**:%02x",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "dp_mlo_peer_find_hash_add_be",
      *(unsigned __int8 *)(a2 + 44),
      *(unsigned __int8 *)(a2 + 45),
      *(unsigned __int8 *)(a2 + 46),
      *(unsigned __int8 *)(a2 + 49));
    v34 = *(_QWORD *)(v3 + 23432);
    if ( (v34 & 1) != 0 )
    {
      *(_QWORD *)(v3 + 23432) = v34 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v3 + 23424);
    }
    else
    {
      return raw_spin_unlock(v3 + 23424);
    }
  }
  return result;
}
