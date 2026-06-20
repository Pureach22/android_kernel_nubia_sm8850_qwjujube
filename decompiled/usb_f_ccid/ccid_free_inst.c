__int64 __fastcall ccid_free_inst(__int64 result)
{
  __int64 v1; // x21
  unsigned int v2; // w20
  __int64 v3; // x19
  __int64 v4; // x23
  unsigned int v5; // w20

  v1 = *(_QWORD *)(result + 176);
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 456);
    v3 = result;
    device_destroy(ccid_class, v2);
    cdev_del(v1 + 328);
    ida_free(&ccid_ida, v2 & 0xFFFFF);
    v4 = *(_QWORD *)(v3 + 176);
    v5 = *(_DWORD *)(v4 + 688);
    device_destroy(ccid_class, v5);
    cdev_del(v4 + 560);
    ida_free(&ccid_ida, v5 & 0xFFFFF);
    mutex_lock(&ccid_ida_lock);
    if ( !qword_140 )
    {
      if ( major )
      {
        unregister_chrdev_region((unsigned int)(major << 20), 4);
        major = 0;
      }
      if ( ccid_class )
      {
        class_destroy();
        ccid_class = 0;
      }
    }
    mutex_unlock(&ccid_ida_lock);
    kfree(*(_QWORD *)(v3 + 176));
    return kfree(v3);
  }
  return result;
}
