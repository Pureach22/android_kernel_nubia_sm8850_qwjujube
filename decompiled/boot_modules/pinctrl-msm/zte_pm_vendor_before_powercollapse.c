void zte_pm_vendor_before_powercollapse()
{
  void *v0; // x19

  if ( gpio_debug_mask )
  {
    v0 = (void *)gpio_sleep_status_info;
    if ( !gpio_sleep_status_info )
    {
      printk(&unk_D702, "zte_pm_vendor_before_powercollapse");
      printk(&unk_D490, "zte_pm_vendor_before_powercollapse");
      v0 = (void *)_kmalloc_large_noprof(30000, 3264);
      gpio_sleep_status_info = (__int64)v0;
    }
    memset(v0, 0, 0xCC0u);
    msm_dump_gpios(0, 0, (__int64)v0);
  }
}
