__int64 hif_pre_runtime_resume()
{
  __int64 v0; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v5; // x20

  v0 = gp_hif_rtpm_ctx;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v0 + 16);
  }
  else
  {
    v5 = v0;
    raw_spin_lock_bh(v0 + 16);
    *(_QWORD *)(v5 + 24) |= 1uLL;
  }
  v2 = gp_hif_rtpm_ctx;
  *(_DWORD *)(gp_hif_rtpm_ctx + 200) = 0;
  *(_DWORD *)(v2 + 188) = 3;
  v3 = *(_QWORD *)(v2 + 24);
  if ( (v3 & 1) == 0 )
    return raw_spin_unlock(v2 + 16);
  *(_QWORD *)(v2 + 24) = v3 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v2 + 16);
}
