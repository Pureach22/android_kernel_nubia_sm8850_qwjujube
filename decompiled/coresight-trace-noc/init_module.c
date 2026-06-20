__int64 init_module()
{
  return _amba_driver_register(&trace_noc_driver, &_this_module);
}
