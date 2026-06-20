__int64 __fastcall dp_peer_ast_entry_del_by_pdev(__int64 a1, __int64 a2, unsigned int a3, __int64 a4, __int64 a5)
{
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x0
  void (__fastcall *v13)(__int64, __int64, __int64, __int64); // x23
  __int64 v14; // x22
  __int64 v15; // x8
  char v16; // w8
  __int64 v17; // x8
  __int64 v18; // x0

  if ( (*(_BYTE *)(a1 + 17706) & 1) != 0 )
    return 4294967292LL;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 17632);
  }
  else
  {
    raw_spin_lock_bh(a1 + 17632);
    *(_QWORD *)(a1 + 17640) |= 1uLL;
  }
  v12 = dp_peer_ast_hash_find_by_pdevid(a1, a2, a3);
  if ( v12 )
  {
    v13 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v12 + 32);
    if ( v13 )
      v14 = *(_QWORD *)(v12 + 40);
    else
      v14 = 0;
    v16 = *(_BYTE *)(v12 + 28);
    *(_QWORD *)(v12 + 32) = a4;
    *(_QWORD *)(v12 + 40) = a5;
    if ( (v16 & 1) == 0 )
      dp_peer_del_ast(a1);
    v17 = *(_QWORD *)(a1 + 17640);
    if ( (v17 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 17640) = v17 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 17632);
      if ( v13 )
        goto LABEL_18;
    }
    else
    {
      raw_spin_unlock(a1 + 17632);
      if ( v13 )
      {
LABEL_18:
        v18 = *(_QWORD *)(a1 + 16);
        if ( *((_DWORD *)v13 - 1) != 1048469180 )
          __break(0x8237u);
        v13(v18, a1, v14, 1);
      }
    }
    return 0;
  }
  v15 = *(_QWORD *)(a1 + 17640);
  if ( (v15 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 17640) = v15 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 17632);
  }
  else
  {
    raw_spin_unlock(a1 + 17632);
  }
  return 4294967292LL;
}
