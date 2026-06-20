__int64 __fastcall lpi_gpio_write(__int64 result, unsigned int a2, unsigned int a3)
{
  unsigned int *v3; // x23
  __int64 v5; // x21
  __int64 v7; // x0
  __int64 v8; // x19

  if ( lpi_dev )
  {
    if ( lpi_dev_up == 1 )
    {
      v3 = (unsigned int *)result;
      v5 = *(_QWORD *)(lpi_dev + 152);
      _pm_runtime_resume(lpi_dev, 4);
      mutex_lock(v5 + 720);
      if ( (*(_BYTE *)(v5 + 712) & 1) != 0 )
      {
        writel(a3, *((_QWORD *)v3 + 2) + *v3 + a2);
      }
      else if ( (unsigned int)__ratelimit(&lpi_gpio_write_rtl, "lpi_gpio_write") )
      {
        if ( (unsigned int)__ratelimit(&lpi_gpio_write__rs_38, "lpi_gpio_write") )
          printk(&unk_8298, "lpi_gpio_write");
      }
      v7 = mutex_unlock(v5 + 720);
      v8 = lpi_dev;
      *(_QWORD *)(v8 + 520) = ktime_get_mono_fast_ns(v7);
      return _pm_runtime_suspend(lpi_dev, 13);
    }
  }
  else
  {
    result = __ratelimit(&lpi_gpio_write_rtl, "lpi_gpio_write");
    if ( (_DWORD)result )
    {
      result = __ratelimit(&lpi_gpio_write__rs, "lpi_gpio_write");
      if ( (_DWORD)result )
        return printk(&unk_8443, "lpi_gpio_write");
    }
  }
  return result;
}
