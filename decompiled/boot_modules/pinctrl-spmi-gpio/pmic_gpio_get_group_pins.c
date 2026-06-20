__int64 __fastcall pmic_gpio_get_group_pins(__int64 a1, unsigned int a2, _QWORD *a3, _DWORD *a4)
{
  __int64 v4; // x8

  v4 = *(_QWORD *)(a1 + 16);
  *a3 = *(_QWORD *)(v4 + 8) + 24LL * a2;
  *a4 = 1;
  return 0;
}
