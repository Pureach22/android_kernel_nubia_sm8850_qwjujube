__int64 __fastcall gen8_preemption_start(__int64 result)
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
  __int64 v12; // x21
  __int64 v13; // x20
  __int64 v14; // x0
  __int64 v15; // x24
  __int64 v16; // x8
  __int64 (__fastcall *v17)(_QWORD); // x8
  __int64 v18; // x26
  __int64 v19; // x2
  unsigned __int64 v25; // x8

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
      _X25 = v1 + 1794;
      do
      {
        kgsl_sharedmem_writel(_X25[23], 20, 0);
        kgsl_sharedmem_writel(_X25[23], 24, 0);
        v12 = v1[9];
        v13 = raw_spin_lock_irqsave((char *)_X25 + 1292);
        kgsl_sharedmem_writel(v1[6], (32LL * *((int *)_X25 + 7)) | 0xC, *(unsigned int *)(v12 + 24));
        v14 = v1[6];
        v15 = *((int *)_X25 + 7);
        if ( v12
          && (v16 = *(_QWORD *)(v12 + 96)) != 0
          && (v17 = *(__int64 (__fastcall **)(_QWORD))(v16 + 48)) != nullptr )
        {
          v18 = v1[6];
          if ( *((_DWORD *)v17 - 1) != 1831526433 )
            __break(0x8228u);
          v19 = v17(v12);
          v14 = v18;
        }
        else
        {
          v19 = 0;
        }
        kgsl_sharedmem_writeq(v14, (32 * v15) | 0x10, v19);
        kgsl_sharedmem_writel(v1[6], (32LL * *((int *)_X25 + 7)) | 0x18, 0);
        result = raw_spin_unlock_irqrestore((char *)_X25 + 1292, v13);
        __asm { PRFM            #0x11, [X25] }
        do
          v25 = __ldxr(_X25);
        while ( __stxr(v25 & 0xFFFFFFFFFFFFFFFELL, _X25) );
        ++v10;
        _X25 += 165;
      }
      while ( v10 < *v2 );
    }
  }
  return result;
}
