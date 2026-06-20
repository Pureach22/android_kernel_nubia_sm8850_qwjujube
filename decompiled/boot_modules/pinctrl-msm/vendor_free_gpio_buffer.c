__int64 vendor_free_gpio_buffer()
{
  if ( !gpio_sleep_status_info )
  {
    kfree(0);
    gpio_sleep_status_info = 0;
  }
  return 0;
}
