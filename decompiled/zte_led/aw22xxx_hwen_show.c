__int64 __fastcall aw22xxx_hwen_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v4; // x0
  int raw_value; // w0

  v4 = gpio_to_desc(*(unsigned int *)(*(_QWORD *)(a1 + 152) + 720LL));
  raw_value = gpiod_get_raw_value(v4);
  return snprintf(a3, 0x1000u, "hwen=%d\n", raw_value);
}
