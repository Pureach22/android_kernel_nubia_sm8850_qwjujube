__int64 __fastcall msm_ois_enable_debugfs(__int64 a1)
{
  __int64 v2; // x20
  __int64 dir; // x0
  __int64 v4; // x21
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v7; // [xsp+10h] [xbp-20h]
  _WORD v8[7]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v9; // [xsp+28h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  memset(v8, 0, sizeof(v8));
  *(_QWORD *)s = 0;
  printk(&unk_3DC0CF);
  if ( !ois_debugfs_base )
  {
    ois_debugfs_base = debugfs_create_dir("zte_ois", 0);
    if ( !ois_debugfs_base )
    {
      printk(&unk_43E62B);
      goto LABEL_10;
    }
  }
  if ( (((unsigned int)ois_probe >> *(_DWORD *)(a1 + 100)) & 1) != 0 )
  {
    printk(&unk_43A829);
    goto LABEL_10;
  }
  v2 = _kmalloc_cache_noprof(request_threaded_irq, 3520, 40);
  if ( !v2 )
  {
    printk(&unk_41BAA6);
    goto LABEL_10;
  }
  v7 = 0;
  memset(v8, 0, sizeof(v8));
  *(_QWORD *)s = 0;
  snprintf(s, 0x1Eu, "%s", (const char *)(a1 + 4516));
  dir = debugfs_create_dir(s, ois_debugfs_base);
  if ( !dir )
  {
    printk(&unk_43E62B);
    goto LABEL_9;
  }
  v4 = dir;
  *(_QWORD *)v2 = a1;
  *(_DWORD *)(v2 + 8) = 2;
  *(_DWORD *)(v2 + 24) = 0;
  if ( !debugfs_create_file("datatype", 420, dir, v2, &ois_debugfs_datatype) )
    goto LABEL_20;
  if ( debugfs_create_file("addrtype", 420, v4, v2, &ois_debugfs_addrtype) )
  {
    if ( debugfs_create_file("address", 420, v4, v2, &ois_debugfs_address)
      && debugfs_create_file("value", 420, v4, v2, &ois_debugfs_value)
      && debugfs_create_file(&unk_432D1F, 420, v4, v2, &ois_debugfs_cal) )
    {
      ois_probe |= 1 << *(_DWORD *)(a1 + 100);
      printk(&unk_3D7EB0);
      result = 0;
      goto LABEL_11;
    }
LABEL_20:
    printk(&unk_43E62B);
  }
  debugfs_remove(v4);
LABEL_9:
  kfree(v2);
LABEL_10:
  result = 4294967284LL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
