__int64 ipa3_odl_pipe_open_from_ssr()
{
  mutex_lock(ipa3_odl_ctx + 384);
  ipa3_odl_pipe_open();
  return mutex_unlock(ipa3_odl_ctx + 384);
}
