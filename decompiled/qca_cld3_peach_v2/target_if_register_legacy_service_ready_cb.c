__int64 __fastcall target_if_register_legacy_service_ready_cb(__int64 a1)
{
  __int64 v2; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v7; // x21

  v2 = g_target_if_ctx;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v2 + 32);
  }
  else
  {
    v7 = v2;
    raw_spin_lock_bh(v2 + 32);
    *(_QWORD *)(v7 + 40) |= 1uLL;
  }
  v4 = g_target_if_ctx;
  v5 = *(_QWORD *)(g_target_if_ctx + 40);
  *(_QWORD *)(g_target_if_ctx + 24) = a1;
  if ( (v5 & 1) != 0 )
  {
    *(_QWORD *)(v4 + 40) = v5 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v4 + 32);
  }
  else
  {
    raw_spin_unlock(v4 + 32);
  }
  return 0;
}
