__int64 __fastcall target_if_init(__int64 a1)
{
  __int64 v2; // x0
  unsigned __int64 StatusReg; // x9
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x0
  __int64 v8; // x21

  v2 = _qdf_mem_malloc(0x30u, "target_if_init", 181);
  g_target_if_ctx = v2;
  if ( !v2 )
    return 2;
  *(_DWORD *)(v2 + 32) = 0;
  *(_QWORD *)(v2 + 40) = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v2 + 32);
  }
  else
  {
    v8 = v2;
    raw_spin_lock_bh(v2 + 32);
    *(_QWORD *)(v8 + 40) |= 1uLL;
  }
  v4 = g_target_if_ctx;
  v5 = *(_QWORD *)(g_target_if_ctx + 40);
  *(_DWORD *)g_target_if_ctx = 1415009280;
  *(_QWORD *)(v4 + 8) = a1;
  if ( (v5 & 1) != 0 )
  {
    *(_QWORD *)(v4 + 40) = v5 & 0xFFFFFFFFFFFFFFFELL;
    v6 = raw_spin_unlock_bh(v4 + 32);
  }
  else
  {
    v6 = raw_spin_unlock(v4 + 32);
  }
  direct_buf_rx_init(v6);
  return 0;
}
