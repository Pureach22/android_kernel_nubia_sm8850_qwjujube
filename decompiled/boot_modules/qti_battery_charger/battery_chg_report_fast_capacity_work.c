__int64 __fastcall battery_chg_report_fast_capacity_work(__int64 a1, __int64 a2, __int64 a3)
{
  void *v3; // x0
  __int64 result; // x0
  _QWORD *v6; // x21
  int v7; // w8
  _QWORD *v8; // x20
  signed int v9; // w22
  unsigned int *v10; // x9
  int v11; // w9
  unsigned int v12; // w23
  unsigned int v13; // w23
  int v14; // w8
  unsigned int v15; // w9
  __int64 v16; // x2
  void *v17; // x0
  unsigned int v18; // w22
  unsigned int v19; // w8
  __int64 v20; // x2
  __int64 v21; // x1
  unsigned __int64 v22; // t2
  int v23; // w8
  int v24; // w8
  __int64 v25; // x2
  bool v26; // cc
  __int64 v27; // x2
  signed int v28; // w8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x2
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // [xsp+0h] [xbp-20h] BYREF
  int v39; // [xsp+8h] [xbp-18h]
  __int64 v40; // [xsp+Ch] [xbp-14h]
  int v41; // [xsp+14h] [xbp-Ch]
  __int64 v42; // [xsp+18h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( battery_chg_report_fast_capacity_work_is_work_running != 1 )
  {
    v6 = (_QWORD *)(a1 - 632);
    v7 = *(_DWORD *)(*(_QWORD *)(a1 - 256) + 16LL);
    v8 = (_QWORD *)(a1 - 280);
    battery_chg_report_fast_capacity_work_is_work_running = 1;
    v9 = (v7 + 50) / 0x64u;
    printk(&unk_11BF9, "battery_chg_report_fast_capacity_work", (unsigned int)v9);
    v10 = *(unsigned int **)(a1 - 256);
    a3 = *v10;
    if ( (_DWORD)a3 == 1 && *(_BYTE *)(a1 + 415) )
    {
      battery_chg_report_fast_capacity_work_batt_stat_error_times = 0;
      goto LABEL_15;
    }
    ++battery_chg_report_fast_capacity_work_batt_stat_error_times;
    printk(&unk_10E14, "battery_chg_report_fast_capacity_work", a3);
    v11 = *(_DWORD *)(a1 - 244);
    v40 = 0;
    v41 = 0;
    v38 = 0x10000800ALL;
    v39 = v11;
    battery_chg_write((__int64)v6, (__int64)&v38, 0x18u, 0x3E8u);
    v10 = *(unsigned int **)(a1 - 256);
    v12 = *v10;
    if ( *v10 == 1 && (*(_BYTE *)(a1 + 415) & 1) != 0 )
    {
LABEL_15:
      v14 = *(_DWORD *)(a1 + 136);
      if ( *(_DWORD *)(*(_QWORD *)(a1 - 208) + 52LL) == 7 )
      {
        v15 = v10[16];
        if ( v14 <= 9999 )
          *(_DWORD *)(a1 + 136) = ++v14;
        if ( v14 / 100 == v9 )
        {
          *(_DWORD *)(a1 + 408) = -22;
          if ( v14 == 10000 )
          {
            battery_chg_report_fast_capacity_work_is_work_running = 0;
            send_capacity_event(v6, 10000);
            power_supply_changed(*v8);
            v3 = &unk_FF7D;
            goto LABEL_3;
          }
          v18 = v15 / 0x3E8;
          read_property_id((__int64)v6, (__int64)v8, 9);
          v19 = 360 * v18 / (*(_DWORD *)(*(_QWORD *)(a1 - 256) + 36LL) / 0x3E8u);
          if ( v19 >= 0x1F4 )
            v19 = 500;
          if ( v19 <= 0x78 )
            v13 = 120;
          else
            v13 = v19;
        }
        else
        {
          if ( v14 / 100 <= v9 )
          {
            v17 = &unk_10C86;
            v16 = (unsigned int)(100 * v9);
            v13 = 200;
            *(_DWORD *)(a1 + 136) = v16;
          }
          else
          {
            v16 = (unsigned int)(v14 - 1);
            v17 = &unk_104C4;
            *(_DWORD *)(a1 + 136) = v16;
            v13 = 1500;
          }
          printk(v17, "battery_chg_report_fast_capacity_work", v16);
          power_supply_changed(*v8);
        }
        printk(&unk_114F2, "battery_chg_report_fast_capacity_work", v13);
        v21 = *(unsigned int *)(a1 + 136);
        HIDWORD(v22) = -1030792151 * v21 + 85899344;
        LODWORD(v22) = HIDWORD(v22);
        if ( (unsigned int)(v22 >> 2) <= 0x28F5C28 && *v8 )
        {
          printk(&unk_FFC5, "battery_chg_report_fast_capacity_work", v20);
          power_supply_changed(*v8);
          v21 = *(unsigned int *)(a1 + 136);
        }
        send_capacity_event(v6, v21);
        goto LABEL_64;
      }
      if ( v14 >= 1 )
      {
        printk(&unk_1176F, "battery_chg_report_fast_capacity_work", a3);
        *(_DWORD *)(a1 + 136) = -22;
      }
      a3 = *(unsigned int *)(a1 + 408);
      if ( (a3 & 0x80000000) != 0 )
      {
LABEL_24:
        battery_chg_report_fast_capacity_work_is_work_running = 0;
        v3 = &unk_118BA;
        goto LABEL_3;
      }
LABEL_56:
      if ( (unsigned int)a3 >= v9 )
      {
        v13 = 60000;
      }
      else
      {
        a3 = (unsigned int)(a3 + 1);
        *(_DWORD *)(a1 + 408) = a3;
        if ( v9 == (_DWORD)a3 )
        {
          v30 = *v8;
          *(_DWORD *)(a1 + 408) = -22;
          power_supply_changed(v30);
          battery_chg_report_fast_capacity_work_is_work_running = 0;
          v3 = &unk_10609;
          goto LABEL_3;
        }
        if ( v9 - (int)a3 <= 2 )
          v13 = 60000;
        else
          v13 = 30000;
      }
      printk(&unk_11C56, "battery_chg_report_fast_capacity_work", a3);
      goto LABEL_64;
    }
    result = printk(&unk_114AD, "battery_chg_report_fast_capacity_work", v12);
    a3 = *(unsigned int *)(a1 + 408);
    if ( (a3 & 0x80000000) != 0 && battery_chg_report_fast_capacity_work_batt_stat_error_times >= 2 )
      goto LABEL_67;
    if ( v12 == 3 )
    {
      if ( (a3 & 0x80000000) == 0 )
      {
        if ( (_DWORD)a3 != v9 )
        {
LABEL_13:
          v13 = 60000;
LABEL_66:
          pm_wakeup_dev_event(*v6, v13 + 100, 0);
          v33 = _msecs_to_jiffies(v13);
          result = queue_delayed_work_on(32, system_wq, a1, v33);
          goto LABEL_67;
        }
LABEL_72:
        v34 = *v8;
        *(_DWORD *)(a1 + 408) = -22;
        power_supply_changed(v34);
        battery_chg_report_fast_capacity_work_is_work_running = 0;
        v3 = &unk_11650;
        goto LABEL_3;
      }
LABEL_67:
      battery_chg_report_fast_capacity_work_is_work_running = 0;
      goto LABEL_68;
    }
    if ( v12 != 4 )
    {
      if ( v12 == 2 )
      {
        printk(&unk_100E2, "battery_chg_report_fast_capacity_work", a3);
        v28 = *(_DWORD *)(a1 + 408);
        if ( v28 <= v9 )
        {
          if ( v28 >= v9 )
            goto LABEL_72;
          v13 = 60000;
          if ( (v28 & 0x80000000) == 0 )
            goto LABEL_66;
LABEL_65:
          v31 = ktime_get_with_offset(1);
          if ( ns_to_timespec64(v31) - *(_QWORD *)(a1 + 144) >= 16 )
          {
            printk(&unk_1084C, "battery_chg_report_fast_capacity_work", v32);
            v35 = *v8;
            battery_chg_report_fast_capacity_work_is_work_running = 0;
            result = power_supply_changed(v35);
            goto LABEL_68;
          }
          goto LABEL_66;
        }
        if ( *(_BYTE *)(a1 + 152) == 1 )
        {
          printk(&unk_11531, "battery_chg_report_fast_capacity_work", v27);
          v36 = *v8;
          --*(_DWORD *)(a1 + 408);
          power_supply_changed(v36);
          if ( *(_DWORD *)(a1 + 408) <= v9 )
          {
            v37 = *v8;
            *(_DWORD *)(a1 + 408) = -22;
            power_supply_changed(v37);
            battery_chg_report_fast_capacity_work_is_work_running = 0;
            v3 = &unk_FD3B;
            goto LABEL_3;
          }
          goto LABEL_13;
        }
        v13 = 60000;
        *(_BYTE *)(a1 + 152) = 1;
LABEL_64:
        if ( (*(_DWORD *)(a1 + 408) & 0x80000000) == 0 )
          goto LABEL_66;
        goto LABEL_65;
      }
      if ( v12 != 1 )
      {
        printk(&unk_11A73, "battery_chg_report_fast_capacity_work", a3);
        v29 = *v8;
        *(_DWORD *)(a1 + 408) = -22;
        result = power_supply_changed(v29);
        goto LABEL_67;
      }
      v10 = *(unsigned int **)(a1 - 256);
      goto LABEL_15;
    }
    v23 = *(_DWORD *)(a1 + 136);
    if ( *(_DWORD *)(*(_QWORD *)(a1 - 208) + 52LL) != 7 )
    {
      if ( v23 >= 1 )
      {
        printk(&unk_1176F, "battery_chg_report_fast_capacity_work", a3);
        a3 = *(unsigned int *)(a1 + 408);
        *(_DWORD *)(a1 + 136) = -22;
      }
      if ( (a3 & 0x80000000) != 0 )
        goto LABEL_24;
      goto LABEL_56;
    }
    printk(&unk_117AF, "battery_chg_report_fast_capacity_work", (unsigned int)v23);
    v24 = *(_DWORD *)(a1 + 136);
    v25 = (unsigned int)(v24 / 100);
    if ( v24 / 100 < v9 )
    {
      *(_DWORD *)(a1 + 136) = ++v24;
      v25 = (unsigned int)(v24 / 100);
    }
    if ( (_DWORD)v25 == v9 )
    {
      *(_DWORD *)(a1 + 408) = -22;
      if ( v24 == 10000 )
      {
        battery_chg_report_fast_capacity_work_is_work_running = 0;
        send_capacity_event(v6, 10000);
        v3 = &unk_11C96;
        goto LABEL_3;
      }
      printk(&unk_FE70, "battery_chg_report_fast_capacity_work", v25);
      v13 = 1500;
      goto LABEL_64;
    }
    if ( (_DWORD)v25 == *(_DWORD *)(a1 + 408) )
    {
      v26 = (int)v25 < v9;
      if ( (int)v25 > v9 )
      {
LABEL_48:
        v13 = 1500;
        goto LABEL_64;
      }
    }
    else
    {
      *(_DWORD *)(a1 + 408) = v25;
      printk(&unk_118F5, "battery_chg_report_fast_capacity_work", v25);
      power_supply_changed(*v8);
      v26 = *(_DWORD *)(a1 + 136) / 100 < v9;
      if ( *(_DWORD *)(a1 + 136) / 100 > v9 )
        goto LABEL_48;
    }
    if ( v26 )
      v13 = 200;
    else
      v13 = -1;
    goto LABEL_64;
  }
  v3 = &unk_11889;
LABEL_3:
  result = printk(v3, "battery_chg_report_fast_capacity_work", a3);
LABEL_68:
  _ReadStatusReg(SP_EL0);
  return result;
}
