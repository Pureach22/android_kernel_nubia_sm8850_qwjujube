__int64 __fastcall ufs_qcom_config_scaling_param(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 v5; // x21
  __int64 result; // x0

  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 64) + 744LL);
  *(_QWORD *)(a2 + 8) = 0x10000003CLL;
  *a3 = 0x4100000046LL;
  of_property_read_variable_u32_array(v5, "qcom,devfreq_polling_ms", a2 + 8, 1, 0);
  of_property_read_variable_u32_array(v5, "qcom,devfreq_upthreshold", a3, 1, 0);
  result = of_property_read_variable_u32_array(v5, "qcom,devfreq_downdifferential", (char *)a3 + 4, 1, 0);
  *(_BYTE *)(a1 + 3205) = 1;
  return result;
}
