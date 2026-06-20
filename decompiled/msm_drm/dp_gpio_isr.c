__int64 __fastcall dp_gpio_isr(__int64 a1, __int64 *a2)
{
  __int64 v3; // x0
  int raw_value_cansleep; // w0
  bool v5; // w8
  __int64 v6; // x1
  __int64 result; // x0
  int v8; // w20
  __int64 v9; // x0
  __int64 v10; // x8
  void (__fastcall *v11)(_QWORD); // x8
  __int64 v12; // x0

  if ( !a2 )
    return 0;
  v3 = gpio_to_desc(*((unsigned int *)a2 + 20));
  raw_value_cansleep = gpiod_get_raw_value_cansleep(v3);
  v5 = raw_value_cansleep != 0;
  if ( (*((_BYTE *)a2 + 236) & 1) == 0 && raw_value_cansleep )
  {
    v6 = system_wq;
    *((_BYTE *)a2 + 236) = 1;
LABEL_5:
    queue_delayed_work_on(32, v6, a2 + 15, 0);
    return 1;
  }
  if ( !*((_BYTE *)a2 + 236) )
    return 1;
  v8 = 50;
  while ( !v5 )
  {
    usleep_range_state(2000, 2100, 2);
    v9 = gpio_to_desc(*((unsigned int *)a2 + 20));
    v5 = (unsigned int)gpiod_get_raw_value_cansleep(v9) != 0;
    if ( !--v8 )
    {
      *((_BYTE *)a2 + 236) = 0;
      v6 = system_wq;
      goto LABEL_5;
    }
  }
  v10 = a2[28];
  result = 1;
  *((_BYTE *)a2 + 17) = 1;
  if ( v10 )
  {
    v11 = *(void (__fastcall **)(_QWORD))(v10 + 16);
    if ( v11 )
    {
      v12 = *a2;
      if ( *((_DWORD *)v11 - 1) != 711998475 )
        __break(0x8228u);
      v11(v12);
      return 1;
    }
  }
  return result;
}
