unsigned __int64 __fastcall qcom_dynamic_hw_thermal_trip_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 v5; // x20
  unsigned __int64 qcom_scmi_device; // x0
  unsigned __int64 result; // x0
  __int64 (*v8)(void); // x8
  unsigned __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 (__fastcall *v12)(__int64, int *, __int64, __int64, __int64, __int64); // x8
  __int64 v13; // x0
  int v14; // w0
  unsigned __int64 v15; // x19
  unsigned int v16; // w19
  _QWORD v17[3]; // [xsp+8h] [xbp-28h] BYREF
  int v18; // [xsp+20h] [xbp-10h] BYREF
  int v19; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+28h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  v18 = 0;
  v17[0] = 0;
  v17[1] = 0x100000001LL;
  v17[2] = 0;
  if ( (of_property_read_variable_u32_array(v2, "qcom,cpu-cluster-type", &v18, 1, 0) & 0x80000000) != 0 )
  {
    result = 4294967277LL;
    goto LABEL_20;
  }
  v3 = a1 + 16;
  v4 = devm_kmalloc(a1 + 16, 96, 3520);
  if ( !v4 )
  {
    result = 4294967284LL;
    goto LABEL_20;
  }
  v5 = v4;
  *(_QWORD *)(v4 + 32) = v3;
  qcom_scmi_device = platform_get_qcom_scmi_device(0);
  *(_QWORD *)(v5 + 24) = qcom_scmi_device;
  if ( qcom_scmi_device >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (_DWORD)qcom_scmi_device == -517 )
    {
      result = 4294966779LL;
    }
    else
    {
      v15 = qcom_scmi_device;
      dev_err(v3, "Error getting scmi_dev for cpu_cluster_%d ret=%d\n", v18, qcom_scmi_device);
      result = v15;
    }
    goto LABEL_20;
  }
  v8 = *(__int64 (**)(void))(*(_QWORD *)(qcom_scmi_device + 928) + 24LL);
  if ( *((_DWORD *)v8 - 1) != -1171826031 )
    __break(0x8228u);
  v9 = v8();
  *(_QWORD *)(v5 + 40) = v9;
  if ( v9 >= 0xFFFFFFFFFFFFF001LL )
  {
    v16 = v9;
    *(_QWORD *)(v5 + 40) = 0;
    dev_err(v3, "Error getting vendor protocol ops: %d\n", v9);
    result = v16;
    goto LABEL_20;
  }
  snprintf((char *)v5, 0x14u, "cpu-hw-trip-%d", v18);
  *(_DWORD *)(v5 + 64) = v18;
  v10 = ipc_log_context_create(2, v5, 0);
  *(_QWORD *)(v5 + 72) = v10;
  if ( v10 )
  {
    v11 = *(_QWORD *)(v5 + 40);
    if ( v11 )
    {
LABEL_13:
      v12 = *(__int64 (__fastcall **)(__int64, int *, __int64, __int64, __int64, __int64))(v11 + 8);
      v13 = *(_QWORD *)(v5 + 48);
      v19 = *(_DWORD *)(v5 + 64);
      if ( *((_DWORD *)v12 - 1) != 1134762728 )
        __break(0x8228u);
      v14 = v12(v13, &v19, 0x6A746E7964LL, 1, 4, 4);
      if ( v14 < 0 )
        dev_err(*(_QWORD *)(v5 + 32), "Error to get dyntj trip for %s ret=%d\n", (const char *)v5, v14);
      else
        LODWORD(v17[0]) = v19;
    }
  }
  else
  {
    dev_err(
      *(_QWORD *)(v5 + 32),
      "%s: unable to create IPC Logging for %s\n",
      "qcom_dynamic_hw_thermal_trip_probe",
      (const char *)v5);
    v11 = *(_QWORD *)(v5 + 40);
    if ( v11 )
      goto LABEL_13;
  }
  result = thermal_zone_device_register_with_trips(v5, v17, 1, v5, &tzone_ops, &tzone_params, 0, 0);
  *(_QWORD *)(v5 + 56) = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    result = 0;
    *(_QWORD *)(a1 + 168) = v5;
  }
  else
  {
    *(_QWORD *)(v5 + 56) = 0;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
