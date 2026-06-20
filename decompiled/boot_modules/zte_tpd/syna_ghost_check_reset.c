__int64 __fastcall syna_ghost_check_reset(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x2
  __int64 v3; // x2

  v1 = *(_QWORD *)(a1 + 3072);
  syna_dev_free_input_events(v1);
  syna_spi_hw_reset(*(_QWORD *)(v1 + 624));
  syna_recovery_game_mode_after_reset((int *)v1);
  syna_dev_set_screen_on_fp_mode((_QWORD *)v1, 0, v2);
  printk(&unk_3AEDE, "syna_ghost_check_reset", v3);
  return 0;
}
