__int64 __fastcall get_effective_client(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w19

  if ( a1 )
  {
    v2 = raw_spin_lock_irqsave(a1 + 104);
    v3 = *(_DWORD *)(a1 + 96);
    raw_spin_unlock_irqrestore(a1 + 104, v2);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v3;
}
