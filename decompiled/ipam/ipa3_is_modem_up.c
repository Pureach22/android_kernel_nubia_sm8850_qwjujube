__int64 ipa3_is_modem_up()
{
  unsigned int v0; // w19

  mutex_lock(ipa3_ctx + 52440);
  v0 = *(unsigned __int8 *)(ipa3_ctx + 51096);
  mutex_unlock(ipa3_ctx + 52440);
  return v0;
}
