__int64 __fastcall lpi_gpio_get(__int64 a1, unsigned int a2)
{
  __int64 data; // x0

  data = gpiochip_get_data();
  return lpi_gpio_read(
           *(unsigned int **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(data + 8) + 16LL) + 8LL) + 24LL * a2 + 16),
           0);
}
