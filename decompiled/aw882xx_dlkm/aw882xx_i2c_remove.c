__int64 __fastcall aw882xx_i2c_remove(__int64 a1)
{
  __int64 v1; // x20
  __int64 *v3; // x8
  __int64 v4; // x1
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned int v7; // w0
  void (__fastcall *v8)(_QWORD); // x8

  v1 = *(_QWORD *)(a1 + 184);
  v3 = *(__int64 **)(v1 + 64);
  v4 = v3[14];
  if ( !v4 )
    v4 = *v3;
  printk(&unk_26EB3, v4, "aw882xx_i2c_remove");
  v5 = gpio_to_desc(*(unsigned int *)(v1 + 32));
  if ( (unsigned int)gpiod_to_irq(v5) )
  {
    v6 = gpio_to_desc(*(unsigned int *)(v1 + 32));
    v7 = gpiod_to_irq(v6);
    devm_free_irq(a1 + 32, v7, v1);
  }
  sysfs_remove_group(a1 + 32, &aw882xx_attribute_group);
  aw882xx_dev_remove(*(_QWORD *)(v1 + 96));
  v8 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v1 + 48) + 24LL);
  if ( *((_DWORD *)v8 - 1) != 1820440776 )
    __break(0x8228u);
  v8(a1 + 32);
  mutex_lock(&g_aw882xx_lock);
  if ( !--g_aw882xx_dev_cnt && g_awinic_cfg )
  {
    vfree();
    g_awinic_cfg = 0;
  }
  return mutex_unlock(&g_aw882xx_lock);
}
