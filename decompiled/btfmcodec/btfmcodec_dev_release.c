__int64 __fastcall btfmcodec_dev_release(__int64 a1)
{
  __int64 v1; // x20
  void *v3; // x0
  __int64 v4; // x19
  int v11; // w8

  v1 = *(_QWORD *)(a1 + 656);
  _ReadStatusReg(SP_EL0);
  _X19 = (unsigned int *)(v1 + 136);
  if ( (unsigned __int8)log_lvl <= 7u )
    v3 = &unk_D3F2;
  else
    v3 = &unk_D25A;
  printk(v3, "btfmcodec_dev_release");
  __asm { PRFM            #0x11, [X19] }
  do
    v11 = __ldxr(_X19);
  while ( __stlxr(v11 - 1, _X19) );
  if ( v11 <= 1 )
    refcount_warn_saturate(v1 + 136, 4);
  if ( *_X19 == 1 )
  {
    v4 = raw_spin_lock_irqsave(v1 + 520);
    skb_queue_purge_reason(v1 + 528, 85);
    _wake_up(v1 + 496, 1, 1, 0);
    raw_spin_unlock_irqrestore(v1 + 520, v4);
    skb_queue_purge_reason(v1 + 320, 85);
    skb_queue_purge_reason(v1 + 344, 85);
  }
  *(_BYTE *)(v1 + 744) = 3;
  _wake_up(v1 + 552, 1, 1, 0);
  *(_BYTE *)(v1 + 745) = 3;
  _wake_up(v1 + 576, 1, 1, 0);
  *(_BYTE *)(v1 + 746) = 3;
  _wake_up(v1 + 600, 1, 1, 0);
  *(_BYTE *)(v1 + 747) = 3;
  _wake_up(v1 + 624, 1, 1, 0);
  *(_BYTE *)(v1 + 748) = 3;
  _wake_up(v1 + 648, 1, 1, 0);
  *(_BYTE *)(v1 + 749) = 3;
  _wake_up(v1 + 672, 1, 1, 0);
  *(_BYTE *)(v1 + 750) = 3;
  _wake_up(v1 + 696, 1, 1, 0);
  *(_BYTE *)(v1 + 751) = 3;
  _wake_up(v1 + 720, 1, 1, 0);
  if ( *(_QWORD *)(v1 + 424) )
    cancel_work_sync(v1 + 400);
  if ( *(_QWORD *)(v1 + 488) )
    cancel_work_sync(v1 + 464);
  if ( *(_QWORD *)(v1 + 456) )
    cancel_work_sync(v1 + 432);
  return 0;
}
