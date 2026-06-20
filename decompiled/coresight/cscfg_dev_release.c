__int64 cscfg_dev_release()
{
  mutex_lock(&cscfg_mutex);
  kfree(cscfg_mgr);
  cscfg_mgr = 0;
  return mutex_unlock(&cscfg_mutex);
}
