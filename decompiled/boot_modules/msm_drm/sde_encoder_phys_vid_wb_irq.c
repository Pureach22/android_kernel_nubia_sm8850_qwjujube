__int64 __fastcall sde_encoder_phys_vid_wb_irq(
        __int64 result,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int v8; // w4
  char vars0; // [xsp+0h] [xbp+0h]

  if ( result )
  {
    if ( *(_QWORD *)result )
      v8 = *(_DWORD *)(*(_QWORD *)result + 24LL);
    else
      v8 = -1;
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "sde_encoder_phys_vid_wb_irq",
               1309,
               -1,
               v8,
               a2,
               -1059143953,
               a8,
               vars0);
    if ( (_drm_debug & 4) != 0 )
      return _drm_dev_dbg(0, 0, 0, "WD irq!\n");
  }
  return result;
}
