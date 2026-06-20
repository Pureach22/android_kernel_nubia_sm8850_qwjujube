__int64 init_module()
{
  unsigned int v0; // w19

  v0 = bus_register(&coresight_bustype);
  if ( !v0 )
  {
    v0 = etm_perf_init();
    if ( !v0 )
    {
      v0 = cscfg_init();
      if ( !v0 )
        return v0;
      etm_perf_exit();
    }
    bus_unregister(&coresight_bustype);
  }
  return v0;
}
