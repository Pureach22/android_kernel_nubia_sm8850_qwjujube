__int64 __fastcall pmic_glink_debug_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 next_child_node; // x0
  unsigned __int64 v6; // x22
  unsigned int v7; // w27
  unsigned int v8; // w28
  __int64 v9; // x0
  char *v10; // x26
  unsigned __int64 v11; // x0
  __int64 result; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned __int64 v15; // x22
  __int64 v16; // x0
  __int64 *v17; // x28
  _QWORD *v18; // x26
  __int64 u32_array; // x0
  unsigned __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x0
  __int64 v25; // x26
  __int64 v26; // x0
  __int64 v27; // x8
  unsigned __int64 v28; // x8
  __int64 v29; // x8
  __int64 v30; // x9
  __int64 v31; // x0
  __int64 v32; // x20
  __int64 v33; // x20
  __int64 v34; // x8
  void (__fastcall *v35)(_QWORD); // x8
  __int64 v36; // x19
  __int64 v37; // x8
  void (__fastcall *v38)(_QWORD); // x8
  __int64 v39; // x8
  void (__fastcall *v40)(_QWORD); // x8
  __int64 v41; // x8
  const char *v42; // x1
  char *s1; // [xsp+8h] [xbp-38h] BYREF
  const char *v44; // [xsp+10h] [xbp-30h] BYREF
  __int64 v45; // [xsp+18h] [xbp-28h]
  __int64 v46; // [xsp+20h] [xbp-20h]
  __int64 (__fastcall *v47)(); // [xsp+28h] [xbp-18h]
  __int64 v48; // [xsp+30h] [xbp-10h]
  __int64 v49; // [xsp+38h] [xbp-8h]

  v1 = a1 + 16;
  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = nullptr;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  s1 = nullptr;
  v44 = nullptr;
  v3 = devm_kmalloc(a1 + 16, 408, 3520);
  if ( !v3 )
    goto LABEL_48;
  v4 = v3;
  *(_QWORD *)(v3 + 8) = v1;
  _mutex_init(v3 + 16, "&gd->lock", &pmic_glink_debug_probe___key);
  *(_DWORD *)(v4 + 64) = 0;
  _init_swait_queue_head(v4 + 72, "&x->wait", &init_completion___key);
  *(_QWORD *)(a1 + 168) = v4;
  next_child_node = device_get_next_child_node(v1, 0);
  if ( next_child_node )
  {
    v6 = next_child_node;
    v7 = 0;
    v8 = 0;
    while ( 1 )
    {
      v9 = fwnode_property_read_string(v6, "qcom,bus-type", &s1);
      if ( (_DWORD)v9 )
      {
        if ( (_DWORD)v9 != -22 )
        {
          v36 = v9;
          if ( v6 <= 0xFFFFFFFFFFFFF000LL )
          {
            v37 = *(_QWORD *)(v6 + 8);
            if ( v37 )
            {
              v38 = *(void (__fastcall **)(_QWORD))(v37 + 8);
              if ( v38 )
              {
                if ( *((_DWORD *)v38 - 1) != -643302289 )
                  __break(0x8228u);
                v38(v6);
              }
            }
          }
          dev_err(*(_QWORD *)(v4 + 8), "Get qcom,bus-type failed, ret=%d\n", (unsigned int)v36);
          goto LABEL_71;
        }
      }
      else
      {
        v10 = s1;
        if ( !strcmp(s1, "i2c") )
        {
          ++v7;
          goto LABEL_6;
        }
        if ( strcmp(v10, "spmi") )
        {
          dev_err(*(_QWORD *)(v4 + 8), "unsupported bus type: %s\n", v10);
          if ( v6 <= 0xFFFFFFFFFFFFF000LL
            && (v39 = *(_QWORD *)(v6 + 8)) != 0
            && (v40 = *(void (__fastcall **)(_QWORD))(v39 + 8)) != nullptr )
          {
            if ( *((_DWORD *)v40 - 1) != -643302289 )
              __break(0x8228u);
            v40(v6);
            result = 4294967274LL;
          }
          else
          {
            result = 4294967274LL;
          }
          goto LABEL_49;
        }
      }
      ++v8;
LABEL_6:
      v6 = device_get_next_child_node(v1, v6);
      if ( !v6 )
        goto LABEL_13;
    }
  }
  v8 = 0;
  v7 = 0;
LABEL_13:
  if ( !(v8 | v7) )
  {
    dev_err(v1, "pmic bus child nodes missing\n");
    result = 4294967277LL;
    goto LABEL_49;
  }
  LODWORD(v45) = 32783;
  v44 = "pmic_register_dump";
  v46 = v4;
  v47 = pmic_glink_debug_callback;
  v11 = pmic_glink_register_client(v1, &v44);
  *(_QWORD *)v4 = v11;
  if ( v11 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (_DWORD)v11 == -517 )
    {
      result = 4294966779LL;
      goto LABEL_49;
    }
    v36 = v11;
    dev_err(v1, "Error registering with pmic_glink, ret=%d\n", (unsigned int)v11);
LABEL_71:
    result = v36;
    goto LABEL_49;
  }
  if ( v8 && (v13 = devm_kmalloc(v1, 8LL * v8, 3520), (*(_QWORD *)(v4 + 384) = v13) == 0)
    || v7 && (v14 = devm_kmalloc(v1, 8LL * v7, 3520), (*(_QWORD *)(v4 + 392) = v14) == 0) )
  {
LABEL_48:
    result = 4294967284LL;
    goto LABEL_49;
  }
  result = device_get_next_child_node(v1, 0);
  if ( !result )
    goto LABEL_49;
  v15 = result;
  while ( 1 )
  {
    s1 = nullptr;
    if ( (unsigned int)fwnode_property_read_string(v15, "qcom,bus-type", &s1) || strcmp(s1, "i2c") )
    {
      if ( !*(_QWORD *)(v4 + 384) )
        goto LABEL_51;
      v16 = spmi_controller_alloc(*(_QWORD *)(v4 + 8), 24);
      if ( !v16 )
        goto LABEL_52;
      v17 = *(__int64 **)(v16 + 152);
      v18 = (_QWORD *)v16;
      *v17 = v4;
      v17[1] = v16;
      u32_array = fwnode_property_read_u32_array(v15, "reg", v17 + 2, 1);
      if ( (_DWORD)u32_array )
      {
        v32 = u32_array;
        dev_err(*(_QWORD *)(v4 + 8), "Could not find reg property, ret=%d\n", u32_array);
      }
      else
      {
        v18[115] = spmi_glink_cmd;
        v18[116] = spmi_glink_read_cmd;
        v18[117] = spmi_glink_write_cmd;
        if ( v15 <= 0xFFFFFFFFFFFFF000LL )
        {
          if ( *(_UNKNOWN **)(v15 + 8) == &of_fwnode_ops )
            v20 = v15 - 24;
          else
            v20 = 0;
        }
        else
        {
          v20 = 0;
        }
        v18[93] = v20;
        v21 = spmi_controller_add(v18);
        if ( !(_DWORD)v21 )
        {
          v22 = *(unsigned int *)(v4 + 400);
          v23 = *(_QWORD *)(v4 + 384);
          *(_DWORD *)(v4 + 400) = v22 + 1;
          *(_QWORD *)(v23 + 8 * v22) = v17;
          goto LABEL_35;
        }
        v32 = v21;
      }
      put_device(v18);
      goto LABEL_55;
    }
    if ( !*(_QWORD *)(v4 + 392) )
    {
LABEL_51:
      v31 = 4294967277LL;
      goto LABEL_56;
    }
    v24 = devm_kmalloc(*(_QWORD *)(v4 + 8), 1256, 3520);
    if ( !v24 )
    {
LABEL_52:
      v31 = 4294967284LL;
      goto LABEL_56;
    }
    v25 = v24;
    v26 = fwnode_property_read_u32_array(v15, "reg", v24 + 1248, 1);
    if ( (_DWORD)v26 )
      break;
    v27 = *(_QWORD *)(v4 + 8);
    *(_QWORD *)v25 = v4;
    *(_QWORD *)(v25 + 24) = glink_i2c_algo;
    *(_QWORD *)(v25 + 216) = v27;
    if ( v15 <= 0xFFFFFFFFFFFFF000LL )
    {
      if ( *(_UNKNOWN **)(v15 + 8) == &of_fwnode_ops )
        v28 = v15 - 24;
      else
        v28 = 0;
    }
    else
    {
      v28 = 0;
    }
    *(_QWORD *)(v25 + 864) = v28;
    strcpy((char *)(v25 + 1044), "glink-i2c");
    *(_QWORD *)(v25 + 272) = v25;
    v26 = i2c_add_adapter(v25 + 8);
    if ( (_DWORD)v26 )
    {
      v41 = *(_QWORD *)(v4 + 8);
      v42 = "Add i2c adapter failed, ret=%d\n";
      goto LABEL_82;
    }
    v29 = *(unsigned int *)(v4 + 404);
    v30 = *(_QWORD *)(v4 + 392);
    *(_DWORD *)(v4 + 404) = v29 + 1;
    *(_QWORD *)(v30 + 8 * v29) = v25;
    v31 = devm_of_platform_populate(*(_QWORD *)(v4 + 8));
    if ( (_DWORD)v31 )
      goto LABEL_56;
LABEL_35:
    v15 = device_get_next_child_node(v1, v15);
    result = 0;
    if ( !v15 )
      goto LABEL_49;
  }
  v41 = *(_QWORD *)(v4 + 8);
  v42 = "Could not find reg property, ret=%d\n";
LABEL_82:
  v32 = v26;
  dev_err(v41, v42);
LABEL_55:
  v31 = v32;
LABEL_56:
  v33 = v31;
  if ( v15 <= 0xFFFFFFFFFFFFF000LL )
  {
    v34 = *(_QWORD *)(v15 + 8);
    if ( v34 )
    {
      v35 = *(void (__fastcall **)(_QWORD))(v34 + 8);
      if ( v35 )
      {
        if ( *((_DWORD *)v35 - 1) != -643302289 )
          __break(0x8228u);
        v35(v15);
      }
    }
  }
  pmic_glink_debug_remove(a1);
  result = v33;
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
