__int64 target_if_get_psoc_legacy_service_ready_cb()
{
  __int64 v0; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x19
  __int64 v6; // x20

  v0 = g_target_if_ctx;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v0 + 32);
  }
  else
  {
    v6 = v0;
    raw_spin_lock_bh(v0 + 32);
    *(_QWORD *)(v6 + 40) |= 1uLL;
  }
  v2 = g_target_if_ctx;
  v3 = *(_QWORD *)(g_target_if_ctx + 40);
  v4 = *(_QWORD *)(g_target_if_ctx + 24);
  if ( (v3 & 1) != 0 )
  {
    *(_QWORD *)(g_target_if_ctx + 40) = v3 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v2 + 32);
  }
  else
  {
    raw_spin_unlock(g_target_if_ctx + 32);
  }
  return v4;
}
