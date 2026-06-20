__int64 __fastcall battery_chg_probe(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  __int64 v5; // x0
  _QWORD *v6; // x19
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  unsigned int v10; // w22
  __int64 v12; // x0
  unsigned __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x24
  _BOOL8 v16; // x2
  int v17; // w0
  unsigned int v18; // w23
  unsigned int v19; // w25
  unsigned int v20; // w0
  _DWORD *v21; // x0
  unsigned int variable_u32_array; // w0
  unsigned int v23; // w2
  __int64 v24; // x9
  __int64 v25; // x8
  __int64 v26; // x11
  __int64 v27; // x11
  __int64 v28; // x12
  __int64 v29; // x13
  __int64 v30; // x11
  __int64 v31; // x9
  __int64 v32; // x12
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x8
  unsigned __int64 v36; // x0
  unsigned __int64 v37; // x0
  unsigned __int64 v38; // x0
  unsigned __int64 v39; // x0
  unsigned __int64 v40; // x0
  unsigned int v41; // w0
  unsigned __int64 v42; // x0
  unsigned __int64 dir; // x2
  unsigned int v44; // w0
  __int64 v45; // x20
  int v46; // w10
  unsigned int v47; // w0
  void *v48; // x0
  const char *v49; // x1
  const char *v50; // [xsp+8h] [xbp-68h] BYREF
  __int64 v51; // [xsp+10h] [xbp-60h]
  _QWORD *v52; // [xsp+18h] [xbp-58h]
  __int64 (__fastcall *v53)(); // [xsp+20h] [xbp-50h]
  __int64 (__fastcall *v54)(); // [xsp+28h] [xbp-48h]
  __int64 v55; // [xsp+30h] [xbp-40h] BYREF
  _BYTE v56[24]; // [xsp+38h] [xbp-38h]
  __int64 v57; // [xsp+50h] [xbp-20h]
  __int64 v58; // [xsp+58h] [xbp-18h]
  __int64 v59; // [xsp+60h] [xbp-10h]
  __int64 v60; // [xsp+68h] [xbp-8h]

  v4 = a1 + 16;
  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v53 = nullptr;
  v54 = nullptr;
  v51 = 0;
  v52 = nullptr;
  v50 = nullptr;
  printk(&unk_11B06, "battery_chg_probe", a3);
  v5 = devm_kmalloc(v4, 1168, 3520);
  if ( !v5 )
  {
    dev_err(v4, "bcdev devm_kzalloc fail\n");
LABEL_7:
    v10 = -12;
    goto LABEL_8;
  }
  v6 = (_QWORD *)v5;
  *(_QWORD *)(v5 + 368) = &battery_prop_map;
  *(_QWORD *)(v5 + 384) = 0x3000000033LL;
  *(_DWORD *)(v5 + 392) = 49;
  *(_QWORD *)(v5 + 416) = &usb_prop_map;
  *(_QWORD *)(v5 + 432) = 0x3200000010LL;
  *(_DWORD *)(v5 + 440) = 51;
  *(_QWORD *)(v5 + 464) = &wls_prop_map;
  *(_QWORD *)(v5 + 480) = 0x3400000016LL;
  *(_DWORD *)(v5 + 488) = 53;
  v7 = devm_kmalloc(v4, 204, 3520);
  v6[47] = v7;
  if ( !v7
    || (v8 = devm_kmalloc(v4, 4LL * *((unsigned int *)v6 + 108), 3520), (v6[53] = v8) == 0)
    || (v9 = devm_kmalloc(v4, 4LL * *((unsigned int *)v6 + 120), 3520), (v6[59] = v9) == 0) )
  {
    dev_err(v4, "bcdev->psy_list.prop devm_kcalloc fail\n");
    goto LABEL_7;
  }
  v12 = devm_kmalloc(v4, 128, 3520);
  v6[45] = v12;
  if ( !v12 )
  {
    dev_err(v4, "bcdev->psy_list.model devm_kcalloc fail\n");
    goto LABEL_7;
  }
  _mutex_init(v6 + 18, "&bcdev->rw_lock", &battery_chg_probe___key);
  _init_rwsem(v6 + 24, "&bcdev->state_sem", &battery_chg_probe___key_16);
  *((_DWORD *)v6 + 64) = 0;
  _init_swait_queue_head(v6 + 33, "&x->wait", &init_completion___key);
  *((_DWORD *)v6 + 72) = 0;
  _init_swait_queue_head(v6 + 37, "&x->wait", &init_completion___key);
  *((_DWORD *)v6 + 80) = 0;
  _init_swait_queue_head(v6 + 41, "&x->wait", &init_completion___key);
  v6[70] = 0xFFFFFFFE00000LL;
  v6[71] = v6 + 71;
  v6[72] = v6 + 71;
  v6[73] = battery_chg_subsys_up_work;
  v6[74] = 0xFFFFFFFE00000LL;
  v6[75] = v6 + 75;
  v6[76] = v6 + 75;
  v6[77] = battery_chg_update_usb_type_work;
  v6[126] = 0xFFFFFFFE00000LL;
  v6[127] = v6 + 127;
  v6[128] = v6 + 127;
  v6[129] = battery_chg_check_status_work;
  v6[79] = 0xFFFFFFFE00000LL;
  v6[80] = v6 + 80;
  v6[81] = v6 + 80;
  v6[82] = battery_chg_report_fast_capacity_work;
  init_timer_key(v6 + 83, &delayed_work_timer_fn, 0x200000, 0, 0);
  v6[92] = 0xFFFFFFFE00000LL;
  v6[93] = v6 + 93;
  v6[94] = v6 + 93;
  v6[95] = battery_chg_update_prop_work;
  *((_DWORD *)v6 + 192) = -22;
  *((_BYTE *)v6 + 784) = 0;
  v6[99] = 0xFFFFFFFE00000LL;
  v6[100] = v6 + 100;
  v6[101] = v6 + 100;
  v6[102] = battery_chg_screen_on_select_fcc_work;
  init_timer_key(v6 + 103, &delayed_work_timer_fn, 0x200000, 0, 0);
  v6[113] = 0xFFFFFFFE00000LL;
  v6[114] = v6 + 114;
  v6[115] = v6 + 114;
  v6[116] = battery_chg_update_soc_work;
  init_timer_key(v6 + 117, &delayed_work_timer_fn, 0x200000, 0, 0);
  queue_delayed_work_on(32, system_wq, v6 + 113, 2500);
  *((_DWORD *)v6 + 139) = 1;
  LODWORD(v51) = 32778;
  v50 = "battery_charger";
  v52 = v6;
  v53 = battery_chg_callback;
  *v6 = v4;
  v54 = battery_chg_state_cb;
  v13 = pmic_glink_register_client(v4, &v50);
  v6[17] = v13;
  if ( v13 >= 0xFFFFFFFFFFFFF001LL )
  {
    v10 = v13;
    if ( (_DWORD)v13 != -517 )
      dev_err(v4, "Error in registering with pmic_glink %d\n", v13);
    dev_err(v4, "bcdev->client IS_ERR with pmic_glink %d\n", v10);
    goto LABEL_67;
  }
  *((_WORD *)v6 + 525) = 0;
  *((_WORD *)v6 + 523) = 257;
  *((_BYTE *)v6 + 1052) = 1;
  v6[132] = 0;
  *((_BYTE *)v6 + 1048) = 0;
  *((_DWORD *)v6 + 136) = 0;
  down_write(v6 + 24);
  *((_DWORD *)v6 + 139) = 1;
  *((_BYTE *)v6 + 1144) = 1;
  up_write(v6 + 24);
  v6[137] = battery_chg_reboot_notify;
  *((_DWORD *)v6 + 278) = 255;
  *(_QWORD *)((char *)v6 + 1148) = 0;
  register_reboot_notifier(v6 + 137);
  v14 = *v6;
  LODWORD(v55) = 0;
  v15 = *(_QWORD *)(v14 + 744);
  of_property_read_string(v15, "qcom,wireless-fw-name", v6 + 67);
  of_property_read_variable_u32_array(v15, "qcom,shutdown-voltage", v6 + 69, 1, 0);
  *((_BYTE *)v6 + 1076) = of_find_property(v15, "qcom,ship-mode-immediate", 0) != 0;
  v16 = of_find_property(v15, "qcom,fast-capacity-enable", 0) != 0;
  *((_BYTE *)v6 + 624) = v16;
  printk(&unk_10152, "battery_chg_parse_dt", v16);
  *(_DWORD *)(v6[47] + 44LL) = 16000000;
  v17 = of_property_count_elems_of_size(v15, "qcom,thermal-mitigation", 4);
  if ( v17 > 0 )
  {
    v18 = v17;
    v19 = 0;
    *((_DWORD *)v6 + 284) = 0;
    do
    {
      v20 = of_property_read_u32_index(v15, "qcom,thermal-mitigation", v19, &v55);
      if ( (v20 & 0x80000000) != 0 )
      {
        v10 = v20;
        goto LABEL_64;
      }
      ++v19;
    }
    while ( v18 != v19 );
    if ( (int)(v18 + 1) < 0 )
    {
      v6[66] = 0;
      v10 = -12;
    }
    else
    {
      v21 = (_DWORD *)devm_kmalloc(*v6, 4LL * (v18 + 1), 3520);
      v6[66] = v21;
      if ( v21 )
      {
        *v21 = *(_DWORD *)(v6[47] + 44LL);
        variable_u32_array = of_property_read_variable_u32_array(v15, "qcom,thermal-mitigation", v21 + 1, v18, 0);
        if ( (variable_u32_array & 0x80000000) == 0 )
        {
          if ( (unsigned int)charger_100W() )
          {
            memcpy((void *)(v6[66] + 4LL), &array_100w, 0xA0u);
          }
          else if ( (unsigned int)charger_80W() )
          {
            v25 = v6[66];
            v26 = array_80w;
            *(_QWORD *)(v25 + 12) = qword_D8;
            *(_QWORD *)(v25 + 4) = v26;
            v27 = qword_F0;
            v28 = qword_E0;
            v29 = qword_E8;
            *(_QWORD *)(v25 + 44) = qword_F8;
            *(_QWORD *)(v25 + 36) = v27;
            *(_QWORD *)(v25 + 28) = v29;
            *(_QWORD *)(v25 + 20) = v28;
            v30 = qword_110;
            v32 = qword_100;
            v31 = qword_108;
            *(_QWORD *)(v25 + 76) = qword_118;
            *(_QWORD *)(v25 + 68) = v30;
            *(_QWORD *)(v25 + 60) = v31;
            *(_QWORD *)(v25 + 52) = v32;
          }
          goto LABEL_30;
        }
        v10 = variable_u32_array;
        printk(&unk_10977, "battery_chg_parse_dt", variable_u32_array);
      }
      else
      {
        v10 = -12;
      }
    }
LABEL_64:
    v49 = "Failed to parse dt rc=%d\n";
    goto LABEL_65;
  }
  if ( (of_property_read_variable_u32_array(v15, "qcom,thermal-mitigation-step", &v55, 1, 0) & 0x80000000) != 0 )
    goto LABEL_31;
  v23 = v55;
  if ( (unsigned int)v55 < 0x7A120 || (v24 = v6[47], (unsigned int)v55 >= *(_DWORD *)(v24 + 44)) )
  {
    printk(&unk_10D36, "battery_chg_parse_dt", (unsigned int)v55);
    v10 = -22;
    goto LABEL_64;
  }
  *((_DWORD *)v6 + 284) = v55;
  v18 = (__PAIR64__(*(_DWORD *)(v24 + 44) / v23, *(_DWORD *)(v24 + 44) % v23) - 500000) >> 32;
LABEL_30:
  v33 = v6[47];
  *((_DWORD *)v6 + 137) = v18;
  *((_DWORD *)v6 + 280) = *(_DWORD *)(v33 + 44);
LABEL_31:
  v34 = *v6;
  *(_QWORD *)(a1 + 168) = v6;
  *((_DWORD *)v6 + 281) = 1000000;
  *((_DWORD *)v6 + 260) = -22;
  v35 = *(_QWORD *)(v34 + 744);
  v58 = 0;
  v59 = 0;
  v57 = 0;
  *(_QWORD *)v56 = 0;
  *(_OWORD *)&v56[8] = (unsigned __int64)v6;
  v55 = v35;
  v36 = ((__int64 (*)(void))devm_power_supply_register)();
  v6[50] = v36;
  if ( v36 >= 0xFFFFFFFFFFFFF001LL )
  {
    v10 = v36;
    v6[50] = 0;
    v48 = &unk_11567;
  }
  else
  {
    v37 = devm_power_supply_register(*v6, &wls_psy_desc, &v55);
    v6[56] = v37;
    if ( v37 >= 0xFFFFFFFFFFFFF001LL )
    {
      v10 = v37;
      v6[56] = 0;
      v48 = &unk_10BAF;
    }
    else
    {
      v38 = devm_power_supply_register(*v6, &batt_psy_desc, &v55);
      v6[44] = v38;
      if ( v38 >= 0xFFFFFFFFFFFFF001LL )
      {
        v10 = v38;
        v6[44] = 0;
        v48 = &unk_11B32;
      }
      else
      {
        v39 = zte_devm_power_supply_register(*v6, &zte_batt_psy_desc, &v55);
        v6[62] = v39;
        if ( v39 >= 0xFFFFFFFFFFFFF001LL )
        {
          v10 = v39;
          v48 = &unk_10F34;
        }
        else
        {
          v40 = zte_devm_power_supply_register(*v6, &zte_usb_psy_desc, &v55);
          v6[63] = v40;
          if ( v40 <= 0xFFFFFFFFFFFFF000LL )
            goto LABEL_36;
          v10 = v40;
          v48 = &unk_10188;
        }
      }
    }
  }
  printk(v48, "battery_chg_init_psy", v10);
  if ( (v10 & 0x80000000) != 0 )
    goto LABEL_66;
LABEL_36:
  v6[1] = "qcom-battery";
  v6[2] = &battery_class_groups;
  v41 = class_register(v6 + 1);
  if ( (v41 & 0x80000000) != 0 )
  {
    v10 = v41;
    v49 = "Failed to create battery_class rc=%d\n";
LABEL_65:
    dev_err(v4, v49, v10);
LABEL_66:
    cancel_work_sync(v6 + 70);
    down_write(v6 + 24);
    *((_DWORD *)v6 + 139) = 0;
    *((_BYTE *)v6 + 1144) = 0;
    up_write(v6 + 24);
    pmic_glink_unregister_client(v6[17]);
    cancel_work_sync(v6 + 74);
    cancel_work_sync(v6 + 70);
    cancel_work_sync(v6 + 126);
    complete(v6 + 32);
    unregister_reboot_notifier(v6 + 137);
LABEL_67:
    if ( v6[65] )
      panel_event_notifier_unregister();
    goto LABEL_8;
  }
  v42 = devm_thermal_of_cooling_device_register(v4, *(_QWORD *)(a1 + 760), **(_QWORD **)v6[44], v6, battery_tcd_ops);
  if ( !v42 || v42 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( v42 <= 0xFFFFFFFFFFFFF000LL )
      v10 = 0;
    else
      v10 = v42;
    dev_err(v4, "Failed to register thermal cooling device rc=%d\n", v10);
    class_unregister(v6 + 1);
    goto LABEL_66;
  }
  *((_DWORD *)v6 + 272) = 1000;
  zte_misc_register_callback(&screen_on_node, v6);
  zte_misc_register_callback(&oem_charger_type_node, v6);
  dir = debugfs_create_dir("battery_charger", 0);
  if ( dir >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_1009C, "battery_chg_add_debugfs", dir);
  }
  else
  {
    v6[64] = dir;
    debugfs_create_bool("block_tx", 384);
  }
  v55 = 0x20000800ALL;
  *((_BYTE *)v6 + 1164) = 0;
  *(_QWORD *)&v56[12] = 0;
  *(_QWORD *)&v56[4] = 0;
  *(_DWORD *)v56 = 4;
  v44 = battery_chg_write((__int64)v6, (__int64)&v55, 0x1Cu, 0x3E8u);
  if ( (v44 & 0x80000000) != 0 )
    printk(&unk_11A0A, "battery_chg_notify_enable", v44);
  else
    *((_BYTE *)v6 + 1164) = 1;
  v45 = *v6;
  device_set_wakeup_capable(*v6, 1);
  device_wakeup_enable(v45);
  queue_work_on(32, system_wq, v6 + 74);
  v46 = *((_DWORD *)v6 + 97);
  *(_DWORD *)&v56[12] = 0;
  *(_QWORD *)&v56[4] = 0x1800000000LL;
  v55 = 0x10000800ALL;
  *(_DWORD *)v56 = v46;
  v47 = battery_chg_write((__int64)v6, (__int64)&v55, 0x18u, 0x3E8u);
  if ( (v47 & 0x80000000) != 0 )
  {
    printk(&unk_11154, "get_charge_control_en", v47);
    v10 = 0;
  }
  else
  {
    v10 = 0;
    *((_BYTE *)v6 + 1143) = *(_DWORD *)(v6[47] + 96LL) != 0;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v10;
}
