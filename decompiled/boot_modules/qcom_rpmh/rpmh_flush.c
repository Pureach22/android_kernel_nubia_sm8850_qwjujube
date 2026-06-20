__int64 __fastcall rpmh_flush(__int64 a1, unsigned int a2)
{
  __int64 v5; // x21
  unsigned int v6; // w20

  if ( (rpmh_standalone & 1) != 0 )
    return 0;
  v5 = raw_spin_lock_irqsave(a1);
  v6 = rpmh_flush(a1, a2);
  raw_spin_unlock_irqrestore(a1, v5);
  return v6;
}
