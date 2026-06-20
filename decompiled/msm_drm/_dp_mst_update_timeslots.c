__int64 __fastcall dp_mst_update_timeslots(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 mst_payload_state; // x0
  __int64 v6; // x0
  __int64 v8; // x20
  int v9; // w23
  int v10; // w22
  int v11; // w8
  int v12; // w8
  int v13; // w3
  void (*v14)(void); // x8
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v17; // x8
  int v18; // w3
  int v19; // w3
  void (*v20)(void); // x8
  __int64 v21; // x0
  __int64 v22; // x8
  int v23; // w3

  mst_payload_state = drm_atomic_get_mst_payload_state(*(_QWORD *)(a1 + 120), a3);
  if ( mst_payload_state )
  {
    v8 = mst_payload_state;
    if ( a1 + 1336 == a2 )
    {
      if ( *(char *)(mst_payload_state + 8) < 0 )
      {
        v9 = *(_DWORD *)(a1 + 2708);
        v10 = *(_DWORD *)(a1 + 2704);
        v11 = 0;
        *(_QWORD *)(a1 + 2700) = 0;
        *(_DWORD *)(a1 + 2708) = 1;
      }
      else
      {
        v10 = 0;
        v9 = 0;
        *(_DWORD *)(a1 + 2700) = *(_DWORD *)(mst_payload_state + 16);
        *(_DWORD *)(a1 + 2708) = *(char *)(mst_payload_state + 8);
        *(_DWORD *)(a1 + 2704) = *(_DWORD *)(mst_payload_state + 12);
        v11 = *(unsigned __int8 *)(mst_payload_state + 9);
      }
      *(_DWORD *)(a1 + 2696) = v11;
    }
    else
    {
      v10 = 0;
      v9 = 0;
    }
    if ( a1 + 2728 == a2 )
    {
      if ( *(char *)(mst_payload_state + 8) < 0 )
      {
        v9 = *(_DWORD *)(a1 + 4100);
        v10 = *(_DWORD *)(a1 + 4096);
        v12 = 0;
        *(_QWORD *)(a1 + 4092) = 0;
        *(_DWORD *)(a1 + 4100) = 1;
      }
      else
      {
        *(_DWORD *)(a1 + 4092) = *(_DWORD *)(mst_payload_state + 16);
        *(_DWORD *)(a1 + 4100) = *(char *)(mst_payload_state + 8);
        *(_DWORD *)(a1 + 4096) = *(_DWORD *)(mst_payload_state + 12);
        v12 = *(unsigned __int8 *)(mst_payload_state + 9);
      }
      *(_DWORD *)(a1 + 4088) = v12;
    }
    v13 = *(_DWORD *)(a1 + 2708);
    if ( *(char *)(mst_payload_state + 8) < 0 && v13 > v9 )
      *(_DWORD *)(a1 + 2708) = v13 - v10;
    v14 = *(void (**)(void))(*(_QWORD *)(a1 + 4120) + 264LL);
    if ( *((_DWORD *)v14 - 1) != -133057824 )
      __break(0x8228u);
    v14();
    ipc_log_context = get_ipc_log_context();
    StatusReg = _ReadStatusReg(SP_EL0);
    v17 = *(_QWORD *)(a1 + 2680);
    if ( v17 )
      v18 = *(_DWORD *)(v17 + 64);
    else
      v18 = 0;
    ipc_log_string(
      ipc_log_context,
      "[i][%-4d]conn:%d vcpi:%d start_slot:%d num_slots:%d, pbn:%d\n",
      *(_DWORD *)(StatusReg + 1800),
      v18,
      *(_DWORD *)(a1 + 2696),
      *(_DWORD *)(a1 + 2708),
      *(_DWORD *)(a1 + 2704),
      *(_DWORD *)(a1 + 2700));
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_2530E2, *(unsigned int *)(StatusReg + 1800));
    else
      printk(&unk_24C133, "_dp_mst_update_timeslots");
    v19 = *(_DWORD *)(a1 + 4100);
    if ( *(char *)(v8 + 8) < 0 && v19 > v9 )
      *(_DWORD *)(a1 + 4100) = v19 - v10;
    v20 = *(void (**)(void))(*(_QWORD *)(a1 + 4120) + 264LL);
    if ( *((_DWORD *)v20 - 1) != -133057824 )
      __break(0x8228u);
    v20();
    v21 = get_ipc_log_context();
    v22 = *(_QWORD *)(a1 + 4072);
    if ( v22 )
      v23 = *(_DWORD *)(v22 + 64);
    else
      v23 = 0;
    ipc_log_string(
      v21,
      "[i][%-4d]conn:%d vcpi:%d start_slot:%d num_slots:%d, pbn:%d\n",
      *(_DWORD *)(StatusReg + 1800),
      v23,
      *(_DWORD *)(a1 + 4088),
      *(_DWORD *)(a1 + 4100),
      *(_DWORD *)(a1 + 4096),
      *(_DWORD *)(a1 + 4092));
    if ( (_drm_debug & 4) != 0 )
      return printk(&unk_2530E2, *(unsigned int *)(StatusReg + 1800));
    else
      return printk(&unk_24C133, "_dp_mst_update_timeslots");
  }
  else
  {
    v6 = get_ipc_log_context();
    ipc_log_string(
      v6,
      "[e][%-4d]mst bridge [%d] update_timeslots failed, null payload\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a2 + 400));
    return printk(&unk_21563E, "_dp_mst_update_timeslots");
  }
}
