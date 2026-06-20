__int64 __fastcall pld_have_platform_driver_support(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x3
  unsigned int v6; // w8
  unsigned int v7; // w8

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
        goto LABEL_12;
      }
    }
    while ( *(_QWORD *)(v4 - 16) != a1 );
    raw_spin_unlock_irqrestore(v2 + 8, v3);
    if ( v4 != 16 )
    {
      v6 = *(_DWORD *)(v4 + 16);
      if ( v6 < 8 && ((0xF7u >> v6) & 1) != 0 )
      {
        v7 = 0xE9u >> v6;
        return v7 & 1;
      }
    }
  }
  else
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, a1);
  }
LABEL_12:
  printk(&unk_8EB76B, "pld_have_platform_driver_support", 2570, v5);
  LOBYTE(v7) = 0;
  return v7 & 1;
}
