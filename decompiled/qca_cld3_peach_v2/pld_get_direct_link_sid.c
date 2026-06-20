__int64 __fastcall pld_get_direct_link_sid(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v5; // x0
  __int64 v6; // x22

  v3 = pld_ctx;
  if ( a1 && pld_ctx )
  {
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
    if ( v6 != 16 && !*(_DWORD *)(v6 + 16) )
      return cnss_get_direct_link_sid(a1, a2);
  }
  else
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
  }
  return 4294967274LL;
}
