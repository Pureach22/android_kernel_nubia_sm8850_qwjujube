__int64 __fastcall lpass_cdc_wsa_macro_add_child_devices(__int64 a1)
{
  __int64 *v1; // x27
  __int64 v3; // x0
  __int64 result; // x0
  const char **v5; // x20
  __int64 v6; // x22
  unsigned __int16 v7; // w28
  const char *v8; // x25
  size_t v9; // x0
  unsigned __int64 v10; // x2
  __int64 v11; // x25
  __int64 v12; // x0
  unsigned __int64 v13; // x26
  __int64 v14; // x0
  __int64 v15; // x8
  unsigned __int64 v16; // x9
  bool v17; // cf
  unsigned __int64 v18; // x9
  __int64 v19; // x8
  _QWORD v20[11]; // [xsp+18h] [xbp-58h] BYREF

  v1 = (__int64 *)(a1 - 320);
  v20[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v20, 0, 80);
  if ( a1 == 320 )
  {
    result = printk(&unk_FA06, "lpass_cdc_wsa_macro_add_child_devices");
    goto LABEL_33;
  }
  v3 = *v1;
  if ( !*v1 || !*(_QWORD *)(v3 + 744) )
  {
    result = dev_err(v3, "%s: DT node for wsa_priv does not exist\n", "lpass_cdc_wsa_macro_add_child_devices");
    goto LABEL_33;
  }
  *(_DWORD *)(a1 + 272) = 0;
  result = of_get_next_available_child(*(_QWORD *)(v3 + 744), 0);
  if ( result )
  {
    v5 = (const char **)result;
    v6 = 0;
    v7 = 0;
    _ReadStatusReg(SP_EL0);
    do
    {
      if ( strnstr(*v5, "wsa_swr_master", 14) )
      {
        strcpy((char *)v20, "wsa_swr_ctrl");
      }
      else
      {
        if ( !strnstr(*v5, "msm_cdc_pinctrl", 15) )
          goto LABEL_7;
        v8 = *v5;
        v9 = strnlen(*v5, 0x4Fu);
        if ( v9 == -1 )
          goto LABEL_44;
        if ( v9 == 79 )
          v10 = 79;
        else
          v10 = v9 + 1;
        if ( v10 >= 0x51 )
          goto LABEL_43;
        sized_strscpy(v20, v8);
      }
      v11 = platform_device_alloc(v20, 0xFFFFFFFFLL);
      v12 = *v1;
      if ( !v11 )
      {
        result = dev_err(v12, "%s: pdev memory alloc failed\n", "lpass_cdc_wsa_macro_add_child_devices");
        break;
      }
      *(_QWORD *)(v11 + 112) = v12;
      *(_QWORD *)(v11 + 760) = v5;
      if ( strnstr(*v5, "wsa_swr_master", 14) )
      {
        if ( (unsigned int)platform_device_add_data(v11, a1 - 56, 56) )
        {
          result = dev_err(v11 + 16, "%s: cannot add plat data ctrl:%d\n", "lpass_cdc_wsa_macro_add_child_devices", v7);
LABEL_37:
          if ( *(int *)(a1 + 272) >= 1 )
          {
            result = platform_device_put(*(_QWORD *)(a1 + 248));
            if ( *(int *)(a1 + 272) >= 2 )
            {
              result = platform_device_put(*(_QWORD *)(a1 + 256));
              if ( *(int *)(a1 + 272) >= 3 )
              {
                result = platform_device_put(*(_QWORD *)(a1 + 264));
                if ( *(int *)(a1 + 272) > 3 )
                {
LABEL_41:
                  __break(0x5512u);
LABEL_42:
                  __break(1u);
LABEL_43:
                  _fortify_panic(7, 80);
LABEL_44:
                  _fortify_panic(2, -1);
                }
              }
            }
          }
          break;
        }
        v13 = 8LL * v7 + 8;
        v14 = krealloc_noprof(v6, v13, 3264);
        v6 = v14;
        if ( !v14 )
        {
          result = dev_err(v11 + 16, "out of memory\n");
          goto LABEL_37;
        }
        v15 = v7;
        v16 = 8LL * v7;
        v17 = v13 >= v16;
        v18 = v13 - v16;
        if ( !v17 || v18 < 8 )
          goto LABEL_42;
        ++v7;
        *(_QWORD *)(v14 + 8 * v15) = v11;
        *(_QWORD *)(a1 - 64) = v14;
      }
      result = platform_device_add(v11);
      if ( (_DWORD)result )
      {
        result = dev_err(v11 + 16, "%s: Cannot add platform device\n", "lpass_cdc_wsa_macro_add_child_devices");
        goto LABEL_37;
      }
      v19 = *(unsigned int *)(a1 + 272);
      if ( (int)v19 > 2 )
        break;
      *(_DWORD *)(a1 + 272) = v19 + 1;
      if ( (unsigned int)v19 >= 3 )
        goto LABEL_41;
      *(_QWORD *)(a1 + 248 + 8 * v19) = v11;
LABEL_7:
      result = of_get_next_available_child(*(_QWORD *)(*v1 + 744), v5);
      v5 = (const char **)result;
    }
    while ( result );
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
