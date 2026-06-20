__int64 __fastcall qcom_mpam_probe(__int64 a1)
{
  unsigned __int64 qcom_scmi_device; // x0
  unsigned int v3; // w20
  __int64 (*v4)(void); // x8
  unsigned __int64 v5; // x0

  qcom_scmi_device = get_qcom_scmi_device();
  sdev = qcom_scmi_device;
  if ( qcom_scmi_device < 0xFFFFFFFFFFFFF001LL )
  {
    v4 = *(__int64 (**)(void))(*(_QWORD *)(qcom_scmi_device + 928) + 24LL);
    if ( *((_DWORD *)v4 - 1) != -1171826031 )
      __break(0x8228u);
    v5 = v4();
    ops = v5;
    if ( v5 >= 0xFFFFFFFFFFFFF001LL )
    {
      v3 = v5;
      ops = 0;
      dev_err(a1 + 16, "Error getting vendor protocol ops: %d\n", v5);
    }
    else
    {
      return 0;
    }
  }
  else if ( (_DWORD)qcom_scmi_device == -517 )
  {
    return (unsigned int)-517;
  }
  else
  {
    v3 = qcom_scmi_device;
    dev_err(a1 + 16, "Error getting scmi_dev ret=%d\n", qcom_scmi_device);
  }
  return v3;
}
