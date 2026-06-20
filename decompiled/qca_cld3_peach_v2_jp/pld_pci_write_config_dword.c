__int64 __fastcall pld_pci_write_config_dword(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v3; // x22
  __int64 v4; // x23
  __int64 v8; // x0
  __int64 v9; // x24
  __int64 v10; // x3
  unsigned int v11; // w8

  v3 = a1 + 200;
  v4 = pld_ctx;
  if ( pld_ctx )
  {
    v8 = raw_spin_lock_irqsave(pld_ctx + 8);
    v9 = v4 + 16;
    do
    {
      v9 = *(_QWORD *)v9;
      if ( v9 == v4 + 16 )
      {
        raw_spin_unlock_irqrestore(v4 + 8, v8);
        goto LABEL_14;
      }
    }
    while ( *(_QWORD *)(v9 - 16) != v3 );
    raw_spin_unlock_irqrestore(v4 + 8, v8);
    if ( v9 != 16 )
    {
      v11 = *(_DWORD *)(v9 + 16);
      if ( v11 <= 7 )
      {
        if ( ((1 << v11) & 0xF6) != 0 )
          return 0;
        if ( !v11 )
          return pci_write_config_dword(a1, a2, a3);
      }
    }
  }
  else
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, v3);
  }
LABEL_14:
  printk(&unk_8EB76B, "pld_pci_write_config_dword", 2143, v10);
  return 0;
}
