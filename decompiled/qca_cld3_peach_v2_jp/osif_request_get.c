__int64 __fastcall osif_request_get(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x1
  __int64 v4; // x20
  __int64 result; // x0
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (is_initialized & 1) != 0 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(&spinlock);
    }
    else
    {
      raw_spin_lock_bh(&spinlock);
      qword_7168B8 |= 1uLL;
    }
    v6[0] = 0;
    if ( (unsigned int)qdf_list_peek_front(&requests, v6) )
    {
LABEL_9:
      v3 = 0;
    }
    else
    {
      while ( 1 )
      {
        v3 = v6[0];
        if ( *(_QWORD *)(v6[0] + 16LL) == a1 )
          break;
        if ( (unsigned int)qdf_list_peek_next(&requests, v6[0], v6) )
          goto LABEL_9;
      }
      if ( v6[0] )
        ++*(_DWORD *)(v6[0] + 24LL);
    }
    v4 = v3;
    if ( (qword_7168B8 & 1) != 0 )
    {
      qword_7168B8 &= ~1uLL;
      raw_spin_unlock_bh(&spinlock);
    }
    else
    {
      raw_spin_unlock(&spinlock);
    }
    result = v4;
  }
  else
  {
    qdf_trace_msg(72, 2, "%s: invoked when not initialized", "osif_request_get");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
