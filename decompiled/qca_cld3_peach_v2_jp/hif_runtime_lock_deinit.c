__int64 __fastcall hif_runtime_lock_deinit(__int64 a1)
{
  __int64 v2; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v7; // x21

  if ( !a1 )
    return qdf_trace_msg(61, 2, "%s: Runtime PM lock already freed", "hif_runtime_lock_deinit");
  qdf_trace_msg(
    61,
    8,
    "%s: Deinitializing Runtime PM wakelock %s",
    "hif_runtime_lock_deinit",
    *(const char **)(a1 + 24));
  v2 = gp_hif_rtpm_ctx;
  if ( gp_hif_rtpm_ctx )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v2 + 152);
    }
    else
    {
      v7 = v2;
      raw_spin_lock_bh(v2 + 152);
      *(_QWORD *)(v7 + 160) |= 1uLL;
    }
    _hif_pm_runtime_allow_suspend(a1);
    v4 = gp_hif_rtpm_ctx;
    v5 = *(_QWORD *)(gp_hif_rtpm_ctx + 160);
    if ( (v5 & 1) != 0 )
    {
      *(_QWORD *)(gp_hif_rtpm_ctx + 160) = v5 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v4 + 152);
    }
    else
    {
      raw_spin_unlock(gp_hif_rtpm_ctx + 152);
    }
  }
  return _qdf_mem_free(a1);
}
