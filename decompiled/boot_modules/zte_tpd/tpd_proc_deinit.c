__int64 __fastcall tpd_proc_deinit(__int64 a1, __int64 a2, __int64 a3)
{
  if ( !tpd_proc_dir )
    return printk(&unk_3CE70, "tpd_proc_deinit", a3);
  remove_proc_entry("ts_information");
  remove_proc_entry("wake_gesture");
  remove_proc_entry("smart_cover");
  remove_proc_entry("glove_mode");
  remove_proc_entry("FW_upgrade");
  remove_proc_entry("suspend");
  remove_proc_entry("headset_state");
  remove_proc_entry("rotation_limit_level");
  remove_proc_entry("mRotation");
  remove_proc_entry("single_tap");
  remove_proc_entry("single_aod");
  remove_proc_entry("get_noise");
  remove_proc_entry("edge_report_limit");
  remove_proc_entry("one_key");
  remove_proc_entry("play_game");
  remove_proc_entry("tp_report_rate");
  remove_proc_entry("follow_hand_level");
  remove_proc_entry("sensibility");
  remove_proc_entry("game_partition");
  remove_proc_entry("pen_only");
  remove_proc_entry("finger_lock_flag");
  remove_proc_entry("tp_self_test");
  remove_proc_entry("tp_palm_mode");
  remove_proc_entry("fold_state");
  remove_proc_entry("fake_sleep");
  remove_proc_entry("screen_off_awake");
  remove_proc_entry("BBAT_test");
  remove_proc_entry("frame_data");
  remove_proc_entry("ghost_debug");
  return remove_proc_entry("touchscreen");
}
