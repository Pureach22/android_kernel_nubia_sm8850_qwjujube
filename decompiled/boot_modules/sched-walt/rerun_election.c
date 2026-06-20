__int64 __fastcall rerun_election(__int64 a1)
{
  __int64 v2; // x0
  __int64 (__fastcall *v3)(__int64, __int64, __int64, __int64); // x8
  __int64 v4; // x20
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x1
  unsigned int v8; // w21

  if ( a1 )
  {
    v2 = raw_spin_lock_irqsave(a1 + 104);
    v3 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 120);
    v4 = v2;
    if ( v3 )
    {
      v6 = *(unsigned int *)(a1 + 96);
      v5 = *(unsigned int *)(a1 + 100);
      v7 = *(_QWORD *)(a1 + 112);
      if ( *((_DWORD *)v3 - 1) != -1953655469 )
        __break(0x8228u);
      v8 = v3(a1, v7, v5, v6);
    }
    else
    {
      v8 = 0;
    }
    raw_spin_unlock_irqrestore(a1 + 104, v4);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v8;
}
