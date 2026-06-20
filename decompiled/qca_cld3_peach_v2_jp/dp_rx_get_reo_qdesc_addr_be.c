__int64 __fastcall dp_rx_get_reo_qdesc_addr_be(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int16 *a4,
        unsigned int a5)
{
  unsigned int v6; // w19
  __int64 v8; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v10; // x19
  __int64 v11; // x8
  unsigned int v12; // w8
  unsigned int v19; // w10
  __int64 v20; // x20
  unsigned int v23; // w9
  __int64 v24; // x8

  if ( *(_BYTE *)(a1 + 74576) )
    return a4[4];
  v6 = a4[4];
  v8 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a4 + 24LL) + 8LL);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v8 + 13256);
  }
  else
  {
    raw_spin_lock_bh(v8 + 13256);
    *(_QWORD *)(v8 + 13264) |= 1uLL;
  }
  if ( *(_DWORD *)(v8 + 13276) > v6 )
  {
    v10 = *(_QWORD *)(*(_QWORD *)(v8 + 13088) + 8LL * v6);
    if ( v10 )
    {
      if ( *(unsigned __int8 *)(v10 + 380) <= 2u )
      {
        v12 = *(_DWORD *)(v10 + 40);
        while ( v12 )
        {
          _X12 = (unsigned int *)(v10 + 40);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v19 = __ldxr(_X12);
            if ( v19 != v12 )
              break;
            if ( !__stlxr(v12 + 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v19 == v12;
          v12 = v19;
          if ( _ZF )
          {
            _X8 = (unsigned int *)(v10 + 304);
            __asm { PRFM            #0x11, [X8] }
            do
              v23 = __ldxr(_X8);
            while ( __stxr(v23 + 1, _X8) );
            v24 = *(_QWORD *)(v8 + 13264);
            if ( (v24 & 1) != 0 )
            {
              *(_QWORD *)(v8 + 13264) = v24 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v8 + 13256);
            }
            else
            {
              raw_spin_unlock(v8 + 13256);
            }
            v20 = *(_QWORD *)(*(_QWORD *)(v10 + 88) + 144LL * a5 + 56);
            dp_peer_unref_delete(v10, 12);
            return v20;
          }
        }
      }
    }
  }
  v11 = *(_QWORD *)(v8 + 13264);
  if ( (v11 & 1) != 0 )
  {
    *(_QWORD *)(v8 + 13264) = v11 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v8 + 13256);
  }
  else
  {
    raw_spin_unlock(v8 + 13256);
  }
  return 0;
}
