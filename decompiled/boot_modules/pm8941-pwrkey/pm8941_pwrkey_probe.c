__int64 __fastcall pm8941_pwrkey_probe(_QWORD *a1)
{
  _QWORD *v2; // x19
  __int64 v3; // x0
  __int64 result; // x0
  bool v5; // w24
  _QWORD *v6; // x0
  _QWORD *v7; // x21
  __int64 match_data; // x0
  __int64 v9; // x23
  __int64 v10; // x22
  __int64 regmap; // x0
  __int64 v12; // x0
  unsigned int *address; // x0
  __int64 v14; // x9
  unsigned int *v15; // x0
  unsigned int v16; // w0
  __int64 device; // x0
  __int64 v18; // x8
  int v19; // w9
  int v20; // w8
  char v21; // w8
  const char *v22; // x1
  const char *v23; // x1
  unsigned int v24; // w20
  int v25; // [xsp+0h] [xbp-10h] BYREF
  int v26; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v2 = a1 + 2;
  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[95];
  v25 = 0;
  if ( (of_property_read_variable_u32_array(v3, "debounce", &v25, 1, 0) & 0x80000000) != 0 )
  {
    v25 = 15625;
  }
  else if ( (unsigned int)(v25 - 2000001) < 0xFFE17B80 )
  {
    dev_err(v2, "invalid debounce time: %u\n", v25);
    result = 4294967274LL;
    goto LABEL_24;
  }
  v5 = of_find_property(a1[95], "bias-pull-up", 0) != 0;
  v6 = (_QWORD *)devm_kmalloc(v2, 184, 3520);
  if ( !v6 )
    goto LABEL_23;
  v7 = v6;
  *v6 = v2;
  match_data = of_device_get_match_data(v2);
  v7[12] = match_data;
  if ( !match_data )
  {
    v22 = "match data not found\n";
LABEL_46:
    dev_err(v2, v22);
    result = 4294967277LL;
    goto LABEL_24;
  }
  v9 = a1[14];
  v10 = a1[95];
  regmap = dev_get_regmap(v9, 0);
  v7[3] = regmap;
  if ( !regmap )
  {
    v10 = *(_QWORD *)(v9 + 744);
    v12 = dev_get_regmap(*(_QWORD *)(v9 + 96), 0);
    v7[3] = v12;
    if ( !v12 )
    {
      v22 = "failed to locate regmap\n";
      goto LABEL_46;
    }
  }
  *((_DWORD *)v7 + 22) = v25;
  *((_BYTE *)v7 + 93) = v5;
  address = (unsigned int *)_of_get_address(v10, 0, 0xFFFFFFFFLL, 0, 0);
  if ( !address )
  {
    dev_err(v2, "reg property missing\n");
    result = 4294967274LL;
    goto LABEL_24;
  }
  v14 = v7[12];
  *((_DWORD *)v7 + 3) = bswap32(*address);
  if ( *(_BYTE *)(v14 + 10) == 1 )
  {
    v15 = (unsigned int *)_of_get_address(v10, 1, 0xFFFFFFFFLL, 0, 0);
    if ( v15 )
      *((_DWORD *)v7 + 4) = bswap32(*v15);
  }
  result = platform_get_irq(a1, 0);
  *((_DWORD *)v7 + 2) = result;
  if ( (result & 0x80000000) == 0 )
  {
    v16 = regmap_read(v7[3], (unsigned int)(*((_DWORD *)v7 + 3) + 1), v7 + 5);
    if ( v16 )
    {
      v23 = "failed to read revision: %d\n";
      goto LABEL_52;
    }
    v16 = regmap_read(v7[3], (unsigned int)(*((_DWORD *)v7 + 3) + 5), (char *)v7 + 44);
    if ( v16 )
    {
      v23 = "failed to read subtype: %d\n";
      goto LABEL_52;
    }
    if ( (of_property_read_variable_u32_array(a1[95], "linux,code", v7 + 9, 1, 0) & 0x80000000) != 0 )
      *((_DWORD *)v7 + 18) = 116;
    device = devm_input_allocate_device(v2);
    v7[4] = device;
    if ( device )
    {
      input_set_capability(device, 1, *((unsigned int *)v7 + 18));
      *(_QWORD *)v7[4] = *(_QWORD *)(v7[12] + 16LL);
      *(_QWORD *)(v7[4] + 8LL) = *(_QWORD *)(v7[12] + 24LL);
      v16 = pm8941_pwrkey_hw_init(v7);
      if ( v16 )
      {
        v23 = "Failed to initialize H/W : %d\n";
        goto LABEL_52;
      }
      v18 = v7[12];
      v26 = 0;
      v19 = *(unsigned __int8 *)(v18 + 10);
      v20 = *((_DWORD *)v7 + 4);
      if ( v19 == 1 )
      {
        if ( !v20 )
        {
          dev_err(*v7, "PON_PBS address missing, can't read HW debounce time\n");
LABEL_32:
          if ( !strcmp(*(const char **)v7[4], "pmic_resin") )
          {
            dev_err(v2, "skip zte set timer part 1\n");
          }
          else
          {
            if ( (unsigned int)is_s2_warm_reset() )
            {
              dev_err(
                v2,
                "%s: s2 warm reset is enabled by vendorcfg, power key long press to memory dump\n",
                "pm8941_pwrkey_probe");
              vendor_mod_ponreg(v7);
            }
            init_timer_key(v7 + 13, pwrkey_timer, 0, 0, 0);
            v7[18] = 0xFFFFFFFE00000LL;
            v7[19] = v7 + 19;
            v7[20] = v7 + 19;
            v7[21] = pwrkey_poweroff;
          }
          v16 = devm_request_threaded_irq(
                  v2,
                  *((unsigned int *)v7 + 2),
                  0,
                  pm8941_pwrkey_irq,
                  0x2000,
                  *(_QWORD *)(v7[12] + 16LL),
                  v7);
          if ( v16 )
          {
            v23 = "failed requesting IRQ: %d\n";
          }
          else
          {
            v16 = input_register_device(v7[4]);
            if ( v16 )
            {
              v23 = "failed to register input device: %d\n";
            }
            else
            {
              if ( *(_BYTE *)(v7[12] + 8LL) != 1
                || (v7[6] = pm8941_reboot_notify, (v16 = register_reboot_notifier(v7 + 6)) == 0) )
              {
                a1[21] = v7;
                device_set_wakeup_capable(v2, 1);
                device_wakeup_enable(v2);
                result = 0;
                goto LABEL_24;
              }
              v23 = "failed to register reboot notifier: %d\n";
            }
          }
LABEL_52:
          v24 = v16;
          dev_err(v2, v23, v16);
          result = v24;
          goto LABEL_24;
        }
      }
      else if ( !v20 )
      {
        v20 = *((_DWORD *)v7 + 3);
      }
      result = regmap_read(v7[3], (unsigned int)(v20 + 113), &v26);
      if ( (_DWORD)result )
        goto LABEL_24;
      if ( *((_DWORD *)v7 + 11) <= 3u )
        v21 = 7;
      else
        v21 = 15;
      *((_DWORD *)v7 + 19) = 0x1E8480u >> (v21 & ~(_BYTE)v26);
      goto LABEL_32;
    }
LABEL_23:
    result = 4294967284LL;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
