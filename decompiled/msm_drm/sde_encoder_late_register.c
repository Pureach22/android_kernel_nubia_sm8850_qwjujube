__int64 __fastcall sde_encoder_late_register(__int64 a1)
{
  __int64 v2; // x8
  __int64 dir; // x0
  unsigned int v4; // w8
  __int64 v5; // x0
  void (*v6)(void); // x9
  __int64 v7; // x0
  void (*v8)(void); // x9
  __int64 v9; // x0
  void (*v10)(void); // x9
  __int64 v11; // x0
  void (*v12)(void); // x9
  __int64 result; // x0
  void *v14; // x0
  void *v15; // x0
  char s[8]; // [xsp+8h] [xbp-18h] BYREF
  int v17; // [xsp+10h] [xbp-10h]
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  *(_QWORD *)s = 0;
  if ( !a1 )
  {
    v15 = &unk_26FCAB;
LABEL_37:
    printk(v15, "_sde_encoder_init_debugfs");
    result = 4294967274LL;
    goto LABEL_38;
  }
  if ( !*(_QWORD *)a1 )
  {
    v14 = &unk_26FCAB;
    goto LABEL_36;
  }
  v2 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v2 || !*(_QWORD *)(v2 + 8) )
  {
    v14 = &unk_234896;
LABEL_36:
    printk(v14, "sde_encoder_get_kms");
    v15 = &unk_25E374;
    goto LABEL_37;
  }
  snprintf(s, 0xCu, "encoder%u", *(_DWORD *)(a1 + 24));
  dir = debugfs_create_dir(s, *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 64LL) + 32LL));
  *(_QWORD *)(a1 + 520) = dir;
  if ( !dir )
  {
    result = 4294967284LL;
    goto LABEL_38;
  }
  debugfs_create_file("status", 256, dir, a1, &sde_encoder_init_debugfs_debugfs_status_fops);
  debugfs_create_file(
    "sim_arp_panel_mode",
    384,
    *(_QWORD *)(a1 + 520),
    a1,
    &sde_encoder_init_debugfs_sde_arp_sim_mode_fops);
  debugfs_create_u32("arp_te_time_in_ms", 384, *(_QWORD *)(a1 + 520), a1 + 4880);
  debugfs_create_file(
    "arp_freq_steps",
    384,
    *(_QWORD *)(a1 + 520),
    a1,
    &sde_encoder_init_debugfs_debugfs_arp_freq_steps_fops);
  debugfs_create_file("misr_data", 384, *(_QWORD *)(a1 + 520), a1, &sde_encoder_init_debugfs_debugfs_misr_fops);
  debugfs_create_bool("idle_power_collapse", 384, *(_QWORD *)(a1 + 520), a1 + 836);
  debugfs_create_u32("frame_trigger_mode", 256, *(_QWORD *)(a1 + 520), a1 + 1316);
  debugfs_create_x32("dynamic_irqs_config", 384, *(_QWORD *)(a1 + 520), a1 + 4928);
  v4 = *(_DWORD *)(a1 + 196);
  if ( !v4 )
    goto LABEL_31;
  v5 = *(_QWORD *)(a1 + 200);
  if ( v5 )
  {
    v6 = *(void (**)(void))(v5 + 16);
    if ( v6 )
    {
      if ( *((_DWORD *)v6 - 1) != 135593734 )
        __break(0x8229u);
      v6();
      v4 = *(_DWORD *)(a1 + 196);
    }
  }
  if ( v4 < 2 )
    goto LABEL_31;
  v7 = *(_QWORD *)(a1 + 208);
  if ( v7 )
  {
    v8 = *(void (**)(void))(v7 + 16);
    if ( v8 )
    {
      if ( *((_DWORD *)v8 - 1) != 135593734 )
        __break(0x8229u);
      v8();
      v4 = *(_DWORD *)(a1 + 196);
    }
  }
  if ( v4 < 3 )
    goto LABEL_31;
  v9 = *(_QWORD *)(a1 + 216);
  if ( v9 )
  {
    v10 = *(void (**)(void))(v9 + 16);
    if ( v10 )
    {
      if ( *((_DWORD *)v10 - 1) != 135593734 )
        __break(0x8229u);
      v10();
      v4 = *(_DWORD *)(a1 + 196);
    }
  }
  if ( v4 < 4 )
    goto LABEL_31;
  v11 = *(_QWORD *)(a1 + 224);
  if ( v11 )
  {
    v12 = *(void (**)(void))(v11 + 16);
    if ( v12 )
    {
      if ( *((_DWORD *)v12 - 1) != 135593734 )
        __break(0x8229u);
      v12();
      v4 = *(_DWORD *)(a1 + 196);
    }
  }
  if ( v4 <= 4 )
  {
LABEL_31:
    result = 0;
LABEL_38:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return sde_encoder_early_unregister();
}
