__int64 init_module()
{
  return scmi_driver_register(&qcom_scmi_client_drv, &_this_module, "qcom_scmi_client");
}
