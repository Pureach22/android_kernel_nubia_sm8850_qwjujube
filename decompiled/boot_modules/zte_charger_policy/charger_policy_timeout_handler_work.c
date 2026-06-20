__int64 __fastcall charger_policy_timeout_handler_work(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x3
  __int64 v5; // x9
  __int64 v6; // x0
  __int64 v7; // x2
  __int64 v8; // x3
  const char *v9; // x20
  _BOOL4 v11; // w20
  __int64 v12; // x0
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x0
  unsigned int v16; // w8
  void (__fastcall *v17)(_QWORD); // x8
  __int64 result; // x0
  unsigned int v19; // w8
  void *v20; // x0
  __int64 v21; // x3
  __int64 v22; // x2
  __int64 v23; // x3
  __int64 v24; // x2
  __int64 v25; // x3
  __int64 v26; // x2
  __int64 v27; // x3
  int v28; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ktime_get_with_offset(1);
  v3 = ns_to_timespec64(v2);
  v5 = v3 - charger_policy_logger_limit_time_pre_0;
  if ( v3 - charger_policy_logger_limit_time_pre_0 >= 301 )
    charger_policy_logger_limit_time_pre_0 = v3;
  v6 = *(_QWORD *)(a1 + 272);
  v28 = 0;
  *(_BYTE *)(a1 + 373) = v5 > 300;
  if ( (charger_policy_get_prop_by_name(v6, 0, &v28, v4) & 0x80000000) != 0 )
  {
    printk(&unk_A299, "charger_policy_battery_is_charging", v7, v8);
    v9 = "discharging";
  }
  else
  {
    v11 = v28 == 1 || v28 == 4;
    printk(&unk_A4FF, "charger_policy_battery_is_charging", v11, v8);
    if ( v11 )
      v9 = "charging";
    else
      v9 = "discharging";
  }
  if ( *(_DWORD *)(a1 + 324) != *(_DWORD *)(a1 + 328) )
  {
    v12 = *(_QWORD *)(a1 - 160);
    *(_BYTE *)(a1 + 373) = 1;
    if ( v12 )
      power_supply_changed();
  }
  if ( *(_BYTE *)(a1 + 373) == 1 )
  {
    v19 = *(_DWORD *)(a1 + 324);
    if ( v19 >= 4 )
      goto LABEL_46;
    printk(&unk_A6B2, "charger_policy_status_debug", *((_QWORD *)&policy_status_list + 3 * v19 + 1), v9);
  }
  if ( (charger_policy_check_usb_present(a1 - 168) & 1) != 0 )
  {
    if ( (*(_BYTE *)(a1 + 369) & 1) == 0 && *(_BYTE *)(a1 + 370) != 1 )
    {
      v20 = &unk_AC3B;
      goto LABEL_39;
    }
    v15 = *(_QWORD *)(a1 + 272);
    v28 = 0;
    if ( (charger_policy_get_prop_by_name(v15, 0x34u, &v28, v14) & 0x80000000) != 0 )
    {
      printk(&unk_A02D, "charger_policy_check_low_temperature", v13, v14);
      if ( !*(_DWORD *)(a1 + 320) )
        goto LABEL_25;
    }
    else
    {
      if ( *(_BYTE *)(a1 + 368) == 1 )
      {
        v13 = (unsigned int)v28;
        if ( v28 <= 150 )
        {
          printk(&unk_A45B, "charger_policy_check_low_temperature", (unsigned int)v28, 150);
          v20 = &unk_9BDB;
          goto LABEL_39;
        }
      }
      if ( !*(_DWORD *)(a1 + 320) )
      {
LABEL_25:
        if ( *(_DWORD *)(a1 + 324) < 4u )
        {
          alarm_try_to_cancel(a1 - 128);
          alarm_start_relative(a1 - 128, 1000000LL * *(_QWORD *)(a1 + 344));
          _pm_stay_awake(*(_QWORD *)(a1 + 312));
          v16 = *(_DWORD *)(a1 + 324);
          if ( v16 < 4 )
          {
            v17 = *((void (__fastcall **)(_QWORD))&policy_status_list + 3 * v16 + 2);
            if ( v17 )
            {
              if ( *((_DWORD *)v17 - 1) != -508955518 )
                __break(0x8228u);
              v17(a1 - 168);
            }
            result = _pm_relax(*(_QWORD *)(a1 + 312));
            goto LABEL_45;
          }
LABEL_46:
          __break(0x5512u);
        }
        v20 = &unk_9ECB;
        goto LABEL_39;
      }
    }
    v20 = &unk_9EA4;
LABEL_39:
    printk(v20, "charger_policy_status_need_sleep", v13, v14);
  }
  if ( *(_DWORD *)(a1 + 324) )
  {
    _pm_stay_awake(*(_QWORD *)(a1 + 312));
    charger_policy_ctrl_charging_enable(a1 - 168, 1, 1, v21);
    *(_BYTE *)(a1 + 371) = 0;
    *(_QWORD *)(a1 + 352) = 0;
    *(_QWORD *)(a1 + 324) = 0;
    charger_policy_disable_cas(a1 - 168, 0, v22, v23);
    _pm_relax(*(_QWORD *)(a1 + 312));
  }
  else
  {
    charger_policy_ctrl_charging_enable(a1 - 168, 1, 1, v14);
    *(_BYTE *)(a1 + 371) = 0;
    *(_QWORD *)(a1 + 352) = 0;
    *(_QWORD *)(a1 + 324) = 0;
    charger_policy_disable_cas(a1 - 168, 0, v24, v25);
  }
  result = alarm_try_to_cancel(a1 - 128);
  if ( *(_BYTE *)(a1 + 373) == 1 )
    result = printk(&unk_A61A, "charger_policy_notifier_handler", v26, v27);
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
