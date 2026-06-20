__int64 __fastcall scmi_client_probe(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 result; // x0
  __int64 *v6; // x8

  if ( !a1 )
    return 4294967277LL;
  v1 = *(_QWORD *)(a1 + 928);
  if ( !v1 || (v3 = *(_QWORD *)(v1 + 8)) == 0 )
  {
    dev_err(a1 + 16, "Error: qcom vendor scmi handle is missing\n");
    return 4294967277LL;
  }
  if ( !strcmp("CPUCP", (const char *)(v3 + 28)) )
  {
    v4 = 0;
    goto LABEL_13;
  }
  if ( !strcmp("PDP0", (const char *)(v3 + 28)) )
  {
    v4 = 1;
    goto LABEL_13;
  }
  if ( !strcmp("PDP1", (const char *)(v3 + 28)) )
  {
    v4 = 2;
    goto LABEL_13;
  }
  if ( !strcmp("PDP2", (const char *)(v3 + 28)) )
  {
    v4 = 3;
LABEL_13:
    result = 0;
    v6 = &qcom_scmi_devices[2 * v4];
    goto LABEL_14;
  }
  if ( qcom_scmi_devices[0] )
  {
    dev_err(a1 + 16, "Missing sub_vendor_id and CPUCP scmi_dev already set\n");
    return 4294967274LL;
  }
  printk(&unk_6356);
  v6 = qcom_scmi_devices;
  result = 0;
LABEL_14:
  *v6 = a1;
  *((_DWORD *)v6 + 2) = 1;
  return result;
}
