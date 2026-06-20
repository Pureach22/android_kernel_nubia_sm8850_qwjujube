unsigned __int64 __fastcall gen8_rb_start(__int64 a1)
{
  __int64 v1; // x23
  _DWORD *v3; // x22
  int v4; // w20
  __int64 v5; // x21
  __int64 v6; // x20
  unsigned __int64 v7; // x21
  __int64 v8; // x8
  unsigned __int64 v9; // x21
  unsigned __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // x21
  __int64 v13; // x20
  int v14; // w8
  __int64 v15; // x21
  __int64 v16; // x1
  unsigned __int64 v17; // x8
  __int64 v18; // x0
  const char *v19; // x1
  __int64 v20; // x20

  v1 = *(_QWORD *)(a1 + 14264);
  v3 = (_DWORD *)(a1 + 19632);
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
    while ( v4 < *v3 );
  }
  gen8_preemption_start(a1);
  v6 = *(_QWORD *)(a1 + 19640);
  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 48) + 24LL) + 32LL * *(int *)(v6 + 28);
  kgsl_regmap_write(a1 + 13200, (unsigned int)v7);
  kgsl_regmap_write(a1 + 13200, HIDWORD(v7));
  v8 = *(_QWORD *)(*(_QWORD *)(a1 + 48) + 24LL) + 32LL * *(int *)(v6 + 28);
  v9 = v8 + 4;
  kgsl_regmap_write(a1 + 13200, (unsigned int)(v8 + 4));
  kgsl_regmap_write(a1 + 13200, HIDWORD(v9));
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
    *(_QWORD *)(result + 8) = 0x14B70C80007LL;
    *(_DWORD *)(result + 24) = 2;
    *(_QWORD *)(result + 16) = 0x2000000000000003LL;
    *(_DWORD *)(result + 28) = *(_QWORD *)(*(_QWORD *)(a1 + 20464) + 24LL);
    *(_DWORD *)(result + 32) = *(_DWORD *)(*(_QWORD *)(a1 + 20464) + 28LL);
    *(_DWORD *)(result + 36) = 0x80000000;
    result = gen8_ringbuffer_submit(v6, 0);
    if ( !(_DWORD)result )
    {
      v11 = adreno_spin_idle(a1, 0x7D0u);
      if ( (_DWORD)v11 )
      {
        v12 = v11;
        gen8_spin_idle_debug((_QWORD *)a1, "CP initialization failed to idle\n");
        *(_QWORD *)(v6 + 16) = 0;
        return v12;
      }
      result = adreno_zap_shader_load(a1, *(_QWORD *)(v1 + 120));
      if ( !(_DWORD)result )
      {
        if ( v3[309] )
        {
          result = adreno_ringbuffer_allocspace(v6, 2);
          if ( result >= 0xFFFFFFFFFFFFF001LL )
            return result;
          *(_QWORD *)result = 1894121473;
          if ( !(unsigned int)gen8_ringbuffer_submit(v6, 0) )
          {
            v18 = adreno_spin_idle(a1, 0x7D0u);
            if ( (_DWORD)v18 )
            {
              v19 = "Switch to unsecure failed to idle\n";
              goto LABEL_35;
            }
          }
        }
        else
        {
          kgsl_regmap_write(a1 + 13200, 0);
        }
        gen8_set_gmem_protect((_QWORD *)a1);
        if ( (*(_BYTE *)(a1 + 23984) & 1) == 0 && *(_QWORD *)(*(_QWORD *)(a1 + 20464) + 24LL) )
        {
          gen8_patch_pwrup_reglist(a1);
          *(_BYTE *)(a1 + 23984) = 1;
        }
        v13 = *(_QWORD *)(a1 + 19640);
        if ( (*(_QWORD *)(a1 + 14240) & 0x200) == 0 )
          goto LABEL_19;
        v15 = *(_QWORD *)(*(_QWORD *)(a1 + 48) + 24LL);
        gen8_preemption_prepare_postamble(a1);
        if ( v3[240] )
          v16 = 16;
        else
          v16 = 12;
        result = adreno_ringbuffer_allocspace(v13, v16);
        if ( result > 0xFFFFFFFFFFFFF000LL )
          return result;
        *(_QWORD *)result = 0x170D68006LL;
        *(_DWORD *)(result + 8) = *(_QWORD *)(*(_QWORD *)(v13 + 184) + 24LL);
        *(_DWORD *)(result + 12) = *(_DWORD *)(*(_QWORD *)(v13 + 184) + 28LL);
        *(_DWORD *)(result + 16) = 2;
        *(_DWORD *)(result + 20) = *(_QWORD *)(*(_QWORD *)(v13 + 192) + 24LL);
        *(_DWORD *)(result + 24) = *(_DWORD *)(*(_QWORD *)(v13 + 192) + 28LL);
        if ( v3[240] )
        {
          *(_DWORD *)(result + 28) = 1893040131;
          *(_QWORD *)(result + 32) = v15 + 800;
          v17 = result + 44;
          *(_DWORD *)(result + 40) = v3[240] & 0xFFFFF | 0x300000;
        }
        else
        {
          v17 = result + 28;
        }
        *(_QWORD *)(v17 + 4) = 0;
        *(_DWORD *)v17 = 1886060548;
        *(_QWORD *)(v17 + 12) = 0;
        result = gen8_ringbuffer_submit(v13, 0);
        if ( (_DWORD)result )
          return result;
        v18 = adreno_spin_idle(a1, 0x7D0u);
        if ( !(_DWORD)v18 )
        {
LABEL_19:
          v14 = **(_DWORD **)(a1 + 14264);
          if ( (unsigned int)(v14 - 524800) < 2 || v14 == 526592 )
            gen8_hwcg_set(a1, 1);
          return 0;
        }
        v19 = "hw preemption initialization failed to idle\n";
LABEL_35:
        v20 = v18;
        gen8_spin_idle_debug((_QWORD *)a1, v19);
        return v20;
      }
    }
  }
  return result;
}
