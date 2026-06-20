unsigned __int64 __fastcall a5xx_rb_start(__int64 a1)
{
  __int64 v2; // x22
  int v3; // w20
  __int64 v4; // x21
  __int64 v5; // x20
  unsigned __int64 v6; // x21
  __int64 v7; // x8
  __int64 v8; // x24
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x19
  unsigned __int64 result; // x0
  int v14; // w8
  int v15; // w8
  __int64 v16; // x0
  const char *v17; // x1
  __int64 v18; // x20
  int v19; // w8
  __int64 v20; // x20
  _DWORD *v21; // x0
  _DWORD *v22; // x8
  __int64 v23; // x9
  __int64 v24; // x11

  v2 = a1 + 19632;
  if ( *(int *)(a1 + 19632) >= 1 )
  {
    v3 = 0;
    v4 = a1 + 14360;
    do
    {
      memset(*(void **)(*(_QWORD *)v4 + 8LL), 170, 0x8000u);
      kgsl_sharedmem_writel(*(_QWORD *)(a1 + 48), 32LL * *(int *)(v4 + 20), 0);
      *(_QWORD *)(v4 + 8) = 0;
      ++v3;
      *(_DWORD *)(v4 + 1272) = -1;
      v4 += 1320;
    }
    while ( v3 < *(_DWORD *)v2 );
  }
  v5 = *(_QWORD *)(a1 + 19640);
  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 48) + 24LL) + 32LL * *(int *)(v5 + 28);
  kgsl_regmap_write(a1 + 13200, (unsigned int)v6);
  kgsl_regmap_write(a1 + 13200, HIDWORD(v6));
  kgsl_regmap_write(a1 + 13200, 134218252);
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(v5 + 8) + 24LL));
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(v5 + 8) + 28LL));
  v7 = *(_QWORD *)(a1 + 14328);
  v8 = *(_QWORD *)(a1 + 14264);
  LODWORD(v6) = *(_DWORD *)(v7 + 28);
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(v7 + 24));
  kgsl_regmap_write(a1 + 13200, (unsigned int)v6);
  v9 = *(_QWORD *)(a1 + 14296);
  LODWORD(v6) = *(_DWORD *)(v9 + 28);
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(v9 + 24));
  kgsl_regmap_write(a1 + 13200, (unsigned int)v6);
  if ( *(_BYTE *)(a1 + 96) == 1 )
  {
    if ( !*(_DWORD *)(v2 + 1236) || (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 32LL) & 0x10) != 0 )
    {
      result = adreno_zap_shader_load(a1, *(_QWORD *)(v8 + 128));
      if ( (_DWORD)result )
        return result;
    }
    else
    {
      v10 = qcom_scm_set_remote_state(0, 13);
      if ( (_DWORD)v10 )
      {
        v11 = *(_QWORD *)a1;
        v12 = v10;
        dev_err(v11, "SCM zap resume call failed: %d\n", v10);
        return v12;
      }
    }
  }
  kgsl_regmap_write(a1 + 13200, 0);
  result = adreno_ringbuffer_allocspace(v5, 9);
  if ( result > 0xFFFFFFFFFFFFF000LL )
    return result;
  *(_QWORD *)(result + 16) = 0;
  *(_QWORD *)result = 0x2F70C80008LL;
  *(_QWORD *)(result + 8) = 0x2000000000000003LL;
  v14 = **(_DWORD **)(a1 + 14264);
  if ( (unsigned int)(v14 - 505) >= 2 )
  {
    if ( v14 == 510 )
    {
      v15 = 1;
      goto LABEL_17;
    }
    if ( v14 != 530 )
    {
      v15 = 0;
      goto LABEL_17;
    }
  }
  v15 = 11;
LABEL_17:
  *(_DWORD *)(result + 24) = v15;
  result = a5xx_ringbuffer_submit(v5, 0, 1);
  if ( (_DWORD)result )
    return result;
  v16 = adreno_spin_idle(a1, 0x7D0u);
  if ( (_DWORD)v16 )
  {
    v17 = "CP initialization failed to idle\n";
LABEL_20:
    v18 = v16;
    a5xx_spin_idle_debug(a1, v17);
    return v18;
  }
  if ( (*(_BYTE *)(v2 + 1024) & 2) != 0 && critical_packet_constructed == 1 )
  {
    result = adreno_ringbuffer_allocspace(v5, 4);
    if ( result > 0xFFFFFFFFFFFFF000LL )
      return result;
    *(_DWORD *)result = 1891598339;
    v19 = crit_pkts_dwords ? 573 : 0;
    *(_QWORD *)(result + 4) = *(_QWORD *)(*(_QWORD *)(a1 + 20872) + 24LL);
    *(_DWORD *)(result + 12) = v19;
    result = a5xx_ringbuffer_submit(v5, 0, 1);
    if ( (_DWORD)result )
      return result;
    v16 = adreno_spin_idle(a1, 0x14u);
    if ( (_DWORD)v16 )
    {
      v17 = "Critical packet submission failed to idle\n";
      goto LABEL_20;
    }
  }
  if ( *(_DWORD *)(v2 + 1236) )
  {
    result = adreno_ringbuffer_allocspace(v5, 2);
    if ( result >= 0xFFFFFFFFFFFFF001LL )
      return result;
    *(_QWORD *)result = 1894121473;
    if ( !(unsigned int)a5xx_ringbuffer_submit(v5, 0, 1) )
    {
      v16 = adreno_spin_idle(a1, 0x7D0u);
      if ( (_DWORD)v16 )
      {
        v17 = "Switch to unsecure failed to idle\n";
        goto LABEL_20;
      }
    }
  }
  else
  {
    kgsl_regmap_write(a1 + 13200, 0);
  }
  result = a5xx_gpmu_init(a1);
  if ( (_DWORD)result )
    return result;
  v20 = *(_QWORD *)(a1 + 19640);
  if ( **(_DWORD **)(a1 + 14264) == 530 || (*(_QWORD *)(a1 + 14240) & 0x200) != 0 )
  {
    v21 = (_DWORD *)adreno_ringbuffer_allocspace(*(_QWORD *)(a1 + 19640), 42);
    if ( (unsigned __int64)v21 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_err(*(_QWORD *)a1, "error allocating preemtion init cmds\n");
    }
    else
    {
      if ( **(_DWORD **)(a1 + 14264) == 530 )
      {
        *v21 = 1883635713;
        v21[1] = 15;
        v22 = v21 + 2;
      }
      else
      {
        v22 = v21;
      }
      v23 = *(_QWORD *)(a1 + 14240);
      if ( (v23 & 0x200) != 0 )
      {
        v24 = *(_QWORD *)(*(_QWORD *)(v20 + 184) + 24LL);
        *((_QWORD *)v22 + 3) = 0x170DF0001LL;
        v22[12] = 1880883201;
        v22[2] = 1208499713;
        v22[3] = v24;
        *(_QWORD *)v22 = 1893662721;
        v22[4] = 1074282241;
        v22[5] = HIDWORD(v24);
        v22[8] = 1894318081;
        v22[9] = 0;
        *(_QWORD *)(v22 + 13) = 0x706B000400000001LL;
        v22[10] = 1894383617;
        v22[11] = 1;
        *(_QWORD *)(v22 + 15) = 0;
        *(_QWORD *)(v22 + 17) = 0x100000000LL;
        v22 += 19;
      }
      *(_DWORD *)(v20 + 16) = *(_DWORD *)(v20 + 16) + ((unsigned __int64)((char *)v22 - (char *)v21) >> 2) - 42;
      if ( !(unsigned int)a5xx_ringbuffer_submit(v20, 0, (v23 & 0x200) == 0) )
      {
        result = adreno_spin_idle(a1, 0x7D0u);
        if ( !(_DWORD)result )
          return result;
        a5xx_spin_idle_debug(a1, "hw initialization failed to idle\n");
      }
    }
  }
  return 0;
}
