__int64 __fastcall sde_encoder_register_frame_event_callback(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  char v8; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return printk(&unk_26C69D, "sde_encoder_register_frame_event_callback");
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "enc%d \n", *(_DWORD *)(a1 + 24));
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_register_frame_event_callback",
    4912,
    -1,
    *(_DWORD *)(a1 + 24),
    a2 != 0,
    0,
    -1059143953,
    v8);
  v6 = raw_spin_lock_irqsave(a1 + 128);
  *(_QWORD *)(a1 + 600) = a2;
  *(_QWORD *)(a1 + 608) = a3;
  return raw_spin_unlock_irqrestore(a1 + 128, v6);
}
