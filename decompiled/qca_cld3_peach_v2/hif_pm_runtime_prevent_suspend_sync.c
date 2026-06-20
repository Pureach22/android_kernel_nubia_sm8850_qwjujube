__int64 __fastcall hif_pm_runtime_prevent_suspend_sync(__int64 a1)
{
  unsigned __int64 StatusReg; // x21
  int v3; // w0
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x2
  _QWORD *v8; // x1
  __int64 v9; // x9
  int v10; // w11
  __int64 v12; // x21

  if ( !gp_hif_rtpm_ctx
    || (*(_BYTE *)gp_hif_rtpm_ctx & 1) == 0 && (*(_WORD *)(*(_QWORD *)(gp_hif_rtpm_ctx + 8) + 488LL) & 7) != 0 )
  {
    return 0;
  }
  if ( a1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      __break(0x800u);
    if ( (*(_BYTE *)(a1 + 16) & 1) == 0 )
    {
      v3 = _pm_runtime_resume(*(_QWORD *)(gp_hif_rtpm_ctx + 8), 4);
      if ( v3 < 0 && v3 != -115 )
      {
        v4 = gp_hif_rtpm_ctx;
        ++*(_DWORD *)(gp_hif_rtpm_ctx + 296);
        qdf_trace_msg(
          61,
          2,
          "%s: pm_state: %d ret: %d",
          "__hif_pm_runtime_prevent_suspend_sync",
          *(_DWORD *)(v4 + 188),
          v3);
      }
      v5 = gp_hif_rtpm_ctx;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v5 + 152);
      }
      else
      {
        v12 = v5;
        raw_spin_lock_bh(v5 + 152);
        *(_QWORD *)(v12 + 160) |= 1uLL;
      }
      v6 = gp_hif_rtpm_ctx;
      v7 = gp_hif_rtpm_ctx + 168;
      v8 = *(_QWORD **)(gp_hif_rtpm_ctx + 176);
      if ( gp_hif_rtpm_ctx + 168 == a1 || v8 == (_QWORD *)a1 || *v8 != v7 )
      {
        _list_add_valid_or_report(a1, v8);
        v6 = gp_hif_rtpm_ctx;
      }
      else
      {
        *(_QWORD *)(gp_hif_rtpm_ctx + 176) = a1;
        *(_QWORD *)a1 = v7;
        *(_QWORD *)(a1 + 8) = v8;
        *v8 = a1;
      }
      *(_BYTE *)(a1 + 16) = 1;
      v9 = *(_QWORD *)(v6 + 160);
      v10 = *(_DWORD *)(v6 + 288) + 1;
      ++*(_DWORD *)(v6 + 184);
      *(_DWORD *)(v6 + 288) = v10;
      if ( (v9 & 1) != 0 )
      {
        *(_QWORD *)(v6 + 160) = v9 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v6 + 152);
      }
      else
      {
        raw_spin_unlock(v6 + 152);
      }
    }
    if ( *(int *)(gp_hif_rtpm_ctx + 188) >= 4 )
      qdf_trace_msg(
        61,
        5,
        "%s: request RTPM resume by %s",
        "hif_pm_runtime_prevent_suspend_sync",
        *(const char **)(a1 + 24));
    return 0;
  }
  return 4294967274LL;
}
