__int64 __fastcall pld_qmi_indication(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x22
  __int64 v7; // x0
  __int64 v8; // x23
  __int64 v9; // x3
  __int64 result; // x0

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
        goto LABEL_13;
      }
    }
    while ( *(_QWORD *)(v8 - 16) != a1 );
    raw_spin_unlock_irqrestore(v4 + 8, v7);
    if ( v8 == 16 )
      goto LABEL_13;
    v9 = *(unsigned int *)(v8 + 16);
    result = 4294967274LL;
    if ( (unsigned int)(v9 - 1) >= 3 && (_DWORD)v9 != 6 )
    {
      if ( (_DWORD)v9 )
        goto LABEL_14;
      return cnss_register_driver_async_data_cb(a1, a2, a3);
    }
  }
  else
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, a1);
LABEL_13:
    v9 = 0xFFFFFFFFLL;
LABEL_14:
    printk(&unk_886A85, "pld_qmi_indication", 2467, v9);
    return 4294967274LL;
  }
  return result;
}
