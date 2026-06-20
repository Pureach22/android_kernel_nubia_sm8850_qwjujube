__int64 walt_mvp_lock_ordering_init()
{
  return tracepoint_probe_register(&_tracepoint_android_vh_alter_mutex_list_add, android_vh_alter_mutex_list_add, 0);
}
