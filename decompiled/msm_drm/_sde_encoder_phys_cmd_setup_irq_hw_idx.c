__int64 __fastcall sde_encoder_phys_cmd_setup_irq_hw_idx(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x10
  __int64 v3; // x9
  int v4; // w10
  int v5; // w8
  int v6; // w8
  int v7; // w8
  int v8; // w9
  int v9; // w9
  int v10; // w9

  v1 = *(_QWORD *)(result + 496);
  if ( !*(_QWORD *)(result + 512) )
    return printk(&unk_26CA1B, "_sde_encoder_phys_cmd_setup_irq_hw_idx");
  if ( !v1 )
    return printk(&unk_26CA1B, "_sde_encoder_phys_cmd_setup_irq_hw_idx");
  v2 = *(_QWORD *)(result + 416);
  if ( !v2 )
    return printk(&unk_26CA1B, "_sde_encoder_phys_cmd_setup_irq_hw_idx");
  if ( *(_BYTE *)(result + 2288) == 1 )
  {
    v3 = *(_QWORD *)(result + 424);
    if ( v3 )
    {
      v4 = *(_DWORD *)(v2 + 64);
      *(_DWORD *)(result + 1352) = v4;
      *(_DWORD *)(result + 1408) = v4;
      *(_DWORD *)(result + 1072) = *(_DWORD *)(v1 + 32);
      v5 = *(_DWORD *)(v3 + 32);
      *(_DWORD *)(result + 1464) = v5;
      *(_DWORD *)(result + 1520) = v5;
      v6 = *(_DWORD *)(v3 + 32);
      *(_DWORD *)(result + 2024) = v6;
      *(_DWORD *)(result + 2136) = v6;
      v7 = *(_DWORD *)(v3 + 32);
      *(_DWORD *)(result + 2192) = v7;
      if ( (*(_QWORD *)(*(_QWORD *)(v3 + 40) + 32LL) & 0x10000) != 0 )
        *(_DWORD *)(result + 2248) = v7;
    }
    else
    {
      return printk(&unk_2461B1, "_sde_encoder_phys_cmd_setup_irq_hw_idx");
    }
  }
  else
  {
    v8 = *(_DWORD *)(v2 + 64);
    *(_DWORD *)(result + 1352) = v8;
    *(_DWORD *)(result + 1408) = v8;
    v9 = *(_DWORD *)(v1 + 32);
    *(_DWORD *)(result + 1072) = v9;
    *(_DWORD *)(result + 1464) = v9;
    v10 = *(_DWORD *)(v1 + 32);
    *(_DWORD *)(result + 1520) = v10;
    *(_DWORD *)(result + 2024) = v10;
    *(_DWORD *)(result + 2136) = *(_DWORD *)(v1 + 32);
  }
  return result;
}
