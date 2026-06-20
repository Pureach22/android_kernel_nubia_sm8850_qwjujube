__int64 __fastcall get_client_vote(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w21
  __int64 v5; // x0

  v2 = -22;
  if ( !a1 || (a2 & 0x80000000) != 0 )
    return v2;
  v5 = raw_spin_lock_irqsave(a1 + 104);
  if ( *(_DWORD *)(a1 + 92) == 2 )
  {
    if ( a2 > 7 )
      goto LABEL_11;
    goto LABEL_8;
  }
  if ( a2 < 8 )
  {
    if ( (*(_BYTE *)(a1 + 8LL * a2 + 24) & 1) == 0 )
    {
LABEL_9:
      raw_spin_unlock_irqrestore(a1 + 104, v5);
      return v2;
    }
LABEL_8:
    v2 = *(_DWORD *)(a1 + 8LL * a2 + 28);
    goto LABEL_9;
  }
LABEL_11:
  __break(0x5512u);
  return get_effective_result_locked(v5, v5);
}
