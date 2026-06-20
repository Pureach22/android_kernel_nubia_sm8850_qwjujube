__int64 __fastcall pld_is_direct_link_supported(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x21
  char fw_cap; // w0

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
        goto LABEL_10;
      }
    }
    while ( *(_QWORD *)(v4 - 16) != a1 );
    raw_spin_unlock_irqrestore(v2 + 8, v3);
    if ( v4 != 16 && !*(_DWORD *)(v4 + 16) )
    {
      fw_cap = cnss_get_fw_cap(a1, 0);
      return fw_cap & 1;
    }
  }
  else
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, a1);
  }
LABEL_10:
  fw_cap = 0;
  return fw_cap & 1;
}
