__int64 __fastcall qti_btl_probe(__int64 a1)
{
  __int64 v1; // x20
  _QWORD *v3; // x0
  _QWORD *v4; // x19
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x1
  __int64 v7; // x0
  const char *v8; // x2
  __int64 result; // x0
  int v10; // w11
  void *v11; // x8
  int v12; // w8
  unsigned __int64 v13; // x0
  int v14; // w8
  __int64 v15; // x0
  _BYTE v16[4]; // [xsp+0h] [xbp-30h] BYREF
  int v17; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v18[5]; // [xsp+8h] [xbp-28h] BYREF

  v1 = a1 + 16;
  v18[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (_QWORD *)devm_kmalloc(a1 + 16, 104, 3520);
  if ( !v3 )
  {
    result = 4294967284LL;
    goto LABEL_23;
  }
  v4 = v3;
  *v3 = v1;
  *(_QWORD *)(a1 + 168) = v3;
  v5 = devm_nvmem_device_get(v1, "btl-sdam");
  v6 = v5;
  v4[1] = v5;
  if ( v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    v7 = *v4;
    v8 = "Failed to get btl SDAM device\n";
LABEL_4:
    result = dev_err_probe(v7, v6, v8);
    goto LABEL_23;
  }
  memset(v18, 0, 32);
  v17 = 0;
  v16[0] = 0;
  result = nvmem_device_read(v5, 73, 1, v16);
  if ( (result & 0x80000000) == 0 )
  {
    v10 = v16[0] & 0xF0;
    *((_BYTE *)v4 + 80) = v16[0] & 0xF;
    v11 = v10 == 16 ? &adc_gen4_batt_therm_10k_map : &adc_gen4_batt_therm_100k_map;
    v4[11] = v11;
    *((_DWORD *)v4 + 24) = 70;
    result = btl_read_temp_record((__int64)v4, 88, (_DWORD *)v4 + 5);
    if ( (result & 0x80000000) == 0 )
    {
      result = btl_read_temp_record((__int64)v4, 86, (_DWORD *)v4 + 6);
      if ( (result & 0x80000000) == 0 )
      {
        result = btl_read_temp_record((__int64)v4, 84, (_DWORD *)v4 + 7);
        if ( (result & 0x80000000) == 0 )
        {
          result = btl_read_temp_record((__int64)v4, 82, (_DWORD *)v4 + 8);
          if ( (result & 0x80000000) == 0 )
          {
            result = btl_read_temp_record((__int64)v4, 80, (_DWORD *)v4 + 9);
            if ( (result & 0x80000000) == 0 )
            {
              result = btl_read_temp_record((__int64)v4, 78, (_DWORD *)v4 + 10);
              if ( (result & 0x80000000) == 0 )
              {
                result = btl_read_temp_record((__int64)v4, 76, (_DWORD *)v4 + 11);
                if ( (result & 0x80000000) == 0 )
                {
                  result = nvmem_device_read(v4[1], 75, 1, v4 + 2);
                  if ( (result & 0x80000000) == 0 )
                  {
                    result = nvmem_device_read(v4[1], 72, 1, v16);
                    if ( (result & 0x80000000) == 0 )
                    {
                      v12 = v16[0];
                      *((_BYTE *)v4 + 100) = v16[0] != 0;
                      if ( v12 )
                        goto LABEL_20;
                      if ( !of_find_property(*(_QWORD *)(*v4 + 744LL), "qcom,temperature-thresholds", 0) )
                        goto LABEL_35;
                      v14 = of_property_count_elems_of_size(*(_QWORD *)(*v4 + 744LL), "qcom,temperature-thresholds", 4);
                      v15 = *v4;
                      if ( v14 != 8 )
                      {
                        dev_err(v15, "Error, Incorrect temperature thresholds list size\n");
                        result = 4294967274LL;
                        goto LABEL_23;
                      }
                      result = of_property_read_variable_u32_array(
                                 *(_QWORD *)(v15 + 744),
                                 "qcom,temperature-thresholds",
                                 v18,
                                 8,
                                 0);
                      if ( (result & 0x80000000) == 0 )
                      {
                        result = btl_set_temp_thresholds(v4, (int *)v18);
                        if ( (result & 0x80000000) == 0 )
                        {
LABEL_35:
                          if ( !of_find_property(*(_QWORD *)(*v4 + 744LL), "qcom,sample-interval-ms", 0)
                            || (result = of_property_read_variable_u32_array(
                                           *(_QWORD *)(*v4 + 744LL),
                                           "qcom,sample-interval-ms",
                                           &v17,
                                           1,
                                           0),
                                (result & 0x80000000) == 0)
                            && (result = btl_set_sample_interval_ms((__int64)v4, v17), (result & 0x80000000) == 0) )
                          {
LABEL_20:
                            v13 = devm_hwmon_device_register_with_groups(v1, "qti_btl", v4, &qti_btl_groups);
                            if ( v13 < 0xFFFFFFFFFFFFF001LL )
                            {
                              result = 0;
                              goto LABEL_23;
                            }
                            v6 = v13;
                            v7 = *v4;
                            v8 = "Failed to register hwmon device for qti_btl\n";
                            goto LABEL_4;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
