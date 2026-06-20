__int64 __fastcall aw22xxx_i2c_remove(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  unsigned int v4; // w0
  __int64 result; // x0
  int v6; // w8

  v2 = *(_QWORD *)(a1 + 184);
  printk(&unk_130E1, "aw22xxx_i2c_remove");
  remove_proc_entry("driver/colorleds_id", 0);
  printk(&unk_131A4, "aw22xxx_proc_deinit");
  sysfs_remove_group(*(_QWORD *)(v2 + 96), &aw22xxx_attribute_group);
  led_classdev_unregister(v2 + 16);
  v3 = gpio_to_desc(*(unsigned int *)(v2 + 740));
  v4 = gpiod_to_irq(v3);
  devm_free_irq(a1 + 32, v4, v2);
  result = devm_kfree(a1 + 32, v2);
  if ( g_custom_en )
    v6 = 11;
  else
    v6 = 4500;
  g_cfgarray_count = v6;
  return result;
}
