__int64 __fastcall pmic_gpio_child_to_parent_hwirq(__int64 a1, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  __int64 data; // x8

  data = gpiochip_get_data();
  *a4 = *(unsigned __int8 *)(data + 649) + a2;
  *a5 = a3;
  return 0;
}
