__int64 __fastcall gpio_status_debug_init(__int64 a1)
{
  __int64 dir; // x0
  unsigned __int64 v3; // x20
  __int64 v4; // x21
  unsigned __int64 v5; // x27
  unsigned __int64 v6; // x22
  __int64 v7; // x0
  __int64 v8; // x28
  __int64 result; // x0
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  chip_debug = a1;
  dir = debugfs_create_dir("zte_gpio", 0);
  debugfs_base = dir;
  if ( dir
    && debugfs_create_file("dump_gpios", 292, dir, 0, &list_gpios_fops)
    && debugfs_create_file("dump_sleep_gpios", 292, debugfs_base, 0, &list_sleep_gpios_fops) )
  {
    v3 = 4LL * *(unsigned __int16 *)(a1 + 172);
    v4 = _kmalloc_noprof(v3, 3520);
    if ( *(_WORD *)(a1 + 172) )
    {
      v5 = 0;
      v6 = 0;
      while ( 1 )
      {
        v10[0] = 0;
        if ( v3 <= v5 )
          __break(1u);
        *(_DWORD *)(v4 + v5) = v6;
        snprintf((char *)v10, 7u, "%d", v6);
        v7 = debugfs_create_dir(v10, debugfs_base);
        if ( !v7 )
          goto LABEL_18;
        v8 = v7;
        if ( !debugfs_create_file("direction", 420, v7, v4 + v5, &gpio_direction_fops)
          || !debugfs_create_file("level", 420, v8, v4 + v5, &gpio_level_fops)
          || !debugfs_create_file("drv_strength", 420, v8, v4 + v5, &gpio_drv_fops)
          || !debugfs_create_file("func_sel", 420, v8, v4 + v5, &gpio_func_sel_fops)
          || !debugfs_create_file("pull", 420, v8, v4 + v5, &gpio_pull_fops)
          || !debugfs_create_file("int_enable", 292, v8, v4 + v5, &gpio_int_enable_fops)
          || !debugfs_create_file("int_owner", 420, v8, v4 + v5, &gpio_int_owner_fops)
          || !debugfs_create_file("int_dect_type", 292, v8, v4 + v5, &gpio_int_dect_fops) )
        {
          break;
        }
        result = 0;
LABEL_19:
        ++v6;
        v5 += 4LL;
        if ( v6 >= *(unsigned __int16 *)(a1 + 172) )
          goto LABEL_22;
      }
      debugfs_remove(v8);
LABEL_18:
      result = 4294967284LL;
      goto LABEL_19;
    }
    result = 0;
  }
  else
  {
    result = 4294967284LL;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
