__int64 init_module()
{
  return scmi_driver_register(&scmi_cpuss_telemetry_driver, &_this_module, "cpuss_telemetry");
}
