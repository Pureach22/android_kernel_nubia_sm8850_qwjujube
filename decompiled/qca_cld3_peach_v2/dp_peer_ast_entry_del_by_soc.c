__int64 __fastcall dp_peer_ast_entry_del_by_soc(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 StatusReg; // x8
  __int64 soc; // x0
  void (__fastcall *v11)(__int64, __int64, __int64, __int64); // x24
  __int64 v12; // x22
  __int64 v13; // x8
  char v14; // w8
  __int64 v15; // x8
  __int64 v16; // x0

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
  soc = dp_peer_ast_hash_find_soc(a1, a2);
  if ( soc )
  {
    v11 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(soc + 32);
    if ( v11 )
      v12 = *(_QWORD *)(soc + 40);
    else
      v12 = 0;
    v14 = *(_BYTE *)(soc + 28);
    *(_QWORD *)(soc + 32) = a3;
    *(_QWORD *)(soc + 40) = a4;
    if ( (v14 & 1) == 0 )
      dp_peer_del_ast(a1);
    v15 = *(_QWORD *)(a1 + 17640);
    if ( (v15 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 17640) = v15 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 17632);
      if ( v11 )
        goto LABEL_18;
    }
    else
    {
      raw_spin_unlock(a1 + 17632);
      if ( v11 )
      {
LABEL_18:
        v16 = *(_QWORD *)(a1 + 16);
        if ( *((_DWORD *)v11 - 1) != 1048469180 )
          __break(0x8238u);
        v11(v16, a1, v12, 1);
      }
    }
    return 0;
  }
  v13 = *(_QWORD *)(a1 + 17640);
  if ( (v13 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 17640) = v13 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 17632);
  }
  else
  {
    raw_spin_unlock(a1 + 17632);
  }
  return 4294967292LL;
}
