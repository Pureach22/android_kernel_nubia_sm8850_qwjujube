__int64 __fastcall rmnet_mem_mode_notify(unsigned int a1)
{
  __int64 v2; // x21

  v2 = raw_spin_lock_irqsave(&unk_8BD8);
  raw_notifier_call_chain(&rmnet_mem_notifier, a1, 0);
  raw_spin_unlock_irqrestore(&unk_8BD8, v2);
  return 1;
}
