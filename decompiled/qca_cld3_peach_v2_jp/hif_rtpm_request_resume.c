__int64 hif_rtpm_request_resume()
{
  const char *v0; // x30
  const char *v1; // x19

  v1 = v0;
  _pm_runtime_resume(*(_QWORD *)(gp_hif_rtpm_ctx + 8), 1);
  return qdf_trace_msg(61, 5, "%s: request RTPM resume %s", "hif_rtpm_request_resume", v1);
}
