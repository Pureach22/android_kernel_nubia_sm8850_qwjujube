__int64 __fastcall dp_rx_fisa_flush_by_intf_ctx_id(__int64 a1, unsigned __int8 a2)
{
  unsigned int v3; // w21
  __int64 result; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x22
  __int64 v9; // x20
  __int64 v10; // x23
  __int64 v11; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v13; // x8
  __int64 v14; // x9
  __int16 v15; // w9
  __int64 v16; // x0

  v3 = a2;
  result = dp_get_context();
  v8 = *(_QWORD *)(result + 1480);
  v9 = *(_QWORD *)v8;
  v10 = *(unsigned __int16 *)(v8 + 32);
  if ( *(_BYTE *)(v8 + 608) == 1 )
  {
    if ( v3 >= 9 )
      goto LABEL_21;
    v11 = v8 + 16LL * v3;
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
      {
        result = raw_spin_lock_bh(v11 + 440);
        *(_QWORD *)(v8 + 16LL * v3 + 448) |= 1uLL;
        if ( !(_DWORD)v10 )
          goto LABEL_8;
        goto LABEL_17;
      }
    }
    result = raw_spin_lock(v11 + 440);
  }
  if ( !(_DWORD)v10 )
    goto LABEL_8;
  do
  {
LABEL_17:
    if ( *(_BYTE *)(v9 + 40) && *(_QWORD *)(v9 + 168) == a1 && *(unsigned __int8 *)(v9 + 144) == v3 )
    {
      v15 = *(_WORD *)(v9 + 194);
      v16 = *(_QWORD *)(v9 + 152);
      *(_WORD *)(v9 + 62) = *(_WORD *)(v9 + 56);
      *(_WORD *)(v9 + 64) = v15;
      result = dp_rx_fisa_flush_flow(v16, v9);
      *(_WORD *)(v9 + 60) = 0;
    }
    --v10;
    v9 += 336;
  }
  while ( v10 );
LABEL_8:
  if ( *(_BYTE *)(v8 + 608) != 1 )
    return result;
  if ( v3 >= 9 )
  {
LABEL_21:
    __break(0x5512u);
    return wlan_dp_get_flow_tuple_from_nbuf(result, v5, v6, v7);
  }
  v13 = v8 + 16LL * v3;
  v14 = *(_QWORD *)(v13 + 448);
  if ( (v14 & 1) == 0 )
    return raw_spin_unlock(v13 + 440);
  *(_QWORD *)(v13 + 448) = v14 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v13 + 440);
}
