__int64 init_module()
{
  unsigned int v0; // w19

  v0 = class_register(&hwmon_class);
  if ( v0 )
    printk(&unk_9825);
  return v0;
}
