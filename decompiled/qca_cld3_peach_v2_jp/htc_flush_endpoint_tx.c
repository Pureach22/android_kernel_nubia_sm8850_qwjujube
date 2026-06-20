__int64 __fastcall htc_flush_endpoint_tx(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x2
  int v6; // w8
  __int64 v7; // x1
  __int64 v8; // x8
  _QWORD *v9; // x9
  __int64 v10; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2992);
    v6 = *(_DWORD *)(a2 + 120);
    if ( !v6 )
      goto LABEL_15;
  }
  else
  {
    raw_spin_lock_bh(a1 + 2992);
    *(_QWORD *)(a1 + 3000) |= 1uLL;
    v6 = *(_DWORD *)(a2 + 120);
    if ( !v6 )
      goto LABEL_15;
  }
  do
  {
    v7 = *(_QWORD *)(a2 + 112);
    if ( v7 != a2 + 104 )
    {
      v8 = *(_QWORD *)v7;
      v9 = *(_QWORD **)(v7 + 8);
      if ( v9 )
        *v9 = v8;
      if ( v8 )
        *(_QWORD *)(v8 + 8) = *(_QWORD *)(v7 + 8);
      *(_QWORD *)v7 = v7;
      *(_QWORD *)(v7 + 8) = v7;
      v6 = *(_DWORD *)(a2 + 120);
      if ( v7 )
      {
        *(_DWORD *)(a2 + 120) = v6 - 1;
        *(_DWORD *)(v7 + 52) = 9;
        send_packet_completion(a1, v7, v5);
        v6 = *(_DWORD *)(a2 + 120);
      }
    }
  }
  while ( v6 );
LABEL_15:
  v10 = *(_QWORD *)(a1 + 3000);
  if ( (v10 & 1) == 0 )
    return raw_spin_unlock(a1 + 2992);
  *(_QWORD *)(a1 + 3000) = v10 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 2992);
}
