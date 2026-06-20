__int64 __fastcall pld_disable_irq(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 result; // x0
  __int64 v6; // x3
  unsigned int v7; // w8

  v2 = pld_ctx;
  if ( !a1 || !pld_ctx )
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, a1);
    return printk(&unk_8EB76B, "pld_disable_irq", 1401, v6);
  }
  v3 = raw_spin_lock_irqsave(pld_ctx + 8);
  v4 = v2 + 16;
  do
  {
    v4 = *(_QWORD *)v4;
    if ( v4 == v2 + 16 )
    {
      raw_spin_unlock_irqrestore(v2 + 8, v3);
      return printk(&unk_8EB76B, "pld_disable_irq", 1401, v6);
    }
  }
  while ( *(_QWORD *)(v4 - 16) != a1 );
  result = raw_spin_unlock_irqrestore(v2 + 8, v3);
  if ( v4 == 16 )
    return printk(&unk_8EB76B, "pld_disable_irq", 1401, v6);
  v7 = *(_DWORD *)(v4 + 16);
  if ( v7 > 7 || v7 == 3 )
    return printk(&unk_8EB76B, "pld_disable_irq", 1401, v6);
  return result;
}
