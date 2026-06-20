__int64 __fastcall gen7_fault_header(_QWORD *a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x26
  __int64 v6; // x8
  int v7; // w28
  const char *v8; // x23
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x24
  unsigned int v12; // w19
  int v13; // w25
  const char *v14; // x0
  __int64 v15; // x8
  const char *v16; // x2
  __int64 v17; // x8
  int v18; // w3
  __int64 v19; // x8
  int v20; // w22
  int v21; // w23
  int v22; // w24
  __int64 v23; // x1
  unsigned int v24; // w25
  __int64 v25; // x27
  __int64 v26; // x25
  __int64 v27; // x1
  int v28; // w26
  __int64 v29; // x1
  unsigned int v30; // w27
  __int64 v31; // x28
  __int64 v32; // x27
  __int64 v33; // x1
  int v34; // w0

  result = adreno_gx_is_on((__int64)a1);
  if ( a2 )
  {
    v5 = *(_QWORD *)(a2 + 8);
    *(_DWORD *)(v5 + 284) = *(_DWORD *)(a2 + 20);
    ++*(_DWORD *)(*(_QWORD *)(a2 + 8) + 280LL);
    v6 = *(_QWORD *)(a2 + 8);
    v7 = *(_DWORD *)(v6 + 4);
    if ( v6 )
    {
      v9 = *(_QWORD *)(v6 + 24);
      if ( v9 )
        v8 = (const char *)(v9 + 16);
      else
        v8 = "unknown";
    }
    else
    {
      v8 = "unknown";
      v9 = 0x183560000F4F68LL;
    }
    v10 = *(_QWORD *)(v9 + 8);
    v11 = *a1;
    v12 = result;
    if ( v10 )
      v13 = *(_DWORD *)(v10 + 112);
    else
      v13 = 0;
    v14 = (const char *)kgsl_context_type(*(unsigned int *)(v5 + 400));
    dev_err(
      v11,
      "%s[%d]: ctx %u ctx_type %s ts %u policy %lX dispatch_queue=%d\n",
      v8,
      v13,
      v7,
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
        goto LABEL_14;
    }
    else
    {
      v16 = "unknown";
      v17 = MEMORY[0x183560000F4F70];
      if ( MEMORY[0x183560000F4F70] )
      {
LABEL_14:
        v18 = *(_DWORD *)(v17 + 112);
        goto LABEL_20;
      }
    }
    v18 = 0;
LABEL_20:
    dev_err(*a1, "%s[%d]: cmdline: %s\n", v16, v18, *(const char **)(*(_QWORD *)(v5 + 24) + 648LL));
    result = v12;
    if ( (v12 & 1) == 0 )
      return result;
    goto LABEL_21;
  }
  if ( (result & 1) == 0 )
    return result;
LABEL_21:
  v20 = kgsl_regmap_read(a1 + 1650);
  v21 = kgsl_regmap_read(a1 + 1650);
  v22 = kgsl_regmap_read(a1 + 1650);
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v23 = 28677;
  else
    v23 = 28674;
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v24 = 28678;
  else
    v24 = 28675;
  kgsl_regmap_write(a1 + 1650, v23);
  __dsb(0xFu);
  v25 = (unsigned int)kgsl_regmap_read(a1 + 1650);
  kgsl_regmap_write(a1 + 1650, v24);
  __dsb(0xFu);
  v26 = v25 | (kgsl_regmap_read(a1 + 1650) << 32);
  if ( *(_DWORD *)a1[1783] >> 1 == 230528 )
    v27 = 28680;
  else
    v27 = 28677;
  kgsl_regmap_write(a1 + 1650, v27);
  __dsb(0xFu);
  v28 = kgsl_regmap_read(a1 + 1650);
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v29 = 28681;
  else
    v29 = 28678;
  if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
    v30 = 28682;
  else
    v30 = 28679;
  kgsl_regmap_write(a1 + 1650, v29);
  __dsb(0xFu);
  v31 = (unsigned int)kgsl_regmap_read(a1 + 1650);
  kgsl_regmap_write(a1 + 1650, v30);
  __dsb(0xFu);
  v32 = v31 | (kgsl_regmap_read(a1 + 1650) << 32);
  if ( *(_DWORD *)a1[1783] >> 1 == 230528 )
    v33 = 28684;
  else
    v33 = 28681;
  kgsl_regmap_write(a1 + 1650, v33);
  __dsb(0xFu);
  v34 = kgsl_regmap_read(a1 + 1650);
  return dev_err(
           *a1,
           "status %8.8X rb %4.4x/%4.4x ib1 %16.16llX/%4.4x ib2 %16.16llX/%4.4x\n",
           v20,
           v21,
           v22,
           v26,
           v28,
           v32,
           v34);
}
