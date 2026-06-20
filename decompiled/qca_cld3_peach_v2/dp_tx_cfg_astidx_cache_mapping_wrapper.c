__int64 __fastcall dp_tx_cfg_astidx_cache_mapping_wrapper(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(a1 + 13304);
      v3 = *(_QWORD *)(a1 + 13312) | 1LL;
      *(_QWORD *)(a1 + 13312) = v3;
      if ( (v3 & 1) == 0 )
        return raw_spin_unlock(a1 + 13304);
LABEL_8:
      *(_QWORD *)(a1 + 13312) = v3 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(a1 + 13304);
    }
  }
  raw_spin_lock(a1 + 13304);
  v3 = *(_QWORD *)(a1 + 13312);
  if ( (v3 & 1) != 0 )
    goto LABEL_8;
  return raw_spin_unlock(a1 + 13304);
}
