unsigned int *cleanup_module()
{
  unsigned int *result; // x0
  int v6; // w8

  cdev_del(qword_7B58);
  device_destroy(sync_dev, (unsigned int)dword_7B48);
  unregister_chrdev_region((unsigned int)dword_7B48, 1);
  result = (unsigned int *)class_destroy(sync_dev);
  if ( qword_7B90 )
  {
    result = (unsigned int *)(qword_7B90 + 56);
    __asm { PRFM            #0x11, [X0] }
    do
      v6 = __ldxr(result);
    while ( __stlxr(v6 - 1, result) );
    if ( v6 == 1 )
    {
      __dmb(9u);
      return (unsigned int *)dma_fence_release(result);
    }
    else if ( v6 <= 0 )
    {
      return (unsigned int *)refcount_warn_saturate(result, 3);
    }
  }
  return result;
}
