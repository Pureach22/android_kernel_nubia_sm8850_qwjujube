__int64 __fastcall pld_athdiag_write(__int64 a1, unsigned int a2, unsigned int a3, unsigned int a4, __int64 a5)
{
  __int64 v6; // x24
  __int64 v11; // x0
  __int64 v12; // x25
  int v13; // w8

  v6 = pld_ctx;
  if ( a1 && pld_ctx )
  {
    v11 = raw_spin_lock_irqsave(pld_ctx + 8);
    v12 = v6 + 16;
    do
    {
      v12 = *(_QWORD *)v12;
      if ( v12 == v6 + 16 )
      {
        raw_spin_unlock_irqrestore(v6 + 8, v11);
        return 4294967274LL;
      }
    }
    while ( *(_QWORD *)(v12 - 16) != a1 );
    raw_spin_unlock_irqrestore(v6 + 8, v11);
    if ( v12 == 16 )
      return 4294967274LL;
    v13 = *(_DWORD *)(v12 + 16);
    if ( (unsigned int)(v13 - 1) < 7 )
      return 0;
    if ( !v13 )
      return cnss_athdiag_write(a1, a2, a3, a4, a5);
  }
  else
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
  }
  return 4294967274LL;
}
