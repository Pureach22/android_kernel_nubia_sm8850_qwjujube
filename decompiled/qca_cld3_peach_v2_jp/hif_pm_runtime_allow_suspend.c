__int64 __fastcall hif_pm_runtime_allow_suspend(__int64 a1)
{
  __int64 v1; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v7; // x21

  v1 = gp_hif_rtpm_ctx;
  if ( !gp_hif_rtpm_ctx
    || (*(_BYTE *)gp_hif_rtpm_ctx & 1) == 0 && (*(_WORD *)(*(_QWORD *)(gp_hif_rtpm_ctx + 8) + 488LL) & 7) != 0 )
  {
    return 0;
  }
  if ( a1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      __break(0x800u);
      v1 = gp_hif_rtpm_ctx;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v1 + 152);
    }
    else
    {
      v7 = v1;
      raw_spin_lock_bh(v1 + 152);
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
    return 0;
  }
  return 4294967274LL;
}
