__int64 __fastcall pld_thermal_register(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // x22
  __int64 v7; // x0
  __int64 v8; // x23
  __int64 v9; // x3

  v4 = pld_ctx;
  if ( a1 && pld_ctx )
  {
    v7 = raw_spin_lock_irqsave(pld_ctx + 8);
    v8 = v4 + 16;
    do
    {
      v8 = *(_QWORD *)v8;
      if ( v8 == v4 + 16 )
      {
        raw_spin_unlock_irqrestore(v4 + 8, v7);
        goto LABEL_16;
      }
    }
    while ( *(_QWORD *)(v8 - 16) != a1 );
    raw_spin_unlock_irqrestore(v4 + 8, v7);
    if ( v8 == 16 )
      goto LABEL_16;
    v9 = *(unsigned int *)(v8 + 16);
    if ( (int)v9 > 5 )
    {
      if ( (_DWORD)v9 == 6 || (_DWORD)v9 == 7 )
        return 0;
    }
    else
    {
      if ( (unsigned int)(v9 - 1) < 5 )
        return 4294967274LL;
      if ( !(_DWORD)v9 )
        return cnss_thermal_cdev_register(a1, a2, a3);
    }
  }
  else
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
LABEL_16:
    v9 = 0xFFFFFFFFLL;
  }
  printk(&unk_9538F1, "pld_thermal_register", 2682, v9);
  return 4294967274LL;
}
