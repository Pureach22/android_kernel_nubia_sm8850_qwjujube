__int64 __fastcall usb_switch_dp_probe(__int64 a1)
{
  __int64 v3; // x0

  printk(&unk_215610, "usb_switch_dp_probe");
  if ( a1 )
  {
    v3 = _kmalloc_cache_noprof(wake_up_process, 3520, 24);
    dp_switch = v3;
    if ( v3 )
    {
      *(_QWORD *)v3 = a1;
      *(_QWORD *)(v3 + 8) = a1 + 16;
      *(_BYTE *)(v3 + 16) = 0;
      if ( (sysfs_create_group(a1 + 16, &usb_switch_dp_attribute_group) & 0x80000000) != 0 )
        dev_err(a1 + 16, "%s error creating sysfs attr files\n", "usb_switch_dp_probe");
      printk(&unk_21919E, "usb_switch_dp_probe");
      return 0;
    }
    else
    {
      dev_err(a1 + 16, "cann't allocate device memory\n");
      return 4294967284LL;
    }
  }
  else
  {
    printk(&unk_21CDD5, "usb_switch_dp_probe");
    return 4294966779LL;
  }
}
