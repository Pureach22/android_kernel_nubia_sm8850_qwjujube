__int64 __fastcall replicator_disable(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 v4; // x21
  unsigned int v12; // w8
  unsigned int v13; // w8
  __int64 v14; // x22
  __int64 v15; // x20
  unsigned int *v16; // x8

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  raw_spin_lock_irqsave(v4 + 32);
  if ( *(_BYTE *)(v4 + 88) == 1 )
  {
    _X9 = a3 + 14;
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v12 = __ldxr(_X9);
      v13 = v12 - 1;
    }
    while ( __stlxr(v13, _X9) );
    __dmb(0xBu);
    if ( !v13 )
    {
      if ( *(_QWORD *)v4 )
      {
        v14 = *a3;
        v15 = *(_QWORD *)(v4 + 24);
        if ( (_DWORD)v14 )
        {
          if ( (_DWORD)v14 != 1 )
          {
            __break(0x800u);
            return raw_spin_unlock_irqrestore(v4 + 32);
          }
          v14 = 4;
        }
        writel_relaxed(3316436565LL, *(_QWORD *)v4 + 4016LL);
        __dsb(0xFu);
        writel_relaxed(255, *(_QWORD *)v4 + v14);
        if ( (unsigned int)readl_relaxed(*(unsigned int **)v4) == 255
          && (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)v4 + 4LL)) == 255 )
        {
          coresight_disclaim_device_unlocked(v15);
        }
        v16 = *(unsigned int **)v4;
        __dsb(0xFu);
        writel_relaxed(0, v16 + 1004);
      }
    }
  }
  return raw_spin_unlock_irqrestore(v4 + 32);
}
