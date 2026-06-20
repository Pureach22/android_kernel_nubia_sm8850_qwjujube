__int64 __fastcall sde_encoder_phys_vid_wait_for_commit_done(__int64 a1)
{
  __int64 v1; // x21
  unsigned int v3; // w20
  int v4; // w7
  __int64 v5; // x0
  int v7; // w7
  __int64 v8; // x8
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  v1 = *(_QWORD *)a1;
  if ( *(_QWORD *)a1 && *(_BYTE *)(v1 + 4936) == 1 && *(_DWORD *)(a1 + 832) == 3 )
  {
    v3 = 0;
    *(_DWORD *)(a1 + 832) = 4;
  }
  else
  {
    v3 = sde_encoder_phys_vid_wait_for_vblank(a1, 1);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_phys_vid_wait_for_commit_done",
      2033,
      -1,
      *(_DWORD *)(a1 + 888),
      v3,
      -1059143953,
      v4,
      vars0);
    if ( !v3 )
    {
      if ( *(_BYTE *)(v1 + 784) != 1 )
        return 0;
      if ( *(int *)(a1 + 888) < 3 )
        return 0;
      v5 = gpio_to_desc(*(unsigned int *)(v1 + 780));
      if ( (unsigned int)gpiod_get_raw_value(v5) )
        return 0;
      printk(&unk_219A16, "sde_encoder_phys_vid_wait_for_commit_done");
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_encoder_phys_vid_wait_for_commit_done",
        2037,
        -1,
        60333,
        *(_DWORD *)(a1 + 888),
        -1059143953,
        v7,
        vars0a);
      *(_DWORD *)(a1 + 888) = 0;
      if ( (sde_encoder_recovery_events_enabled(*(_QWORD *)a1) & 1) != 0 )
      {
        sde_connector_event_notify(*(_QWORD *)(a1 + 8), 2147483655LL, 1, 2);
        v8 = *(_QWORD *)(a1 + 8);
        if ( v8 )
          *(_BYTE *)(v8 + 4516) = 1;
      }
      v3 = -110;
    }
    sde_encoder_helper_phys_reset((unsigned __int64 *)a1);
  }
  return v3;
}
