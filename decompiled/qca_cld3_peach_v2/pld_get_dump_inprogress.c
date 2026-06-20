__int64 __fastcall pld_get_dump_inprogress(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x3

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
    if ( v4 == 16 )
      goto LABEL_12;
    v5 = *(unsigned int *)(v4 + 16);
    if ( (unsigned int)v5 < 7 && ((0x4Fu >> v5) & 1) != 0 )
      return dword_B08DFC[(unsigned int)v5];
  }
  else
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
LABEL_12:
    v5 = 0xFFFFFFFFLL;
  }
  printk(&unk_9538F1, "pld_get_dump_inprogress", 2486, v5);
  return 4294967274LL;
}
