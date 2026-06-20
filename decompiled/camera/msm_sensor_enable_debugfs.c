__int64 __fastcall msm_sensor_enable_debugfs(__int64 a1)
{
  __int64 v2; // x20
  int v3; // w3
  __int64 dir; // x0
  __int64 v5; // x21
  __int64 result; // x0
  char s[16]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 15);
  if ( !debugfs_base )
  {
    debugfs_base = debugfs_create_dir("msm_sensor", 0);
    if ( !debugfs_base )
      goto LABEL_13;
  }
  if ( (((unsigned int)probe >> *(_DWORD *)(a1 + 52)) & 1) != 0 )
  {
    printk(&unk_43A829);
    goto LABEL_13;
  }
  v2 = _kmalloc_cache_noprof(gpiod_to_irq, 3520, 24);
  if ( !v2 )
  {
    printk(&unk_41BAA6);
    goto LABEL_13;
  }
  v3 = *(_DWORD *)(a1 + 52);
  memset(s, 0, 15);
  snprintf(s, 0xFu, "sensor-%d", v3);
  dir = debugfs_create_dir(s, debugfs_base);
  if ( !dir )
  {
LABEL_12:
    kfree(v2);
LABEL_13:
    result = 4294967284LL;
    goto LABEL_14;
  }
  v5 = dir;
  *(_QWORD *)v2 = a1;
  *(_DWORD *)(v2 + 8) = 2;
  if ( !debugfs_create_file("datatype", 420, dir, v2, &sensor_debugfs_datatype)
    || !debugfs_create_file("addrtype", 420, v5, v2, &sensor_debugfs_addrtype)
    || !debugfs_create_file("address", 420, v5, v2, &sensor_debugfs_address)
    || !debugfs_create_file("value", 420, v5, v2, &sensor_debugfs_value) )
  {
    debugfs_remove(v5);
    goto LABEL_12;
  }
  result = 0;
  probe |= 1 << *(_DWORD *)(a1 + 52);
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
