__int64 __fastcall dp_peer_vdev_list_add(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w8
  unsigned int v21; // w10
  _QWORD *v22; // x8
  __int64 v23; // x9
  _QWORD *v24; // x9
  _QWORD *v25; // x9
  __int64 v26; // x8
  __int64 result; // x0
  unsigned int v30; // w9

  if ( *(_DWORD *)(a3 + 408) != 2 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a2 + 144);
    }
    else
    {
      raw_spin_lock_bh(a2 + 144);
      *(_QWORD *)(a2 + 152) |= 1uLL;
    }
    v14 = *(_DWORD *)(a3 + 40);
    while ( v14 )
    {
      _X12 = (unsigned int *)(a3 + 40);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v21 = __ldxr(_X12);
        if ( v21 != v14 )
          break;
        if ( !__stlxr(v14 + 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v21 == v14;
      v14 = v21;
      if ( _ZF )
      {
        _X8 = (unsigned int *)(a3 + 312);
        __asm { PRFM            #0x11, [X8] }
        do
          v30 = __ldxr(_X8);
        while ( __stxr(v30 + 1, _X8) );
        if ( *(_DWORD *)(a2 + 32) == 3 )
        {
          v22 = (_QWORD *)(a2 + 128);
          v23 = *(_QWORD *)(a2 + 128);
          *(_QWORD *)(a3 + 56) = v23;
          if ( v23 )
            v24 = (_QWORD *)(v23 + 64);
          else
            v24 = (_QWORD *)(a2 + 136);
          *v24 = a3 + 56;
          *v22 = a3;
          *(_QWORD *)(a3 + 64) = v22;
        }
        else
        {
          *(_QWORD *)(a3 + 56) = 0;
          v25 = *(_QWORD **)(a2 + 136);
          *(_QWORD *)(a3 + 64) = v25;
          *v25 = a3;
          *(_QWORD *)(a2 + 136) = a3 + 56;
        }
        v26 = *(_QWORD *)(a2 + 152);
        ++*(_DWORD *)(a2 + 43344);
        if ( (v26 & 1) == 0 )
          return raw_spin_unlock(a2 + 144);
        goto LABEL_26;
      }
    }
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: unable to get peer ref at MAP mac: %02x:%02x:%02x:**:**:%02x",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "dp_peer_vdev_list_add",
      *(unsigned __int8 *)(a3 + 44),
      *(unsigned __int8 *)(a3 + 45),
      *(unsigned __int8 *)(a3 + 46),
      *(unsigned __int8 *)(a3 + 49));
    v26 = *(_QWORD *)(a2 + 152);
    if ( (v26 & 1) == 0 )
      return raw_spin_unlock(a2 + 144);
LABEL_26:
    *(_QWORD *)(a2 + 152) = v26 & 0xFFFFFFFFFFFFFFFELL;
    return raw_spin_unlock_bh(a2 + 144);
  }
  return result;
}
