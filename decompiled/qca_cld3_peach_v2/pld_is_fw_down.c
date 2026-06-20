__int64 __fastcall pld_is_fw_down(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x22
  __int64 v5; // x3
  __int64 v7; // x20
  __int64 v8; // x0
  _QWORD *v9; // x9

  v2 = pld_ctx;
  if ( !a1 || !pld_ctx )
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
LABEL_19:
    v5 = 0xFFFFFFFFLL;
LABEL_20:
    printk(&unk_9538F1, "pld_is_fw_down", 2321, v5);
    return 4294967274LL;
  }
  v3 = raw_spin_lock_irqsave(pld_ctx + 8);
  v4 = v2 + 16;
  do
  {
    v4 = *(_QWORD *)v4;
    if ( v4 == v2 + 16 )
    {
      raw_spin_unlock_irqrestore(v2 + 8, v3);
      goto LABEL_19;
    }
  }
  while ( *(_QWORD *)(v4 - 16) != a1 );
  raw_spin_unlock_irqrestore(v2 + 8, v3);
  if ( v4 == 16 )
    goto LABEL_19;
  v5 = *(unsigned int *)(v4 + 16);
  if ( (unsigned int)v5 > 7 )
    goto LABEL_20;
  if ( ((1 << v5) & 0xF6) != 0 )
    return 0;
  if ( !(_DWORD)v5 )
    return cnss_pci_is_device_down(a1);
  v7 = pld_ctx;
  if ( pld_ctx )
  {
    v8 = raw_spin_lock_irqsave(pld_ctx + 8);
    v9 = (_QWORD *)(v7 + 16);
    do
      v9 = (_QWORD *)*v9;
    while ( v9 != (_QWORD *)(v7 + 16) && *(v9 - 2) != a1 );
    raw_spin_unlock_irqrestore(v7 + 8, v8);
    return 0;
  }
  else
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
    return 0;
  }
}
