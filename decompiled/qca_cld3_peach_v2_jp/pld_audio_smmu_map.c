__int64 __fastcall pld_audio_smmu_map(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x23
  __int64 v9; // x0
  __int64 v10; // x24
  int v11; // w8

  v5 = pld_ctx;
  if ( a1 && pld_ctx )
  {
    v9 = raw_spin_lock_irqsave(pld_ctx + 8);
    v10 = v5 + 16;
    do
    {
      v10 = *(_QWORD *)v10;
      if ( v10 == v5 + 16 )
      {
        raw_spin_unlock_irqrestore(v5 + 8, v9);
        return 4294967274LL;
      }
    }
    while ( *(_QWORD *)(v10 - 16) != a1 );
    raw_spin_unlock_irqrestore(v5 + 8, v9);
    if ( v10 == 16 )
      return 4294967274LL;
    v11 = *(_DWORD *)(v10 + 16);
    if ( v11 == 6 )
    {
      return 0;
    }
    else
    {
      if ( v11 )
        return 4294967274LL;
      return cnss_audio_smmu_map(a1, a2, a3, a4);
    }
  }
  else
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, a1);
    return 4294967274LL;
  }
}
