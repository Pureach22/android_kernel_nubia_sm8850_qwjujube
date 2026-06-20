__int64 __fastcall ois_debugfs_cal_g(__int64 a1, __int64 *a2)
{
  __int64 v2; // x21

  v2 = *(_QWORD *)a1;
  if ( !strncmp((const char *)(*(_QWORD *)a1 + 4516LL), "ois_ov64b40_qwbarley", 0x14u) )
  {
    printk(&unk_43A877);
    ois_dw9784_debugfs_cal_g(a1, a2);
  }
  else if ( !strncmp((const char *)(v2 + 4516), "ois_dw9785_qwjujube", 0x13u) )
  {
    printk(&unk_43A877);
    ois_dw9785_debugfs_cal_g(a1, a2);
  }
  else
  {
    printk(&unk_40FBD7);
  }
  printk(&unk_3F8383);
  return 0;
}
