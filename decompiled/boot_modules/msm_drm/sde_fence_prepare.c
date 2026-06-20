__int64 __fastcall sde_fence_prepare(_DWORD *a1)
{
  __int64 v2; // x0

  if ( !a1 )
    return printk(&unk_24029B, "sde_fence_prepare");
  v2 = raw_spin_lock_irqsave(a1 + 4);
  ++*a1;
  return raw_spin_unlock_irqrestore(a1 + 4, v2);
}
