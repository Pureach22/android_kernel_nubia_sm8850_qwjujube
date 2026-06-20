__int64 cleanup_module()
{
  __int64 result; // x0
  __int64 i; // x21
  _QWORD *v2; // x23

  printk(&unk_22A8E);
  if ( mpcie_wq )
    destroy_workqueue(mpcie_wq);
  platform_driver_unregister(msm_pcie_driver);
  result = debugfs_remove(dent_msm_pcie);
  for ( i = 0; i != 5; ++i )
  {
    v2 = (_QWORD *)msm_pcie_dev[i];
    if ( *v2 )
    {
      sysfs_remove_group(*v2 + 16LL, &msm_pcie_debug_attr_group);
      result = sysfs_remove_group(*v2 + 16LL, &msm_aer_stats_attr_group);
    }
  }
  return result;
}
