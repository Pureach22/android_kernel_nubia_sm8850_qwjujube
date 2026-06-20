__int64 __fastcall nop_gpio_vbus_thread(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  int value; // w0
  int v5; // w8
  _BOOL8 v6; // x1

  v2 = *(_QWORD *)(a2 + 32);
  value = gpiod_get_value(*(_QWORD *)(a2 + 400));
  if ( value != *(_DWORD *)(a2 + 432) )
  {
    *(_DWORD *)(a2 + 432) = value;
    if ( value )
      v5 = 3;
    else
      v5 = 1;
    v6 = value != 0;
    *(_DWORD *)(v2 + 40) = v5;
    *(_DWORD *)(a2 + 24) = v6;
    atomic_notifier_call_chain(a2 + 224, v6, *(_QWORD *)(v2 + 32));
  }
  return 1;
}
