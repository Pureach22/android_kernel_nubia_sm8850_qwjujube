__int64 __fastcall enableMicroPump(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0

  printk(&unk_85E9, "enableMicroPump", 243);
  result = *(unsigned int *)(a1 + 20);
  if ( (result & 0x80000000) == 0 )
  {
    if ( a2 )
    {
      v7 = gpio_to_desc(result);
      gpiod_direction_output_raw(v7, 1);
      if ( !*(_DWORD *)(a1 + 2084) )
      {
        soft_reset(a1);
        usleep_range_state(450000, 500000, 2);
      }
      awp1921_i2c_write(a1, 19, 16415);
      awp1921_i2c_write(a1, 20, (4 * (*(_WORD *)(a1 + 2088) & 0x1F)) | 2u);
      awp1921_i2c_write(a1, 21, *(unsigned __int16 *)(a1 + 2092));
      awp1921_i2c_write(a1, 6, 4);
      *(_DWORD *)(a1 + 2084) = 1;
      cancel_delayed_work_sync(a1 + 2096);
      queue_delayed_work_on(32, system_wq, a1 + 2096, 15000);
    }
    else
    {
      cancel_delayed_work_sync(a1 + 2096);
      awp1921_i2c_write(a1, 6, 8);
      v5 = *(unsigned int *)(a1 + 20);
      *(_DWORD *)(a1 + 2084) = 0;
      v6 = gpio_to_desc(v5);
      gpiod_direction_output_raw(v6, 0);
    }
    return printk(&unk_8940, "enableMicroPump", 268);
  }
  return result;
}
