__int64 __fastcall tmc_etr_usb_init(__int64 *a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x4
  __int64 v8; // x5
  __int64 v9; // x6
  __int64 v10; // x7
  __int64 v11; // x20
  __int64 v12; // x22
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v16; // x1

  v4 = devm_kmalloc(a1, 40, 3520);
  if ( !v4 )
    return 4294967284LL;
  *(_QWORD *)(a2 + 336) = v4;
  v11 = v4;
  v12 = *(_QWORD *)(a2 + 304);
  v13 = a1[94];
  *(_QWORD *)(v11 + 16) = a2;
  if ( (fwnode_property_present(v13, "qcom,sw-usb", v5, v6, v7, v8, v9, v10) & 1) != 0 )
  {
    *(_QWORD *)(v11 + 32) = 0;
    *(_DWORD *)(v11 + 8) = 1;
    *(_BYTE *)(v11 + 24) = 0;
    if ( v12 && (v14 = alloc_workqueue("%s", (const char *)0x6000A), (*(_QWORD *)(v12 + 216) = v14) != 0) )
    {
      *(_QWORD *)(v12 + 400) = 0;
      _mutex_init(v12 + 264, "&byte_cntr_data->usb_bypass_lock", &usb_bypass_init___key);
      _init_waitqueue_head(v12 + 192, "&byte_cntr_data->usb_wait_wq", &usb_bypass_init___key_16);
      *(_DWORD *)(v12 + 164) = 255;
      *(_QWORD *)(v12 + 232) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v12 + 240) = v12 + 240;
      *(_QWORD *)(v12 + 248) = v12 + 240;
      *(_QWORD *)(v12 + 256) = usb_read_work_fn;
      return 0;
    }
    else
    {
      return 4294967274LL;
    }
  }
  else
  {
    v16 = a1[14];
    *(_DWORD *)(v11 + 8) = 0;
    if ( !v16 )
      v16 = *a1;
    printk(&unk_FA4C, v16);
    return 0;
  }
}
