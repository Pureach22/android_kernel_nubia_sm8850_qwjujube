__int64 init_module()
{
  const char *v0; // x19
  void *v1; // x0
  int v2; // w8
  int v3; // w0

  printk("init parse_cmdline_and_export drv!\n");
  printk(&unk_6563);
  v0 = boot_mode;
  if ( !strncmp(boot_mode, "ffbm-99", 7u) )
  {
    v1 = &unk_6493;
    v2 = 1;
  }
  else if ( !strncmp(v0, "ffbm-02", 7u) )
  {
    v1 = &unk_64FC;
    v2 = 5;
  }
  else if ( !strncmp(v0, "recovery", 8u) )
  {
    v1 = &unk_6475;
    v2 = 4;
  }
  else
  {
    v3 = strncmp(v0, "charger", 7u);
    if ( v3 )
      v2 = 0;
    else
      v2 = 3;
    if ( v3 )
      v1 = &unk_64B4;
    else
      v1 = &unk_651E;
  }
  g_boot_mode = v2;
  printk(v1);
  printk(&unk_654A);
  return 0;
}
