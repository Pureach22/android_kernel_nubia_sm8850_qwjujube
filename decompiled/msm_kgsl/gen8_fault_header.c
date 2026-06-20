__int64 __fastcall gen8_fault_header(_QWORD *a1, __int64 a2)
{
  int v4; // w22
  __int64 result; // x0
  __int64 v6; // x27
  __int64 v7; // x8
  int v8; // w19
  const char *v9; // x24
  __int64 v10; // x8
  int v11; // w22
  int v12; // w23
  int v13; // w24
  int v14; // w25
  int v15; // w27
  __int64 v16; // x8
  __int64 v17; // x25
  int v18; // w26
  const char *v19; // x0
  __int64 v20; // x8
  const char *v21; // x2
  __int64 v22; // x8
  int v23; // w3
  __int64 v24; // x8
  int v25; // [xsp+24h] [xbp-5Ch]
  int v26; // [xsp+28h] [xbp-58h]
  int v27; // [xsp+2Ch] [xbp-54h]
  int v28; // [xsp+30h] [xbp-50h]
  int v29; // [xsp+34h] [xbp-4Ch]
  int v30; // [xsp+38h] [xbp-48h]
  int v31; // [xsp+3Ch] [xbp-44h]
  int v32; // [xsp+40h] [xbp-40h]
  unsigned __int64 v33; // [xsp+48h] [xbp-38h] BYREF
  unsigned __int64 v34; // [xsp+50h] [xbp-30h] BYREF
  unsigned __int64 v35; // [xsp+58h] [xbp-28h] BYREF
  unsigned __int64 v36; // [xsp+60h] [xbp-20h] BYREF
  unsigned __int64 v37; // [xsp+68h] [xbp-18h] BYREF
  unsigned __int64 v38[2]; // [xsp+70h] [xbp-10h] BYREF

  v38[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  v38[0] = 0;
  v35 = 0;
  v4 = adreno_gx_is_on((__int64)a1);
  if ( a2 )
  {
    v6 = *(_QWORD *)(a2 + 8);
    *(_DWORD *)(v6 + 284) = *(_DWORD *)(a2 + 20);
    ++*(_DWORD *)(*(_QWORD *)(a2 + 8) + 280LL);
    v7 = *(_QWORD *)(a2 + 8);
    v8 = *(_DWORD *)(v7 + 4);
    if ( v7 )
    {
      v10 = *(_QWORD *)(v7 + 24);
      if ( v10 )
        v9 = (const char *)(v10 + 16);
      else
        v9 = "unknown";
    }
    else
    {
      v9 = "unknown";
      v10 = 0x183560000F4F68LL;
    }
    v16 = *(_QWORD *)(v10 + 8);
    v17 = *a1;
    if ( v16 )
      v18 = *(_DWORD *)(v16 + 112);
    else
      v18 = 0;
    v19 = (const char *)kgsl_context_type(*(unsigned int *)(v6 + 400));
    dev_err(
      v17,
      "%s[%d]: ctx %u ctx_type %s ts %u policy %lX\n",
      v9,
      v18,
      v8,
      v19,
      *(_DWORD *)(a2 + 20),
      *(_QWORD *)(a2 + 80));
    v20 = *(_QWORD *)(a2 + 8);
    if ( v20 )
    {
      v24 = *(_QWORD *)(v20 + 24);
      if ( v24 )
        v21 = (const char *)(v24 + 16);
      else
        v21 = "unknown";
      v22 = *(_QWORD *)(v24 + 8);
      if ( v22 )
        goto LABEL_29;
    }
    else
    {
      v21 = "unknown";
      v22 = MEMORY[0x183560000F4F70];
      if ( MEMORY[0x183560000F4F70] )
      {
LABEL_29:
        v23 = *(_DWORD *)(v22 + 112);
LABEL_35:
        dev_err(*a1, "%s[%d]: cmdline: %s\n", v21, v23, *(const char **)(*(_QWORD *)(v6 + 24) + 648LL));
        goto LABEL_2;
      }
    }
    v23 = 0;
    goto LABEL_35;
  }
LABEL_2:
  v36 = 0;
  v33 = 0;
  v34 = 0;
  result = gen8_gmu_rpmh_pwr_state_is_active(a1);
  if ( ((unsigned int)result & v4 & 1) != 0 )
  {
    v11 = kgsl_regmap_read(a1 + 1650);
    v31 = kgsl_regmap_read(a1 + 1650);
    v30 = kgsl_regmap_read(a1 + 1650);
    v29 = kgsl_regmap_read(a1 + 1650);
    v12 = kgsl_regmap_read(a1 + 1650);
    v13 = kgsl_regmap_read(a1 + 1650);
    v32 = kgsl_regmap_read(a1 + 1650);
    gen8_periph_regread64((__int64)a1, 28677, 0x7006u, v38, 1);
    if ( *((_DWORD *)a1 + 6136) != 4096 )
    {
      kgsl_regmap_write(a1 + 1650, 4096);
      __dsb(0xFu);
      *((_DWORD *)a1 + 6136) = 4096;
    }
    kgsl_regmap_write(a1 + 1650, 28680);
    __dsb(0xFu);
    v14 = kgsl_regmap_read(a1 + 1650);
    gen8_periph_regread64((__int64)a1, 28681, 0x700Au, &v37, 1);
    if ( *((_DWORD *)a1 + 6136) != 4096 )
    {
      kgsl_regmap_write(a1 + 1650, 4096);
      __dsb(0xFu);
      *((_DWORD *)a1 + 6136) = 4096;
    }
    kgsl_regmap_write(a1 + 1650, 28684);
    __dsb(0xFu);
    v15 = kgsl_regmap_read(a1 + 1650);
    gen8_periph_regread64((__int64)a1, 28685, 0x700Eu, &v36, 1);
    if ( *((_DWORD *)a1 + 6136) != 4096 )
    {
      kgsl_regmap_write(a1 + 1650, 4096);
      __dsb(0xFu);
      *((_DWORD *)a1 + 6136) = 4096;
    }
    kgsl_regmap_write(a1 + 1650, 28688);
    __dsb(0xFu);
    v28 = kgsl_regmap_read(a1 + 1650);
    gen8_periph_regread64((__int64)a1, 28677, 0x7006u, &v35, 2);
    if ( *((_DWORD *)a1 + 6136) != 0x2000 )
    {
      kgsl_regmap_write(a1 + 1650, 0x2000);
      __dsb(0xFu);
      *((_DWORD *)a1 + 6136) = 0x2000;
    }
    kgsl_regmap_write(a1 + 1650, 28680);
    __dsb(0xFu);
    v27 = kgsl_regmap_read(a1 + 1650);
    gen8_periph_regread64((__int64)a1, 28681, 0x700Au, &v34, 2);
    if ( *((_DWORD *)a1 + 6136) != 0x2000 )
    {
      kgsl_regmap_write(a1 + 1650, 0x2000);
      __dsb(0xFu);
      *((_DWORD *)a1 + 6136) = 0x2000;
    }
    kgsl_regmap_write(a1 + 1650, 28684);
    __dsb(0xFu);
    v26 = kgsl_regmap_read(a1 + 1650);
    gen8_periph_regread64((__int64)a1, 28685, 0x700Eu, &v33, 2);
    if ( *((_DWORD *)a1 + 6136) != 0x2000 )
    {
      kgsl_regmap_write(a1 + 1650, 0x2000);
      __dsb(0xFu);
      *((_DWORD *)a1 + 6136) = 0x2000;
    }
    kgsl_regmap_write(a1 + 1650, 28688);
    __dsb(0xFu);
    v25 = kgsl_regmap_read(a1 + 1650);
    if ( *((_DWORD *)a1 + 6136) )
    {
      kgsl_regmap_write(a1 + 1650, 0);
      __dsb(0xFu);
      *((_DWORD *)a1 + 6136) = 0;
    }
    dev_err(*a1, "status %8.8X gfx_status %8.8X gfx_br_status %8.8X gfx_bv_status %8.8X\n", v11, v31, v29, v30);
    dev_err(
      *a1,
      "BR: rb %4.4x/%4.4x ib1 %16.16llX/%4.4x ib2 %16.16llX/%4.4x ib3 %16.16llX/%4.4x\n",
      v12,
      v13,
      v38[0],
      v14,
      v37,
      v15,
      v36,
      v28);
    result = dev_err(
               *a1,
               "BV: rb %4.4x/%4.4x ib1 %16.16llX/%4.4x ib2 %16.16llX/%4.4x ib3 %16.16llX/%4.4x\n",
               v32,
               v13,
               v35,
               v27,
               v34,
               v26,
               v33,
               v25);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
