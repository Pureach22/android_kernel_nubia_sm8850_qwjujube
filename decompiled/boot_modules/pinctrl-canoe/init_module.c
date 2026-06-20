__int64 init_module()
{
  return _platform_driver_register(&canoe_tlmm_driver, &_this_module);
}
