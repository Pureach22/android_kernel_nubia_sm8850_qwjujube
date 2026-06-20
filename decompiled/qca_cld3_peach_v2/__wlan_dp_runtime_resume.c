__int64 __fastcall _wlan_dp_runtime_resume(
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
  __int64 (*v10)(void); // x8
  __int64 v11; // x19
  __int64 result; // x0

  if ( a1 && *(_QWORD *)a1 && (v9 = *(_QWORD *)(*(_QWORD *)a1 + 64LL)) != 0 )
  {
    v10 = *(__int64 (**)(void))(v9 + 104);
    v11 = gp_dp_ctx;
    if ( !v10 )
      goto LABEL_8;
    if ( *((_DWORD *)v10 - 1) != 261447488 )
      __break(0x8228u);
    result = v10();
    if ( !(_DWORD)result )
    {
LABEL_8:
      dp_resume_fse_cache_flush(v11);
      dp_rx_fst_update_pm_suspend_status(v11, 0);
      dp_rx_fst_requeue_wq(v11);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_runtime_resume");
    return 4;
  }
  return result;
}
