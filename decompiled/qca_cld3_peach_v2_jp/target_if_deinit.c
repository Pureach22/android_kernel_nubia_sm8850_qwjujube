__int64 __fastcall target_if_deinit(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x8
  unsigned __int64 StatusReg; // x9
  _QWORD *v10; // x8
  __int64 v11; // x9
  __int64 v12; // x0
  __int64 v14; // x20

  v8 = g_target_if_ctx;
  if ( g_target_if_ctx )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v8 + 32);
    }
    else
    {
      v14 = v8;
      raw_spin_lock_bh(v8 + 32);
      *(_QWORD *)(v14 + 40) |= 1uLL;
    }
    v10 = (_QWORD *)g_target_if_ctx;
    v11 = *(_QWORD *)(g_target_if_ctx + 40);
    *(_DWORD *)g_target_if_ctx = 0;
    v10[1] = 0;
    v10[2] = 0;
    v10[3] = 0;
    if ( (v11 & 1) != 0 )
    {
      v10[5] = v11 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v10 + 4);
    }
    else
    {
      raw_spin_unlock(v10 + 4);
    }
    v12 = _qdf_mem_free(g_target_if_ctx);
    g_target_if_ctx = 0;
    direct_buf_rx_deinit(v12);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: target if ctx is null", a1, a2, a3, a4, a5, a6, a7, a8, "target_if_deinit");
    return 4;
  }
}
