__int64 __fastcall qpnp_vibrator_ldo_probe(_QWORD *a1)
{
  __int64 v2; // x0
  unsigned int v3; // w0
  __int64 v4; // x3
  __int64 v5; // x0
  __int64 result; // x0
  unsigned int v7; // w19
  void *v8; // x0
  __int64 v9; // x21
  __int64 regmap; // x0
  __int64 v11; // x2
  __int64 v12; // x3
  unsigned int variable_u32_array; // w0
  __int64 v14; // x3
  void *v15; // x8
  bool v16; // w9
  __int64 v17; // x0
  int *v18; // x20
  int v19; // w8
  unsigned int v20; // w0
  __int64 v21; // x3
  unsigned int v22; // w20
  int file_ns; // w0
  const char *v24; // x3
  int v25; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[95];
  v25 = 0;
  v3 = of_property_read_variable_u32_array(v2, "reg", &v25, 1, 0);
  if ( (v3 & 0x80000000) != 0 )
  {
    v7 = v3;
    v8 = &unk_703F;
LABEL_11:
    printk(v8, "qpnp_vibrator_ldo_probe", v7, v4);
    result = v7;
    goto LABEL_4;
  }
  v5 = devm_kmalloc(a1 + 2, 640, 3520);
  if ( !v5 )
  {
    result = 4294967284LL;
    goto LABEL_4;
  }
  v9 = v5;
  regmap = dev_get_regmap(a1[14], 0);
  *(_QWORD *)(v9 + 448) = regmap;
  if ( !regmap )
  {
    printk(&unk_7192, "qpnp_vibrator_ldo_probe", v11, v12);
    result = 4294967274LL;
    goto LABEL_4;
  }
  variable_u32_array = of_property_read_variable_u32_array(a1[95], "qcom,vib-ldo-volt-uv", v9 + 604, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v15 = &unk_6F24;
LABEL_10:
    v7 = variable_u32_array;
    printk(v15, "qpnp_vib_parse_dt", variable_u32_array, v14);
    v8 = &unk_6EBB;
    goto LABEL_11;
  }
  v16 = of_find_property(a1[95], "qcom,disable-overdrive", 0) != 0;
  v17 = a1[95];
  *(_BYTE *)(v9 + 633) = v16;
  if ( of_find_property(v17, "qcom,vib-overdrive-volt-uv", 0) )
  {
    v18 = (int *)(v9 + 608);
    variable_u32_array = of_property_read_variable_u32_array(a1[95], "qcom,vib-overdrive-volt-uv", v9 + 608, 1, 0);
    if ( (variable_u32_array & 0x80000000) != 0 )
    {
      v15 = &unk_6FB2;
      goto LABEL_10;
    }
    v19 = *v18;
    if ( *v18 >= 3544000 )
      v19 = 3544000;
    if ( v19 <= 1504000 )
      v19 = 1504000;
    *v18 = v19;
  }
  *(_WORD *)(v9 + 600) = v25;
  *(_QWORD *)(v9 + 624) = 5000;
  _mutex_init(v9 + 456, "&chip->lock", &qpnp_vibrator_ldo_probe___key);
  *(_QWORD *)(v9 + 568) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v9 + 576) = v9 + 576;
  *(_QWORD *)(v9 + 584) = v9 + 576;
  *(_QWORD *)(v9 + 592) = qpnp_vib_overdrive_work;
  hrtimer_init(v9 + 504, 1, 1);
  *(_QWORD *)(v9 + 544) = vib_overdrive_timer;
  *(_QWORD *)v9 = "vibrator";
  *(_QWORD *)(v9 + 40) = qpnp_vib_brightness_set;
  *(_QWORD *)(v9 + 48) = qpnp_vib_brightness_get;
  a1[21] = v9;
  *(_DWORD *)(v9 + 12) = 100;
  v20 = devm_led_classdev_register_ext(a1 + 2, v9, 0);
  if ( (v20 & 0x80000000) != 0 )
  {
    v22 = v20;
    printk(&unk_6FF1, "qpnp_vibrator_ldo_probe", v20, v21);
LABEL_24:
    result = v22;
    a1[21] = 0;
    goto LABEL_4;
  }
  file_ns = sysfs_create_file_ns(*(_QWORD *)(v9 + 80), &qpnp_vib_attrs, 0);
  if ( file_ns < 0 )
  {
    v22 = file_ns;
    dev_err(a1 + 2, "Error in creating sysfs file, ret=%d\n", file_ns);
    sysfs_remove_file_ns(*(_QWORD *)(v9 + 80), &qpnp_vib_attrs, 0);
    goto LABEL_24;
  }
  if ( *(_BYTE *)(v9 + 633) )
    v24 = "disabled";
  else
    v24 = "enabled";
  printk(&unk_729C, "qpnp_vibrator_ldo_probe", *(unsigned int *)(v9 + 604), v24);
  result = 0;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
