__int64 __fastcall qmi_sens_device_probe(__int64 a1)
{
  __int64 v1; // x27
  __int64 v2; // x20
  __int64 next_available_child; // x0
  __int64 v4; // x1
  int v5; // w21
  unsigned __int64 v6; // x25
  __int64 v7; // x0
  __int64 v8; // x26
  unsigned int v9; // w28
  const char *v10; // x1
  __int64 v11; // x8
  unsigned __int64 v12; // x23
  _QWORD *v13; // x22
  unsigned int variable_u32_array; // w0
  _QWORD *v15; // x28
  int string_helper; // w24
  unsigned __int64 v17; // x9
  unsigned int v18; // w25
  bool v20; // w8
  __int64 v21; // x0
  __int64 v22; // x26
  __int64 v23; // x23
  const char *v24; // x27
  size_t v25; // x0
  unsigned __int64 v26; // x2
  __int64 v27; // x19
  const char *v28; // x27
  _QWORD *v29; // x2
  _QWORD *v30; // x0
  __int64 v31; // x0
  __int64 v32; // x24
  __int64 v33; // x26
  __int64 v34; // x19
  __int64 v35; // x8
  __int64 v36; // x22
  int v37; // w0
  __int64 v38; // x19
  int v39; // w0
  unsigned int v40; // w24
  __int64 v42; // [xsp+18h] [xbp-38h]
  __int64 v43; // [xsp+28h] [xbp-28h]
  bool v44; // [xsp+34h] [xbp-1Ch]
  __int64 v45; // [xsp+38h] [xbp-18h]
  const char *v46[2]; // [xsp+40h] [xbp-10h] BYREF

  v1 = a1 + 16;
  v46[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  next_available_child = of_get_next_available_child(v2, 0);
  if ( !next_available_child )
    goto LABEL_57;
  v4 = next_available_child;
  v5 = 0;
  do
  {
    ++v5;
    v4 = of_get_next_available_child(v2, v4);
  }
  while ( v4 );
  if ( !v5 )
  {
LABEL_57:
    dev_err(v1, "No child node to process\n");
    v40 = -14;
    goto LABEL_59;
  }
  if ( !is_mul_ok(v5, 0x1A0u) || (v6 = 416LL * v5, (v7 = devm_kmalloc(v1, v6, 3520)) == 0) )
  {
LABEL_55:
    v40 = -12;
LABEL_59:
    qmi_ts_cleanup();
    goto LABEL_60;
  }
  v8 = v7;
  v9 = v5 - 1;
  v45 = of_get_next_available_child(v2, 0);
  if ( v45 && v9 <= 0x7FFFFFFE )
  {
    v11 = 0;
    v42 = v8;
LABEL_10:
    v12 = 416 * v11;
    v43 = v11;
    v13 = (_QWORD *)(v8 + 416 * v11);
    variable_u32_array = of_property_read_variable_u32_array(v45, "qcom,instance-id", v13 + 45, 1, 0);
    if ( (variable_u32_array & 0x80000000) != 0 )
    {
      v40 = variable_u32_array;
      dev_err(v1, "error reading qcom,insance-id. ret:%d\n", variable_u32_array);
      goto LABEL_59;
    }
    if ( v6 <= v12 )
      goto LABEL_65;
    if ( (v12 & 0x8000000000000000LL) != 0 )
      goto LABEL_65;
    if ( v6 <= v12 )
      goto LABEL_65;
    *v13 = v1;
    _mutex_init(v13 + 39, "&ts[idx].mutex", &of_get_qmi_ts_platform_data___key);
    v15 = v13 + 46;
    v13[46] = v13 + 46;
    v13[47] = v13 + 46;
    if ( v6 <= v12 + 384
      || (__int64)(v12 + 384) < 0
      || v6 <= v12 + 384
      || (v13[48] = 0xFFFFFFFE00000LL, v13[49] = v13 + 49, v13[50] = v13 + 49, v6 < v12 + 408)
      || (__int64)(v12 + 408) < 0
      || v6 < v12 + 408 )
    {
LABEL_65:
      __break(1u);
LABEL_66:
      _fortify_panic(7, 40);
LABEL_67:
      _fortify_panic(2, -1);
    }
    v13[51] = qmi_ts_svc_arrive;
    string_helper = of_property_read_string_helper(v45, "qcom,qmi-sensor-names", 0, 0, 0);
    if ( string_helper < 1 )
    {
      dev_err(v1, "Invalid or no sensor. err:%d\n", string_helper);
LABEL_56:
      v40 = -22;
      goto LABEL_59;
    }
    v17 = v6;
    v18 = 0;
    v20 = (__int64)(v12 + 368) < 0 || v17 < v12 + 368;
    v44 = v20;
    while ( 1 )
    {
      v46[0] = nullptr;
      v21 = devm_kmalloc(v1, 144, 3520);
      if ( !v21 )
        goto LABEL_55;
      v22 = v21;
      v23 = v1;
      of_property_read_string_helper(v45, "qcom,qmi-sensor-names", v46, 1, v18);
      v24 = v46[0];
      v25 = strnlen(v46[0], 0x28u);
      if ( v25 == -1 )
        goto LABEL_67;
      if ( v25 == 40 )
        v26 = 40;
      else
        v26 = v25 + 1;
      if ( v26 >= 0x29 )
        goto LABEL_66;
      sized_strscpy(v22 + 8, v24);
      v27 = 0;
      v28 = (const char *)&sensor_clients;
      while ( strcmp(v28, (const char *)(v22 + 8)) )
      {
        ++v27;
        v28 += 40;
        if ( v27 == 83 )
        {
          dev_err(v23, "Unknown sensor:%s\n", (const char *)(v22 + 8));
          goto LABEL_56;
        }
      }
      *(_DWORD *)(v22 + 104) = v27;
      *(_QWORD *)(v22 + 80) = 0x7FFFFFFF00000000LL;
      *(_DWORD *)(v22 + 88) = -2147483647;
      *(_QWORD *)(v22 + 112) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v22 + 96) = v13;
      *(_QWORD *)v22 = v23;
      *(_QWORD *)(v22 + 120) = v22 + 120;
      *(_QWORD *)(v22 + 128) = v22 + 120;
      *(_QWORD *)(v22 + 136) = qmi_ts_thresh_notify;
      if ( v44 )
        goto LABEL_65;
      v29 = (_QWORD *)*v15;
      v1 = v23;
      v30 = (_QWORD *)(v22 + 56);
      if ( *(_QWORD **)(*v15 + 8LL) != v15 || v30 == v15 || v29 == v30 )
      {
        _list_add_valid_or_report(v30, v13 + 46);
      }
      else
      {
        v29[1] = v30;
        *(_QWORD *)(v22 + 56) = v29;
        *(_QWORD *)(v22 + 64) = v15;
        *v15 = v30;
      }
      if ( ++v18 == string_helper )
      {
        v31 = of_get_next_available_child(v2, v45);
        v8 = v42;
        v10 = "qcom,instance-id";
        v6 = 416LL * v5;
        v9 = v5 - 1;
        v45 = v31;
        if ( v31 )
        {
          v11 = v43 + 1;
          if ( v43 + 1 < v5 )
            goto LABEL_10;
        }
        break;
      }
    }
  }
  ts_instances = v8;
  ts_inst_cnt = v5;
  if ( v9 <= 0x7FFFFFFE )
  {
    v32 = 0;
    v33 = 368;
    while ( 1 )
    {
      v34 = ts_instances;
      v35 = ts_instances + v33;
      if ( ts_instances + v33 == *(_QWORD *)(ts_instances + v33) )
      {
        v40 = -19;
        goto LABEL_59;
      }
      v36 = v35 - 360;
      v37 = qmi_handle_init(v35 - 360, 3179, thermal_qmi_event_ops, &handlers);
      if ( v37 < 0 )
      {
        dev_err(v1, "QMI[0x%x] handle init failed. err:%d\n", *(_DWORD *)(v34 + v33 - 8), v37);
        ts_inst_cnt = v32;
        v40 = -517;
        goto LABEL_59;
      }
      v38 = v34 + v33;
      v39 = qmi_add_lookup(v36, 23, 2, *(unsigned int *)(v38 - 8));
      if ( v39 < 0 )
        break;
      ++v32;
      v33 += 416;
      if ( v32 >= ts_inst_cnt )
        goto LABEL_54;
    }
    dev_err(v1, "QMI register failed for 0x%x, ret:%d\n", *(_DWORD *)(v38 - 8), v39);
    v40 = -517;
    goto LABEL_59;
  }
LABEL_54:
  in_suspend = 0;
  register_pm_notifier(&qmi_sensor_pm_nb, v10);
  v40 = 0;
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return v40;
}
