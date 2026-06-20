__int64 __fastcall hif_pm_runtime_prevent_suspend(__int64 a1)
{
  __int64 v1; // x8
  _BOOL4 v3; // w9
  __int64 result; // x0
  unsigned __int64 StatusReg; // x9
  __int64 v6; // x8
  int v7; // w0
  __int64 v8; // x8
  __int64 v9; // x2
  _QWORD *v10; // x1
  int v11; // w10
  __int64 v12; // x9
  __int64 v13; // x21

  v1 = gp_hif_rtpm_ctx;
  if ( !gp_hif_rtpm_ctx )
    return 4294967274LL;
  if ( (*(_BYTE *)gp_hif_rtpm_ctx & 1) != 0 )
  {
    v3 = 1;
    result = 4294967274LL;
    if ( !a1 )
      return result;
  }
  else
  {
    v3 = (*(_WORD *)(*(_QWORD *)(gp_hif_rtpm_ctx + 8) + 488LL) & 7) == 0;
    result = 4294967274LL;
    if ( !a1 )
      return result;
  }
  if ( v3 )
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
      v13 = v1;
      raw_spin_lock_bh(v1 + 152);
      *(_QWORD *)(v13 + 160) |= 1uLL;
    }
    v6 = gp_hif_rtpm_ctx;
    if ( (*(_BYTE *)(a1 + 16) & 1) == 0 )
    {
      v7 = _pm_runtime_resume(*(_QWORD *)(gp_hif_rtpm_ctx + 8), 5);
      if ( v7 < 0 && v7 != -115 )
      {
        v8 = gp_hif_rtpm_ctx;
        ++*(_DWORD *)(gp_hif_rtpm_ctx + 296);
        qdf_trace_msg(61, 2, "%s: pm_state: %d ret: %d", "__hif_pm_runtime_prevent_suspend", *(_DWORD *)(v8 + 188), v7);
      }
      v6 = gp_hif_rtpm_ctx;
      v9 = gp_hif_rtpm_ctx + 168;
      v10 = *(_QWORD **)(gp_hif_rtpm_ctx + 176);
      if ( gp_hif_rtpm_ctx + 168 == a1 || v10 == (_QWORD *)a1 || *v10 != v9 )
      {
        _list_add_valid_or_report(a1, v10);
        v6 = gp_hif_rtpm_ctx;
      }
      else
      {
        *(_QWORD *)(gp_hif_rtpm_ctx + 176) = a1;
        *(_QWORD *)a1 = v9;
        *(_QWORD *)(a1 + 8) = v10;
        *v10 = a1;
      }
      *(_BYTE *)(a1 + 16) = 1;
      v11 = *(_DWORD *)(v6 + 288) + 1;
      ++*(_DWORD *)(v6 + 184);
      *(_DWORD *)(v6 + 288) = v11;
    }
    v12 = *(_QWORD *)(v6 + 160);
    if ( (v12 & 1) != 0 )
    {
      *(_QWORD *)(v6 + 160) = v12 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v6 + 152);
    }
    else
    {
      raw_spin_unlock(v6 + 152);
    }
    if ( *(int *)(gp_hif_rtpm_ctx + 188) >= 4 )
      qdf_trace_msg(61, 5, "%s: request RTPM resume by %s", "hif_pm_runtime_prevent_suspend", *(const char **)(a1 + 24));
    return 0;
  }
  return result;
}
