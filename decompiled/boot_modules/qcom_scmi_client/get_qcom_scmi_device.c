__int64 get_qcom_scmi_device()
{
  __int64 result; // x0

  if ( !dword_6308 )
    return -517;
  result = qcom_scmi_devices[0];
  if ( !qcom_scmi_devices[0] || !*(_QWORD *)(qcom_scmi_devices[0] + 928) )
    return -19;
  return result;
}
