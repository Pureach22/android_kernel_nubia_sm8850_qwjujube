__int64 __fastcall tpd_proc_deinit(__int64 a1, __int64 a2, __int64 a3)
{
  if ( !tpd_proc_dir )
    return printk(unk_3CE70, "tpd_proc_deinit", a3);
  remove_proc_entry("ts_information", tpd_proc_dir);
  remove_proc_entry("wake_gesture", tpd_proc_dir);
  remove_proc_entry("smart_cover", tpd_proc_dir);
  remove_proc_entry("glove_mode", tpd_proc_dir);
  remove_proc_entry("FW_upgrade", tpd_proc_dir);
  remove_proc_entry("suspend", tpd_proc_dir);
  remove_proc_entry("headset_state", tpd_proc_dir);
  remove_proc_entry("rotation_limit_level", tpd_proc_dir);
  remove_proc_entry("mRotation", tpd_proc_dir);
  remove_proc_entry("single_tap", tpd_proc_dir);
  remove_proc_entry("single_aod", tpd_proc_dir);
  remove_proc_entry("get_noise", tpd_proc_dir);
  remove_proc_entry("edge_report_limit", tpd_proc_dir);
  remove_proc_entry("one_key", tpd_proc_dir);
  remove_proc_entry("play_game", tpd_proc_dir);
  remove_proc_entry("tp_report_rate", tpd_proc_dir);
  remove_proc_entry("follow_hand_level", tpd_proc_dir);
  remove_proc_entry("sensibility", tpd_proc_dir);
  remove_proc_entry("game_partition", tpd_proc_dir);
  remove_proc_entry("pen_only", tpd_proc_dir);
  remove_proc_entry("finger_lock_flag", tpd_proc_dir);
  remove_proc_entry("tp_self_test", tpd_proc_dir);
  remove_proc_entry("tp_palm_mode", tpd_proc_dir);
  remove_proc_entry("fold_state", tpd_proc_dir);
  remove_proc_entry("fake_sleep", tpd_proc_dir);
  remove_proc_entry("screen_off_awake", tpd_proc_dir);
  remove_proc_entry("BBAT_test", tpd_proc_dir);
  remove_proc_entry("frame_data", tpd_proc_dir);
  remove_proc_entry("ghost_debug", tpd_proc_dir);
  remove_proc_entry("touchscreen", NULL);
  return 0;
}
