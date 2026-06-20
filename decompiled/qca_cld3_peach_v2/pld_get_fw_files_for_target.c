__int64 __fastcall pld_get_fw_files_for_target(__int64 a1, char *a2)
{
  __int64 v3; // x23
  __int64 v5; // x0
  __int64 v6; // x24
  unsigned int v7; // w8

  v3 = pld_ctx;
  if ( !a1 || !pld_ctx )
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
    return 4294967274LL;
  }
  v5 = raw_spin_lock_irqsave(pld_ctx + 8);
  v6 = v3 + 16;
  do
  {
    v6 = *(_QWORD *)v6;
    if ( v6 == v3 + 16 )
    {
      raw_spin_unlock_irqrestore(v3 + 8, v5);
      return 4294967274LL;
    }
  }
  while ( *(_QWORD *)(v6 - 16) != a1 );
  raw_spin_unlock_irqrestore(v3 + 8, v5);
  if ( v6 == 16 )
    return 4294967274LL;
  v7 = *(_DWORD *)(v6 + 16);
  if ( v7 > 7 )
    return 4294967274LL;
  if ( ((1 << v7) & 0xF6) != 0 )
    return 0;
  if ( !v7 )
    return pld_pcie_get_fw_files_for_target(a1, a2);
  memset(a2 + 21, 0, 0x8E2u);
  strcpy(a2, "peach_v2/athwlan.bin");
  strcpy(a2 + 255, "peach_v2/fakeboar.bin");
  strcpy(a2 + 510, "peach_v2/otp.bin");
  strcpy(a2 + 765, "peach_v2/utf.bin");
  strcpy(a2 + 1020, "peach_v2/fakeboar.bin");
  strcpy(a2 + 1275, "peach_v2/epping.bin");
  strcpy(a2 + 1785, "peach_v2/athsetup.bin");
  return 0;
}
