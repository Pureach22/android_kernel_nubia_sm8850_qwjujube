__int64 __fastcall pld_power_on(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x3
  unsigned int v6; // w8

  v2 = pld_ctx;
  if ( !a1 || !pld_ctx )
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
LABEL_12:
    printk(&unk_9C3340, "pld_power_on", 1581, v5);
    return 0;
  }
  v3 = raw_spin_lock_irqsave(pld_ctx + 8);
  v4 = v2 + 16;
  do
  {
    v4 = *(_QWORD *)v4;
    if ( v4 == v2 + 16 )
    {
      raw_spin_unlock_irqrestore(v2 + 8, v3);
      goto LABEL_12;
    }
  }
  while ( *(_QWORD *)(v4 - 16) != a1 );
  raw_spin_unlock_irqrestore(v2 + 8, v3);
  if ( v4 == 16 )
    goto LABEL_12;
  v6 = *(_DWORD *)(v4 + 16);
  if ( v6 > 7 || ((1 << v6) & 0xF3) == 0 )
    goto LABEL_12;
  return 0;
}
