__int64 __fastcall cam_get_gpio_counts(__int64 a1)
{
  return of_count_phandle_with_args(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 744LL), "gpios", "#gpio-cells");
}
