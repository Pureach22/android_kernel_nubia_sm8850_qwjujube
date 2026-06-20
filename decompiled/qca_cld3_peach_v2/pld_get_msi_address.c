__int64 __fastcall pld_get_msi_address(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x22
  __int64 v7; // x0
  __int64 v8; // x23
  __int64 result; // x0
  __int64 v10; // x3
  void *v11; // x0
  __int64 v12; // x2

  v4 = pld_ctx;
  if ( !a1 || !pld_ctx )
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
LABEL_14:
    v10 = 0xFFFFFFFFLL;
    goto LABEL_15;
  }
  v7 = raw_spin_lock_irqsave(pld_ctx + 8);
  v8 = v4 + 16;
  do
  {
    v8 = *(_QWORD *)v8;
    if ( v8 == v4 + 16 )
    {
      raw_spin_unlock_irqrestore(v4 + 8, v7);
      goto LABEL_14;
    }
  }
  while ( *(_QWORD *)(v8 - 16) != a1 );
  result = raw_spin_unlock_irqrestore(v4 + 8, v7);
  if ( v8 == 16 )
    goto LABEL_14;
  v10 = *(unsigned int *)(v8 + 16);
  if ( (unsigned int)(v10 - 5) >= 3 )
  {
    if ( !(_DWORD)v10 )
      return cnss_get_msi_address(a1, a2, a3);
    if ( (unsigned int)(v10 - 1) < 4 )
    {
      v11 = &unk_A0E3B2;
      v12 = 2200;
      return printk(v11, "pld_get_msi_address", v12, v10);
    }
LABEL_15:
    v11 = &unk_9538F1;
    v12 = 2206;
    return printk(v11, "pld_get_msi_address", v12, v10);
  }
  return result;
}
