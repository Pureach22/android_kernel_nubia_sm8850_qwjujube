__int64 __fastcall sde_encoder_phys_cmd_irq_control(__int64 result, char a2)
{
  __int64 v2; // x8
  _DWORD *v3; // x19
  __int64 v5; // x8
  int v6; // w4
  int v7; // w21
  int v8; // w20

  if ( result )
  {
    if ( (v2 = *(_QWORD *)(result + 8), v3 = (_DWORD *)result, !v2)
      || (v5 = *(_QWORD *)(v2 + 2512)) == 0
      || (*(_DWORD *)(v5 + 1376) != 10 || *(_DWORD *)(result + 664) != 3)
      && (*(_DWORD *)(result + 664) != 3 || *(_DWORD *)(v5 + 3256) != 10) )
    {
      if ( *(_QWORD *)result )
        v6 = *(_DWORD *)(*(_QWORD *)result + 24LL);
      else
        v6 = -1;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_encoder_phys_cmd_irq_control",
        1311,
        -1,
        v6,
        *(_DWORD *)(*(_QWORD *)(result + 496) + 32LL) - 1,
        a2 & 1,
        *(_DWORD *)(result + 848),
        239);
      if ( *(_QWORD *)v3 )
      {
        v7 = *(unsigned __int8 *)(*(_QWORD *)v3 + 4922LL);
        if ( (a2 & 1) != 0 )
        {
          if ( (v7 & 1) != 0 )
          {
            v8 = 1;
            goto LABEL_17;
          }
LABEL_16:
          sde_encoder_helper_register_irq((__int64)v3, 1u);
          v8 = 0;
LABEL_17:
          result = sde_encoder_phys_cmd_control_vblank_irq(v3, 1);
          if ( v3[166] != 3 )
          {
            sde_encoder_helper_register_irq((__int64)v3, 0x12u);
            result = sde_encoder_helper_register_irq((__int64)v3, 9u);
            if ( v8 )
              return sde_encoder_helper_register_irq((__int64)v3, 7u);
          }
          return result;
        }
        if ( v3[166] == 3 )
        {
          result = sde_encoder_phys_cmd_control_vblank_irq(v3, 0);
          if ( (v7 & 1) != 0 )
            return result;
          return sde_encoder_helper_unregister_irq((__int64)v3, 1u);
        }
        sde_encoder_helper_unregister_irq((__int64)v3, 0x12u);
        sde_encoder_helper_unregister_irq((__int64)v3, 9u);
        if ( v7 )
        {
          sde_encoder_helper_unregister_irq((__int64)v3, 7u);
          return sde_encoder_phys_cmd_control_vblank_irq(v3, 0);
        }
      }
      else
      {
        if ( (a2 & 1) != 0 )
          goto LABEL_16;
        if ( v3[166] != 3 )
        {
          sde_encoder_helper_unregister_irq((__int64)v3, 0x12u);
          sde_encoder_helper_unregister_irq((__int64)v3, 9u);
        }
      }
      sde_encoder_phys_cmd_control_vblank_irq(v3, 0);
      return sde_encoder_helper_unregister_irq((__int64)v3, 1u);
    }
  }
  return result;
}
