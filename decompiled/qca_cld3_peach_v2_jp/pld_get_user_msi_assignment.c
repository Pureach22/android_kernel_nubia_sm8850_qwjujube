__int64 __fastcall pld_get_user_msi_assignment(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // x24
  __int64 v11; // x0
  __int64 v12; // x25
  __int64 v13; // x3
  __int64 result; // x0

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
        goto LABEL_19;
      }
    }
    while ( *(_QWORD *)(v12 - 16) != a1 );
    raw_spin_unlock_irqrestore(v6 + 8, v11);
    if ( v12 == 16 )
      goto LABEL_19;
    v13 = *(unsigned int *)(v12 + 16);
    result = 4294967274LL;
    if ( (int)v13 > 5 )
    {
      if ( (_DWORD)v13 == 6 )
        return 0;
      if ( (_DWORD)v13 == 7 )
        return result;
    }
    else
    {
      if ( !(_DWORD)v13 )
        return cnss_get_user_msi_assignment(a1, a2, a3, a4, a5);
      if ( (_DWORD)v13 == 5 )
        return result;
      if ( (unsigned int)(v13 - 1) < 4 )
      {
        printk(&unk_92F235, "pld_get_user_msi_assignment", 1848, v13);
        return 4294967277LL;
      }
    }
  }
  else
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, a1);
LABEL_19:
    v13 = 0xFFFFFFFFLL;
  }
  printk(&unk_886A85, "pld_get_user_msi_assignment", 1858, v13);
  return 4294967274LL;
}
