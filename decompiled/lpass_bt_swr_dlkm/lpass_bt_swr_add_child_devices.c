__int64 __fastcall lpass_bt_swr_add_child_devices(__int64 a1)
{
  __int64 *v1; // x26
  __int64 v3; // x0
  __int64 result; // x0
  _QWORD *v5; // x20
  __int64 v6; // x23
  unsigned __int16 v7; // w27
  __int64 v8; // x24
  __int64 v9; // x0
  unsigned __int64 v10; // x25
  unsigned __int64 v11; // x9
  bool v12; // cf
  unsigned __int64 v13; // x9
  int v14; // w8
  _QWORD v15[11]; // [xsp+18h] [xbp-58h] BYREF

  v1 = (__int64 *)(a1 - 272);
  v15[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v15, 0, 80);
  if ( a1 == 272 )
  {
    result = printk(&unk_73D9, "lpass_bt_swr_add_child_devices");
    goto LABEL_27;
  }
  v3 = *v1;
  if ( !*v1 || !*(_QWORD *)(v3 + 744) )
  {
    result = dev_err(v3, "%s: DT node for priv does not exist\n", "lpass_bt_swr_add_child_devices");
    goto LABEL_27;
  }
  *(_DWORD *)(a1 + 40) = 0;
  result = of_get_next_available_child(*(_QWORD *)(v3 + 744), 0);
  if ( result )
  {
    v5 = (_QWORD *)result;
    v6 = 0;
    v7 = 0;
    _ReadStatusReg(SP_EL0);
    do
    {
      if ( strnstr(*v5, "bt_swr_mstr", 11) )
      {
        strcpy((char *)v15, "bt_swr_mstr");
        v8 = platform_device_alloc(v15, 0xFFFFFFFFLL);
        v9 = *v1;
        if ( !v8 )
        {
          result = dev_err(v9, "%s: pdev memory alloc failed\n", "lpass_bt_swr_add_child_devices");
          break;
        }
        *(_QWORD *)(v8 + 112) = v9;
        *(_QWORD *)(v8 + 760) = v5;
        if ( (unsigned int)platform_device_add_data(v8, a1 - 56, 56) )
        {
          result = dev_err(v8 + 16, "%s: cannot add plat data ctrl:%d\n", "lpass_bt_swr_add_child_devices", v7);
          goto LABEL_25;
        }
        v10 = 8LL * v7 + 8;
        v6 = krealloc_noprof(v6, v10, 3264);
        if ( !v6 )
        {
          result = dev_err(v8 + 16, "out of memory\n");
          goto LABEL_25;
        }
        v11 = 8LL * v7;
        v12 = v10 >= v11;
        v13 = v10 - v11;
        if ( !v12 || v13 < 8 )
        {
          __break(1u);
          goto LABEL_29;
        }
        *(_QWORD *)(v6 + 8LL * v7) = v8;
        *(_QWORD *)(a1 - 64) = v6;
        result = platform_device_add(v8);
        if ( (_DWORD)result )
        {
          result = dev_err(v8 + 16, "%s: Cannot add platform device\n", "lpass_bt_swr_add_child_devices");
LABEL_25:
          if ( *(int *)(a1 + 40) >= 1 )
          {
            result = platform_device_put(*(_QWORD *)(a1 + 32));
            if ( *(int *)(a1 + 40) > 1 )
LABEL_29:
              __break(0x5512u);
          }
          break;
        }
        v14 = *(_DWORD *)(a1 + 40);
        if ( v14 > 0 )
          break;
        *(_DWORD *)(a1 + 40) = v14 + 1;
        if ( v14 )
          goto LABEL_29;
        ++v7;
        *(_QWORD *)(a1 + 32) = v8;
      }
      result = of_get_next_available_child(*(_QWORD *)(*v1 + 744), v5);
      v5 = (_QWORD *)result;
    }
    while ( result );
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
