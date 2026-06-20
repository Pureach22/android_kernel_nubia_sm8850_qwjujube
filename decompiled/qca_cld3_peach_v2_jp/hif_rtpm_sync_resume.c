__int64 hif_rtpm_sync_resume()
{
  __int64 v0; // x20
  int v2; // w19
  __int64 v3; // x0
  int v4; // w21
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x9

  if ( !gp_hif_rtpm_ctx )
    return 0;
  v0 = *(_QWORD *)(gp_hif_rtpm_ctx + 8);
  if ( (*(_BYTE *)gp_hif_rtpm_ctx & 1) == 0 && (*(_WORD *)(v0 + 488) & 7) != 0 )
    return 0;
  v2 = *(_DWORD *)(gp_hif_rtpm_ctx + 188);
  v3 = _pm_runtime_resume(*(_QWORD *)(gp_hif_rtpm_ctx + 8), 0);
  v4 = v3;
  *(_QWORD *)(v0 + 520) = ktime_get_mono_fast_ns(v3);
  if ( v4 < 0 )
  {
    qdf_trace_msg(61, 2, "%s: pm_state: %d, err: %d", "hif_rtpm_sync_resume", v2, v4);
    return 16;
  }
  else
  {
    ++*(_DWORD *)(gp_hif_rtpm_ctx + 208);
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    v6 = gp_hif_rtpm_ctx;
    *(_QWORD *)(gp_hif_rtpm_ctx + 224) = StatusReg;
    *(_QWORD *)(v6 + 248) = StatusReg;
    return 0;
  }
}
