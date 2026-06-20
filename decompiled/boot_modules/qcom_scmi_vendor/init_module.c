__int64 init_module()
{
  return scmi_protocol_register(&qcom_scmi_vendor);
}
