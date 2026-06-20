__int64 __fastcall sde_encoder_phys_cmd_dynamic_irq_control(__int64 result, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 v5; // x20

  if ( result )
  {
    if ( (v2 = *(_QWORD *)(result + 8), v3 = result, !v2)
      || (v4 = *(_QWORD *)(v2 + 2512)) == 0
      || (*(_DWORD *)(v4 + 1376) != 10 || *(_DWORD *)(result + 664) != 3)
      && (*(_DWORD *)(result + 664) != 3 || *(_DWORD *)(v4 + 3256) != 10) )
    {
      if ( (a2 & 1) != 0 )
      {
        v5 = *(_QWORD *)result;
        if ( (*(_QWORD *)(*(_QWORD *)result + 4928LL) & 4) != 0 )
          result = sde_encoder_helper_register_irq(result, 0x14u);
        if ( (*(_QWORD *)(v5 + 4928) & 1) != 0 && *(_BYTE *)(v3 + 2288) == 1 )
          result = sde_encoder_helper_register_irq(v3, 0x15u);
        if ( (*(_QWORD *)(v5 + 4928) & 2) != 0
          && (*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 424) + 40LL) + 32LL) & 0x10000) != 0
          && *(_BYTE *)(v3 + 2288) == 1 )
        {
          return sde_encoder_helper_register_irq(v3, 0x16u);
        }
      }
      else
      {
        if ( (*(_DWORD *)(result + 2140) & 0x80000000) == 0 )
          result = sde_encoder_helper_unregister_irq(result, 0x14u);
        if ( (*(_DWORD *)(v3 + 2196) & 0x80000000) == 0 )
          result = sde_encoder_helper_unregister_irq(v3, 0x15u);
        if ( (*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 424) + 40LL) + 32LL) & 0x10000) != 0
          && (*(_DWORD *)(v3 + 2252) & 0x80000000) == 0 )
        {
          return sde_encoder_helper_unregister_irq(v3, 0x16u);
        }
      }
    }
  }
  return result;
}
