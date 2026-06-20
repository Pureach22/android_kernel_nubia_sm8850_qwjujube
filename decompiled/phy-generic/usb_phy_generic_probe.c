unsigned __int64 __fastcall usb_phy_generic_probe(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  _QWORD *v4; // x21
  unsigned __int64 result; // x0
  unsigned int v6; // w0
  unsigned int v7; // w8
  __int64 v8; // x0
  int v9; // w8
  int v10; // w0
  _BOOL8 v11; // x1
  unsigned int v12; // w20
  unsigned int v13; // w20
  int v14; // w0

  v2 = *(_QWORD *)(a1 + 760);
  v3 = devm_kmalloc(a1 + 16, 440, 3520);
  if ( !v3 )
    return 4294967284LL;
  v4 = (_QWORD *)v3;
  result = usb_phy_gen_create_phy(a1 + 16, v3);
  if ( !(_DWORD)result )
  {
    if ( v4[50] )
    {
      v6 = ((__int64 (*)(void))gpiod_to_irq)();
      v7 = devm_request_threaded_irq(a1 + 16, v6, 0, nop_gpio_vbus_thread, 8323, "vbus_detect", v4);
      v8 = v4[50];
      if ( v7 )
      {
        v13 = v7;
        v14 = gpiod_to_irq(v8);
        dev_err(a1 + 16, "can't request irq %i, err: %d\n", v14, v13);
        return v13;
      }
      if ( (unsigned int)gpiod_get_value(v8) )
        v9 = 3;
      else
        v9 = 1;
      *(_DWORD *)(v4[4] + 40LL) = v9;
    }
    v4[33] = usb_gen_phy_init;
    v4[34] = usb_gen_phy_shutdown;
    v10 = usb_add_phy_dev(v4);
    if ( v10 )
    {
      v12 = v10;
      dev_err(a1 + 16, "can't register transceiver, err: %d\n", v10);
      return v12;
    }
    else
    {
      *(_QWORD *)(a1 + 168) = v4;
      v11 = of_find_property(v2, "wakeup-source", 0) != 0;
      device_set_wakeup_capable(a1 + 16, v11);
      return 0;
    }
  }
  return result;
}
