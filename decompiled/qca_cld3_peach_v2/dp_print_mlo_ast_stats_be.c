__int64 __fastcall dp_print_mlo_ast_stats_be(__int64 result)
{
  __int64 v1; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x8

  if ( result )
  {
    v1 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 23424);
      v3 = *(_QWORD *)(v1 + 23432);
      if ( (v3 & 1) == 0 )
        return raw_spin_unlock(v1 + 23424);
    }
    else
    {
      raw_spin_lock_bh(result + 23424);
      *(_QWORD *)(v1 + 23432) |= 1uLL;
      v3 = *(_QWORD *)(v1 + 23432);
      if ( (v3 & 1) == 0 )
        return raw_spin_unlock(v1 + 23424);
    }
    *(_QWORD *)(v1 + 23432) = v3 & 0xFFFFFFFFFFFFFFFELL;
    return raw_spin_unlock_bh(v1 + 23424);
  }
  return result;
}
