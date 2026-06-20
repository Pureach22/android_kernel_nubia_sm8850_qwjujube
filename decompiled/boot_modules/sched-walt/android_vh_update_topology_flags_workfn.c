__int64 android_vh_update_topology_flags_workfn()
{
  return queue_work_on(32, system_wq, &walt_init_work);
}
