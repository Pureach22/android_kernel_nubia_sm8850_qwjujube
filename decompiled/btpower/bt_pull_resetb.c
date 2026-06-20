__int64 __fastcall bt_pull_resetb(__int64 a1, unsigned int a2)
{
  __int64 v3; // x0
  __int64 result; // x0

  v3 = gpio_to_desc(a1);
  result = gpiod_direction_output_raw(v3, a2);
  if ( (_DWORD)result )
    return printk(&unk_11A15, "bt_pull_resetb");
  return result;
}
