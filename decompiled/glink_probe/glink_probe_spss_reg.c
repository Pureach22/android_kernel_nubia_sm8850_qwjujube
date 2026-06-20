__int64 __fastcall glink_probe_spss_reg(__int64 a1)
{
  __int64 v1; // x20
  unsigned __int64 v3; // x0

  v1 = *(_QWORD *)(a1 + 16);
  v3 = qcom_glink_spss_register(v1, *(_QWORD *)(a1 + 24));
  *(_QWORD *)(a1 + 48) = v3;
  if ( !v3 || v3 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(v1, "[%s]: register failed for %s\n", "glink_probe_spss_reg", *(const char **)(a1 + 32));
    ipc_log_string(glink_ilc, "[%s]: register failed for %s\n", "glink_probe_spss_reg", *(const char **)(a1 + 32));
    *(_QWORD *)(a1 + 48) = 0;
  }
  return 0;
}
