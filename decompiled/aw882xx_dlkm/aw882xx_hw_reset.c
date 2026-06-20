__int64 __fastcall aw882xx_hw_reset(__int64 a1)
{
  __int64 *v1; // x8
  __int64 v3; // x1
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 *v7; // x8
  __int64 v8; // x1

  v1 = *(__int64 **)(a1 + 64);
  v3 = v1[14];
  if ( !v3 )
    v3 = *v1;
  printk(&unk_26EB3, v3, "aw882xx_hw_reset");
  if ( (*(_DWORD *)(a1 + 28) & 0x80000000) != 0 )
  {
    v7 = *(__int64 **)(a1 + 64);
    v8 = v7[14];
    if ( !v8 )
      v8 = *v7;
    printk(&unk_2603D, v8, "aw882xx_hw_reset");
  }
  else
  {
    v4 = ((__int64 (*)(void))gpio_to_desc)();
    gpiod_set_raw_value_cansleep(v4, 0);
    _const_udelay(4295000);
    v5 = gpio_to_desc(*(unsigned int *)(a1 + 28));
    gpiod_set_raw_value_cansleep(v5, 1);
    _const_udelay(8590000);
  }
  return 0;
}
