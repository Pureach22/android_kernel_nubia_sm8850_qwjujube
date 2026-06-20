__int64 trigger_dump_enable()
{
  __int64 v0; // x0

  mutex_lock(g_pd + 48);
  v0 = g_pd + 48;
  *(_BYTE *)(g_pd + 136) = 1;
  return mutex_unlock(v0);
}
