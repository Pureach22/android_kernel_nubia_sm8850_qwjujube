__int64 __fastcall dp_wds_reset_ast_table_wifi3(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x8

  if ( (*(_BYTE *)(a1 + 17706) & 1) == 0 )
  {
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
    dp_soc_iterate_peer(a1, dp_peer_reset_ast_entries);
    v3 = *(_QWORD *)(a1 + 17640);
    if ( (v3 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 17640) = v3 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 17632);
    }
    else
    {
      raw_spin_unlock(a1 + 17632);
    }
  }
  return 0;
}
