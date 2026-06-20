__int64 ipa_opt_log_release()
{
  __int64 v0; // x0

  mutex_lock(ipa3_opt_log_ctx + 224);
  v0 = ipa3_opt_log_ctx + 224;
  *(_BYTE *)(ipa3_opt_log_ctx + 272) &= ~2u;
  mutex_unlock(v0);
  return 1;
}
