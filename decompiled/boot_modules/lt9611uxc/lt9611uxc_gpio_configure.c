__int64 __fastcall lt9611uxc_gpio_configure(unsigned int *a1, char a2)
{
  unsigned int v3; // w0
  __int64 v4; // x0
  unsigned int v5; // w0
  unsigned int v6; // w0
  __int64 v7; // x0
  unsigned int v8; // w0
  unsigned int v9; // w0
  __int64 v10; // x0
  unsigned int v11; // w0
  __int64 v12; // x0
  unsigned int v13; // w0
  __int64 v14; // x0
  unsigned int v15; // w0
  __int64 v16; // x0
  unsigned int v17; // w0
  __int64 v18; // x0
  unsigned int v19; // w0
  unsigned int v20; // w0
  __int64 v21; // x0
  __int64 result; // x0
  unsigned int v23; // w20
  unsigned int v24; // w19
  void *v25; // x0
  void *v26; // x0
  void *v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0

  if ( (a2 & 1) != 0 )
  {
    if ( (a1[785] & 0x80000000) == 0 )
    {
      v3 = ((__int64 (*)(void))gpio_request)();
      if ( v3 )
      {
        v23 = v3;
        v25 = &unk_B556;
        goto LABEL_40;
      }
      v4 = gpio_to_desc(a1[785]);
      v5 = gpiod_direction_output_raw(v4, 0);
      if ( v5 )
      {
        v23 = v5;
        v27 = &unk_A6F8;
        goto LABEL_43;
      }
    }
    if ( (a1[786] & 0x80000000) == 0 )
    {
      v6 = ((__int64 (*)(void))gpio_request)();
      if ( v6 )
      {
        v23 = v6;
        v25 = &unk_ACD3;
        goto LABEL_40;
      }
      v7 = gpio_to_desc(a1[786]);
      v8 = gpiod_direction_output_raw(v7, 0);
      if ( v8 )
      {
        v23 = v8;
        v27 = &unk_A61B;
        goto LABEL_43;
      }
    }
    v9 = gpio_request(a1[782], "lt9611-reset-gpio");
    if ( v9 )
    {
      v24 = v9;
      printk(&unk_AF29, "lt9611uxc_gpio_configure");
      return v24;
    }
    v10 = gpio_to_desc(a1[782]);
    v11 = gpiod_direction_output_raw(v10, 0);
    if ( v11 )
    {
      v23 = v11;
      v25 = &unk_AFE1;
    }
    else
    {
      v12 = a1[784];
      if ( (v12 & 0x80000000) != 0 )
      {
LABEL_13:
        v16 = a1[783];
        if ( (v16 & 0x80000000) != 0 )
          goto LABEL_16;
        v17 = gpio_request(v16, "lt9611-hdmi-ps-gpio");
        if ( !v17 )
        {
          v18 = gpio_to_desc(a1[783]);
          v19 = gpiod_direction_input(v18);
          if ( v19 )
          {
            v23 = v19;
            v26 = &unk_A586;
            goto LABEL_45;
          }
LABEL_16:
          v20 = gpio_request(a1[781], "lt9611-irq-gpio");
          if ( !v20 )
          {
            v21 = gpio_to_desc(a1[781]);
            result = gpiod_direction_input(v21);
            if ( !(_DWORD)result )
              return result;
            v23 = result;
            printk(&unk_A7BB, "lt9611uxc_gpio_configure");
            gpio_free(a1[781]);
            goto LABEL_46;
          }
          v23 = v20;
          v26 = &unk_AA1E;
LABEL_45:
          printk(v26, "lt9611uxc_gpio_configure");
LABEL_46:
          v28 = a1[783];
          if ( (v28 & 0x80000000) == 0 )
            gpio_free(v28);
          goto LABEL_48;
        }
        v23 = v17;
        v27 = &unk_A64E;
LABEL_43:
        printk(v27, "lt9611uxc_gpio_configure");
LABEL_48:
        v29 = a1[784];
        if ( (v29 & 0x80000000) == 0 )
          gpio_free(v29);
        goto LABEL_50;
      }
      v13 = gpio_request(v12, "lt9611-hdmi-en-gpio");
      if ( !v13 )
      {
        v14 = gpio_to_desc(a1[784]);
        v15 = gpiod_direction_output_raw(v14, 1);
        if ( v15 )
        {
          v23 = v15;
          v27 = &unk_A9F2;
          goto LABEL_43;
        }
        goto LABEL_13;
      }
      v23 = v13;
      v25 = &unk_B3D9;
    }
LABEL_40:
    printk(v25, "lt9611uxc_gpio_configure");
LABEL_50:
    gpio_free(a1[782]);
    return v23;
  }
  if ( (a1[781] & 0x80000000) == 0 )
    ((void (*)(void))gpio_free)();
  if ( (a1[783] & 0x80000000) == 0 )
    ((void (*)(void))gpio_free)();
  if ( (a1[784] & 0x80000000) == 0 )
    ((void (*)(void))gpio_free)();
  if ( (a1[782] & 0x80000000) == 0 )
    ((void (*)(void))gpio_free)();
  if ( (a1[786] & 0x80000000) == 0 )
    ((void (*)(void))gpio_free)();
  if ( (a1[785] & 0x80000000) == 0 )
    ((void (*)(void))gpio_free)();
  return 0;
}
