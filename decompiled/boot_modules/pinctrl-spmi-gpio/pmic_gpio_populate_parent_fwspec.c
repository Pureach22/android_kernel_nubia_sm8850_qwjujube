__int64 __fastcall pmic_gpio_populate_parent_fwspec(__int64 a1, __int64 a2, int a3, int a4)
{
  __int64 data; // x8
  __int64 v10; // x9

  data = gpiochip_get_data();
  v10 = *(_QWORD *)(*(_QWORD *)(a1 + 312) + 104LL);
  *(_DWORD *)(a2 + 8) = 4;
  *(_QWORD *)a2 = v10;
  *(_DWORD *)(a2 + 12) = *(unsigned __int8 *)(data + 648);
  *(_DWORD *)(a2 + 16) = a3;
  *(_DWORD *)(a2 + 24) = a4;
  return 0;
}
