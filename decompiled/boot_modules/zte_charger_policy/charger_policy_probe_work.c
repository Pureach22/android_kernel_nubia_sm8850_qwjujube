__int64 __fastcall charger_policy_probe_work(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w9
  int v6; // w10
  int v7; // w8
  int v8; // w8
  __int64 v9; // x0
  _QWORD *v10; // x21
  _QWORD *v11; // x20
  __int64 v12; // x2
  __int64 v13; // x3
  unsigned int v14; // w0
  __int64 v15; // x3
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x3
  __int64 v19; // x0
  unsigned __int64 v20; // x0
  __int64 v21; // x3
  __int64 v22; // x0
  __int64 v23; // x2
  __int64 v24; // x3
  __int64 v25; // x2
  __int64 result; // x0
  __int64 v27; // x2
  __int64 v28; // x3
  void *v29; // x0
  __int64 v30; // [xsp+0h] [xbp-40h] BYREF
  __int64 v31; // [xsp+8h] [xbp-38h]
  __int64 v32; // [xsp+10h] [xbp-30h]
  __int64 v33; // [xsp+18h] [xbp-28h]
  __int64 v34; // [xsp+20h] [xbp-20h]
  __int64 v35; // [xsp+28h] [xbp-18h]
  __int64 v36; // [xsp+30h] [xbp-10h]
  __int64 v37; // [xsp+38h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v30 = 0;
  printk(&unk_A5E9, "charger_policy_probe_work", a3, a4);
  v5 = *(_DWORD *)(a1 + 108);
  v6 = *(_DWORD *)(a1 + 112);
  v7 = *(_DWORD *)(a1 + 124);
  *(_DWORD *)(a1 + 192) = 0;
  *(_QWORD *)(a1 + 212) = 0;
  *(_BYTE *)(a1 + 257) = 0;
  *(_DWORD *)(a1 + 220) = v7;
  *(_DWORD *)(a1 + 224) = 2592000;
  *(_BYTE *)(a1 + 258) = v5 != 0;
  v8 = *(_DWORD *)(a1 + 116);
  *(_QWORD *)(a1 + 232) = 30000;
  *(_QWORD *)(a1 + 240) = 0;
  *(_BYTE *)(a1 + 259) = 0;
  *(_BYTE *)(a1 + 260) = v8 != 0;
  *(_BYTE *)(a1 + 256) = v6 != 0;
  alarm_init(a1 - 240, 1, charger_policy_timeout_alarm_cb);
  v9 = alloc_workqueue(&unk_9B64, 393226, 1, "charger-policy-service");
  *(_QWORD *)(a1 - 112) = 0xFFFFFFFE00000LL;
  v10 = (_QWORD *)(a1 - 112);
  *(_QWORD *)(a1 - 120) = v9;
  v10[1] = a1 - 104;
  v10[2] = a1 - 104;
  v11 = (_QWORD *)(a1 - 280);
  v10[3] = charger_policy_timeout_handler_work;
  init_timer_key(a1 - 80, &delayed_work_timer_fn, 0x200000, 0, 0);
  if ( a1 == 280 )
  {
    printk(&unk_9D53, "charger_policy_probe_work", v12, v13);
    goto LABEL_12;
  }
  *(_QWORD *)(a1 - 264) = charger_policy_notifier_switch;
  v14 = power_supply_reg_notifier(a1 - 264);
  if ( (v14 & 0x80000000) != 0 )
  {
    printk(&unk_ADC3, "charger_policy_register_notifier", v14, v15);
    printk(&unk_9D53, "charger_policy_probe_work", v16, v17);
  }
  else
  {
    v19 = *v11;
    v35 = 0;
    v36 = 0;
    v32 = a1 - 280;
    v33 = 0;
    v30 = 0;
    v31 = 0;
    v34 = 0;
    v20 = devm_power_supply_register(v19, &policy_psy_desc, &v30);
    *(_QWORD *)(a1 - 272) = v20;
    if ( v20 < 0xFFFFFFFFFFFFF001LL )
    {
      zte_misc_register_callback(&demo_charging_policy_node, a1 - 280);
      zte_misc_register_callback(&expired_charging_policy_node, a1 - 280);
      zte_misc_register_callback(&charging_time_sec_node, a1 - 280);
      zte_misc_register_callback(&force_disching_sec_node, a1 - 280);
      zte_misc_register_callback(&policy_cap_min_node, a1 - 280);
      zte_misc_register_callback(&policy_cap_max_node, a1 - 280);
      zte_misc_register_callback(&policy_enable_node, a1 - 280);
      v22 = wakeup_source_register(*v11, "charger_policy_service");
      *(_QWORD *)(a1 + 200) = v22;
      if ( v22 )
      {
        queue_delayed_work_on(32, *(_QWORD *)(a1 - 120), a1 - 112, 25);
        v29 = &unk_9E70;
        goto LABEL_13;
      }
      printk(&unk_AB60, "charger_policy_probe_work", v23, v24);
    }
    else
    {
      printk(&unk_8F98, "charger_policy_probe_work", v20, v21);
    }
    power_supply_unreg_notifier(a1 - 264);
  }
  v25 = (unsigned int)(charger_policy_check_retry_probe_count + 1);
  charger_policy_check_retry_probe_count = v25;
  if ( (unsigned int)v25 >= *(_DWORD *)(a1 + 120) )
  {
LABEL_12:
    devm_kfree(*v11, a1 - 280);
    v29 = &unk_AE89;
LABEL_13:
    result = printk(v29, "charger_policy_probe_work", v27, v28);
    goto LABEL_14;
  }
  printk(&unk_942F, "charger_policy_check_retry", v25, v18);
  result = queue_delayed_work_on(32, *(_QWORD *)(a1 - 8), a1, 1250);
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
