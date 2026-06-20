__int64 __fastcall target_if_store_pdev_target_if_ctx(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v15; // x21

  v9 = g_target_if_ctx;
  if ( g_target_if_ctx )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v9 + 32);
    }
    else
    {
      v15 = v9;
      raw_spin_lock_bh(v9 + 32);
      *(_QWORD *)(v15 + 40) |= 1uLL;
    }
    v12 = g_target_if_ctx;
    v13 = *(_QWORD *)(g_target_if_ctx + 40);
    *(_QWORD *)(g_target_if_ctx + 16) = a1;
    if ( (v13 & 1) != 0 )
    {
      *(_QWORD *)(v12 + 40) = v13 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v12 + 32);
    }
    else
    {
      raw_spin_unlock(v12 + 32);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: target if ctx is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_store_pdev_target_if_ctx");
    return 4;
  }
}
