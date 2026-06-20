__int64 __fastcall lpg_brightness_mc_set(__int64 a1, unsigned int a2)
{
  _QWORD *v2; // x20

  v2 = (_QWORD *)(a1 - 456);
  mutex_lock(*(_QWORD *)(a1 - 456) + 16LL);
  led_mc_calc_color_components(a1, a2);
  lpg_brightness_set(v2, a1, *(_QWORD *)(a1 + 456));
  mutex_unlock(*v2 + 16LL);
  return 0;
}
