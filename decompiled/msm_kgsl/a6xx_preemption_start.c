__int64 __fastcall a6xx_preemption_start(__int64 result)
{
  _QWORD *v1; // x19
  unsigned int *v2; // x22
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x9
  __int64 (__fastcall *v6)(_QWORD); // x9
  __int64 v7; // x20
  __int64 v8; // x0
  __int64 v9; // x2
  unsigned int v10; // w23
  int *v11; // x24
  __int64 v12; // x2
  __int64 v13; // x21
  __int64 v14; // x20
  __int64 v15; // x0
  __int64 v16; // x28
  __int64 v17; // x8
  __int64 (__fastcall *v18)(_QWORD); // x8
  __int64 v19; // x25

  if ( (*(_QWORD *)(result + 14240) & 0x200) != 0 )
  {
    __dmb(0xAu);
    v1 = (_QWORD *)result;
    v2 = (unsigned int *)(result + 19632);
    *(_DWORD *)(result + 20488) = 0;
    __dmb(0xAu);
    if ( (*(_QWORD *)(result + 104) & 0x40) != 0 )
    {
      kgsl_sharedmem_writel(*(_QWORD *)(result + 1000), 0, 605245653);
      v3 = v1[9];
      v4 = v1[125];
      if ( v3 && (v5 = *(_QWORD *)(v3 + 96)) != 0 && (v6 = *(__int64 (__fastcall **)(_QWORD))(v5 + 48)) != nullptr )
      {
        v7 = v1[125];
        v8 = v1[9];
        if ( *((_DWORD *)v6 - 1) != 1831526433 )
          __break(0x8229u);
        v9 = v6(v8);
        v4 = v7;
      }
      else
      {
        v9 = 0;
      }
      kgsl_sharedmem_writeq(v4, 8, v9);
      kgsl_sharedmem_writel(v1[125], 16, 3737844653LL);
      kgsl_sharedmem_writel(v1[125], 20, 0);
      kgsl_regmap_write(v1 + 1650, *(unsigned int *)(v1[125] + 24LL));
      result = kgsl_regmap_write(v1 + 1650, *(unsigned int *)(v1[125] + 28LL));
    }
    if ( *v2 )
    {
      v10 = 0;
      v11 = (int *)v1 + 3595;
      do
      {
        kgsl_sharedmem_writel(*(_QWORD *)(v11 + 39), 20, 0);
        kgsl_sharedmem_writel(*(_QWORD *)(v11 + 39), 24, 0);
        v13 = v1[9];
        v14 = raw_spin_lock_irqsave(v11 + 316);
        kgsl_sharedmem_writel(v1[6], (32LL * *v11) | 0xC, *(unsigned int *)(v13 + 24));
        v15 = v1[6];
        v16 = *v11;
        if ( v13
          && (v17 = *(_QWORD *)(v13 + 96)) != 0
          && (v18 = *(__int64 (__fastcall **)(_QWORD))(v17 + 48)) != nullptr )
        {
          v19 = v1[6];
          if ( *((_DWORD *)v18 - 1) != 1831526433 )
            __break(0x8228u);
          v12 = v18(v13);
          v15 = v19;
        }
        else
        {
          v12 = 0;
        }
        kgsl_sharedmem_writeq(v15, (32 * v16) | 0x10, v12);
        kgsl_sharedmem_writel(v1[6], (32LL * *v11) | 0x18, 0);
        result = raw_spin_unlock_irqrestore(v11 + 316, v14);
        ++v10;
        v11 += 330;
      }
      while ( v10 < *v2 );
    }
  }
  return result;
}
