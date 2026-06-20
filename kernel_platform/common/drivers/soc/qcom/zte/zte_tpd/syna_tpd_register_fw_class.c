__int64 __fastcall syna_tpd_register_fw_class(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x0
  __int64 v5; // x2
  __int64 v6; // x2
  __int64 v7; // x0
  void (*v8)(void); // x8
  __int64 v9; // x2
  __int64 v10; // x8
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  printk(unk_390F2, "syna_tpd_register_fw_class", a3);
  v4 = alloc_workqueue(unk_364AC, 393226, 1, "syna_charger_detect");
  *(_QWORD *)(a1 + 1672) = v4;
  if ( v4 )
  {
    v7 = syna_get_charger_status_batt_psy;
    if ( syna_get_charger_status_batt_psy
      || (v7 = power_supply_get_by_name("battery"), (syna_get_charger_status_batt_psy = v7) != 0) )
    {
      v8 = *(void (**)(void))(*(_QWORD *)v7 + 40LL);
      if ( *((_DWORD *)v8 - 1) != -392622893 )
        __break(0x8228u);
      v8();
    }
    printk(unk_3A676, "syna_get_charger_status", 0);
    syna_usb_detect_flag = 0;
    *(_QWORD *)(a1 + 1568) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(a1 + 1576) = a1 + 1576;
    *(_QWORD *)(a1 + 1584) = a1 + 1576;
    *(_QWORD *)(a1 + 1592) = syna_work_charger_detect_work;
    init_timer_key(a1 + 1600, &delayed_work_timer_fn, 0x200000, 0, 0);
    printk(unk_37409, "syna_init_charger_notifier", v9);
    *(_QWORD *)(a1 + 1680) = syna_charger_notify_call;
    power_supply_reg_notifier(a1 + 1680);
  }
  else
  {
    printk(unk_3D4B9, "syna_tpd_register_fw_class", v5);
  }
  v10 = tpd_cdev;
  *(_QWORD *)(tpd_cdev + 3176) = tpd_init_tpinfo;
  *(_QWORD *)(v10 + 3184) = tpd_get_wakegesture;
  *(_QWORD *)(v10 + 3192) = tpd_enable_wakegesture;
  *(_QWORD *)(v10 + 3360) = tpd_get_singlegamegesture;
  *(_QWORD *)(v10 + 3368) = tpd_set_singlegamegesture;
  *(_QWORD *)(v10 + 3344) = tpd_get_singleaodgesture;
  *(_QWORD *)(v10 + 3352) = tpd_set_singleaodgesture;
  *(_QWORD *)(v10 + 3328) = tpd_get_singlefpgesture;
  *(_QWORD *)(v10 + 3336) = tpd_set_singlefpgesture;
  *(_QWORD *)(v10 + 3392) = tpd_set_one_key;
  *(_QWORD *)(v10 + 3384) = tpd_get_one_key;
  *(_QWORD *)(v10 + 3560) = tpd_test_cmd_store;
  *(_QWORD *)(v10 + 3552) = tpd_test_cmd_show;
  *(_QWORD *)(v10 + 3424) = tpd_get_tp_report_rate;
  *(_QWORD *)(v10 + 3416) = tpd_set_tp_report_rate;
  *(_QWORD *)(v10 + 3496) = tpd_get_sensibility_level;
  *(_QWORD *)(v10 + 3504) = tpd_set_sensibility_level;
  *(_QWORD *)(v10 + 3440) = tpd_get_follow_hand_level;
  *(_QWORD *)(v10 + 3432) = tpd_set_follow_hand_level;
  *(_QWORD *)(v10 + 3456) = tpd_get_stability_level;
  *(_QWORD *)(v10 + 3448) = tpd_set_stability_level;
  *(_QWORD *)(v10 + 3280) = tpd_get_rotation_limit_level;
  *(_QWORD *)(v10 + 3272) = tpd_set_rotation_limit_level;
  *(_QWORD *)(v10 + 3288) = tpd_set_display_rotation;
  *(_QWORD *)(v10 + 3400) = tpd_get_play_game;
  *(_QWORD *)(v10 + 3408) = tpd_set_play_game;
  *(_QWORD *)(v10 + 3480) = tpd_set_game_partition;
  *(_QWORD *)(v10 + 3656) = tpd_get_frame_data;
  *(_QWORD *)(v10 + 3648) = tpd_set_frame_data;
  *(_QWORD *)(v10 + 3568) = tpd_get_palm_mode;
  *(_QWORD *)(v10 + 3576) = tpd_set_palm_mode;
  *(_QWORD *)(v10 + 3640) = syna_ghost_check_reset;
  *(_QWORD *)(v10 + 3608) = tpd_set_fake_sleep;
  *(_QWORD *)(v10 + 3600) = tpd_get_fake_sleep;
  *(_QWORD *)(v10 + 3624) = tpd_set_screen_off_awake;
  *(_QWORD *)(v10 + 3072) = a1;
  *(_QWORD *)(v10 + 3616) = tpd_get_screen_off_awake;
  *(_WORD *)(v10 + 1090) = *(_DWORD *)(a1 + 952);
  *(_WORD *)(v10 + 1092) = *(_DWORD *)(a1 + 956);
  result = printk(unk_3AECC, "syna_tpd_register_fw_class", v6);
  _ReadStatusReg(SP_EL0);
  return result;
}
