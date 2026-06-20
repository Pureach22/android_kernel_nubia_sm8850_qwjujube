__int64 ipa_init_deinit_lock()
{
  return qdf_mutex_acquire((__int64)&g_init_deinit_lock);
}
