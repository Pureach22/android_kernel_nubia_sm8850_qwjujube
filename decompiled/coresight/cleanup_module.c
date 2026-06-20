__int64 cleanup_module()
{
  cscfg_exit();
  etm_perf_exit();
  return bus_unregister(&coresight_bustype);
}
