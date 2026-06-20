__int64 __fastcall msm_msi_config(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 v6; // x22

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 144) + 32LL);
  v2 = raw_spin_lock_irqsave(v1 + 144);
  *(_BYTE *)(v1 + 148) = 1;
  result = raw_spin_unlock_irqrestore(v1 + 144, v2);
  if ( *(_DWORD *)(v1 + 140) )
  {
    writel_relaxed(*(unsigned int *)(v1 + 128), *(_QWORD *)(v1 + 152) + 2080LL);
    result = writel_relaxed(0, *(_QWORD *)(v1 + 152) + 2084LL);
    if ( *(int *)(v1 + 40) >= 1 )
    {
      v4 = 0;
      v5 = 0;
      do
      {
        v6 = *(_QWORD *)(v1 + 48) + v4;
        writel_relaxed(*(unsigned int *)(v6 + 24), *(_QWORD *)(v6 + 8));
        result = writel_relaxed(0xFFFFFFFFLL, *(_QWORD *)v6);
        ++v5;
        v4 += 1056;
      }
      while ( v5 < *(int *)(v1 + 40) );
    }
  }
  return result;
}
