__int64 __fastcall backlight_cdev_register(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v7; // x0
  int v8; // w8
  __int64 v9; // x1
  __int64 v10; // x0
  unsigned int v11; // w8
  unsigned __int64 v12; // x0
  __int64 v13; // x1

  v3 = -22;
  if ( a1 && a2 && a3 )
  {
    if ( of_find_property(*(_QWORD *)(a1 + 744), "#cooling-cells", 0) )
    {
      v7 = devm_kmalloc(a1, 104, 3520);
      if ( v7 )
      {
        v8 = *(_DWORD *)(a2 + 4);
        v3 = v7;
        v9 = *(_QWORD *)(a2 + 280);
        *(_QWORD *)(v7 + 80) = a2;
        *(_QWORD *)(v7 + 88) = 0;
        v10 = *(_QWORD *)(a1 + 744);
        if ( v8 <= 255 )
          v11 = 1;
        else
          v11 = v8 / 0xFFu;
        *(_DWORD *)(v3 + 96) = v11;
        if ( !v9 )
          v9 = *(_QWORD *)(a2 + 168);
        v12 = thermal_of_cooling_device_register(v10, v9, v3, sde_cdev_ops);
        *(_QWORD *)(v3 + 72) = v12;
        if ( v12 && v12 < 0xFFFFFFFFFFFFF001LL )
        {
          _init_rwsem(v3, "&(&disp_cdev->notifier_head)->rwsem", &backlight_cdev_register___key);
          *(_QWORD *)(v3 + 64) = 0;
          blocking_notifier_chain_register(v3, a3);
        }
        else
        {
          printk(&unk_21805A, v13);
          return *(_QWORD *)(v3 + 72);
        }
      }
      else
      {
        return -12;
      }
    }
    else
    {
      return -19;
    }
  }
  return v3;
}
