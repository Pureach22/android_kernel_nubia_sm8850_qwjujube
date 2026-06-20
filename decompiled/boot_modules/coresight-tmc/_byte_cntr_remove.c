__int64 __fastcall byte_cntr_remove(__int64 a1)
{
  device_destroy(*(_QWORD *)(a1 + 136), *(unsigned int *)(a1 + 128));
  class_destroy(*(_QWORD *)(a1 + 136));
  return unregister_chrdev_region(*(unsigned int *)(a1 + 128), 1);
}
