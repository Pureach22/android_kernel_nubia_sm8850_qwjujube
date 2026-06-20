__int64 __fastcall osif_request_put(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  int v3; // w8
  void (__fastcall *v5)(_QWORD); // x8

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
  v3 = *(_DWORD *)(a1 + 24) - 1;
  *(_DWORD *)(a1 + 24) = v3;
  if ( !v3 )
  {
    qdf_list_remove_node(&requests, a1);
    if ( (qword_7168B8 & 1) != 0 )
    {
      qword_7168B8 &= ~1uLL;
      raw_spin_unlock_bh(&spinlock);
      v5 = *(void (__fastcall **)(_QWORD))(a1 + 40);
      if ( v5 )
        goto LABEL_10;
    }
    else
    {
      raw_spin_unlock(&spinlock);
      v5 = *(void (__fastcall **)(_QWORD))(a1 + 40);
      if ( v5 )
      {
LABEL_10:
        if ( *((_DWORD *)v5 - 1) != 251140989 )
          __break(0x8228u);
        v5(a1 + 88);
      }
    }
    qdf_event_destroy(a1 + 48);
    return _qdf_mem_free(a1);
  }
  if ( (qword_7168B8 & 1) == 0 )
    return raw_spin_unlock(&spinlock);
  qword_7168B8 &= ~1uLL;
  return raw_spin_unlock_bh(&spinlock);
}
