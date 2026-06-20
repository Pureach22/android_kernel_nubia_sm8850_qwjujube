__int64 __fastcall eusb2_repeater_register_tune_register(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x20
  __int64 v8; // x0
  __int64 v9; // x0
  int v10; // w21
  unsigned __int64 v12; // x0
  unsigned __int64 v13; // x22
  int group; // w0
  __int64 v15; // x0

  if ( a1 && a2 && a3 )
  {
    if ( !repeater_tune_class )
    {
      repeater_tune_class = class_create("eusb2_repeater");
      if ( (unsigned __int64)repeater_tune_class >= 0xFFFFFFFFFFFFF001LL )
      {
        dev_err(a3, "Failed to create class\n");
        return repeater_tune_class;
      }
    }
    v6 = devm_kmalloc(a3, 112, 3520);
    if ( !v6 )
      return -12;
    v7 = v6;
    _mutex_init(v6 + 32, "&eed->lock", &eusb2_repeater_register_tune_register___key);
    *(_QWORD *)v7 = a1;
    *(_QWORD *)(v7 + 8) = a2;
    *(_QWORD *)(v7 + 16) = a3;
    *(_BYTE *)(v7 + 80) = 0;
    v8 = devm_kmalloc(a3, 100, 3520);
    *(_QWORD *)(v7 + 88) = v8;
    if ( !v8 )
      return -12;
    v9 = devm_kmalloc(a3, 12, 3520);
    *(_QWORD *)(v7 + 96) = v9;
    if ( v9 )
    {
      v12 = device_create(repeater_tune_class, 0, 0, 0, "register_tune");
      v13 = v12;
      if ( v12 < 0xFFFFFFFFFFFFF001LL )
      {
        *(_QWORD *)(v12 + 152) = v7;
        *(_QWORD *)(v7 + 24) = v12;
        group = sysfs_create_group(v12, &diagram_tune_attr_group);
        if ( !group )
        {
          dev_info(a3, "Repeater Tune driver registered successfully\n");
          return v7;
        }
        v10 = group;
        dev_err(a3, "Failed to create sysfs attributes\n");
        v15 = repeater_tune_class;
        *(_QWORD *)(v13 + 152) = 0;
        device_destroy(v15, 0);
      }
      else
      {
        dev_err(a3, "Failed to create class device\n");
        return (int)v13;
      }
    }
    else
    {
      return -12;
    }
  }
  else
  {
    printk(&unk_80EC);
    return -22;
  }
  return v10;
}
