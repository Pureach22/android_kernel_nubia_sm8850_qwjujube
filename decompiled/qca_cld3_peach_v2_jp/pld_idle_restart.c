__int64 __fastcall pld_idle_restart(__int64 a1, __int64 (__fastcall *a2)(_QWORD))
{
  __int64 v3; // x20
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x3

  if ( !a2 )
    return 4294967274LL;
  v3 = pld_ctx;
  if ( !a1 || !pld_ctx )
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, a1);
LABEL_19:
    v7 = 0xFFFFFFFFLL;
LABEL_20:
    printk(&unk_886A85, "pld_idle_restart", 2648, v7);
    return 4294967274LL;
  }
  v5 = raw_spin_lock_irqsave(pld_ctx + 8);
  v6 = v3 + 16;
  do
  {
    v6 = *(_QWORD *)v6;
    if ( v6 == v3 + 16 )
    {
      raw_spin_unlock_irqrestore(v3 + 8, v5);
      goto LABEL_19;
    }
  }
  while ( *(_QWORD *)(v6 - 16) != a1 );
  raw_spin_unlock_irqrestore(v3 + 8, v5);
  if ( v6 == 16 )
    goto LABEL_19;
  v7 = *(unsigned int *)(v6 + 16);
  if ( (unsigned int)v7 > 7 )
    goto LABEL_20;
  if ( ((1 << v7) & 0xF2) != 0 )
    return 0;
  if ( ((1 << v7) & 0xC) == 0 )
    return cnss_idle_restart(a1);
  if ( *((_DWORD *)a2 - 1) != 711998475 )
    __break(0x8235u);
  return a2(a1);
}
