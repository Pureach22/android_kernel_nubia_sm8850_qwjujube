__int64 __fastcall qmi_device_probe(__int64 a1)
{
  __int64 v1; // x21
  __int64 next_available_child; // x0
  __int64 v3; // x1
  int v4; // w27
  unsigned __int64 v5; // x24
  __int64 v6; // x0
  __int64 v7; // x25
  __int64 v8; // x0
  __int64 v9; // x23
  __int64 v10; // x26
  unsigned __int64 v11; // x20
  _QWORD *v12; // x22
  __int64 variable_u32_array; // x0
  _QWORD *v14; // x28
  __int64 v15; // x0
  const char **v16; // x24
  bool v18; // w20
  __int64 v19; // x0
  const char *v20; // x26
  __int64 v21; // x25
  unsigned __int64 v22; // x2
  const char *v23; // x26
  __int64 v24; // x26
  _QWORD *v25; // x2
  _QWORD *v26; // x0
  __int64 v27; // x0
  unsigned int v28; // w21
  __int64 result; // x0
  __int64 v30; // x20
  __int64 v31; // x24
  __int64 v32; // x8
  __int64 v33; // x22
  unsigned int v34; // w0
  __int64 v35; // x25
  unsigned int v36; // w0
  unsigned int v37; // [xsp+4h] [xbp-3Ch]
  __int64 v38; // [xsp+8h] [xbp-38h]
  __int64 v39; // [xsp+20h] [xbp-20h]
  __int64 v40; // [xsp+28h] [xbp-18h]
  const char *v41[2]; // [xsp+30h] [xbp-10h] BYREF

  v41[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 760);
  v40 = a1 + 16;
  next_available_child = of_get_next_available_child(v1, 0);
  if ( !next_available_child )
    goto LABEL_67;
  v3 = next_available_child;
  v4 = 0;
  do
  {
    ++v4;
    v3 = of_get_next_available_child(v1, v3);
  }
  while ( v3 );
  if ( !v4 )
  {
LABEL_67:
    dev_err(v40, "No child node to process\n");
    v28 = -14;
    goto LABEL_56;
  }
  if ( !is_mul_ok(v4, 0x1A0u) )
    goto LABEL_55;
  v5 = 416LL * v4;
  v6 = devm_kmalloc(v40, v5, 3520);
  if ( !v6 )
    goto LABEL_55;
  v7 = v6;
  v37 = v4 - 1;
  v8 = of_get_next_available_child(v1, 0);
  if ( v8 && v37 <= 0x7FFFFFFE )
  {
    v9 = v8;
    v10 = 0;
    v38 = v7;
    while ( 1 )
    {
      v11 = 416 * v10;
      v12 = (_QWORD *)(v7 + 416 * v10);
      variable_u32_array = of_property_read_variable_u32_array(v9, "qcom,instance-id", v12 + 45, 1, 0);
      if ( (variable_u32_array & 0x80000000) != 0 )
        break;
      if ( v5 <= v11 )
        goto LABEL_70;
      v39 = v10;
      if ( (v11 & 0x8000000000000000LL) != 0 )
        goto LABEL_70;
      if ( v5 <= v11 )
        goto LABEL_70;
      *v12 = v40;
      variable_u32_array = _mutex_init(v12 + 39, "&tmd[idx].mutex", &of_get_qmi_tmd_platform_data___key);
      v14 = v12 + 46;
      v12[46] = v12 + 46;
      v12[47] = v12 + 46;
      if ( v5 <= v11 + 384
        || (__int64)(v11 + 384) < 0
        || v5 <= v11 + 384
        || (v12[48] = 0xFFFFFFFE00000LL, v12[49] = v12 + 49, v12[50] = v12 + 49, v5 < v11 + 408)
        || (__int64)(v11 + 408) < 0
        || v5 < v11 + 408 )
      {
LABEL_70:
        __break(1u);
LABEL_71:
        _fortify_panic(2, -1, variable_u32_array + 1);
LABEL_72:
        _fortify_panic(7, 32, v22);
      }
      v12[51] = qmi_tmd_svc_arrive;
      v15 = of_get_next_available_child(v9, 0);
      if ( v15 )
      {
        v16 = (const char **)v15;
        v18 = (__int64)(v11 + 368) < 0 || 416LL * v4 < v11 + 368;
        while ( 1 )
        {
          v41[0] = nullptr;
          v19 = devm_kmalloc(v40, 120, 3520);
          if ( !v19 )
            break;
          v20 = *v16;
          v21 = v19;
          variable_u32_array = strnlen(*v16, 0x20u);
          if ( variable_u32_array == -1 )
            goto LABEL_71;
          if ( variable_u32_array == 32 )
            v22 = 32;
          else
            v22 = variable_u32_array + 1;
          if ( v22 >= 0x21 )
            goto LABEL_72;
          sized_strscpy(v21 + 8, v20);
          if ( (unsigned int)of_property_read_string(v16, "qcom,qmi-dev-name", v41) )
          {
            dev_err(v40, "Fail to parse dev name for %s\n", *v16);
            goto LABEL_51;
          }
          v23 = v41[0];
          variable_u32_array = strnlen(v41[0], 0x20u);
          if ( variable_u32_array == -1 )
            goto LABEL_71;
          if ( variable_u32_array == 32 )
            v22 = 32;
          else
            v22 = variable_u32_array + 1;
          if ( v22 >= 0x21 )
            goto LABEL_72;
          sized_strscpy(v21 + 40, v23);
          v24 = 0;
          while ( 1 )
          {
            variable_u32_array = strcmp(&device_clients[v24], (const char *)(v21 + 40));
            if ( !(_DWORD)variable_u32_array )
              break;
            v24 += 32;
            if ( v24 == 2400 )
            {
              dev_err(v40, "Not supported dev name for %s\n", *v16);
              goto LABEL_51;
            }
          }
          *(_QWORD *)(v21 + 112) = v12;
          *(_QWORD *)v21 = v16;
          *(_DWORD *)(v21 + 104) = 0;
          if ( v18 )
            goto LABEL_70;
          v25 = (_QWORD *)*v14;
          v26 = (_QWORD *)(v21 + 80);
          if ( *(_QWORD **)(*v14 + 8LL) != v14 || v26 == v14 || v25 == v26 )
          {
            _list_add_valid_or_report(v26, v12 + 46);
          }
          else
          {
            v25[1] = v26;
            *(_QWORD *)(v21 + 80) = v25;
            *(_QWORD *)(v21 + 88) = v14;
            *v14 = v26;
          }
          v16 = (const char **)of_get_next_available_child(v9, v16);
          if ( !v16 )
            goto LABEL_51;
        }
LABEL_55:
        v28 = -12;
        goto LABEL_56;
      }
LABEL_51:
      v27 = of_get_next_available_child(v1, v9);
      v5 = 416LL * v4;
      v7 = v38;
      if ( v27 )
      {
        v10 = v39 + 1;
        v9 = v27;
        if ( v39 + 1 < v4 )
          continue;
      }
      goto LABEL_57;
    }
    v28 = variable_u32_array;
    dev_err(v40, "error reading qcom,insance-id. ret:%d\n", variable_u32_array);
LABEL_56:
    qmi_tmd_cleanup();
    result = v28;
  }
  else
  {
LABEL_57:
    tmd_instances = v7;
    tmd_inst_cnt = v4;
    if ( v37 <= 0x7FFFFFFE )
    {
      v30 = 0;
      v31 = 368;
      do
      {
        v32 = v7 + v31;
        if ( v7 + v31 != *(_QWORD *)(v7 + v31) )
        {
          v33 = v32 - 360;
          v34 = qmi_handle_init(v32 - 360, 3279, thermal_qmi_event_ops, 0);
          if ( (v34 & 0x80000000) != 0 )
          {
            v28 = v34;
            dev_err(v40, "QMI[0x%x] handle init failed. err:%d\n", *(_DWORD *)(v7 + v31 - 8), v34);
            tmd_inst_cnt = v30;
            goto LABEL_56;
          }
          v35 = v7 + v31;
          v36 = qmi_add_lookup(v33, 24, 1, *(unsigned int *)(v35 - 8));
          if ( (v36 & 0x80000000) != 0 )
          {
            v28 = v36;
            dev_err(v40, "QMI register failed for 0x%x, ret:%d\n", *(_DWORD *)(v35 - 8), v36);
            goto LABEL_56;
          }
          v7 = tmd_instances;
          v4 = tmd_inst_cnt;
        }
        ++v30;
        v31 += 416;
      }
      while ( v30 < v4 );
    }
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
