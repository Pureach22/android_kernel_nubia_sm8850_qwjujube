__int64 init_module()
{
  return _platform_driver_register(heuristics_scid_driver, &_this_module);
}
