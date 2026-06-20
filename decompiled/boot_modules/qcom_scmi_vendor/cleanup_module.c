__int64 cleanup_module()
{
  return scmi_protocol_unregister(&qcom_scmi_vendor);
}
