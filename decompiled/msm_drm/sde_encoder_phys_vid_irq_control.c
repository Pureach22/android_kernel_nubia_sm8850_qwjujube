__int64 __fastcall sde_encoder_phys_vid_irq_control(__int64 result, char a2)
{
  __int64 v2; // x19
  int v3; // w4

  if ( result )
  {
    v2 = result;
    if ( *(_QWORD *)result )
      v3 = *(_DWORD *)(*(_QWORD *)result + 24LL);
    else
      v3 = -1;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_phys_vid_irq_control",
      2707,
      -1,
      v3,
      *(_DWORD *)(*(_QWORD *)(result + 424) + 32LL) - 1,
      a2 & 1,
      *(_DWORD *)(result + 848),
      239);
    if ( (a2 & 1) != 0 )
    {
      result = sde_encoder_phys_vid_control_vblank_irq(v2, 1);
      if ( !(_DWORD)result )
        return sde_encoder_helper_register_irq(v2, 2u);
    }
    else
    {
      sde_encoder_phys_vid_control_vblank_irq(v2, 0);
      return sde_encoder_helper_unregister_irq(v2, 2u);
    }
  }
  return result;
}
