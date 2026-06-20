__int64 __fastcall record_sleep_awake_time_vendor(char a1)
{
  unsigned int v2; // w24
  int v3; // w22
  __int64 v4; // x8
  int v5; // w20
  __int64 v6; // x8
  int v7; // w27
  __int64 result; // x0
  int v9; // w20
  int v10; // w21
  int v11; // w26
  int v12; // w28
  int v13; // w19
  int v14; // w26
  int v15; // w22
  unsigned int v16; // w23
  int v17; // w9
  void *v18; // x0
  int v19; // [xsp+0h] [xbp-50h]
  _QWORD v20[4]; // [xsp+10h] [xbp-40h] BYREF
  int v21; // [xsp+30h] [xbp-20h]
  __int64 v22; // [xsp+38h] [xbp-18h] BYREF
  __int64 v23; // [xsp+40h] [xbp-10h]
  __int64 v24; // [xsp+48h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  v23 = 0;
  v21 = 0;
  memset(v20, 0, sizeof(v20));
  ktime_get_coarse_real_ts64(&v22);
  rtc_time64_to_tm((unsigned int)(v22 - 60 * sys_tz), v20);
  printk(&unk_966E);
  v2 = (int)v23 / 1000000 + 1000 * (v22 - time_updated_when_sleep_awake) + (int)qword_91F8 / -1000000;
  if ( (a1 & 1) == 0 )
  {
    record_sleep_awake_time_vendor_sleep_success_flag = 1;
    if ( zte_imem_ptr )
    {
      printk(&unk_9D19);
      v6 = zte_imem_ptr;
      v7 = *(_DWORD *)(zte_imem_ptr + 4);
    }
    else
    {
      printk(&unk_9BE3);
      v6 = zte_imem_ptr;
      v7 = 0;
    }
    record_sleep_awake_time_vendor_amss_sleep_time_ms = v7;
    v9 = record_sleep_awake_time_vendor_amss_awake_time_ms;
    if ( v6 )
    {
      v10 = *(_DWORD *)(v6 + 12);
      printk(&unk_A06E);
      v11 = *(_DWORD *)(zte_imem_ptr + 8);
      record_sleep_awake_time_vendor_amss_awake_time_ms = v11;
      if ( zte_imem_ptr )
        goto LABEL_11;
    }
    else
    {
      printk(&unk_A0DB);
      v10 = 0;
      v11 = 0;
      record_sleep_awake_time_vendor_amss_awake_time_ms = 0;
      if ( zte_imem_ptr )
      {
LABEL_11:
        printk(&unk_9D39);
        v12 = *(_DWORD *)(zte_imem_ptr + 16);
LABEL_14:
        record_sleep_awake_time_vendor_amss_physlink_current_total_time_s = v12;
        record_sleep_awake_time_vendor_amss_physlink_last_total_time_s = v12;
        if ( record_sleep_awake_time_vendor_amss_current_sleep_or_awake_previous | v10 )
        {
          if ( v10 == 4 )
            printk(&unk_A832);
        }
        else if ( (unsigned int)(v11 - v9) <= 0x63 && v2 >= 0x1389 )
        {
          printk(&unk_A0C4);
        }
        if ( record_sleep_awake_time_vendor_record_firsttime == 1 )
          record_sleep_awake_time_vendor_time_app_total_awake_s += v2 / 0x3E8;
        record_sleep_awake_time_vendor_record_firsttime = 1;
        printk(&unk_9FEB);
        printk(&unk_9ED9);
        printk(&unk_9F22);
        result = printk(&unk_9DA0);
        goto LABEL_44;
      }
    }
    printk(&unk_A1E5);
    v12 = 0;
    goto LABEL_14;
  }
  if ( (record_sleep_awake_time_vendor_sleep_success_flag & 1) != 0 )
  {
    v3 = record_sleep_awake_time_vendor_amss_sleep_time_ms;
    record_sleep_awake_time_vendor_sleep_success_flag = 0;
    if ( zte_imem_ptr )
    {
      printk(&unk_9D19);
      v4 = zte_imem_ptr;
      v5 = *(_DWORD *)(zte_imem_ptr + 4);
    }
    else
    {
      printk(&unk_9BE3);
      v4 = zte_imem_ptr;
      v5 = 0;
    }
    record_sleep_awake_time_vendor_amss_sleep_time_ms = v5;
    v19 = record_sleep_awake_time_vendor_amss_awake_time_ms;
    if ( v4 )
    {
      v10 = *(_DWORD *)(v4 + 12);
      printk(&unk_A06E);
      v13 = *(_DWORD *)(zte_imem_ptr + 8);
      record_sleep_awake_time_vendor_amss_awake_time_ms = v13;
      if ( zte_imem_ptr )
        goto LABEL_26;
    }
    else
    {
      printk(&unk_A0DB);
      v10 = 0;
      v13 = 0;
      record_sleep_awake_time_vendor_amss_awake_time_ms = 0;
      if ( zte_imem_ptr )
      {
LABEL_26:
        printk(&unk_9D39);
        v14 = *(_DWORD *)(zte_imem_ptr + 16);
        goto LABEL_29;
      }
    }
    printk(&unk_A1E5);
    v14 = 0;
LABEL_29:
    v15 = v5 - v3;
    record_sleep_awake_time_vendor_amss_physlink_current_total_time_s = v14;
    record_sleep_awake_time_vendor_amss_physlink_last_total_time_s = v14;
    if ( record_sleep_awake_time_vendor_amss_current_sleep_or_awake_previous | v10 )
    {
      if ( v10 == 4 )
        printk(&unk_A832);
      v16 = v2 - v15;
    }
    else
    {
      v16 = v13 - v19;
      if ( (unsigned int)(v13 - v19) <= 0x63 && v2 >= 0x1389 )
        printk(&unk_A0C4);
    }
    record_sleep_awake_time_vendor_time_app_total_sleep_s += v2 / 0x3E8;
    if ( record_sleep_awake_time_vendor_record_firsttime_modem != 1 )
    {
      record_sleep_awake_time_vendor_time_modem_firsttime_sleep_s = record_sleep_awake_time_vendor_amss_sleep_time_ms
                                                                  / 0x3E8u;
      record_sleep_awake_time_vendor_record_firsttime_modem = 1;
      record_sleep_awake_time_vendor_time_modem_firsttime_awake_s = v16 / 0x3E8;
    }
    printk(&unk_9DD8);
    printk(&unk_A58A);
    v17 = kernel_sleep_count;
    if ( kernel_sleep_count < 10001 )
    {
      ++kernel_sleep_count;
      if ( (unsigned int)(-858993459 * (v17 + 1) + 429496729) > 0x33333332 )
      {
LABEL_43:
        printk(&unk_974C);
        printk(&unk_A3CB);
        result = printk(&unk_A748);
LABEL_44:
        record_sleep_awake_time_vendor_amss_current_sleep_or_awake_previous = v10;
        time_updated_when_sleep_awake = v22;
        qword_91F8 = v23;
        goto LABEL_45;
      }
      v18 = &unk_9A23;
    }
    else
    {
      v18 = &unk_99F7;
      kernel_sleep_count = 1;
    }
    printk(v18);
    goto LABEL_43;
  }
  result = printk(&unk_97E8);
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
