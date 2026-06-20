__int64 __fastcall hfi_encoder_frame_event_callback(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // x8
  __int64 v5; // x22
  __int64 v7; // x21
  unsigned int fps; // w0
  __int64 v9; // x8
  __int64 v10; // x0
  unsigned int v11; // w8
  unsigned int v18; // w10
  int v19; // w6
  int v20; // w7
  int v21; // w7
  _DWORD *v22; // x8
  void *v24; // x0
  unsigned int v27; // w9
  char v28; // [xsp+0h] [xbp-10h]
  char v29; // [xsp+0h] [xbp-10h]

  if ( !a1 || !*(_QWORD *)a1 )
  {
    v24 = &unk_26FCAB;
LABEL_27:
    printk(v24, "sde_encoder_get_kms");
    return printk(&unk_26C210, "hfi_encoder_frame_event_callback");
  }
  v4 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v4 || !*(_QWORD *)(v4 + 8) )
  {
    v24 = &unk_234896;
    goto LABEL_27;
  }
  v5 = *(_QWORD *)(a1 + 4976);
  if ( !v5 )
    return printk(&unk_26C210, "hfi_encoder_frame_event_callback");
  if ( !*(_QWORD *)(a1 + 328) )
    return printk(&unk_265417, "hfi_encoder_frame_event_callback");
  v7 = a2;
  if ( a2 )
  {
    fps = sde_encoder_get_fps(a1);
    v9 = (unsigned __int128)(192LL * *(_QWORD *)v7 * (__int128)0x346DC5D63886594BLL) >> 64;
    *(_DWORD *)(v5 + 48) = *(_DWORD *)(v7 + 8);
    v7 = sde_encoder_event_timestamp_adjust(*(unsigned int *)(a1 + 24), fps, (v9 >> 11) + ((unsigned __int64)v9 >> 63));
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "hfi_enc_unpack_frame_event",
      56,
      -1,
      *(_DWORD *)(a1 + 24),
      *(_DWORD *)(v5 + 44),
      *(_DWORD *)(v5 + 48),
      v7,
      239);
  }
  else
  {
    printk(&unk_231519, "hfi_enc_unpack_frame_event");
  }
  v10 = raw_spin_lock_irqsave(a1 + 128);
  v11 = *(_DWORD *)(a1 + 592);
  do
  {
    if ( !v11 )
      break;
    _X12 = (unsigned int *)(a1 + 592);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v18 = __ldxr(_X12);
      if ( v18 != v11 )
        break;
      if ( !__stlxr(v11 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v18 == v11;
    v11 = v18;
  }
  while ( !_ZF );
  raw_spin_unlock_irqrestore(a1 + 128, v10);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "hfi_encoder_frame_event_callback",
    131,
    -1,
    *(_DWORD *)(a1 + 592),
    -1059143953,
    v19,
    v20,
    v28);
  v22 = *(_DWORD **)(a1 + 600);
  *(_QWORD *)(a1 + 616) = *(_QWORD *)(*(_QWORD *)(a1 + 328) + 8LL);
  if ( v22 )
  {
    if ( *(v22 - 1) != -458624868 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, __int64))v22)(a1 + 608, a3, v7);
  }
  if ( !*(_QWORD *)(a1 + 504) )
  {
    _X8 = (unsigned int *)(v5 + 40);
    __asm { PRFM            #0x11, [X8] }
    do
      v27 = __ldxr(_X8);
    while ( __stlxr(v27 + 1, _X8) );
    __dmb(0xBu);
    *(_QWORD *)(v5 + 32) = v7;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "hfi_encoder_frame_event_callback",
      142,
      -1,
      *(_DWORD *)(v5 + 40),
      v7,
      -1059143953,
      v21,
      v29);
  }
  return _wake_up(v5 + 88, 3, 0, 0);
}
