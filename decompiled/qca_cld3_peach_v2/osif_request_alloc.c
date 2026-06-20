__int64 __fastcall osif_request_alloc(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v4; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x10

  if ( (is_initialized & 1) != 0 )
  {
    v2 = _qdf_mem_malloc(*(unsigned int *)a1 + 88LL, "osif_request_alloc", 91);
    v3 = v2;
    if ( v2 )
    {
      *(_DWORD *)(v2 + 24) = 1;
      v4 = a1[1];
      *(_QWORD *)(v2 + 32) = *a1;
      *(_QWORD *)(v2 + 40) = v4;
      qdf_event_create(v2 + 48);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(&spinlock);
      }
      else
      {
        raw_spin_lock_bh(&spinlock);
        qword_7CF2E8 |= 1uLL;
      }
      v6 = cookie + 1;
      *(_QWORD *)(v3 + 16) = cookie;
      cookie = v6;
      qdf_list_insert_back(&requests, v3);
      if ( (qword_7CF2E8 & 1) != 0 )
      {
        qword_7CF2E8 &= ~1uLL;
        raw_spin_unlock_bh(&spinlock);
      }
      else
      {
        raw_spin_unlock(&spinlock);
      }
    }
  }
  else
  {
    qdf_trace_msg(72, 2, "%s: invoked when not initialized", "osif_request_alloc");
    return 0;
  }
  return v3;
}
