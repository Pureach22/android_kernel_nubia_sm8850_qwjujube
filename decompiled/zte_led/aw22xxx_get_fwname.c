__int64 __fastcall aw22xxx_get_fwname(unsigned int a1)
{
  int v1; // w22
  int v3; // w20
  unsigned int v4; // w21
  const char *v6; // x19
  size_t v7; // x2
  __int64 v8; // x0

  v1 = HIBYTE(a1);
  printk(&unk_13F1B, "aw22xxx_get_fwname");
  v3 = (a1 >> 12) & 0xFFF;
  printk(&unk_12981, "aw22xxx_get_fwname");
  v4 = a1 & 0xFFF;
  printk(&unk_13D92, "aw22xxx_get_fwname");
  if ( v1 > 1 )
  {
    if ( v1 == 2 )
    {
      sprintf(aw22xxx_dyn_name, "aw_touch%x_%x.bin", v3, v4);
      return printk(&unk_12EA6, "aw22xxx_get_fwname");
    }
    if ( v1 == 3 )
    {
      sprintf(aw22xxx_dyn_name, "aw_fan%x_%x.bin", v3, v4);
      return printk(&unk_12EA6, "aw22xxx_get_fwname");
    }
    return printk(&unk_13506, "aw22xxx_get_fwname");
  }
  if ( v1 )
  {
    if ( v1 == 1 )
    {
      sprintf(aw22xxx_dyn_name, "aw_cfg%x_%x.bin", v3, v4);
      return printk(&unk_12EA6, "aw22xxx_get_fwname");
    }
    return printk(&unk_13506, "aw22xxx_get_fwname");
  }
  if ( v4 >= 0xC )
    return printk(&unk_13506, "aw22xxx_get_fwname");
  v6 = *(const char **)(aw22xxx_cfg_name + 8LL * a1);
  v7 = strlen(v6) + 1;
  if ( v7 < 0x41 )
  {
    memcpy(aw22xxx_dyn_name, v6, v7);
    return printk(&unk_12EA6, "aw22xxx_get_fwname");
  }
  v8 = _fortify_panic(31, 64);
  return aw22xxx_cfg_update_wait_from_dyn_name(v8);
}
