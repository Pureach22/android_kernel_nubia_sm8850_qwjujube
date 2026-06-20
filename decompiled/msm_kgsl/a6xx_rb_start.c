unsigned __int64 __fastcall a6xx_rb_start(__int64 a1)
{
  __int64 v1; // x23
  _DWORD *v2; // x22
  int v4; // w25
  int v5; // w20
  __int64 v6; // x21
  __int64 v7; // x20
  unsigned __int64 v8; // x21
  unsigned __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x21
  __int64 v13; // x20
  _QWORD *v14; // x0
  _QWORD *v15; // x9
  char *v16; // x8
  const char *v17; // x1
  unsigned __int64 v18; // x20
  __int64 v19; // x8
  unsigned int v20; // w19

  v1 = *(_QWORD *)(a1 + 14264);
  v2 = (_DWORD *)(a1 + 19632);
  v4 = (*(_DWORD *)(v1 + 32) << 16) & 0x8000000;
  if ( *(int *)(a1 + 19632) >= 1 )
  {
    v5 = 0;
    v6 = a1 + 14360;
    do
    {
      memset(*(void **)(*(_QWORD *)v6 + 8LL), 170, 0x8000u);
      kgsl_sharedmem_writel(*(_QWORD *)(a1 + 48), 32LL * *(int *)(v6 + 20), 0);
      *(_QWORD *)(v6 + 8) = 0;
      ++v5;
      *(_DWORD *)(v6 + 1272) = -1;
      v6 += 1320;
    }
    while ( v5 < *v2 );
  }
  a6xx_preemption_start(a1);
  v7 = *(_QWORD *)(a1 + 19640);
  v8 = *(_QWORD *)(*(_QWORD *)(a1 + 48) + 24LL) + 32LL * *(int *)(v7 + 28);
  kgsl_regmap_write(a1 + 13200, (unsigned int)v8);
  kgsl_regmap_write(a1 + 13200, HIDWORD(v8));
  kgsl_regmap_write(a1 + 13200, v4 ^ 0x800020Cu);
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(v7 + 8) + 24LL));
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(v7 + 8) + 28LL));
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14296) + 24LL));
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14296) + 28LL));
  kgsl_regmap_write(a1 + 13200, 1);
  result = adreno_ringbuffer_allocspace(v7, 11);
  if ( result > 0xFFFFFFFFFFFFF000LL )
    return result;
  *(_QWORD *)result = 0x16F70C8800ALL;
  *(_QWORD *)(result + 8) = 0x2000000000000003LL;
  *(_QWORD *)(result + 16) = 0;
  *(_QWORD *)(result + 24) = 0x200000000LL;
  v10 = *(_QWORD *)(*(_QWORD *)(a1 + 20464) + 24LL);
  *(_DWORD *)(result + 40) = 0;
  *(_QWORD *)(result + 32) = v10;
  result = a6xx_ringbuffer_submit(v7, 0, 1);
  if ( (_DWORD)result )
    return result;
  v11 = adreno_spin_idle(a1, 0x7D0u);
  if ( (_DWORD)v11 )
  {
    v12 = v11;
    a6xx_spin_idle_debug((_QWORD *)a1, "CP initialization failed to idle\n");
    kgsl_sharedmem_writel(*(_QWORD *)(a1 + 48), 32LL * *(int *)(v7 + 28), 0);
    *(_QWORD *)(v7 + 16) = 0;
    return v12;
  }
  result = adreno_zap_shader_load(a1, *(_QWORD *)(v1 + 120));
  if ( (_DWORD)result )
    return result;
  if ( v2[309] )
  {
    result = adreno_ringbuffer_allocspace(v7, 2);
    if ( result >= 0xFFFFFFFFFFFFF001LL )
      return result;
    *(_QWORD *)result = 1894121473;
    if ( !(unsigned int)a6xx_ringbuffer_submit(v7, 0, 1) )
    {
      result = adreno_spin_idle(a1, 0x7D0u);
      if ( (_DWORD)result )
      {
        v17 = "Switch to unsecure failed to idle\n";
        goto LABEL_29;
      }
    }
  }
  else
  {
    kgsl_regmap_write(a1 + 13200, 0);
  }
  v13 = *(_QWORD *)(a1 + 19640);
  if ( (*(_QWORD *)(a1 + 14240) & 0x200) == 0 )
    return 0;
  v14 = (_QWORD *)adreno_ringbuffer_allocspace(*(_QWORD *)(a1 + 19640), 42);
  if ( (unsigned __int64)v14 >= 0xFFFFFFFFFFFFF001LL )
  {
    v19 = *(_QWORD *)a1;
    v20 = (unsigned int)v14;
    dev_err(v19, "error allocating preemption init cmds\n");
    return v20;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 8) != 0 )
  {
    v15 = v14;
  }
  else
  {
    v15 = v14 + 1;
    *v14 = 1893662721;
  }
  *v15 = 0x170D68006LL;
  v15[1] = *(_QWORD *)(*(_QWORD *)(v13 + 184) + 24LL);
  *((_DWORD *)v15 + 4) = 2;
  *(_QWORD *)((char *)v15 + 20) = *(_QWORD *)(*(_QWORD *)(v13 + 192) + 24LL);
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 8) != 0 )
  {
    v16 = (char *)v15 + 28;
  }
  else
  {
    *((_DWORD *)v15 + 7) = 1893662721;
    *((_DWORD *)v15 + 8) = 1;
    v16 = (char *)v15 + 36;
  }
  *(_QWORD *)(v16 + 4) = 0;
  *(_QWORD *)(v16 + 12) = 0;
  *(_DWORD *)v16 = 1886060548;
  *(_DWORD *)(v13 + 16) = *(_DWORD *)(v13 + 16) + ((unsigned __int64)(v16 - (char *)v14 + 20) >> 2) - 42;
  result = a6xx_ringbuffer_submit(v13, 0, 0);
  if ( !(_DWORD)result )
  {
    result = adreno_spin_idle(a1, 0x7D0u);
    if ( (_DWORD)result )
    {
      v17 = "hw preemption initialization failed to idle\n";
LABEL_29:
      v18 = result;
      a6xx_spin_idle_debug((_QWORD *)a1, v17);
      return v18;
    }
  }
  return result;
}
