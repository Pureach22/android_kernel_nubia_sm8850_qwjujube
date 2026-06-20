__int64 __fastcall bt_resetb_operation(unsigned int a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x1
  __int64 v5; // x0
  __int64 result; // x0

  printk(&unk_10F52, a2);
  v3 = gpio_to_desc(a1);
  if ( (unsigned int)gpiod_direction_output_raw(v3, 0) )
    return printk(&unk_11A15, "bt_pull_resetb");
  msleep(20);
  printk(&unk_11D55, v4);
  v5 = gpio_to_desc(a1);
  result = gpiod_direction_output_raw(v5, 1);
  if ( (_DWORD)result )
    return printk(&unk_11A15, "bt_pull_resetb");
  return result;
}
