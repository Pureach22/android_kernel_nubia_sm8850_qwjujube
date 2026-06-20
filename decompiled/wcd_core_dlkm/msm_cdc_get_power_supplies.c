__int64 __fastcall msm_cdc_get_power_supplies(__int64 a1, __int64 *a2, int *a3)
{
  unsigned int string_helper; // w20
  int v7; // w0
  unsigned int v8; // w23
  int v9; // w0
  unsigned int v10; // w21
  int v11; // w27
  __int64 v12; // x0
  __int64 v13; // x22
  unsigned int v14; // w0
  unsigned int v15; // w24
  unsigned int v17; // w0

  if ( !a1 )
  {
    if ( (unsigned int)__ratelimit(&msm_cdc_get_power_supplies__rs, "msm_cdc_get_power_supplies") )
    {
      printk(&unk_9DB5, "msm_cdc_get_power_supplies");
      return (unsigned int)-22;
    }
    return (unsigned int)-22;
  }
  string_helper = of_property_read_string_helper(*(_QWORD *)(a1 + 744), "qcom,cdc-static-supplies", 0, 0, 0);
  if ( (string_helper & 0x80000000) == 0 )
  {
    v7 = of_property_read_string_helper(*(_QWORD *)(a1 + 744), "qcom,cdc-on-demand-supplies", 0, 0, 0);
    v8 = v7 & ~(v7 >> 31);
    v9 = of_property_read_string_helper(*(_QWORD *)(a1 + 744), "qcom,cdc-cp-supplies", 0, 0, 0);
    v10 = v9 & ~(v9 >> 31);
    v11 = v10 + v8 + string_helper;
    if ( v11 > 0 )
    {
      v12 = devm_kmalloc(a1, 32LL * (v10 + v8 + string_helper), 3520);
      if ( v12 )
      {
        v13 = v12;
        v14 = msm_cdc_parse_supplies(a1, v12, "qcom,cdc-static-supplies", string_helper, 0);
        if ( v14 )
        {
          v15 = v14;
          if ( (unsigned int)__ratelimit(&msm_cdc_get_power_supplies__rs_27, "msm_cdc_get_power_supplies") )
            dev_err(a1, "%s: failed to parse static supplies(%d)\n", "msm_cdc_get_power_supplies", v15);
          return v15;
        }
        else
        {
          v17 = msm_cdc_parse_supplies(a1, v13 + 32LL * string_helper, "qcom,cdc-on-demand-supplies", v8, 1);
          if ( v17 )
          {
            string_helper = v17;
            if ( (unsigned int)__ratelimit(&msm_cdc_get_power_supplies__rs_29, "msm_cdc_get_power_supplies") )
              dev_err(a1, "%s: failed to parse demand supplies(%d)\n", "msm_cdc_get_power_supplies", string_helper);
          }
          else
          {
            string_helper = msm_cdc_parse_supplies(
                              a1,
                              v13 + 32LL * (int)(v8 + string_helper),
                              "qcom,cdc-cp-supplies",
                              v10,
                              1);
            if ( string_helper )
            {
              if ( (unsigned int)__ratelimit(&msm_cdc_get_power_supplies__rs_31, "msm_cdc_get_power_supplies") )
                dev_err(a1, "%s: failed to parse cp supplies(%d)\n", "msm_cdc_get_power_supplies", string_helper);
            }
            else
            {
              *a2 = v13;
              *a3 = v11;
            }
          }
        }
      }
      else
      {
        return (unsigned int)-12;
      }
      return string_helper;
    }
    if ( (unsigned int)__ratelimit(&msm_cdc_get_power_supplies__rs_25, "msm_cdc_get_power_supplies") )
    {
      dev_err(a1, "%s: supply count is 0 or negative\n", "msm_cdc_get_power_supplies");
      return (unsigned int)-22;
    }
    return (unsigned int)-22;
  }
  if ( (unsigned int)__ratelimit(&msm_cdc_get_power_supplies__rs_23, "msm_cdc_get_power_supplies") )
    dev_err(a1, "%s: Failed to get static supplies(%d)\n", "msm_cdc_get_power_supplies", string_helper);
  return string_helper;
}
