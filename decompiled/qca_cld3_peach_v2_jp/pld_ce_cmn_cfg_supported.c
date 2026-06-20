__int64 __fastcall pld_ce_cmn_cfg_supported(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  _QWORD *v4; // x9

  v2 = pld_ctx;
  if ( a1 && pld_ctx )
  {
    v3 = raw_spin_lock_irqsave(pld_ctx + 8);
    v4 = (_QWORD *)(v2 + 16);
    do
      v4 = (_QWORD *)*v4;
    while ( v4 != (_QWORD *)(v2 + 16) && *(v4 - 2) != a1 );
    raw_spin_unlock_irqrestore(v2 + 8, v3);
  }
  else
  {
    printk(&unk_99F123, "pld_get_dev_node", 198, a1);
  }
  return 0;
}
