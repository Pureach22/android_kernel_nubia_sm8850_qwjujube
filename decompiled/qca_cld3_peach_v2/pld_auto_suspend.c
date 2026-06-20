__int64 __fastcall pld_auto_suspend(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x21
  unsigned int v5; // w8

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
        return 4294967274LL;
      }
    }
    while ( *(_QWORD *)(v4 - 16) != a1 );
    raw_spin_unlock_irqrestore(v2 + 8, v3);
    if ( v4 != 16 )
    {
      v5 = *(_DWORD *)(v4 + 16);
      if ( v5 <= 7 )
      {
        if ( ((1 << v5) & 0xF6) != 0 )
          return 0;
        if ( !v5 )
          return cnss_auto_suspend(a1);
      }
    }
  }
  else
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
  }
  return 4294967274LL;
}
