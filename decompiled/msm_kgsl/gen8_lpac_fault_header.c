__int64 __fastcall gen8_lpac_fault_header(_QWORD *a1, __int64 a2)
{
  int v4; // w0
  __int64 v5; // x26
  int v6; // w21
  __int64 v7; // x8
  __int64 v8; // x22
  const char *v9; // x23
  __int64 v10; // x9
  int v11; // w24
  __int64 v12; // x9
  int v13; // w25
  const char *v14; // x0
  __int64 v15; // x8
  const char *v16; // x2
  __int64 v17; // x8
  int v18; // w3
  __int64 v19; // x8
  __int64 result; // x0
  int v21; // w21
  int v22; // w22
  int v23; // w23
  int v24; // w24
  int v25; // w25
  int v26; // w10
  int v27; // w28
  __int64 v28; // x8
  const char *v29; // x2
  __int64 v30; // x8
  int v31; // w3
  __int64 v32; // x8
  unsigned __int64 v33; // [xsp+30h] [xbp-20h] BYREF
  unsigned __int64 v34; // [xsp+38h] [xbp-18h] BYREF
  unsigned __int64 v35[2]; // [xsp+40h] [xbp-10h] BYREF

  v35[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v35[0] = 0;
  v33 = 0;
  v4 = adreno_gx_is_on((__int64)a1);
  v5 = *(_QWORD *)(a2 + 8);
  v6 = v4;
  *(_DWORD *)(v5 + 284) = *(_DWORD *)(a2 + 20);
  ++*(_DWORD *)(*(_QWORD *)(a2 + 8) + 280LL);
  v7 = *(_QWORD *)(a2 + 8);
  v8 = *a1;
  if ( v7 )
  {
    v12 = *(_QWORD *)(v7 + 24);
    if ( v12 )
      v9 = (const char *)(v12 + 16);
    else
      v9 = "unknown";
    v10 = *(_QWORD *)(v12 + 8);
    if ( v10 )
      goto LABEL_3;
  }
  else
  {
    v9 = "unknown";
    v10 = MEMORY[0x183560000F4F70];
    if ( MEMORY[0x183560000F4F70] )
    {
LABEL_3:
      v11 = *(_DWORD *)(v10 + 112);
      goto LABEL_9;
    }
  }
  v11 = 0;
LABEL_9:
  v13 = *(_DWORD *)(v7 + 4);
  v14 = (const char *)kgsl_context_type(*(unsigned int *)(v5 + 400));
  dev_err(
    v8,
    "%s[%d]: LPAC ctx %u ctx_type %s ts %u policy %lX dispatch_queue=%d\n",
    v9,
    v11,
    v13,
    v14,
    *(_DWORD *)(a2 + 20),
    *(_QWORD *)(a2 + 80),
    *(_DWORD *)(*(_QWORD *)(a2 + 8) + 292LL));
  v15 = *(_QWORD *)(a2 + 8);
  if ( v15 )
  {
    v19 = *(_QWORD *)(v15 + 24);
    if ( v19 )
      v16 = (const char *)(v19 + 16);
    else
      v16 = "unknown";
    v17 = *(_QWORD *)(v19 + 8);
    if ( v17 )
      goto LABEL_11;
  }
  else
  {
    v16 = "unknown";
    v17 = MEMORY[0x183560000F4F70];
    if ( MEMORY[0x183560000F4F70] )
    {
LABEL_11:
      v18 = *(_DWORD *)(v17 + 112);
      goto LABEL_17;
    }
  }
  v18 = 0;
LABEL_17:
  dev_err(*a1, "%s[%d]: lpac cmdline: %s\n", v16, v18, *(const char **)(*(_QWORD *)(v5 + 24) + 648LL));
  result = gen8_gmu_rpmh_pwr_state_is_active(a1);
  if ( ((unsigned int)result & v6 & 1) != 0 )
  {
    v21 = kgsl_regmap_read(a1 + 1650);
    v22 = kgsl_regmap_read(a1 + 1650);
    v23 = kgsl_regmap_read(a1 + 1650);
    gen8_periph_regread64((__int64)a1, 28677, 0x7006u, v35, 3);
    if ( *((_DWORD *)a1 + 6136) != 12288 )
    {
      kgsl_regmap_write(a1 + 1650, 12288);
      __dsb(0xFu);
      *((_DWORD *)a1 + 6136) = 12288;
    }
    kgsl_regmap_write(a1 + 1650, 28680);
    __dsb(0xFu);
    v24 = kgsl_regmap_read(a1 + 1650);
    gen8_periph_regread64((__int64)a1, 28681, 0x700Au, &v34, 3);
    if ( *((_DWORD *)a1 + 6136) != 12288 )
    {
      kgsl_regmap_write(a1 + 1650, 12288);
      __dsb(0xFu);
      *((_DWORD *)a1 + 6136) = 12288;
    }
    kgsl_regmap_write(a1 + 1650, 28684);
    __dsb(0xFu);
    v25 = kgsl_regmap_read(a1 + 1650);
    gen8_periph_regread64((__int64)a1, 28685, 0x700Eu, &v33, 3);
    if ( *((_DWORD *)a1 + 6136) != 12288 )
    {
      kgsl_regmap_write(a1 + 1650, 12288);
      __dsb(0xFu);
      *((_DWORD *)a1 + 6136) = 12288;
    }
    kgsl_regmap_write(a1 + 1650, 28688);
    __dsb(0xFu);
    v26 = kgsl_regmap_read(a1 + 1650);
    if ( *((_DWORD *)a1 + 6136) )
    {
      v27 = v26;
      kgsl_regmap_write(a1 + 1650, 0);
      __dsb(0xFu);
      v26 = v27;
      *((_DWORD *)a1 + 6136) = 0;
    }
    v28 = *(_QWORD *)(a2 + 8);
    if ( v28 )
    {
      v32 = *(_QWORD *)(v28 + 24);
      if ( v32 )
        v29 = (const char *)(v32 + 16);
      else
        v29 = "unknown";
      v30 = *(_QWORD *)(v32 + 8);
      if ( v30 )
        goto LABEL_29;
    }
    else
    {
      v29 = "unknown";
      v30 = MEMORY[0x183560000F4F70];
      if ( MEMORY[0x183560000F4F70] )
      {
LABEL_29:
        v31 = *(_DWORD *)(v30 + 112);
LABEL_35:
        result = dev_err(
                   *a1,
                   "%s[%d]: LPAC: status %8.8X rb %4.4x/%4.4x ib1 %16.16llX/%4.4x ib2 %16.16llX/%4.4x ib3 %16.16llX/%4.4x\n",
                   v29,
                   v31,
                   v21,
                   v22,
                   v23,
                   v35[0],
                   v24,
                   v34,
                   v25,
                   v33,
                   v26);
        goto LABEL_18;
      }
    }
    v31 = 0;
    goto LABEL_35;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
