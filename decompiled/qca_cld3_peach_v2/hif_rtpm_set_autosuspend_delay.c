__int64 __fastcall hif_rtpm_set_autosuspend_delay(int a1)
{
  if ( a1 < 1 || (unsigned int)(a1 - 10001) > 0xFFFFD952 )
  {
    pm_runtime_set_autosuspend_delay(*(_QWORD *)(gp_hif_rtpm_ctx + 8), (unsigned int)a1);
    *(_DWORD *)(gp_hif_rtpm_ctx + 316) = a1;
    qdf_trace_msg(61, 5, "%s: RTPM delay set: %d ms", "hif_rtpm_set_autosuspend_delay", a1);
    return 0;
  }
  else
  {
    qdf_trace_msg(61, 2, "%s: Invalid delay value %d ms", "hif_rtpm_set_autosuspend_delay", a1);
    return 4;
  }
}
