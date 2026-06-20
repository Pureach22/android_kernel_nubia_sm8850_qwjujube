__int64 __fastcall lpass_cdc_add_child_devices(__int64 a1)
{
  __int64 *v1; // x24
  __int64 v3; // x0
  __int64 result; // x0
  const char **v5; // x20
  __int64 property; // x0
  const char *v7; // x22
  __int64 v8; // x23
  size_t v9; // x0
  unsigned __int64 v10; // x2
  __int64 v11; // x22
  __int64 v12; // x0
  unsigned int v13; // w8
  __int64 v14; // x10
  _QWORD v15[11]; // [xsp+8h] [xbp-58h] BYREF

  v1 = (__int64 *)(a1 - 816);
  v15[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v15, 0, 80);
  if ( a1 == 816 )
  {
    result = printk(&unk_D5F9, "lpass_cdc_add_child_devices");
  }
  else
  {
    v3 = *v1;
    if ( *v1 && *(_QWORD *)(v3 + 744) )
    {
      *(_WORD *)(a1 + 152) = 0;
      result = of_get_next_available_child(*(_QWORD *)(v3 + 744), 0);
      if ( result )
      {
        v5 = (const char **)result;
        while ( 1 )
        {
          property = of_find_property(v5, "qcom,split-codec", 0);
          v7 = *v5;
          v8 = property;
          v9 = strnlen(*v5, 0x4Fu);
          if ( v9 == -1 )
            goto LABEL_31;
          if ( v9 == 79 )
            v10 = 79;
          else
            v10 = v9 + 1;
          if ( v10 >= 0x51 )
            goto LABEL_30;
          sized_strscpy(v15, v7);
          v11 = platform_device_alloc(v15, 0xFFFFFFFFLL);
          v12 = *v1;
          if ( !v11 )
          {
            result = dev_err(v12, "%s: pdev memory alloc failed\n", "lpass_cdc_add_child_devices");
            goto LABEL_20;
          }
          *(_QWORD *)(v11 + 112) = v12;
          *(_QWORD *)(v11 + 760) = v5;
          *(_QWORD *)(*v1 + 144) = a1 + 160;
          if ( v8 )
            *(_QWORD *)(a1 + 184) = v11 + 16;
          result = platform_device_add(v11);
          if ( (_DWORD)result )
            break;
          v13 = *(unsigned __int16 *)(a1 + 152);
          if ( v13 <= 5 )
          {
            v14 = *v1;
            *(_WORD *)(a1 + 152) = v13 + 1;
            *(_QWORD *)(a1 + 104 + 8LL * v13) = v11;
            result = of_get_next_available_child(*(_QWORD *)(v14 + 744), v5);
            v5 = (const char **)result;
            if ( result )
              continue;
          }
          goto LABEL_20;
        }
        dev_err(v11 + 16, "%s: Cannot add platform device\n", "lpass_cdc_add_child_devices");
        result = platform_device_put(v11);
        if ( *(_WORD *)(a1 + 152) )
        {
          result = platform_device_put(*(_QWORD *)(a1 + 104));
          if ( *(unsigned __int16 *)(a1 + 152) > 1u )
          {
            result = platform_device_put(*(_QWORD *)(a1 + 112));
            if ( *(unsigned __int16 *)(a1 + 152) >= 3u )
            {
              result = platform_device_put(*(_QWORD *)(a1 + 120));
              if ( *(unsigned __int16 *)(a1 + 152) >= 4u )
              {
                result = platform_device_put(*(_QWORD *)(a1 + 128));
                if ( *(unsigned __int16 *)(a1 + 152) >= 5u )
                {
                  result = platform_device_put(*(_QWORD *)(a1 + 136));
                  if ( *(unsigned __int16 *)(a1 + 152) >= 6u )
                  {
                    result = platform_device_put(*(_QWORD *)(a1 + 144));
                    if ( *(unsigned __int16 *)(a1 + 152) > 6u )
                    {
                      __break(0x5512u);
LABEL_30:
                      _fortify_panic(7, 80);
LABEL_31:
                      _fortify_panic(2, -1);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else
    {
      result = dev_err(v3, "%s: DT node for lpass_cdc does not exist\n", "lpass_cdc_add_child_devices");
    }
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
