__int64 __fastcall simple_amp_gpio_powerdown(__int64 a1)
{
  return gpiod_direction_output(a1, 1);
}
