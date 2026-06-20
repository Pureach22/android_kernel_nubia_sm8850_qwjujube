__int64 cleanup_module()
{
  return scmi_driver_unregister(&qcom_scmi_client_drv);
}
