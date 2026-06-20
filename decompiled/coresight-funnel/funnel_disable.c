__int64 __fastcall funnel_disable(__int64 a1, __int64 a2)
{
  unsigned int **v3; // x22
  int v4; // w21
  unsigned int *v5; // x20
  unsigned int v6; // w21
  unsigned int *v7; // x8
  unsigned int v15; // w8
  unsigned int v16; // w8

  v3 = *(unsigned int ***)(*(_QWORD *)(a1 + 152) + 152LL);
  raw_spin_lock_irqsave(v3 + 5);
  if ( *((_BYTE *)v3 + 88) == 1 )
  {
    _X9 = (unsigned int *)(a2 + 60);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v15 = __ldxr(_X9);
      v16 = v15 - 1;
    }
    while ( __stlxr(v16, _X9) );
    __dmb(0xBu);
    if ( !v16 )
    {
      if ( *v3 )
      {
        v4 = *(_DWORD *)(a2 + 4);
        v5 = v3[3];
        writel_relaxed(0xC5ACCE55, *v3 + 1004);
        __dsb(0xFu);
        v6 = readl_relaxed(*v3) & ~(1 << v4);
        writel_relaxed(v6, *v3);
        if ( !(_BYTE)v6 )
          coresight_disclaim_device_unlocked(v5);
        v7 = *v3;
        __dsb(0xFu);
        writel_relaxed(0, v7 + 1004);
      }
    }
  }
  return raw_spin_unlock_irqrestore(v3 + 5);
}
