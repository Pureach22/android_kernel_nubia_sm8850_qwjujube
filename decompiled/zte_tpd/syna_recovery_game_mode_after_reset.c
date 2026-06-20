__int64 __fastcall syna_recovery_game_mode_after_reset(int *a1)
{
  __int64 v2; // x9
  unsigned int v3; // w19
  int v4; // w0
  __int64 v5; // x2
  void *v6; // x19
  void *v7; // x0
  __int64 v9; // x2
  __int64 v10; // x2
  __int64 v11; // x2
  __int64 v12; // x2
  int v13; // w0

  if ( !a1 )
    return 4294967274LL;
  v2 = *((_QWORD *)a1 + 78);
  if ( v2 != -168 && *(_DWORD *)(v2 + 184) && (*(_BYTE *)(v2 + 188) & 1) != 0 )
    v3 = 0;
  else
    v3 = *(_DWORD *)(*(_QWORD *)a1 + 524LL);
  if ( a1[375] )
  {
    printk(&unk_35F27, "syna_dev_set_play_game", 1);
    if ( (syna_tcm_set_dynamic_config(*(_QWORD *)a1, 213, 3, v3) & 0x80000000) != 0 )
      printk(&unk_34708, "syna_recovery_game_mode_after_reset", v9);
    if ( (syna_dev_set_tp_report_rate(a1, a1[382], v3) & 0x80000000) != 0 )
      printk(&unk_37D46, "syna_recovery_game_mode_after_reset", v10);
    if ( (syna_dev_set_sensibility_level(a1, a1[383], v3) & 0x80000000) != 0 )
      printk(&unk_34708, "syna_recovery_game_mode_after_reset", v11);
    if ( (syna_dev_set_follow_hand_level(a1, a1[384], v3) & 0x80000000) != 0 )
      printk(&unk_34708, "syna_recovery_game_mode_after_reset", v12);
    v13 = syna_dev_set_stability_level(a1, a1[385], v3);
    v6 = &unk_3BDE4;
    if ( (v13 & 0x80000000) == 0 )
      goto LABEL_22;
    v7 = &unk_34708;
    goto LABEL_21;
  }
  v4 = syna_dev_set_tp_report_rate(a1, a1[382], v3);
  v6 = &unk_3A258;
  if ( v4 < 0 )
  {
    v7 = &unk_37D46;
LABEL_21:
    printk(v7, "syna_recovery_game_mode_after_reset", v5);
  }
LABEL_22:
  printk(v6, "syna_recovery_game_mode_after_reset", v5);
  return 0;
}
