__int64 __fastcall aw882xx_cali_deinit(__int64 a1)
{
  __int64 **v2; // x20
  __int64 v3; // x1
  __int64 v4; // x1

  if ( *(_BYTE *)(a1 + 1) == 1 )
  {
    v2 = (__int64 **)(a1 - 536);
    sysfs_remove_group(*(_QWORD *)(a1 - 536), &aw_cali_attr_group);
    v3 = (*v2)[14];
    if ( !v3 )
      v3 = **v2;
    printk(&unk_2474D, v3, "aw_cali_attr_deinit");
    class_remove_file_ns(&aw_cali_class, &class_att_re_range, 0);
    class_remove_file_ns(&aw_cali_class, &class_attr_re25_calib, 0);
    class_remove_file_ns(&aw_cali_class, &class_attr_f0_calib, 0);
    class_remove_file_ns(&aw_cali_class, &class_attr_cali_time, 0);
    class_remove_file_ns(&aw_cali_class, &class_attr_re_show, 0);
    class_remove_file_ns(&aw_cali_class, &class_attr_f0_show, 0);
    class_unregister(&aw_cali_class);
    v4 = (*v2)[14];
    if ( !v4 )
      v4 = **v2;
    printk(&unk_25226, v4, "aw_cali_class_attr_deinit");
  }
  mutex_lock(&g_cali_lock);
  if ( g_misc_dev )
  {
    misc_deregister();
    g_misc_dev = 0;
  }
  return mutex_unlock(&g_cali_lock);
}
