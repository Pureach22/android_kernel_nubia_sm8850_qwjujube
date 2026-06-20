__int64 __fastcall pld_request_pm_qos(__int64 a1, unsigned int a2)
{
  __int64 v3; // x21
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 result; // x0
  __int64 v8; // x3
  int v9; // w8

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
        return printk(&unk_8EB76B, "pld_request_pm_qos", 849, v8);
      }
    }
    while ( *(_QWORD *)(v6 - 16) != a1 );
    result = raw_spin_unlock_irqrestore(v3 + 8, v5);
    if ( v6 == 16 )
      return printk(&unk_8EB76B, "pld_request_pm_qos", 849, v8);
    v9 = *(_DWORD *)(v6 + 16);
    if ( (unsigned int)(v9 - 1) >= 7 )
    {
      if ( v9 )
        return printk(&unk_8EB76B, "pld_request_pm_qos", 849, v8);
      return cnss_request_pm_qos(a1, a2);
    }
  }
  else
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, a1);
    return printk(&unk_8EB76B, "pld_request_pm_qos", 849, v8);
  }
  return result;
}
