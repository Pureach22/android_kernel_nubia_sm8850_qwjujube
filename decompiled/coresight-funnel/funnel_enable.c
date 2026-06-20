__int64 __fastcall funnel_enable(__int64 a1, __int64 a2)
{
  unsigned int *v3; // x23
  unsigned int v4; // w21
  int v6; // w24
  __int64 v7; // x21
  int v8; // w22
  unsigned int *v9; // x8
  unsigned int v16; // w9

  v3 = *(unsigned int **)(*(_QWORD *)(a1 + 152) + 152LL);
  raw_spin_lock_irqsave(v3 + 10);
  if ( *((_BYTE *)v3 + 88) == 1 )
  {
    if ( *(_DWORD *)(a2 + 60) || !*(_QWORD *)v3 )
      goto LABEL_11;
    v6 = *(_DWORD *)(a2 + 4);
    v7 = *((_QWORD *)v3 + 3);
    writel_relaxed(0xC5ACCE55, (unsigned int *)(*(_QWORD *)v3 + 4016LL));
    __dsb(0xFu);
    v8 = readl_relaxed(*(unsigned int **)v3);
    if ( (_BYTE)v8 || (v4 = coresight_claim_device_unlocked(v7)) == 0 )
    {
      writel_relaxed((1 << v6) | v8 & 0xFFFFF0FF | 0x700, *(unsigned int **)v3);
      writel_relaxed(v3[8], (unsigned int *)(*(_QWORD *)v3 + 4LL));
      v4 = 0;
    }
    v9 = *(unsigned int **)v3;
    __dsb(0xFu);
    writel_relaxed(0, v9 + 1004);
    if ( !v4 )
    {
LABEL_11:
      _X8 = (unsigned int *)(a2 + 60);
      __asm { PRFM            #0x11, [X8] }
      do
        v16 = __ldxr(_X8);
      while ( __stxr(v16 + 1, _X8) );
      v4 = 0;
    }
  }
  else
  {
    v4 = -22;
  }
  raw_spin_unlock_irqrestore(v3 + 10);
  return v4;
}
