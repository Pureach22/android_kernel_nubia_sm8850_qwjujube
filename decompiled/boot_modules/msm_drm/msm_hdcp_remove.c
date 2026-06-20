__int64 __fastcall msm_hdcp_remove(__int64 result)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(result + 168);
  if ( v1 )
  {
    sysfs_remove_group(*(_QWORD *)(v1 + 160), &msm_hdcp_fs_attr_group);
    cdev_del(v1 + 16);
    device_destroy(*(_QWORD *)(v1 + 152), *(unsigned int *)(v1 + 8));
    class_destroy(*(_QWORD *)(v1 + 152));
    return unregister_chrdev_region(*(unsigned int *)(v1 + 8), 1);
  }
  return result;
}
