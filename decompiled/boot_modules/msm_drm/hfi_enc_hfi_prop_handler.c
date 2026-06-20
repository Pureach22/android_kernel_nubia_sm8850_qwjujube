void __fastcall hfi_enc_hfi_prop_handler(__int64 a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  _QWORD *v5; // x4
  __int64 v6; // x19
  __int64 v7; // t1
  char v9; // w20
  __int64 connector; // x0
  __int64 v11; // x0
  _QWORD *v13; // x20
  __int64 v14; // x21
  __int64 fps; // x1
  __int64 v17; // x0
  __int64 v18; // x20
  __int64 v19; // x0
  int v20; // w4
  void (__fastcall *v21)(__int64, __int64); // x8
  __int64 v22; // x0
  unsigned int v29; // w9
  char v30; // [xsp+0h] [xbp+0h]

  v7 = *(_QWORD *)(a5 - 112);
  v5 = (_QWORD *)(a5 - 112);
  v6 = v7;
  if ( !v5 )
  {
    printk(&unk_2348DE, "hfi_enc_hfi_prop_handler");
    return;
  }
  if ( a2 <= 0x4000000 )
  {
    if ( (unsigned int)(a2 - 33554436) < 2 )
      return;
    if ( a2 == -16777204 )
    {
      v9 = sde_encoder_recovery_events_enabled(v6);
      connector = sde_encoder_get_connector(*(_QWORD *)v6, v6);
      if ( connector )
      {
        if ( *(_DWORD *)(connector + 2740) == *(_DWORD *)a3 )
        {
          if ( (v9 & 1) != 0 )
          {
            sde_connector_event_notify();
          }
          else if ( (*(_BYTE *)(a3 + 4) & 1) != 0 )
          {
            hfi_dbg_ctrl("hfi_enc_hfi_prop_handler", 0, "stop_ftrace", 0);
            hfi_dbg_ctrl("hfi_enc_hfi_prop_handler", 0, "panic_underrun", 0);
          }
          else
          {
            hfi_dbg_dump(1, "hfi_enc_hfi_prop_handler", 0, "panic", 3235823343LL);
          }
        }
        else
        {
          printk(&unk_22A7D4, "hfi_enc_hfi_prop_handler");
        }
      }
      else
      {
        printk(&unk_24F8F8, "hfi_enc_hfi_prop_handler");
      }
      return;
    }
LABEL_34:
    printk(&unk_24F975, "hfi_enc_hfi_prop_handler");
    return;
  }
  if ( a2 != 67108865 )
  {
    if ( a2 == 67108867 )
    {
      hfi_encoder_frame_event_callback(v6, a3, 1);
      return;
    }
    if ( a2 == 67108866 )
    {
      v11 = v6;
      v13 = v5;
      sde_encoder_update_pending_kickoff_cnt(v11);
      hfi_encoder_frame_event_callback(*v13, a3, 25);
      return;
    }
    goto LABEL_34;
  }
  if ( a3 )
  {
    v14 = *(_QWORD *)(v6 + 4976);
    if ( v14 )
    {
      fps = (unsigned int)sde_encoder_get_fps(v6);
      v17 = v6 ? *(unsigned int *)(v6 + 24) : 0xFFFFFFFFLL;
      v19 = sde_encoder_event_timestamp_adjust(v17, fps, 192LL * *(_QWORD *)a3 / 10000);
      v18 = v19;
      _X8 = (unsigned int *)(v14 + 40);
      __asm { PRFM            #0x11, [X8] }
      do
        v29 = __ldxr(_X8);
      while ( __stlxr(v29 + 1, _X8) );
      __dmb(0xBu);
      *(_QWORD *)(v14 + 32) = v19;
      v20 = v6 ? *(_DWORD *)(v6 + 24) : -1;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "hfi_enc_unpack_vsync_event",
        101,
        -1,
        v20,
        *(_DWORD *)(v14 + 40),
        v19,
        -1059143953,
        v30);
    }
    else
    {
      v18 = -22;
    }
    v21 = *(void (__fastcall **)(__int64, __int64))(v6 + 504);
    if ( v21 )
    {
      v22 = *(_QWORD *)(v6 + 512);
      if ( *((_DWORD *)v21 - 1) != -1575138099 )
        __break(0x8228u);
      v21(v22, v18);
    }
  }
}
