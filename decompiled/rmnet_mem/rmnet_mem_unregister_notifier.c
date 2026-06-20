__int64 __fastcall rmnet_mem_unregister_notifier(__int64 a1)
{
  __int64 v2; // x21

  v2 = raw_spin_lock_irqsave(&unk_8BD8);
  LODWORD(a1) = raw_notifier_chain_unregister(&rmnet_mem_notifier, a1);
  raw_spin_unlock_irqrestore(&unk_8BD8, v2);
  return (unsigned int)a1;
}
