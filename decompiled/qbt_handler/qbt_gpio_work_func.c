__int64 __fastcall qbt_gpio_work_func(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x0
  __int64 raw_value; // x0
  int v5; // w8
  int v6; // w20
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x1
  _QWORD v10[3]; // [xsp+0h] [xbp-30h] BYREF
  __int64 v11; // [xsp+18h] [xbp-18h]
  __int64 v12; // [xsp+20h] [xbp-10h]
  __int64 v13; // [xsp+28h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v3 = gpio_to_desc(*(unsigned int *)(a1 - 16));
    raw_value = gpiod_get_raw_value(v3);
    v5 = *(_DWORD *)(a1 - 12);
    v11 = 0;
    v12 = 0;
    v10[2] = 0;
    v6 = v5 ^ ((_DWORD)raw_value != 0);
    ktime_get(raw_value);
    v7 = printk(&unk_94B4, "qbt_gpio_report_event");
    if ( (*(_BYTE *)(a1 + 624) & 1) != 0 )
    {
      if ( !*(_DWORD *)(a1 + 36) || *(_DWORD *)(a1 + 32) != v6 )
      {
        HIDWORD(v11) = v6;
        *(_DWORD *)(a1 + 32) = v6;
        *(_DWORD *)(a1 + 36) = 1;
        LOBYTE(v12) = 0;
        v8 = ktime_get(v7);
        v10[0] = ns_to_timespec64(v8);
        v10[1] = v9;
        qbt_fd_report_event(a1 - 520, v10);
      }
    }
    else
    {
      printk(&unk_9F95, "qbt_gpio_report_event");
    }
    result = pm_relax(*(_QWORD *)(a1 - 232));
  }
  else
  {
    result = printk(&unk_9A11, "qbt_gpio_work_func");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
