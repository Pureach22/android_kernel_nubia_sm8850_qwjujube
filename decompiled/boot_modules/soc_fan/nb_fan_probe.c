__int64 __fastcall nb_fan_probe(__int64 a1)
{
  __int64 v2; // x19
  _QWORD *v3; // x0
  unsigned __int64 v4; // x19
  _QWORD *v6; // x21
  unsigned __int64 v7; // x0
  unsigned int v8; // w19
  int v9; // w0
  int is_enabled; // w0
  __int64 v11; // x21
  unsigned __int64 v12; // x0
  unsigned __int64 v13; // x0
  void *v14; // x0
  __int64 v15; // x3
  int v16; // w0
  int v17; // w0
  __int64 v18; // x8
  __int64 v19; // x1
  __int64 v20; // x0
  int group; // w0
  int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_7CCE, "NB_FAN", "nb_fan_probe", 883);
  v2 = a1 + 16;
  v3 = (_QWORD *)devm_kmalloc(v2, 88, 3520);
  chip = (__int64)v3;
  if ( !v3 )
    goto LABEL_2;
  *v3 = v2;
  v6 = v3;
  v22 = 0;
  v7 = regulator_get(v2, "fan,avdd");
  v6[9] = v7;
  if ( v7 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(*v6 + 744LL), "fan,voltage", &v22, 1, 0) & 0x80000000) != 0 )
    {
      v8 = 2800000;
      printk(&unk_7A59, "NB_FAN", "nb_fan_power_proc", 765);
      v22 = 2800000;
    }
    else
    {
      v8 = v22;
    }
    v9 = regulator_set_voltage(v6[9], v8, v8);
    if ( v9 )
    {
      LODWORD(v4) = v9;
      printk(&unk_81D8, "NB_FAN", "nb_fan_power_proc", 772);
    }
    else
    {
      printk(&unk_7942, "NB_FAN", "nb_fan_power_proc", 775);
      is_enabled = regulator_is_enabled(v6[9]);
      if ( !is_enabled )
      {
        printk(&unk_820F, "NB_FAN", "nb_fan_power_proc", 781);
        goto LABEL_13;
      }
      LODWORD(v4) = is_enabled;
      printk(&unk_7AAA, "NB_FAN", "nb_fan_power_proc", 779);
    }
LABEL_21:
    v14 = &unk_7CF4;
    v15 = 893;
LABEL_27:
    printk(v14, "NB_FAN", "nb_fan_probe", v15);
    goto LABEL_3;
  }
  printk(&unk_8434, "NB_FAN", "nb_fan_power_proc", 758);
  LODWORD(v4) = *((_DWORD *)v6 + 18);
  if ( (_DWORD)v4 )
    goto LABEL_21;
LABEL_13:
  printk(&unk_83A1, "NB_FAN", "nb_fan_probe", 896);
  v11 = chip;
  v12 = devm_pinctrl_get(*(_QWORD *)chip);
  v4 = v12;
  if ( v12 && v12 < 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_7D60, "NB_FAN", "nb_fan_pinctrl_proc", 809);
    v13 = pinctrl_lookup_state(v4, "default");
    *(_QWORD *)(v11 + 80) = v13;
    if ( v13 && v13 < 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_7B8E, "NB_FAN", "nb_fan_pinctrl_proc", 817);
      LODWORD(v4) = pinctrl_select_state(v4, *(_QWORD *)(v11 + 80));
    }
    else
    {
      printk(&unk_7C4E, "NB_FAN", "nb_fan_pinctrl_proc", 814);
      LODWORD(v4) = *(_DWORD *)(v11 + 80);
    }
  }
  else
  {
    printk(&unk_83C9, "NB_FAN", "nb_fan_pinctrl_proc", 806);
  }
  if ( (_DWORD)v4 )
  {
    v14 = &unk_78E0;
    v15 = 901;
    goto LABEL_27;
  }
  printk(&unk_7CA1, "NB_FAN", "nb_fan_probe", 904);
  v16 = nb_fan_parse_dt(chip);
  if ( v16 < 0 )
  {
    LODWORD(v4) = v16;
    v14 = &unk_8487;
    v15 = 909;
    goto LABEL_27;
  }
  printk(&unk_79B2, "NB_FAN", "nb_fan_probe", 912);
  v17 = nb_fan_gpio_proc(chip);
  if ( v17 )
  {
    LODWORD(v4) = v17;
    v14 = &unk_8047;
    v15 = 917;
    goto LABEL_27;
  }
  printk(&unk_8168, "NB_FAN", "nb_fan_probe", 920);
  _mutex_init(chip + 24, "&chip->lock", &nb_fan_probe___key);
  hrtimer_init(*(_QWORD *)(chip + 8) + 40LL, 1, 1);
  v18 = chip;
  *(_QWORD *)(*(_QWORD *)(chip + 8) + 80LL) = fan_hrtimer_hander;
  v19 = kernel_kobj;
  *(_QWORD *)(*(_QWORD *)v18 + 152LL) = v18;
  v20 = kobject_create_and_add("fan", v19);
  *(_QWORD *)(chip + 16) = v20;
  if ( !v20 )
  {
    printk(&unk_8283, "NB_FAN", "nb_fan_probe", 931);
LABEL_2:
    LODWORD(v4) = -12;
    goto LABEL_3;
  }
  group = sysfs_create_group(v20, &chip_attr_group);
  if ( group )
  {
    LODWORD(v4) = group;
    printk(&unk_7D21, "NB_FAN", "nb_fan_probe", 937);
  }
  else
  {
    printk(&unk_8190, "NB_FAN", "nb_fan_probe", 940);
    printk(&unk_84C3, "NB_FAN", "nb_fan_probe", 946);
    LODWORD(v4) = 0;
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v4;
}
