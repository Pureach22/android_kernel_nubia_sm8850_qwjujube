__int64 __fastcall pld_qmi_send_put(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x3
  __int64 result; // x0

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
        goto LABEL_13;
      }
    }
    while ( *(_QWORD *)(v4 - 16) != a1 );
    raw_spin_unlock_irqrestore(v2 + 8, v3);
    if ( v4 == 16 )
      goto LABEL_13;
    v5 = *(unsigned int *)(v4 + 16);
    result = 0;
    if ( (unsigned int)(v5 - 1) >= 3 && (_DWORD)v5 != 6 )
    {
      if ( (_DWORD)v5 )
        goto LABEL_14;
      return cnss_qmi_send_put(a1);
    }
  }
  else
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
LABEL_13:
    v5 = 0xFFFFFFFFLL;
LABEL_14:
    printk(&unk_9538F1, "pld_qmi_send_put", 2425, v5);
    return 4294967274LL;
  }
  return result;
}
