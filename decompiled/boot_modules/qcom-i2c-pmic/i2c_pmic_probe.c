__int64 __fastcall i2c_pmic_probe(__int64 a1)
{
  __int64 v1; // x21
  _QWORD *v3; // x0
  _QWORD *v4; // x20
  __int64 inited; // x0
  __int64 v6; // x9
  __int64 v7; // x8
  bool v8; // zf
  __int64 v9; // x8
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x22
  unsigned int v14; // w2
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x27
  __int64 v18; // x23
  int u32_index; // w0
  __int64 property; // x0
  int v21; // w2
  __int64 v22; // x24
  __int64 v23; // x25
  __int64 v24; // x23
  __int64 v25; // x28
  int v26; // w27
  unsigned int v27; // w0
  __int64 v28; // x8
  char v29; // w10
  unsigned int v30; // w0
  unsigned int v31; // w23
  __int64 v32; // x1
  unsigned int v33; // w22
  __int64 v34; // x0
  const char *v35; // x1
  __int64 result; // x0
  unsigned int v37; // w21
  __int64 v38; // x22
  unsigned __int64 v39; // x0
  unsigned __int64 v40; // x23
  unsigned __int64 v41; // x22
  int v42; // w0
  unsigned int v43; // w0
  int v44; // w23
  unsigned int v45; // w0
  int v46; // w21
  __int64 v47; // x8
  const char *v48; // x1
  _QWORD v49[13]; // [xsp+8h] [xbp-68h] BYREF

  v1 = a1 + 32;
  v49[12] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (_QWORD *)devm_kmalloc(a1 + 32, 112, 3520);
  if ( !v3 )
  {
    result = 4294967284LL;
    goto LABEL_57;
  }
  v4 = v3;
  *v3 = v1;
  inited = _devm_regmap_init_i2c(a1, &i2c_pmic_regmap_config, 0, 0);
  v4[1] = inited;
  if ( !inited )
  {
    result = 4294967277LL;
    goto LABEL_57;
  }
  devm_regmap_qti_debugfs_register(*v4, inited);
  v6 = *v4;
  *(_QWORD *)(a1 + 184) = v4;
  *((_DWORD *)v4 + 25) = -22;
  if ( !of_find_property(*(_QWORD *)(v6 + 744), "interrupt-controller", 0) )
  {
    v37 = 0;
LABEL_56:
    of_platform_populate(*(_QWORD *)(*v4 + 744LL), 0, 0);
    result = v37;
    goto LABEL_57;
  }
  v7 = *(_QWORD *)(a1 + 776);
  v49[2] = 0xFFFFFFFFLL;
  memset(&v49[3], 0, 24);
  v8 = v7 == 0;
  v9 = v7 + 24;
  if ( v8 )
    v9 = 0;
  memset(&v49[8], 0, 32);
  v49[0] = v9;
  v49[1] = 0;
  v49[6] = &i2c_pmic_domain_ops;
  v49[7] = v4;
  v10 = irq_domain_instantiate(v49);
  if ( v10 <= 0xFFFFFFFFFFFFF000LL )
    v11 = v10;
  else
    v11 = 0;
  v4[2] = v11;
  if ( !v11 )
  {
    result = 4294967284LL;
    *(_QWORD *)(a1 + 184) = 0;
    goto LABEL_57;
  }
  v12 = *v4;
  LODWORD(v49[0]) = 0;
  v13 = *(_QWORD *)(v12 + 744);
  if ( !v13 )
  {
    dev_err(v12, "missing device tree\n");
    goto LABEL_62;
  }
  v14 = of_property_count_elems_of_size(*(_QWORD *)(v12 + 744), "qcom,periph-map", 4);
  *((_DWORD *)v4 + 24) = v14;
  if ( (v14 & 0x80000000) == 0 )
  {
    v15 = *v4;
    if ( v14 )
    {
      v16 = devm_kmalloc(v15, 72LL * v14, 3520);
      v4[3] = v16;
      if ( v16 )
      {
        if ( *((int *)v4 + 24) >= 1 )
        {
          v17 = 0;
          v18 = 0;
          while ( 1 )
          {
            u32_index = of_property_read_u32_index(v13, "qcom,periph-map", (unsigned int)v18, v49);
            if ( u32_index < 0 )
              break;
            *(_WORD *)(v4[3] + v17 + 8) = LOWORD(v49[0]) << 8;
            *(_QWORD *)(v4[3] + v17) = v4;
            _mutex_init(v4[3] + v17 + 24, "&chip->periph[i].lock", &i2c_pmic_parse_dt___key);
            ++v18;
            v17 += 72;
            if ( v18 >= *((int *)v4 + 24) )
              goto LABEL_18;
          }
          v46 = u32_index;
          dev_err(*v4, "Couldn't read qcom,periph-map[%d] rc=%d\n", v18, u32_index);
          v21 = v46;
          goto LABEL_67;
        }
LABEL_18:
        of_property_read_string(v13, "pinctrl-names", v4 + 11);
        property = of_find_property(v13, "qcom,enable-toggle-stat", 0);
        v21 = *((_DWORD *)v4 + 24);
        *((_BYTE *)v4 + 106) = property != 0;
        goto LABEL_19;
      }
      v21 = -12;
LABEL_67:
      v37 = v21;
      dev_err(*v4, "Couldn't parse device tree rc=%d\n");
      goto LABEL_75;
    }
    dev_err(v15, "qcom,periph-map must contain at least one address\n");
LABEL_62:
    v21 = -22;
    goto LABEL_67;
  }
  dev_err(*v4, "missing qcom,periph-map property rc=%d\n", v14);
  v21 = *((_DWORD *)v4 + 24);
  if ( v21 < 0 )
    goto LABEL_67;
LABEL_19:
  if ( v21 >= 1 )
  {
    v22 = 0;
    v23 = 0;
    do
    {
      v24 = v4[1];
      v25 = v4[3] + v22;
      v26 = *(unsigned __int16 *)(v25 + 8);
      v27 = regmap_bulk_read(v24, v26 | 0x11u, v25 + 10, 5);
      if ( v27 == -107 && (v27 = regmap_bulk_read(v24, v26 | 0x11u, v25 + 10, 5), v27 == -107) )
      {
        v30 = regmap_bulk_read(v24, v26 | 0x11u, v25 + 10, 5);
        if ( v30 == -107 )
        {
          v31 = regmap_bulk_read(v24, v26 | 0x11u, v25 + 10, 5);
          if ( v31 == -107 )
            v32 = 3;
          else
            v32 = 2;
        }
        else
        {
          v31 = v30;
          v32 = 1;
        }
        printk(&unk_7CEB, v32, v31);
        v27 = v31;
        if ( (v31 & 0x80000000) != 0 )
        {
LABEL_32:
          v33 = v27;
          dev_err(*v4, "Couldn't read irq data rc=%d\n", v27);
          v34 = *v4;
          v35 = "Couldn't determine initial status rc=%d\n";
          goto LABEL_74;
        }
      }
      else if ( (v27 & 0x80000000) != 0 )
      {
        goto LABEL_32;
      }
      ++v23;
      v28 = v4[3] + v22;
      v22 += 72;
      v29 = *(_BYTE *)(v28 + 14);
      *(_DWORD *)(v28 + 15) = *(_DWORD *)(v28 + 10);
      *(_BYTE *)(v28 + 19) = v29;
    }
    while ( v23 < *((int *)v4 + 24) );
  }
  v38 = v4[11];
  if ( !v38 )
    goto LABEL_44;
  v39 = devm_pinctrl_get(*v4);
  v40 = v39;
  if ( v39 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_42;
  v41 = pinctrl_lookup_state(v39, v38);
  if ( v41 >= 0xFFFFFFFFFFFFF001LL )
  {
    devm_pinctrl_put(v40);
    goto LABEL_43;
  }
  v42 = pinctrl_select_state(v40, v41);
  if ( v42 < 0 )
  {
    LODWORD(v41) = v42;
    devm_pinctrl_put(v40);
    v41 = (int)v41;
  }
  else
  {
LABEL_42:
    v41 = v40;
  }
LABEL_43:
  v4[4] = v41;
  if ( v41 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(*v4, "Couldn't select %s pinctrl rc=%ld\n", (const char *)v4[11], v41);
    v37 = *((_DWORD *)v4 + 8);
    goto LABEL_75;
  }
LABEL_44:
  *((_BYTE *)v4 + 104) = 1;
  _mutex_init(v4 + 5, "&chip->irq_complete", &i2c_pmic_probe___key);
  if ( *((_BYTE *)v4 + 106) != 1 || !*((_DWORD *)v4 + 24) )
    goto LABEL_54;
  v43 = regmap_write(v4[1], *(unsigned __int16 *)(v4[3] + 8LL) | 0x15u, 1);
  if ( (v43 & 0x80000000) != 0 )
  {
    v47 = *v4;
    v48 = "Couldn't write to int_en_set rc=%d\n";
LABEL_72:
    v33 = v43;
    dev_err(v47, v48, v43);
    goto LABEL_73;
  }
  v43 = regmap_write(v4[1], *(unsigned __int16 *)(v4[3] + 8LL) | 0xE0u, 128);
  if ( (v43 & 0x80000000) != 0 )
  {
    v47 = *v4;
    v48 = "Couldn't write to int_test rc=%d\n";
    goto LABEL_72;
  }
  v44 = 5;
  while ( 1 )
  {
    v45 = regmap_write(v4[1], *(unsigned __int16 *)(v4[3] + 8LL) | 0xE1u, 1);
    if ( (v45 & 0x80000000) != 0
      || (usleep_range_state(5000, 5500, 2),
          v45 = regmap_write(v4[1], *(unsigned __int16 *)(v4[3] + 8LL) | 0xE1u, 0),
          (v45 & 0x80000000) != 0) )
    {
      v33 = v45;
      dev_err(*v4, "Couldn't write to int_test_val rc=%d\n", v45);
      goto LABEL_53;
    }
    v33 = regmap_write(v4[1], *(unsigned __int16 *)(v4[3] + 8LL) | 0x14u, 1);
    if ( (v33 & 0x80000000) != 0 )
      break;
    usleep_range_state(5000, 5500, 2);
    if ( !--v44 )
      goto LABEL_53;
  }
  dev_err(*v4, "Couldn't write to int_latched_clr rc=%d\n", v33);
LABEL_53:
  regmap_write(v4[1], *(unsigned __int16 *)(v4[3] + 8LL) | 0xE0u, 0);
  regmap_write(v4[1], *(unsigned __int16 *)(v4[3] + 8LL) | 0x16u, 1);
  if ( (v33 & 0x80000000) != 0 )
  {
LABEL_73:
    v34 = *v4;
    v35 = "Couldn't toggle stat rc=%d\n";
LABEL_74:
    v37 = v33;
    dev_err(v34, v35);
    goto LABEL_75;
  }
LABEL_54:
  v37 = devm_request_threaded_irq(
          v1,
          *(unsigned int *)(a1 + 948),
          0,
          i2c_pmic_irq_handler,
          8320,
          "i2c_pmic_stat_irq",
          v4);
  if ( (v37 & 0x80000000) == 0 )
  {
    *((_DWORD *)v4 + 25) = *(_DWORD *)(a1 + 948);
    irq_set_irq_wake();
    goto LABEL_56;
  }
  dev_err(*v4, "Couldn't request irq %d rc=%d\n", *(_DWORD *)(a1 + 948), v37);
LABEL_75:
  if ( v4[2] )
    irq_domain_remove();
  result = v37;
  *(_QWORD *)(a1 + 184) = 0;
LABEL_57:
  _ReadStatusReg(SP_EL0);
  return result;
}
