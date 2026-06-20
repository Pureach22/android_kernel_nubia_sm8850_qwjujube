__int64 __fastcall htc_flush_endpoint_txlookupQ(__int64 a1, unsigned int a2, char a3)
{
  __int64 v5; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x2
  __int64 v8; // x1
  __int64 v9; // x8
  _QWORD *v10; // x9
  __int64 v11; // x8

  if ( a2 >= 0xA )
  {
    __break(0x5512u);
    return htc_flush_endpoint();
  }
  v5 = a1 + 328LL * a2 + 8;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2992);
    if ( *(_DWORD *)(v5 + 240) )
      goto LABEL_9;
  }
  else
  {
    raw_spin_lock_bh(a1 + 2992);
    *(_QWORD *)(a1 + 3000) |= 1uLL;
    while ( *(_DWORD *)(v5 + 240) )
    {
LABEL_9:
      v8 = *(_QWORD *)(v5 + 232);
      if ( v8 != v5 + 224 )
      {
        v9 = *(_QWORD *)v8;
        v10 = *(_QWORD **)(v8 + 8);
        if ( v10 )
          *v10 = v9;
        if ( v9 )
          *(_QWORD *)(v9 + 8) = *(_QWORD *)(v8 + 8);
        *(_QWORD *)v8 = v8;
        *(_QWORD *)(v8 + 8) = v8;
        if ( v8 )
        {
          --*(_DWORD *)(v5 + 240);
          if ( (a3 & 1) != 0 )
          {
            *(_DWORD *)(v8 + 52) = 9;
            send_packet_completion(a1, v8, v7);
          }
          else
          {
            _qdf_mem_free(v8);
          }
        }
      }
    }
  }
  v11 = *(_QWORD *)(a1 + 3000);
  if ( (v11 & 1) == 0 )
    return raw_spin_unlock(a1 + 2992);
  *(_QWORD *)(a1 + 3000) = v11 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 2992);
}
