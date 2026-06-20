__int64 __fastcall aw22xxx_parse_led_cdev(_QWORD *a1, __int64 a2)
{
  __int64 next_child; // x0
  __int64 v5; // x21
  int string; // w0
  int variable_u32_array; // w0
  int v8; // w0
  int v9; // w0
  __int64 v10; // x0
  int v11; // w0
  __int64 result; // x0

  printk(&unk_130E1, "aw22xxx_parse_led_cdev");
  next_child = of_get_next_child(a2, 0);
  if ( next_child )
  {
    v5 = next_child;
    while ( 1 )
    {
      string = of_property_read_string(v5, "aw22xxx,name", a1 + 2);
      if ( string < 0 )
        return dev_err(a1[1], "Failure reading led name, ret = %d\n", string);
      variable_u32_array = of_property_read_variable_u32_array(v5, "aw22xxx,imax", a1 + 94, 1, 0);
      if ( variable_u32_array < 0 )
        return dev_err(a1[1], "Failure reading imax, ret = %d\n", variable_u32_array);
      v8 = of_property_read_variable_u32_array(v5, "aw22xxx,brightness", a1 + 3, 1, 0);
      if ( v8 < 0 )
        return dev_err(a1[1], "Failure reading brightness, ret = %d\n", v8);
      v9 = of_property_read_variable_u32_array(v5, "aw22xxx,max_brightness", (char *)a1 + 28, 1, 0);
      if ( v9 < 0 )
        return dev_err(a1[1], "Failure reading max brightness, ret = %d\n", v9);
      v5 = of_get_next_child(a2, v5);
      if ( !v5 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    a1[58] = 0xFFFFFFFE00000LL;
    a1[59] = a1 + 59;
    a1[60] = a1 + 59;
    a1[61] = aw22xxx_brightness_work;
    a1[62] = 0xFFFFFFFE00000LL;
    a1[63] = a1 + 63;
    a1[64] = a1 + 63;
    v10 = a1[1];
    a1[65] = aw22xxx_task_work;
    a1[6] = aw22xxx_set_brightness;
    v11 = led_classdev_register_ext(v10, a1 + 2, 0);
    if ( v11 )
    {
      return dev_err(a1[1], "unable to register led ret=%d\n", v11);
    }
    else
    {
      result = sysfs_create_group(a1[12], &aw22xxx_attribute_group);
      if ( (_DWORD)result )
      {
        dev_err(a1[1], "led sysfs ret: %d\n", result);
        return led_classdev_unregister(a1 + 2);
      }
    }
  }
  return result;
}
