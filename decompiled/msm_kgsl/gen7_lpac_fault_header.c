__int64 __fastcall gen7_lpac_fault_header(_QWORD *a1, __int64 a2)
{
  char v4; // w0
  __int64 v5; // x26
  char v6; // w20
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
  int v21; // w20
  int v22; // w22
  int v23; // w23
  __int64 v24; // x1
  unsigned int v25; // w24
  __int64 v26; // x26
  __int64 v27; // x24
  __int64 v28; // x1
  int v29; // w25
  __int64 v30; // x1
  unsigned int v31; // w26
  __int64 v32; // x26
  __int64 v33; // x1
  int v34; // w0
  __int64 v35; // x9
  const char *v36; // x2
  __int64 v37; // x9
  __int64 v38; // x9
  __int64 v39; // x26
  int v40; // w3
  __int64 v41; // [xsp+18h] [xbp-8h]

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
    "%s[%d]: LPAC ctx %d ctx_type %s ts %d dispatch_queue=%d\n",
    v9,
    v11,
    v13,
    v14,
    *(_DWORD *)(a2 + 20),
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
  result = dev_err(*a1, "%s[%d]: lpac cmdline: %s\n", v16, v18, *(const char **)(*(_QWORD *)(v5 + 24) + 648LL));
  if ( (v6 & 1) != 0 )
  {
    v21 = kgsl_regmap_read(a1 + 1650);
    v22 = kgsl_regmap_read(a1 + 1650);
    v23 = kgsl_regmap_read(a1 + 1650);
    if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
      v24 = 28677;
    else
      v24 = 28674;
    if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
      v25 = 28678;
    else
      v25 = 28675;
    kgsl_regmap_write(a1 + 1650, v24);
    __dsb(0xFu);
    v26 = (unsigned int)kgsl_regmap_read(a1 + 1650);
    kgsl_regmap_write(a1 + 1650, v25);
    __dsb(0xFu);
    v27 = v26 | (kgsl_regmap_read(a1 + 1650) << 32);
    if ( *(_DWORD *)a1[1783] >> 1 == 230528 )
      v28 = 28680;
    else
      v28 = 28677;
    kgsl_regmap_write(a1 + 1650, v28);
    __dsb(0xFu);
    v29 = kgsl_regmap_read(a1 + 1650);
    if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
      v30 = 28681;
    else
      v30 = 28678;
    if ( (*(_DWORD *)a1[1783] & 0xFFFFFFFE) == 0x70900 )
      v31 = 28682;
    else
      v31 = 28679;
    kgsl_regmap_write(a1 + 1650, v30);
    __dsb(0xFu);
    v41 = (unsigned int)kgsl_regmap_read(a1 + 1650);
    kgsl_regmap_write(a1 + 1650, v31);
    __dsb(0xFu);
    v32 = (unsigned int)kgsl_regmap_read(a1 + 1650);
    if ( *(_DWORD *)a1[1783] >> 1 == 230528 )
      v33 = 28684;
    else
      v33 = 28681;
    kgsl_regmap_write(a1 + 1650, v33);
    __dsb(0xFu);
    v34 = kgsl_regmap_read(a1 + 1650);
    v35 = *(_QWORD *)(a2 + 8);
    if ( v35 )
    {
      v37 = *(_QWORD *)(v35 + 24);
      if ( v37 )
        v36 = (const char *)(v37 + 16);
      else
        v36 = "unknown";
    }
    else
    {
      v36 = "unknown";
      v37 = 0x183560000F4F68LL;
    }
    v38 = *(_QWORD *)(v37 + 8);
    v39 = v41 | (v32 << 32);
    if ( v38 )
      v40 = *(_DWORD *)(v38 + 112);
    else
      v40 = 0;
    return dev_err(
             *a1,
             "%s[%d]: LPAC: status %8.8X rb %4.4x/%4.4x ib1 %16.16llX/%4.4x ib2 %16.16llX/%4.4x\n",
             v36,
             v40,
             v21,
             v22,
             v23,
             v27,
             v29,
             v39,
             v34);
  }
  return result;
}
