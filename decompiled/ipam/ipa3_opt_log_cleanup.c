void ipa3_opt_log_cleanup()
{
  __int64 v0; // x8

  v0 = ipa3_opt_log_ctx;
  *(_DWORD *)(ipa3_opt_log_ctx + 272) = 0;
  *(_DWORD *)(v0 + 284) = 0;
  *(_DWORD *)(v0 + 288) = 0;
  *(_QWORD *)(v0 + 276) = 0;
}
