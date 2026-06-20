__int64 ipa3_notify_clients_registered()
{
  __int64 v0; // x0

  mutex_lock(ipa3_ctx + 29472);
  v0 = ipa3_ctx + 29472;
  *(_BYTE *)(ipa3_ctx + 48856) = 1;
  return mutex_unlock(v0);
}
