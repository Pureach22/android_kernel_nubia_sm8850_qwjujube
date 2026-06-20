__int64 __fastcall lpi_gpio_read(unsigned int *a1, unsigned int a2)
{
  __int64 v4; // x21
  unsigned int v5; // w22
  __int64 result; // x0
  __int64 v7; // x0
  __int64 v8; // x19

  if ( lpi_dev )
  {
    if ( (lpi_dev_up & 1) != 0 )
    {
      v4 = *(_QWORD *)(lpi_dev + 152);
      _pm_runtime_resume(lpi_dev, 4);
      mutex_lock(v4 + 720);
      if ( (*(_BYTE *)(v4 + 712) & 1) != 0 )
      {
        v5 = readl(*((_QWORD *)a1 + 2) + *a1 + a2);
        if ( (v5 & 0x80000000) != 0 )
        {
          if ( (unsigned int)__ratelimit(&lpi_gpio_read__rs_36, "lpi_gpio_read") )
            printk(&unk_852E, "lpi_gpio_read");
        }
      }
      else
      {
        if ( (unsigned int)__ratelimit(&lpi_gpio_read_rtl, "lpi_gpio_read")
          && (unsigned int)__ratelimit(&lpi_gpio_read__rs_34, "lpi_gpio_read") )
        {
          printk(&unk_8298, "lpi_gpio_read");
        }
        v5 = -22;
      }
      v7 = mutex_unlock(v4 + 720);
      v8 = lpi_dev;
      *(_QWORD *)(v8 + 520) = ktime_get_mono_fast_ns(v7);
      _pm_runtime_suspend(lpi_dev, 13);
      return v5;
    }
    else
    {
      result = __ratelimit(&lpi_gpio_read_rtl, "lpi_gpio_read");
      if ( (_DWORD)result )
      {
        result = __ratelimit(&lpi_gpio_read__rs_32, "lpi_gpio_read");
        if ( (_DWORD)result )
        {
          printk(&unk_857A, "lpi_gpio_read");
          return 0;
        }
      }
    }
  }
  else if ( (unsigned int)__ratelimit(&lpi_gpio_read_rtl, "lpi_gpio_read")
         && (unsigned int)__ratelimit(&lpi_gpio_read__rs, "lpi_gpio_read") )
  {
    printk(&unk_8443, "lpi_gpio_read");
    return 4294967274LL;
  }
  else
  {
    return 4294967274LL;
  }
  return result;
}
