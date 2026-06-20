__int64 __fastcall lpass_cdc_rx_macro_add_child_devices(__int64 a1)
{
  __int64 *v1; // x26
  __int64 v3; // x0
  __int64 result; // x0
  const char **v5; // x20
  __int64 v6; // x22
  unsigned __int16 v7; // w27
  __int64 v8; // x25
  const char *v9; // x24
  size_t v10; // x0
  unsigned __int64 v11; // x2
  __int64 v12; // x24
  __int64 v13; // x0
  unsigned __int64 v14; // x25
  __int64 v15; // x8
  unsigned __int64 v16; // x9
  bool v17; // cf
  unsigned __int64 v18; // x9
  __int64 v19; // x8
  __int64 v20; // x9
  void *v21; // x0
  _QWORD v22[11]; // [xsp+18h] [xbp-58h] BYREF

  v1 = (__int64 *)(a1 - 264);
  v22[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v22, 0, 80);
  if ( a1 == 264 )
  {
    v21 = &unk_F4DC;
LABEL_29:
    result = printk(v21, "lpass_cdc_rx_macro_add_child_devices");
    goto LABEL_38;
  }
  v3 = *v1;
  if ( !*v1 )
  {
    v21 = &unk_F723;
    goto LABEL_29;
  }
  if ( !*(_QWORD *)(v3 + 744) )
  {
    result = dev_err(v3, "%s: DT node for RX dev does not exist\n", "lpass_cdc_rx_macro_add_child_devices");
    goto LABEL_38;
  }
  *(_DWORD *)(a1 + 2056) = 0;
  result = of_get_next_available_child(*(_QWORD *)(v3 + 744), 0);
  if ( result )
  {
    v5 = (const char **)result;
    v6 = 0;
    v7 = 0;
    _ReadStatusReg(SP_EL0);
    do
    {
      v8 = strnstr(*v5, "rx_swr_master", 13);
      if ( v8 )
      {
        strcpy((char *)v22, "rx_swr_ctrl");
      }
      else
      {
        v9 = *v5;
        v10 = strnlen(*v5, 0x4Fu);
        if ( v10 == -1 )
          goto LABEL_42;
        if ( v10 == 79 )
          v11 = 79;
        else
          v11 = v10 + 1;
        if ( v11 >= 0x51 )
          goto LABEL_41;
        sized_strscpy(v22, v9);
      }
      v12 = platform_device_alloc(v22, 0xFFFFFFFFLL);
      v13 = *v1;
      if ( !v12 )
      {
        result = dev_err(v13, "%s: pdev memory alloc failed\n", "lpass_cdc_rx_macro_add_child_devices");
        break;
      }
      *(_QWORD *)(v12 + 112) = v13;
      *(_QWORD *)(v12 + 760) = v5;
      if ( v8 )
      {
        if ( (unsigned int)platform_device_add_data(v12, a1 - 56, 56) )
        {
          result = dev_err(v12 + 16, "%s: cannot add plat data ctrl:%d\n", "lpass_cdc_rx_macro_add_child_devices", v7);
LABEL_34:
          if ( *(int *)(a1 + 2056) >= 1 )
          {
            result = platform_device_put(*(_QWORD *)(a1 + 2032));
            if ( *(int *)(a1 + 2056) >= 2 )
            {
              result = platform_device_put(*(_QWORD *)(a1 + 2040));
              if ( *(int *)(a1 + 2056) >= 3 )
              {
                result = platform_device_put(*(_QWORD *)(a1 + 2048));
                if ( *(int *)(a1 + 2056) > 3 )
                {
LABEL_39:
                  __break(0x5512u);
LABEL_40:
                  __break(1u);
LABEL_41:
                  _fortify_panic(7, 80);
LABEL_42:
                  _fortify_panic(2, -1);
                }
              }
            }
          }
          break;
        }
        v14 = 8LL * v7 + 8;
        result = krealloc_noprof(v6, v14, 3264);
        v6 = result;
        if ( !result )
          goto LABEL_34;
        v15 = v7;
        v16 = 8LL * v7;
        v17 = v14 >= v16;
        v18 = v14 - v16;
        if ( !v17 || v18 < 8 )
          goto LABEL_40;
        ++v7;
        *(_QWORD *)(result + 8 * v15) = v12;
        *(_QWORD *)(a1 - 64) = result;
      }
      result = platform_device_add(v12);
      if ( (_DWORD)result )
      {
        result = dev_err(v12 + 16, "%s: Cannot add platform device\n", "lpass_cdc_rx_macro_add_child_devices");
        goto LABEL_34;
      }
      v19 = *(unsigned int *)(a1 + 2056);
      if ( (int)v19 > 2 )
        break;
      *(_DWORD *)(a1 + 2056) = v19 + 1;
      if ( (unsigned int)v19 >= 3 )
        goto LABEL_39;
      v20 = *v1;
      *(_QWORD *)(a1 + 2032 + 8 * v19) = v12;
      result = of_get_next_available_child(*(_QWORD *)(v20 + 744), v5);
      v5 = (const char **)result;
    }
    while ( result );
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
