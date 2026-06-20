__int64 __fastcall pld_is_ipa_offload_disabled(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x3
  void *v6; // x0
  __int64 v7; // x2

  v2 = pld_ctx;
  if ( !a1 || !pld_ctx )
  {
    printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
LABEL_12:
    v5 = 0xFFFFFFFFLL;
LABEL_13:
    v6 = &unk_9538F1;
    v7 = 2921;
    goto LABEL_14;
  }
  v3 = raw_spin_lock_irqsave(pld_ctx + 8);
  v4 = v2 + 16;
  do
  {
    v4 = *(_QWORD *)v4;
    if ( v4 == v2 + 16 )
    {
      raw_spin_unlock_irqrestore(v2 + 8, v3);
      goto LABEL_12;
    }
  }
  while ( *(_QWORD *)(v4 - 16) != a1 );
  raw_spin_unlock_irqrestore(v2 + 8, v3);
  if ( v4 == 16 )
    goto LABEL_12;
  v5 = *(unsigned int *)(v4 + 16);
  if ( (_DWORD)v5 != 1 )
  {
    if ( (unsigned int)v5 > 7 )
      goto LABEL_13;
    v6 = &unk_A0E3B2;
    v7 = 2918;
LABEL_14:
    printk(v6, "pld_is_ipa_offload_disabled", v7, v5);
  }
  return 0;
}
