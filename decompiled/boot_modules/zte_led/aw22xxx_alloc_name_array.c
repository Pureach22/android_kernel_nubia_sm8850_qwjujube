__int64 aw22xxx_alloc_name_array()
{
  __int64 v0; // x20
  __int64 v1; // x8
  char **v2; // x0
  __int64 v3; // x10
  __int64 result; // x0
  __int64 v5; // x10
  __int64 v6; // x9
  __int64 v7; // x15
  __int64 v8; // x10
  __int64 v9; // x20

  aw22xxx_cfg_name = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3264, 88);
  if ( !aw22xxx_cfg_name )
    return printk(&unk_12B27, "aw22xxx_alloc_name_array");
  v0 = 0;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v1 = _kmalloc_cache_noprof(snprintf, 3264, 64);
    v2 = (char **)aw22xxx_cfg_name;
    *(_QWORD *)(aw22xxx_cfg_name + 8 * v0) = v1;
    if ( !v1 )
      break;
    if ( ++v0 == 11 )
    {
      strcpy(*v2, "m_led_off.bin");
      v3 = aw22xxx_cfg_name;
      result = *(_QWORD *)"l_rgb_blue.bin";
      strcpy(*(char **)(aw22xxx_cfg_name + 8), "fan_led_on.bin");
      strcpy(*(char **)(v3 + 16), "fan_led_off.bin");
      v5 = aw22xxx_cfg_name;
      strcpy(*(char **)(aw22xxx_cfg_name + 24), "touch_led_off.bin");
      strcpy(*(char **)(v5 + 32), "lamps_init.bin");
      v6 = aw22xxx_cfg_name;
      strcpy(*(char **)(aw22xxx_cfg_name + 40), "nubia_all_rgb_red.bin");
      strcpy(*(char **)(v6 + 48), "nubia_all_rgb_green.bin");
      v7 = aw22xxx_cfg_name;
      strcpy(*(char **)(aw22xxx_cfg_name + 56), "nubia_all_rgb_blue.bin");
      strcpy(*(char **)(v7 + 64), "nubia_all_rgb_red.bin");
      v8 = aw22xxx_cfg_name;
      strcpy(*(char **)(aw22xxx_cfg_name + 72), "nubia_all_rgb_green.bin");
      strcpy(*(char **)(v8 + 80), "nubia_all_rgb_blue.bin");
      return result;
    }
  }
  if ( v0 )
  {
    v9 = v0 + 1;
    do
      kfree(*(_QWORD *)(aw22xxx_cfg_name + 8LL * (unsigned int)(v9-- - 2)));
    while ( v9 > 1 );
    v2 = (char **)aw22xxx_cfg_name;
  }
  kfree(v2);
  return printk(&unk_12B27, "aw22xxx_alloc_name_array");
}
