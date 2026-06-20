__int64 init_module()
{
  return _platform_driver_register(&chora_tlmm_driver, &_this_module);
}
