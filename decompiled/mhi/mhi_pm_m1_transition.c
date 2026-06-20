__int64 __fastcall mhi_pm_m1_transition(__int64 a1)
{
  __int64 v2; // x21
  _DWORD *v3; // x8
  __int64 v5; // x22
  __int64 v6; // x8
  void (__fastcall *v7)(__int64, __int64); // x8
  void (__fastcall *v8)(__int64, __int64); // x8

  raw_write_lock_irq(a1 + 320);
  if ( (unsigned int)mhi_tryset_pm_state(a1, 8u) != 8 )
    return raw_write_unlock_irq(a1 + 320);
  v2 = *(_QWORD *)(a1 + 16);
  if ( (unsigned int)mhi_write_reg_field(a1, *(_QWORD *)(a1 + 32), 0x38u) )
  {
    v5 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v2 + 40, "[E][%s] Failed to set MHI state to: %s\n", "mhi_set_mhi_state", "M2");
    if ( v5 )
    {
      if ( *(_DWORD *)(v5 + 24) <= 2u )
        ipc_log_string(*(_QWORD *)(v5 + 32), "[E][%s] Failed to set MHI state to: %s\n", "mhi_set_mhi_state", "M2");
    }
  }
  *(_DWORD *)(a1 + 348) = 4;
  raw_write_unlock_irq(a1 + 320);
  ++*(_DWORD *)(a1 + 364);
  _wake_up(a1 + 456, 3, 0, 0);
  if ( *(_DWORD *)(a1 + 356) || *(_DWORD *)(a1 + 352) )
  {
    v6 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( v6 && !*(_DWORD *)(v6 + 24) )
      ipc_log_string(
        *(_QWORD *)(v6 + 32),
        "[D][%s] Exiting M2, pending_pkts: %d dev_wake: %d\n",
        "mhi_pm_m1_transition",
        *(_DWORD *)(a1 + 356),
        *(_DWORD *)(a1 + 352));
    raw_read_lock_bh(a1 + 320);
    v7 = *(void (__fastcall **)(__int64, __int64))(a1 + 488);
    if ( *((_DWORD *)v7 - 1) != 598874997 )
      __break(0x8228u);
    v7(a1, 1);
    v8 = *(void (__fastcall **)(__int64, __int64))(a1 + 496);
    if ( *((_DWORD *)v8 - 1) != 598874997 )
      __break(0x8228u);
    v8(a1, 1);
    return raw_read_unlock_bh(a1 + 320);
  }
  else
  {
    v3 = *(_DWORD **)(a1 + 480);
    if ( *(v3 - 1) != 1183736653 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, _QWORD))v3)(a1, 0);
  }
}
