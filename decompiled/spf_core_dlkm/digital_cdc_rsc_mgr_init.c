__int64 digital_cdc_rsc_mgr_init()
{
  __int64 result; // x0

  result = _mutex_init(&hw_vote_lock, "&hw_vote_lock", &digital_cdc_rsc_mgr_init___key);
  is_init_done = 1;
  return result;
}
