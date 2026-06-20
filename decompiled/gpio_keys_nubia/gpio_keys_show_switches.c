__int64 __fastcall gpio_keys_show_switches(__int64 a1, __int64 a2, __int64 a3)
{
  return ((__int64 (__fastcall *)(_QWORD, __int64, __int64, _QWORD))gpio_keys_attr_show_helper)(
           *(_QWORD *)(a1 + 152),
           a3,
           5,
           0);
}
