__int64 __fastcall cscfg_csdev_reset_feats(__int64 a1)
{
  _QWORD *i; // x21

  raw_spin_lock_irqsave(a1 + 1040);
  for ( i = *(_QWORD **)(a1 + 1008); i != (_QWORD *)(a1 + 1008); i = (_QWORD *)*i )
    cscfg_reset_feat((__int64)(i - 2));
  return raw_spin_unlock_irqrestore(a1 + 1040);
}
