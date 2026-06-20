__int64 __fastcall nubia_get_gpio_status(__int64 a1)
{
  unsigned int v1; // w19
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 result; // x0
  unsigned int v5; // w19

  v1 = a1;
  v2 = gpio_to_desc(a1);
  gpiod_direction_input(v2);
  msleep(1);
  v3 = gpio_to_desc(v1);
  result = gpiod_get_raw_value(v3);
  if ( debug_value == 1 )
  {
    v5 = result;
    printk(byte_7661, (unsigned __int8)result);
    return v5;
  }
  return result;
}
