__int64 ipa3_odl_pipe_cleanup_from_ssr()
{
  mutex_lock(ipa3_odl_ctx + 384);
  ipa3_odl_pipe_cleanup(1);
  return mutex_unlock(ipa3_odl_ctx + 384);
}
