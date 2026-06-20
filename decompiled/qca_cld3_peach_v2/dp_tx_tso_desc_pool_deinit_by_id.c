__int64 __fastcall dp_tx_tso_desc_pool_deinit_by_id(__int64 result, unsigned __int8 a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x8

  if ( a2 >= 7u )
  {
    __break(0x5512u);
    JUMPOUT(0x5A44524);
  }
  v2 = result + 72LL * a2;
  if ( *(_WORD *)(v2 + 4896) )
  {
    v3 = v2 + 4896;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v3 + 56);
      v5 = *(_QWORD *)(v3 + 64);
    }
    else
    {
      raw_spin_lock_bh(v3 + 56);
      v5 = *(_QWORD *)(v3 + 64) | 1LL;
      *(_QWORD *)(v3 + 64) = v5;
    }
    *(_QWORD *)(v3 + 8) = 0;
    *(_DWORD *)v3 = 0;
    if ( (v5 & 1) != 0 )
    {
      *(_QWORD *)(v3 + 64) = v5 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v3 + 56);
    }
    else
    {
      return raw_spin_unlock(v3 + 56);
    }
  }
  return result;
}
