__int64 __fastcall pld_qmi_send(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4, __int64 a5, __int64 a6)
{
  __int64 v7; // x25
  __int64 v13; // x0
  __int64 v14; // x26
  __int64 v15; // x3

  v7 = pld_ctx;
  if ( !a1 || !pld_ctx )
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
LABEL_14:
    v15 = 0xFFFFFFFFLL;
LABEL_15:
    printk(&unk_9538F1, "pld_qmi_send", 2446, v15);
    return 4294967274LL;
  }
  v13 = raw_spin_lock_irqsave(pld_ctx + 8);
  v14 = v7 + 16;
  do
  {
    v14 = *(_QWORD *)v14;
    if ( v14 == v7 + 16 )
    {
      raw_spin_unlock_irqrestore(v7 + 8, v13);
      goto LABEL_14;
    }
  }
  while ( *(_QWORD *)(v14 - 16) != a1 );
  raw_spin_unlock_irqrestore(v7 + 8, v13);
  if ( v14 == 16 )
    goto LABEL_14;
  v15 = *(unsigned int *)(v14 + 16);
  if ( (unsigned int)(v15 - 1) < 3 )
    return 4294967274LL;
  if ( (_DWORD)v15 == 6 )
    return 0;
  if ( (_DWORD)v15 )
    goto LABEL_15;
  return cnss_qmi_send(a1, a2, a3, a4, a5, a6);
}
