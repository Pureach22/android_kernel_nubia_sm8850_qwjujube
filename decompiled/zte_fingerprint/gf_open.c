__int64 __fastcall gf_open(__int64 a1, __int64 a2)
{
  _UNKNOWN **v4; // x22
  unsigned int v5; // w20
  unsigned int v7; // w0

  printk(&unk_8AA2);
  mutex_lock(&device_list_lock);
  v4 = &device_list;
  do
  {
    v4 = (_UNKNOWN **)*v4;
    if ( v4 == &device_list )
    {
      printk(&unk_8C44);
      v5 = -6;
      goto LABEL_8;
    }
  }
  while ( *((_DWORD *)v4 - 2) != *(_DWORD *)(a1 + 76) );
  printk(&unk_8AC0);
  ++*((_DWORD *)v4 + 12);
  *(_QWORD *)(a2 + 32) = v4 - 1;
  nonseekable_open(a1, a2);
  printk(&unk_8E2E);
  if ( *((_DWORD *)v4 + 12) == 1 )
  {
    v5 = gf_parse_dts(v4 - 1);
    if ( v5 )
    {
LABEL_6:
      mutex_unlock(&device_list_lock);
      return v5;
    }
    printk(&unk_9488);
    *((_DWORD *)v4 + 16) = gf_irq_num(v4 - 1);
    v7 = request_threaded_irq();
    if ( v7 )
    {
      v5 = v7;
      printk(&unk_8ADA);
      gf_cleanup(v4 - 1);
      goto LABEL_6;
    }
    irq_set_irq_wake(*((unsigned int *)v4 + 16), 1);
    *((_DWORD *)v4 + 17) = 1;
  }
  gf_hw_reset(v4 - 1, 5);
  v5 = 0;
  *((_BYTE *)v4 + 104) = 1;
LABEL_8:
  mutex_unlock(&device_list_lock);
  printk(&unk_904E);
  return v5;
}
