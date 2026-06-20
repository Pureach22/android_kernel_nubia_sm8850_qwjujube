__int64 __fastcall pld_get_bus_type(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x21

  v2 = pld_ctx;
  if ( a1 && pld_ctx )
  {
    v3 = raw_spin_lock_irqsave(pld_ctx + 8);
    v4 = v2 + 16;
    do
    {
      v4 = *(_QWORD *)v4;
      if ( v4 == v2 + 16 )
      {
        raw_spin_unlock_irqrestore(v2 + 8, v3);
        return 0xFFFFFFFFLL;
      }
    }
    while ( *(_QWORD *)(v4 - 16) != a1 );
    raw_spin_unlock_irqrestore(v2 + 8, v3);
    if ( v4 == 16 )
      return 0xFFFFFFFFLL;
    return *(unsigned int *)(v4 + 16);
  }
  else
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
    return 0xFFFFFFFFLL;
  }
}
