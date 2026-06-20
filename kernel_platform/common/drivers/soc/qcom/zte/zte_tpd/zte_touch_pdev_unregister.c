void zte_touch_pdev_unregister(void)
{
  __int64 v0 = tpd_cdev;
  if ( v0 && *(_QWORD *)(v0 + 3096) )
  {
    platform_device_unregister(*(struct platform_device **)(v0 + 3096));
    *(_QWORD *)(v0 + 3096) = 0;
  }
}
