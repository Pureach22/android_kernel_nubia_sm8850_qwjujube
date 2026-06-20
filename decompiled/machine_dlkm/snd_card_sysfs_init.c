__int64 snd_card_sysfs_init()
{
  unsigned int v0; // w0
  unsigned int file_ns; // w19
  __int64 v3; // [xsp+8h] [xbp-18h] BYREF
  __int16 v4; // [xsp+10h] [xbp-10h]
  __int64 v5; // [xsp+18h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)"snd_card";
  v4 = 0;
  snd_card_pdata = _kmalloc_cache_noprof(_stack_chk_fail, 3520, 104);
  v0 = kobject_init_and_add();
  if ( (v0 & 0x80000000) != 0 )
  {
    file_ns = v0;
    printk(&unk_131E2, "snd_card_sysfs_init", &v3);
  }
  else
  {
    file_ns = sysfs_create_file_ns(snd_card_pdata, &card_state_attr, 0);
    if ( (file_ns & 0x80000000) != 0 )
    {
      printk(&unk_14110, "snd_card_sysfs_init", &v3);
      kobject_put(snd_card_pdata);
    }
  }
  _ReadStatusReg(SP_EL0);
  return file_ns;
}
