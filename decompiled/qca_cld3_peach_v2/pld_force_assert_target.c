__int64 __fastcall pld_force_assert_target(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x3
  __int64 result; // x0

  v2 = pld_ctx;
  if ( !a1 || !pld_ctx )
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
LABEL_22:
    v5 = 0xFFFFFFFFLL;
    goto LABEL_23;
  }
  v3 = raw_spin_lock_irqsave(pld_ctx + 8);
  v4 = v2 + 16;
  do
  {
    v4 = *(_QWORD *)v4;
    if ( v4 == v2 + 16 )
    {
      raw_spin_unlock_irqrestore(v2 + 8, v3);
      goto LABEL_22;
    }
  }
  while ( *(_QWORD *)(v4 - 16) != a1 );
  raw_spin_unlock_irqrestore(v2 + 8, v3);
  if ( v4 == 16 )
    goto LABEL_22;
  v5 = *(unsigned int *)(v4 + 16);
  if ( (int)v5 <= 3 )
  {
    switch ( (_DWORD)v5 )
    {
      case 0:
        return cnss_force_fw_assert(a1);
      case 1:
        return 0;
      case 2:
        return 4294967274LL;
    }
LABEL_23:
    printk(&unk_9538F1, "pld_force_assert_target", 2368, v5);
    return 4294967274LL;
  }
  result = 4294967201LL;
  if ( (int)v5 <= 5 )
  {
    if ( (_DWORD)v5 == 4 )
      return 4294967274LL;
    return result;
  }
  if ( (_DWORD)v5 == 6 )
    return 4294967274LL;
  if ( (_DWORD)v5 != 7 )
    goto LABEL_23;
  return result;
}
