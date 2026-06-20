__int64 __fastcall cam_get_named_gpio(__int64 a1, unsigned int a2)
{
  return of_get_named_gpio(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 744LL), "gpios", a2);
}
