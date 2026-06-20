__int64 ipa_init_deinit_unlock()
{
  return qdf_mutex_release((__int64)&g_init_deinit_lock);
}
