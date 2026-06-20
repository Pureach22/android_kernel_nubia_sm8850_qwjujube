__int64 __fastcall msm_pcie_fmd_enable(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x19
  __int64 v4; // x0

  if ( !a1 )
    return 4294967277LL;
  while ( !*(_BYTE *)(a1 + 108) || (*(_WORD *)(a1 + 114) & 0xF0) != 0x40 )
  {
    if ( (*(_BYTE *)(a1 + 2851) & 0x80) != 0 )
      a1 = *(_QWORD *)(a1 + 3288);
    v1 = *(_QWORD *)(a1 + 16);
    if ( *(_QWORD *)(v1 + 16) )
    {
      a1 = *(_QWORD *)(v1 + 56);
      if ( a1 )
        continue;
    }
    return 4294967277LL;
  }
  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 232LL) + 200LL);
  if ( !v3 )
  {
    printk(&unk_2F4AF);
    return 4294967277LL;
  }
  ipc_log_string(*(_QWORD *)(v3 + 1704), "INFO:%s: RC%d Enable FMD\n", "msm_pcie_fmd_enable", *(_DWORD *)(v3 + 1348));
  ipc_log_string(*(_QWORD *)(v3 + 1696), "%s: RC%d Enable FMD\n", "msm_pcie_fmd_enable", *(_DWORD *)(v3 + 1348));
  printk(&unk_30410);
  if ( *(_BYTE *)(v3 + 3156) == 1 )
  {
    printk(&unk_264FA);
    return 0;
  }
  else
  {
    v4 = gpio_to_desc(*(unsigned int *)(v3 + 264));
    if ( !(unsigned int)gpiod_get_raw_value(v4) )
      msm_pcie_config_perst(v3, 0);
    *(_BYTE *)(v3 + 3156) = 1;
    return 0;
  }
}
