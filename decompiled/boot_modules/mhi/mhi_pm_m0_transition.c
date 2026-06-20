__int64 __fastcall mhi_pm_m0_transition(__int64 a1)
{
  __int64 v2; // x21
  int v3; // w20
  void (__fastcall *v4)(__int64, __int64); // x8
  unsigned int v5; // w8
  unsigned int v6; // w8
  __int64 v7; // x20
  unsigned int v8; // w23
  __int64 v9; // x21
  __int64 v10; // x20
  unsigned int v11; // w21
  _DWORD *v12; // x8
  __int64 v14; // x19

  v2 = *(_QWORD *)(a1 + 16);
  raw_write_lock_irq(a1 + 320);
  *(_DWORD *)(a1 + 348) = 2;
  v3 = mhi_tryset_pm_state(a1, 4u);
  raw_write_unlock_irq(a1 + 320);
  if ( v3 == 4 )
  {
    ++*(_DWORD *)(a1 + 360);
    raw_read_lock_bh(a1 + 320);
    v4 = *(void (__fastcall **)(__int64, __int64))(a1 + 488);
    if ( *((_DWORD *)v4 - 1) != 598874997 )
      __break(0x8228u);
    v4(a1, 1);
    v5 = *(_DWORD *)(a1 + 344);
    if ( v5 <= 7 && ((1 << v5) & 0x94) != 0 )
    {
      v6 = *(_DWORD *)(a1 + 212);
      v7 = *(_QWORD *)(a1 + 256);
      if ( v6 )
      {
        v8 = 0;
        v9 = *(_QWORD *)(a1 + 248) + 240LL;
        do
        {
          if ( (*(_BYTE *)(v9 + 18) & 1) == 0 )
          {
            raw_spin_lock_irq(v9);
            mhi_ring_er_db((__int64 *)(v9 - 240));
            raw_spin_unlock_irq(v9);
            v6 = *(_DWORD *)(a1 + 212);
          }
          ++v8;
          v9 += 264;
        }
        while ( v8 < v6 );
      }
      raw_spin_lock_irq(v7 + 96);
      if ( *(_QWORD *)(v7 + 40) != *(_QWORD *)(v7 + 48) )
        mhi_ring_cmd_db(a1, v7);
      raw_spin_unlock_irq(v7 + 96);
      mhi_misc_dbs_pending(a1);
    }
    if ( *(_DWORD *)(a1 + 208) )
    {
      v10 = *(_QWORD *)(a1 + 176);
      v11 = 0;
      do
      {
        if ( *(_BYTE *)(v10 + 224) == 1 )
        {
          raw_write_lock_irq(v10 + 368);
          *(_BYTE *)(v10 + 225) = 1;
          raw_write_unlock_irq(v10 + 368);
        }
        raw_read_lock_irq(v10 + 368);
        if ( *(_QWORD *)(v10 + 136) && *(_QWORD *)(v10 + 152) != *(_QWORD *)(v10 + 144) && *(_DWORD *)(v10 + 260) == 1 )
          mhi_ring_chan_db(a1, v10);
        raw_read_unlock_irq(v10 + 368);
        ++v11;
        v10 += 400;
      }
      while ( v11 < *(_DWORD *)(a1 + 208) );
    }
    v12 = *(_DWORD **)(a1 + 496);
    if ( *(v12 - 1) != 598874997 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v12)(a1, 0);
    raw_read_unlock_bh(a1 + 320);
    _wake_up(a1 + 456, 3, 0, 0);
    return 0;
  }
  else
  {
    v14 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v2 + 40, "[E][%s] Unable to transition to M0 state\n", "mhi_pm_m0_transition");
    if ( v14 && *(_DWORD *)(v14 + 24) <= 2u )
      ipc_log_string(*(_QWORD *)(v14 + 32), "[E][%s] Unable to transition to M0 state\n", "mhi_pm_m0_transition");
    return 4294967291LL;
  }
}
