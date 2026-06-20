unsigned __int64 __fastcall gen7_rb_start(__int64 a1)
{
  __int64 v1; // x23
  __int64 v3; // x22
  int v4; // w20
  __int64 v5; // x21
  __int64 v6; // x20
  unsigned __int64 v7; // x21
  int v8; // w8
  __int64 v9; // x8
  unsigned __int64 v10; // x21
  unsigned __int64 result; // x0
  int v12; // w10
  int v13; // w8
  __int64 v14; // x0
  __int64 v15; // x21
  const char *v16; // x1
  __int64 v17; // x20
  __int64 v18; // x21
  __int64 v19; // x1
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x20

  v1 = *(_QWORD *)(a1 + 14264);
  v3 = a1 + 19632;
  if ( *(int *)(a1 + 19632) >= 1 )
  {
    v4 = 0;
    v5 = a1 + 14360;
    do
    {
      memset(*(void **)(*(_QWORD *)v5 + 8LL), 170, 0x8000u);
      kgsl_sharedmem_writel(*(_QWORD *)(a1 + 48), 32LL * *(int *)(v5 + 20), 0);
      kgsl_sharedmem_writel(*(_QWORD *)(a1 + 48), (32LL * *(int *)(v5 + 20)) | 4, 0);
      *(_QWORD *)(v5 + 8) = 0;
      ++v4;
      *(_DWORD *)(v5 + 1272) = -1;
      v5 += 1320;
    }
    while ( v4 < *(_DWORD *)v3 );
  }
  gen7_preemption_start(a1);
  v6 = *(_QWORD *)(a1 + 19640);
  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 48) + 24LL) + 32LL * *(int *)(v6 + 28);
  kgsl_regmap_write(a1 + 13200, (unsigned int)v7);
  kgsl_regmap_write(a1 + 13200, HIDWORD(v7));
  v8 = **(_DWORD **)(a1 + 14264);
  if ( v8 != 459520 && v8 != 462336 && v8 != 463104 )
  {
    v9 = *(_QWORD *)(*(_QWORD *)(a1 + 48) + 24LL) + 32LL * *(int *)(v6 + 28);
    v10 = v9 + 4;
    kgsl_regmap_write(a1 + 13200, (unsigned int)(v9 + 4));
    kgsl_regmap_write(a1 + 13200, HIDWORD(v10));
  }
  kgsl_regmap_write(a1 + 13200, 524);
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(v6 + 8) + 24LL));
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(v6 + 8) + 28LL));
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14296) + 24LL));
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14296) + 28LL));
  kgsl_regmap_write(a1 + 13200, 1);
  result = adreno_ringbuffer_allocspace(v6, 10);
  if ( result <= 0xFFFFFFFFFFFFF000LL )
  {
    *(_QWORD *)result = 0x800000070970001LL;
    v12 = *(unsigned __int8 *)(v3 + 809);
    *(_QWORD *)(result + 16) = 0x2000000000000003LL;
    *(_DWORD *)(result + 24) = 2;
    v13 = v12 ? 331 : 2379;
    *(_DWORD *)(result + 8) = 1892155399;
    *(_DWORD *)(result + 12) = v13;
    *(_DWORD *)(result + 28) = *(_QWORD *)(*(_QWORD *)(a1 + 20464) + 24LL);
    *(_DWORD *)(result + 32) = *(_DWORD *)(*(_QWORD *)(a1 + 20464) + 28LL);
    *(_DWORD *)(result + 36) = 0x80000000;
    result = gen7_ringbuffer_submit(v6, 0);
    if ( !(_DWORD)result )
    {
      v14 = adreno_spin_idle(a1, 0x7D0u);
      if ( (_DWORD)v14 )
      {
        v15 = v14;
        gen7_spin_idle_debug((_QWORD *)a1, "CP initialization failed to idle\n");
        *(_QWORD *)(v6 + 16) = 0;
        return v15;
      }
      result = adreno_zap_shader_load(a1, *(_QWORD *)(v1 + 128));
      if ( !(_DWORD)result )
      {
        if ( *(_DWORD *)(v3 + 1236) )
        {
          result = adreno_ringbuffer_allocspace(v6, 2);
          if ( result >= 0xFFFFFFFFFFFFF001LL )
            return result;
          *(_QWORD *)result = 1894121473;
          if ( !(unsigned int)gen7_ringbuffer_submit(v6, 0) )
          {
            result = adreno_spin_idle(a1, 0x7D0u);
            if ( (_DWORD)result )
            {
              v16 = "Switch to unsecure failed to idle\n";
LABEL_35:
              v21 = result;
              gen7_spin_idle_debug((_QWORD *)a1, v16);
              return v21;
            }
          }
        }
        else
        {
          kgsl_regmap_write(a1 + 13200, 0);
        }
        v17 = *(_QWORD *)(a1 + 19640);
        if ( (*(_QWORD *)(a1 + 14240) & 0x200) == 0 )
          return 0;
        v18 = *(_QWORD *)(*(_QWORD *)(a1 + 48) + 24LL);
        gen7_preemption_prepare_postamble(a1);
        if ( *(_DWORD *)(v3 + 960) )
          v19 = 16;
        else
          v19 = 12;
        result = adreno_ringbuffer_allocspace(v17, v19);
        if ( result < 0xFFFFFFFFFFFFF001LL )
        {
          *(_QWORD *)result = 0x170D68006LL;
          *(_DWORD *)(result + 8) = *(_QWORD *)(*(_QWORD *)(v17 + 184) + 24LL);
          *(_DWORD *)(result + 12) = *(_DWORD *)(*(_QWORD *)(v17 + 184) + 28LL);
          *(_DWORD *)(result + 16) = 2;
          *(_DWORD *)(result + 20) = *(_QWORD *)(*(_QWORD *)(v17 + 192) + 24LL);
          *(_DWORD *)(result + 24) = *(_DWORD *)(*(_QWORD *)(v17 + 192) + 28LL);
          if ( *(_DWORD *)(v3 + 960) )
          {
            *(_DWORD *)(result + 28) = 1893040131;
            *(_QWORD *)(result + 32) = v18 + 800;
            v20 = result + 44;
            *(_DWORD *)(result + 40) = *(_DWORD *)(v3 + 960) & 0xFFFFF | 0x300000;
          }
          else
          {
            v20 = result + 28;
          }
          *(_QWORD *)(v20 + 4) = 0;
          *(_DWORD *)v20 = 1886060548;
          *(_QWORD *)(v20 + 12) = 0;
          result = gen7_ringbuffer_submit(v17, 0);
          if ( !(_DWORD)result )
          {
            result = adreno_spin_idle(a1, 0x7D0u);
            if ( (_DWORD)result )
            {
              v16 = "hw preemption initialization failed to idle\n";
              goto LABEL_35;
            }
          }
        }
      }
    }
  }
  return result;
}
