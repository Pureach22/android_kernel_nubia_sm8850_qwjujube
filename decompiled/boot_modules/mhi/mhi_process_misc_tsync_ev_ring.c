__int64 __fastcall mhi_process_misc_tsync_ev_ring(__int64 a1, __int64 a2)
{
  __int64 v2; // x24
  unsigned int v4; // w22
  __int64 v6; // x21
  __int64 v7; // x23
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x21
  __int64 v10; // x10
  bool v11; // cc
  unsigned __int64 v12; // x11
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x12
  __int64 v15; // x14
  unsigned __int64 v16; // x12
  unsigned __int64 v17; // x9
  bool v18; // cf
  _QWORD *v19; // x10
  unsigned __int64 v20; // x9
  int v21; // w22
  __int64 v22; // x21
  __int64 v23; // x9
  __int64 *i; // x22
  __int64 **v25; // x8
  __int64 *v26; // x9
  __int64 v27; // x0
  void (__fastcall *v28)(__int64, __int64, __int64, __int64); // x8
  __int64 v29; // x1
  __int64 v30; // x2
  void (__fastcall *v31)(_QWORD); // x8
  __int64 v32; // x22
  unsigned int v33; // w21
  __int64 v34; // x8
  __int64 v36; // x21
  __int64 v37; // x21
  void (__fastcall *v38)(_QWORD); // x8

  v2 = *(_QWORD *)(a1 + 16);
  v4 = *(_DWORD *)(a2 + 16);
  v6 = **(_QWORD **)(a1 + 264);
  v7 = *(_QWORD *)(*(_QWORD *)(v2 + 192) + 104LL);
  raw_spin_lock_bh(a2 + 240);
  v8 = *(_QWORD *)(a2 + 48);
  v9 = *(_QWORD *)(v6 + 44LL * v4 + 28);
  if ( v9 < v8 || ((v10 = *(_QWORD *)(a2 + 104), (v9 & 0xF) == 0) ? (v11 = v10 + v8 > v9) : (v11 = 0), !v11) )
  {
    v32 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v2 + 40, "[E][%s] tsync event ring pointer is invalid rp: %llx\n", "mhi_process_misc_tsync_ev_ring", v9);
    if ( v32 && *(_DWORD *)(v32 + 24) <= 2u )
      ipc_log_string(
        *(_QWORD *)(v32 + 32),
        "[E][%s] tsync event ring pointer is invalid rp: %llx\n",
        "mhi_process_misc_tsync_ev_ring",
        v9);
    goto LABEL_40;
  }
  v12 = *(_QWORD *)(a2 + 72);
  v13 = v12 + v9 - v8;
  if ( *(_QWORD *)(a2 + 80) == v13 )
  {
LABEL_40:
    raw_spin_unlock_bh(a2 + 240);
LABEL_41:
    v33 = 0;
    goto LABEL_42;
  }
  if ( v9 == v8 )
    v13 = v12 + v10;
  v14 = v13 - 32;
  *(_QWORD *)(a2 + 80) = v13 - 16;
  v15 = *(_QWORD *)(a2 + 96);
  if ( v13 - 32 < v12 )
    v14 = v12 + v10 - v15;
  v16 = v14 + v15;
  v17 = v8 - v12;
  v18 = v16 >= v12 + v10;
  v19 = *(_QWORD **)(a2 + 56);
  if ( !v18 )
    v12 = v16;
  *(_QWORD *)(a2 + 88) = v12;
  *v19 = v17 + v12;
  v20 = *(_QWORD *)(a2 + 80) + *(_QWORD *)(a2 + 96);
  if ( v20 >= *(_QWORD *)(a2 + 72) + *(_QWORD *)(a2 + 104) )
    v20 = *(_QWORD *)(a2 + 72);
  *(_QWORD *)(a2 + 80) = v20;
  __dmb(0xAu);
  if ( *(unsigned __int8 *)(v13 - 2) << 16 == 4718592 )
  {
    v21 = *(_DWORD *)(v13 - 8);
    v22 = *(_QWORD *)(v13 - 16);
    v23 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( v23 && !*(_DWORD *)(v23 + 24) )
      ipc_log_string(
        *(_QWORD *)(v23 + 32),
        "[D][%s] Received TSYNC event with seq: 0x%x time: 0x%llx\n",
        "mhi_process_misc_tsync_ev_ring",
        v21,
        v22);
    raw_read_lock_bh(a1 + 320);
    if ( (*(_DWORD *)(a1 + 340) & *(_DWORD *)(a1 + 336)) != 0 )
      mhi_ring_er_db((__int64 *)a2);
    raw_read_unlock_bh(a1 + 320);
    raw_spin_unlock_bh(a2 + 240);
    mutex_lock(v7 + 128);
    if ( *(_DWORD *)(v7 + 40) == v21 )
    {
      raw_spin_lock(v7 + 104);
      for ( i = *(__int64 **)(v7 + 112); i != (__int64 *)(v7 + 112) && i; i = *(__int64 **)(v7 + 112) )
      {
        v25 = (__int64 **)i[1];
        if ( *v25 == i && (v26 = (__int64 *)*i, *(__int64 **)(*i + 8) == i) )
        {
          v26[1] = (__int64)v25;
          *v25 = v26;
        }
        else
        {
          _list_del_entry_valid_or_report(i);
        }
        *i = 0xDEAD000000000100LL;
        i[1] = 0xDEAD000000000122LL;
        raw_spin_unlock(v7 + 104);
        v27 = i[4];
        v28 = (void (__fastcall *)(__int64, __int64, __int64, __int64))i[5];
        v29 = *((unsigned int *)i + 4);
        v30 = *(_QWORD *)(v7 + 48);
        if ( *((_DWORD *)v28 - 1) != -8617430 )
          __break(0x8228u);
        v28(v27, v29, v30, v22);
        kfree(i);
        raw_spin_lock(v7 + 104);
      }
      raw_spin_unlock(v7 + 104);
      *(_BYTE *)(v7 + 64) = 0;
      *(_QWORD *)(v7 + 56) = v22;
      complete(v7 + 72);
      v31 = *(void (__fastcall **)(_QWORD))(a1 + 528);
      if ( *((_DWORD *)v31 - 1) != -2145957670 )
        __break(0x8228u);
      v31(a1);
      mhi_device_put(*(_QWORD *)(a1 + 16));
      mutex_unlock(v7 + 128);
      goto LABEL_41;
    }
    __break(0x800u);
    v37 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(
      v2 + 40,
      "[E][%s] Unexpected response: 0x%x Expected: 0x%x\n",
      "mhi_process_misc_tsync_ev_ring",
      v21,
      *(_DWORD *)(v7 + 40));
    if ( v37 && *(_DWORD *)(v37 + 24) <= 2u )
      ipc_log_string(
        *(_QWORD *)(v37 + 32),
        "[E][%s] Unexpected response: 0x%x Expected: 0x%x\n",
        "mhi_process_misc_tsync_ev_ring",
        v21,
        *(_DWORD *)(v7 + 40));
    v38 = *(void (__fastcall **)(_QWORD))(a1 + 528);
    if ( *((_DWORD *)v38 - 1) != -2145957670 )
      __break(0x8228u);
    v38(a1);
    mhi_device_put(*(_QWORD *)(a1 + 16));
    mutex_unlock(v7 + 128);
    v33 = -22;
  }
  else
  {
    __break(0x800u);
    v36 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v2 + 40, "[E][%s] !TIMESYNC event\n", "mhi_process_misc_tsync_ev_ring");
    if ( v36 && *(_DWORD *)(v36 + 24) <= 2u )
      ipc_log_string(*(_QWORD *)(v36 + 32), "[E][%s] !TIMESYNC event\n", "mhi_process_misc_tsync_ev_ring");
    raw_spin_unlock_bh(a2 + 240);
    v33 = -22;
  }
LABEL_42:
  v34 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( v34 && !*(_DWORD *)(v34 + 24) )
    ipc_log_string(
      *(_QWORD *)(v34 + 32),
      "[D][%s] exit er_index: %u, ret: %d\n",
      "mhi_process_misc_tsync_ev_ring",
      *(_DWORD *)(a2 + 16),
      v33);
  return v33;
}
