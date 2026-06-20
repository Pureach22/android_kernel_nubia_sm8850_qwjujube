__int64 __fastcall gpio_keys_store_disabled_switches(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0

  result = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))gpio_keys_attr_store_helper)(*(_QWORD *)(a1 + 152), a3, 5);
  if ( !result )
    return a4;
  return result;
}
