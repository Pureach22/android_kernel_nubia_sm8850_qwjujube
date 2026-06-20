unsigned __int64 __fastcall usb_phy_gen_create_phy(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  bool v5; // w21
  unsigned __int64 optional; // x0
  unsigned __int64 v7; // x0
  unsigned __int64 result; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  char v11; // w8
  __int64 v12; // x0
  unsigned __int64 v13; // x0
  unsigned __int64 exclusive; // x0
  __int64 v15; // x9
  unsigned __int64 v16; // x19
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 744);
  v17 = 0;
  if ( v4 )
  {
    if ( (of_property_read_variable_u32_array(v4, "clock-frequency", &v17, 1, 0) & 0x80000000) != 0 )
      v17 = 0;
    v5 = of_find_property(v4, "clocks", 0) == 0;
  }
  else
  {
    v5 = 1;
  }
  optional = devm_gpiod_get_optional(a1, "reset", 0);
  *(_QWORD *)(a2 + 392) = optional;
  if ( optional >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_8;
  v7 = devm_gpiod_get_optional(a1, "vbus-detect", 0);
  *(_QWORD *)(a2 + 400) = v7;
  if ( v7 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_8;
  v9 = *(_QWORD *)(a2 + 392);
  if ( v9 )
    gpiod_direction_output(v9, 1);
  v10 = devm_kmalloc(a1, 96, 3520);
  *(_QWORD *)(a2 + 32) = v10;
  if ( !v10 )
  {
    result = 4294967284LL;
    goto LABEL_9;
  }
  result = devm_clk_get(a1, "main_clk");
  *(_QWORD *)(a2 + 376) = result;
  v11 = result < 0xFFFFFFFFFFFFF001LL || v5;
  if ( (v11 & 1) != 0 )
  {
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      if ( v17 )
      {
        v12 = clk_set_rate();
        if ( (_DWORD)v12 )
        {
          v16 = v12;
          dev_err(a1, "Error setting clock rate\n");
          result = v16;
          goto LABEL_9;
        }
      }
    }
    v13 = devm_regulator_get_optional(a1, "vcc");
    *(_QWORD *)(a2 + 384) = v13;
    if ( v13 >= 0xFFFFFFFFFFFFF001LL && v13 != -19 )
      goto LABEL_8;
    exclusive = devm_regulator_get_exclusive(a1, "vbus");
    *(_QWORD *)(a2 + 408) = exclusive;
    if ( exclusive == -19 )
    {
      *(_QWORD *)(a2 + 408) = 0;
    }
    else if ( exclusive >= 0xFFFFFFFFFFFFF001LL )
    {
LABEL_8:
      result = dev_err_probe(a1);
      goto LABEL_9;
    }
    v15 = *(_QWORD *)(a2 + 32);
    *(_QWORD *)a2 = a1;
    *(_QWORD *)(a2 + 8) = "nop-xceiv";
    *(_QWORD *)(a2 + 296) = nop_set_suspend;
    result = 0;
    *(_QWORD *)(a2 + 368) = a1;
    *(_DWORD *)(a2 + 20) = 1;
    *(_DWORD *)(v15 + 40) = 0;
    *(_QWORD *)(*(_QWORD *)(a2 + 32) + 16LL) = a2;
    *(_QWORD *)(*(_QWORD *)(a2 + 32) + 48LL) = nop_set_host;
    *(_QWORD *)(*(_QWORD *)(a2 + 32) + 56LL) = nop_set_peripheral;
    *(_QWORD *)(*(_QWORD *)(a2 + 32) + 64LL) = nop_set_vbus;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
