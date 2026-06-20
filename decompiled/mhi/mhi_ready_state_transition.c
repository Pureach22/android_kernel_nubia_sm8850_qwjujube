__int64 __fastcall mhi_ready_state_transition(__int64 a1)
{
  __int64 v1; // x21
  unsigned int v3; // w0
  int v4; // w6
  unsigned int v5; // w0
  __int64 v6; // x20
  unsigned int v7; // w20
  unsigned int v8; // w8
  __int64 v9; // x20
  unsigned int i; // w21
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 *v13; // x12
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x21
  __int64 v18; // x19
  unsigned int v19; // w20
  __int64 v20; // x19
  unsigned int v21; // w19
  __int64 v22; // x22
  const char *v23; // x19
  const char *v24; // x0
  __int64 v25; // x19
  const char *v26; // x21
  const char *v27; // x0
  __int64 v28; // x20
  __int64 v29; // x20
  __int64 v30; // x20

  v1 = *(_QWORD *)(a1 + 16);
  if ( *(_DWORD *)(a1 + 336) == 4096 )
  {
    v18 = *(_QWORD *)(v1 + 192);
    dev_err(v1 + 40, "[E][%s] Device link is not accessible\n", "mhi_ready_state_transition");
    if ( v18 && *(_DWORD *)(v18 + 24) <= 2u )
    {
      ipc_log_string(*(_QWORD *)(v18 + 32), "[E][%s] Device link is not accessible\n", "mhi_ready_state_transition");
      return 4294967291LL;
    }
    return 4294967291LL;
  }
  v3 = mhi_poll_reg_field(a1, *(_QWORD *)(a1 + 32), 0x38u, 2u, 0, 0x61A8u, *(_DWORD *)(a1 + 328));
  if ( v3 )
  {
    v19 = v3;
    v20 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v1 + 40, "[E][%s] Device failed to clear MHI Reset\n", "mhi_ready_state_transition");
    if ( !v20 || *(_DWORD *)(v20 + 24) > 2u )
      return v19;
    ipc_log_string(*(_QWORD *)(v20 + 32), "[E][%s] Device failed to clear MHI Reset\n", "mhi_ready_state_transition");
    return v19;
  }
  v4 = *(_DWORD *)(a1 + 332);
  if ( !v4 )
    v4 = *(_DWORD *)(a1 + 328);
  v5 = mhi_poll_reg_field(a1, *(_QWORD *)(a1 + 32), 0x48u, 1u, 1, 0x61A8u, v4);
  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( v5 )
  {
    v21 = v5;
    dev_err(v1 + 40, "[E][%s] Device failed to enter MHI Ready\n", "mhi_ready_state_transition");
    if ( !v6 || *(_DWORD *)(v6 + 24) > 2u )
      return v21;
    ipc_log_string(*(_QWORD *)(v6 + 32), "[E][%s] Device failed to enter MHI Ready\n", "mhi_ready_state_transition");
    return v21;
  }
  if ( v6 && !*(_DWORD *)(v6 + 24) )
    ipc_log_string(*(_QWORD *)(v6 + 32), "[D][%s] Device in READY State\n", "mhi_ready_state_transition");
  raw_write_lock_irq(a1 + 320);
  v7 = mhi_tryset_pm_state(a1, 2u);
  *(_DWORD *)(a1 + 348) = 1;
  raw_write_unlock_irq(a1 + 320);
  if ( v7 != 2 )
  {
    v22 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    v23 = to_mhi_pm_state_str(2u);
    v24 = to_mhi_pm_state_str(v7);
    dev_err(v1 + 40, "[E][%s] Error moving to state %s from %s\n", "mhi_ready_state_transition", v23, v24);
    if ( v22 && *(_DWORD *)(v22 + 24) <= 2u )
    {
      v25 = *(_QWORD *)(v22 + 32);
      v26 = to_mhi_pm_state_str(2u);
      v27 = to_mhi_pm_state_str(v7);
      ipc_log_string(v25, "[E][%s] Error moving to state %s from %s\n", "mhi_ready_state_transition", v26, v27);
      return 4294967291LL;
    }
    return 4294967291LL;
  }
  raw_read_lock_bh(a1 + 320);
  if ( (*(_WORD *)(a1 + 336) & 0xFDE) == 0 )
  {
    v28 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v1 + 40, "[E][%s] Device registers not accessible\n", "mhi_ready_state_transition");
    if ( v28 && *(_DWORD *)(v28 + 24) < 3u )
      ipc_log_string(*(_QWORD *)(v28 + 32), "[E][%s] Device registers not accessible\n", "mhi_ready_state_transition");
    goto LABEL_38;
  }
  if ( (unsigned int)mhi_init_mmio(a1) )
  {
    v29 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v1 + 40, "[E][%s] Error configuring MMIO registers\n", "mhi_ready_state_transition");
    if ( v29 && *(_DWORD *)(v29 + 24) < 3u )
      ipc_log_string(*(_QWORD *)(v29 + 32), "[E][%s] Error configuring MMIO registers\n", "mhi_ready_state_transition");
LABEL_38:
    raw_read_unlock_bh(a1 + 320);
    return 4294967291LL;
  }
  v8 = *(_DWORD *)(a1 + 212);
  if ( v8 )
  {
    v9 = *(_QWORD *)(a1 + 248);
    for ( i = 0; i < v8; ++i )
    {
      if ( (*(_BYTE *)(v9 + 258) & 1) == 0 && (((*(_DWORD *)(a1 + 348) != 1) ^ *(unsigned __int8 *)(v9 + 256)) & 1) == 0 )
      {
        v12 = *(_QWORD *)(v9 + 96);
        v11 = *(_QWORD *)(v9 + 104);
        v13 = *(__int64 **)(v9 + 56);
        v14 = *(_QWORD *)(v9 + 72) + v11 - v12;
        v15 = v11 - v12 + *(_QWORD *)(v9 + 48);
        *(_QWORD *)(v9 + 88) = v14;
        *v13 = v15;
        __dmb(0xAu);
        raw_spin_lock_irq(v9 + 240);
        mhi_ring_er_db((__int64 *)v9);
        raw_spin_unlock_irq(v9 + 240);
        v8 = *(_DWORD *)(a1 + 212);
      }
      v9 += 264;
    }
  }
  v16 = *(_QWORD *)(a1 + 16);
  if ( (unsigned int)mhi_write_reg_field(a1, *(_QWORD *)(a1 + 32), 0x38u) )
  {
    v30 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v16 + 40, "[E][%s] Failed to set MHI state to: %s\n", "mhi_set_mhi_state", "M0");
    if ( v30 )
    {
      if ( *(_DWORD *)(v30 + 24) <= 2u )
        ipc_log_string(*(_QWORD *)(v30 + 32), "[E][%s] Failed to set MHI state to: %s\n", "mhi_set_mhi_state", "M0");
    }
  }
  raw_read_unlock_bh(a1 + 320);
  return 0;
}
