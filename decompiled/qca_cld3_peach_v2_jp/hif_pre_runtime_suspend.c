__int64 __fastcall hif_pre_runtime_suspend(__int64 a1)
{
  __int64 v1; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x0
  unsigned __int64 v6; // x8
  __int64 v8; // x9
  __int64 v9; // x20

  if ( !hif_can_suspend_link(a1) )
  {
    qdf_trace_msg(61, 2, "%s: Runtime PM not supported for link up suspend", "hif_pre_runtime_suspend");
    return 4294967274LL;
  }
  v1 = gp_hif_rtpm_ctx;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v1 + 16);
  }
  else
  {
    v9 = v1;
    raw_spin_lock_bh(v1 + 16);
    *(_QWORD *)(v9 + 24) |= 1uLL;
  }
  v3 = gp_hif_rtpm_ctx;
  *(_DWORD *)(gp_hif_rtpm_ctx + 188) = 4;
  if ( !v3 || *(_BYTE *)v3 != 1 || *(_DWORD *)(*(_QWORD *)(v3 + 8) + 480LL) )
  {
    v4 = *(_QWORD *)(v3 + 24);
    if ( (v4 & 1) != 0 )
    {
      *(_QWORD *)(v3 + 24) = v4 & 0xFFFFFFFFFFFFFFFELL;
      v5 = raw_spin_unlock_bh(v3 + 16);
    }
    else
    {
      v5 = raw_spin_unlock(v3 + 16);
    }
    ((void (__fastcall *)(__int64))hif_rtpm_print_prevent_list)(v5);
    ++*(_DWORD *)(gp_hif_rtpm_ctx + 216);
    __isb(0xFu);
    v6 = _ReadStatusReg(CNTVCT_EL0);
    *(_QWORD *)(gp_hif_rtpm_ctx + 240) = v6;
    qdf_trace_msg(61, 5, "%s: Runtime PM not allowed now", "hif_pre_runtime_suspend");
    return 4294967274LL;
  }
  v8 = *(_QWORD *)(v3 + 24);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(v3 + 24) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v3 + 16);
  }
  else
  {
    raw_spin_unlock(v3 + 16);
  }
  return 0;
}
