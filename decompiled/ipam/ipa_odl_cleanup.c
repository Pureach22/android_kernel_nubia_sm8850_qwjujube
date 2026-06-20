__int64 ipa_odl_cleanup()
{
  _QWORD *v0; // x20
  __int64 result; // x0

  v0 = (_QWORD *)ipa3_odl_ctx;
  if ( ipa3_odl_ctx )
  {
    ((void (__fastcall *)(_QWORD))ipa_pm_deregister)(*(unsigned int *)(ipa3_odl_ctx + 716));
    device_destroy(v0[20], *((unsigned int *)v0 + 42));
    unregister_chrdev_region(*((unsigned int *)v0 + 42), 1);
    class_destroy(v0[20]);
    device_destroy(*v0, *((unsigned int *)v0 + 2));
    unregister_chrdev_region(*((unsigned int *)v0 + 2), 1);
    class_destroy(*v0);
    result = kfree(ipa3_odl_ctx);
    ipa3_odl_ctx = 0;
  }
  return result;
}
