__int64 __fastcall qbt_dev_unregister(__int64 a1)
{
  class_destroy(*(_QWORD *)a1);
  printk(&unk_A144, "qbt_dev_unregister");
  cdev_del(a1 + 8);
  cdev_del(a1 + 144);
  printk(&unk_9879, "qbt_dev_unregister");
  unregister_chrdev_region(*(unsigned int *)(a1 + 136), 1);
  unregister_chrdev_region(*(unsigned int *)(a1 + 272), 1);
  return printk(&unk_9F2C, "qbt_dev_unregister");
}
