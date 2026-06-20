__int64 cleanup_module()
{
  __int64 result; // x0

  cvp_dsp_device_exit();
  kmem_cache_destroy(*(_QWORD *)(cvp_driver + 72));
  kmem_cache_destroy(*(_QWORD *)(cvp_driver + 88));
  kmem_cache_destroy(*(_QWORD *)(cvp_driver + 104));
  kmem_cache_destroy(*(_QWORD *)(cvp_driver + 120));
  platform_driver_unregister(msm_cvp_driver);
  debugfs_remove(*(_QWORD *)(cvp_driver + 56));
  result = kfree(cvp_driver);
  cvp_driver = 0;
  return result;
}
