__int64 __fastcall hif_rtpm_stop(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 v4; // x20
  int v5; // w19
  __int64 v6; // x0
  int v7; // w21
  unsigned __int64 StatusReg; // x9
  unsigned int v15; // w9

  result = hif_get_conparam(a1);
  if ( *(_BYTE *)gp_hif_rtpm_ctx == 1 && ((unsigned int)result > 8 || ((1 << result) & 0x130) == 0) )
  {
    v2 = *(_QWORD *)(gp_hif_rtpm_ctx + 8);
    _X8 = (unsigned int *)(v2 + 480);
    __asm { PRFM            #0x11, [X8] }
    do
      v15 = __ldxr(_X8);
    while ( __stxr(v15 + 1, _X8) );
    _pm_runtime_set_status(v2, 0);
    pm_runtime_forbid(v2);
    v3 = gp_hif_rtpm_ctx;
    if ( gp_hif_rtpm_ctx )
    {
      v4 = *(_QWORD *)(gp_hif_rtpm_ctx + 8);
      if ( (*(_BYTE *)gp_hif_rtpm_ctx & 1) != 0 || (*(_WORD *)(v4 + 488) & 7) == 0 )
      {
        v5 = *(_DWORD *)(gp_hif_rtpm_ctx + 188);
        v6 = _pm_runtime_resume(*(_QWORD *)(gp_hif_rtpm_ctx + 8), 0);
        v7 = v6;
        *(_QWORD *)(v4 + 520) = ktime_get_mono_fast_ns(v6);
        if ( v7 < 0 )
        {
          qdf_trace_msg(61, 2, "%s: pm_state: %d, err: %d", "hif_rtpm_sync_resume", v5, v7);
          v3 = gp_hif_rtpm_ctx;
        }
        else
        {
          ++*(_DWORD *)(gp_hif_rtpm_ctx + 208);
          __isb(0xFu);
          StatusReg = _ReadStatusReg(CNTVCT_EL0);
          v3 = gp_hif_rtpm_ctx;
          *(_QWORD *)(gp_hif_rtpm_ctx + 224) = StatusReg;
          *(_QWORD *)(v3 + 248) = StatusReg;
        }
      }
    }
    *(_DWORD *)(v3 + 188) = 0;
    return qdf_debugfs_remove_file(*(_QWORD *)(v3 + 304));
  }
  return result;
}
