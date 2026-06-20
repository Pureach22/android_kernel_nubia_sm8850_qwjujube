__int64 init_module()
{
  return scmi_driver_register(&scmi_clocks_driver, &_this_module, "clk_scmi");
}
