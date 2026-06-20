__int64 __fastcall ccid_function_set_alt(__int64 a1)
{
  _QWORD *v2; // x20
  unsigned int v3; // w0
  _QWORD *v4; // x8
  unsigned int v5; // w0
  __int64 result; // x0
  __int64 v7; // x2
  void *v8; // x8
  unsigned int v9; // w19
  __int64 v10; // x2
  void *v11; // x8
  unsigned int v12; // w20
  __int64 v13; // x2
  void *v14; // x8

  v2 = *(_QWORD **)(*(_QWORD *)(a1 + 48) + 48LL);
  v3 = config_ep_by_speed(*v2, a1, *(_QWORD *)(a1 + 240));
  if ( v3 )
  {
    *(_QWORD *)(*(_QWORD *)(a1 + 240) + 24LL) = 0;
    v7 = *(_QWORD *)(*(_QWORD *)(a1 + 240) + 8LL);
    v8 = &unk_8358;
LABEL_10:
    v9 = v3;
    printk(v8, "ccid_function_set_alt", v7);
    return v9;
  }
  v3 = usb_ep_enable(*(_QWORD *)(a1 + 240));
  v4 = *(_QWORD **)(a1 + 240);
  if ( v3 )
  {
    v7 = v4[1];
    v8 = &unk_82C1;
    goto LABEL_10;
  }
  *v4 = a1;
  v5 = config_ep_by_speed(*v2, a1, *(_QWORD *)(a1 + 248));
  if ( v5 )
  {
    *(_QWORD *)(*(_QWORD *)(a1 + 248) + 24LL) = 0;
    v10 = *(_QWORD *)(*(_QWORD *)(a1 + 248) + 8LL);
    v11 = &unk_8358;
  }
  else
  {
    v5 = usb_ep_enable(*(_QWORD *)(a1 + 248));
    if ( !v5 )
    {
      LODWORD(result) = config_ep_by_speed(*v2, a1, *(_QWORD *)(a1 + 256));
      if ( (_DWORD)result )
      {
        *(_QWORD *)(*(_QWORD *)(a1 + 256) + 24LL) = 0;
        v13 = *(_QWORD *)(*(_QWORD *)(a1 + 256) + 8LL);
        v14 = &unk_8358;
      }
      else
      {
        result = usb_ep_enable(*(_QWORD *)(a1 + 256));
        if ( !(_DWORD)result )
        {
          *(_DWORD *)(a1 + 696) = 1;
          *(_DWORD *)(a1 + 232) = 1;
          return result;
        }
        v13 = *(_QWORD *)(*(_QWORD *)(a1 + 256) + 8LL);
        v14 = &unk_82C1;
      }
      v12 = result;
      printk(v14, "ccid_function_set_alt", v13);
      usb_ep_disable(*(_QWORD *)(a1 + 248));
      goto LABEL_17;
    }
    v10 = *(_QWORD *)(*(_QWORD *)(a1 + 248) + 8LL);
    v11 = &unk_82C1;
  }
  v12 = v5;
  printk(v11, "ccid_function_set_alt", v10);
LABEL_17:
  usb_ep_disable(*(_QWORD *)(a1 + 240));
  **(_QWORD **)(a1 + 240) = 0;
  return v12;
}
