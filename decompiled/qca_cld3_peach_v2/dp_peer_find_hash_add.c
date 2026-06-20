__int64 __fastcall dp_peer_find_hash_add(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v10; // w4
  unsigned int v12; // w21
  unsigned int v13; // w8
  int v14; // w22
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w11
  __int64 v26; // x8
  unsigned int v33; // w13
  __int64 (*v34)(void); // x8
  __int64 v35; // x10
  __int64 v36; // x9
  __int64 v37; // x24
  unsigned int v40; // w12

  v10 = *(_DWORD *)(a2 + 408);
  if ( v10 == 2 )
  {
    v34 = *(__int64 (**)(void))(result + 1520);
    if ( v34 )
    {
      if ( *((_DWORD *)v34 - 1) != -1773781185 )
        __break(0x8228u);
      return v34();
    }
  }
  else if ( v10 == 1 )
  {
    v12 = *(_DWORD *)(result + 13144);
    v13 = *(unsigned __int16 *)(a2 + 46) ^ *(unsigned __int16 *)(a2 + 44) ^ *(unsigned __int16 *)(a2 + 48);
    v14 = (v13 >> *(_DWORD *)(result + 13148)) ^ v13;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v16 = result;
      raw_spin_lock(result + 13288);
    }
    else
    {
      v37 = result;
      raw_spin_lock_bh(result + 13288);
      v16 = v37;
      *(_QWORD *)(v37 + 13296) |= 1uLL;
    }
    v25 = *(_DWORD *)(a2 + 40);
    v26 = v16;
    while ( v25 )
    {
      _X15 = (unsigned int *)(a2 + 40);
      __asm { PRFM            #0x11, [X15] }
      while ( 1 )
      {
        v33 = __ldxr(_X15);
        if ( v33 != v25 )
          break;
        if ( !__stlxr(v25 + 1, _X15) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v33 == v25;
      v25 = v33;
      if ( _ZF )
      {
        _X11 = (unsigned int *)(a2 + 312);
        __asm { PRFM            #0x11, [X11] }
        do
          v40 = __ldxr(_X11);
        while ( __stxr(v40 + 1, _X11) );
        v35 = 16LL * (v14 & v12);
        *(_QWORD *)(a2 + 72) = 0;
        *(_QWORD *)(a2 + 80) = *(_QWORD *)(*(_QWORD *)(v16 + 13152) + v35 + 8);
        **(_QWORD **)(*(_QWORD *)(v16 + 13152) + v35 + 8) = a2;
        *(_QWORD *)(*(_QWORD *)(v16 + 13152) + v35 + 8) = a2 + 72;
        v36 = *(_QWORD *)(v16 + 13296);
        if ( (v36 & 1) == 0 )
          return raw_spin_unlock(v26 + 13288);
        goto LABEL_26;
      }
    }
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: fail to get peer ref:%02x:%02x:%02x:**:**:%02x",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "dp_peer_find_hash_add",
      *(unsigned __int8 *)(a2 + 44),
      *(unsigned __int8 *)(a2 + 45),
      *(unsigned __int8 *)(a2 + 46),
      *(unsigned __int8 *)(a2 + 49));
    v36 = *(_QWORD *)(v16 + 13296);
    v26 = v16;
    if ( (v36 & 1) == 0 )
      return raw_spin_unlock(v26 + 13288);
LABEL_26:
    *(_QWORD *)(v26 + 13296) = v36 & 0xFFFFFFFFFFFFFFFELL;
    return raw_spin_unlock_bh(v26 + 13288);
  }
  else
  {
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: unknown peer type %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "dp_peer_find_hash_add");
  }
  return result;
}
