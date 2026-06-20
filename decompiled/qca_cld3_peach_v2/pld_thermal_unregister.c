__int64 __fastcall pld_thermal_unregister(__int64 a1, unsigned int a2)
{
  __int64 v3; // x21
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 result; // x0
  __int64 v8; // x3

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
        goto LABEL_12;
      }
    }
    while ( *(_QWORD *)(v6 - 16) != a1 );
    result = raw_spin_unlock_irqrestore(v3 + 8, v5);
    if ( v6 == 16 )
      goto LABEL_12;
    v8 = *(unsigned int *)(v6 + 16);
    if ( (unsigned int)(v8 - 1) >= 7 )
    {
      if ( (_DWORD)v8 )
        return printk(&unk_9538F1, "pld_thermal_unregister", 2713, v8);
      return cnss_thermal_cdev_unregister(a1, a2);
    }
  }
  else
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
LABEL_12:
    v8 = 0xFFFFFFFFLL;
    return printk(&unk_9538F1, "pld_thermal_unregister", 2713, v8);
  }
  return result;
}
