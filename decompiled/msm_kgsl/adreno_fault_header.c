__int64 __fastcall adreno_fault_header(_QWORD *a1, __int64 a2, __int64 a3, char a4)
{
  __int64 v8; // x27
  __int64 v9; // x8
  __int64 v10; // x23
  char v11; // w0
  int v12; // w26
  const char *v13; // x19
  _DWORD *v14; // x8
  __int64 result; // x0
  __int64 v16; // x22
  _DWORD *v17; // x8
  int v18; // w25
  __int64 v19; // x8
  const char *v20; // x23
  __int64 v21; // x9
  int v22; // w24
  int v23; // w28
  int v24; // w23
  int v25; // w9
  __int64 v26; // x8
  __int64 v27; // x23
  const char *v28; // x10
  __int64 v29; // x9
  __int64 v30; // x9
  int v31; // w24
  int v32; // w25
  const char *v33; // x0
  __int64 v34; // x8
  const char *v35; // x2
  __int64 v36; // x8
  __int64 v37; // x8
  int v38; // w3
  __int64 v39; // x9
  int v40; // w26
  int v41; // w24
  int v42; // w25
  const char *v43; // x0
  __int64 v44; // x8
  const char *v45; // x2
  __int64 v46; // x8
  __int64 v47; // x8
  int v48; // w3
  __int64 v49; // x8
  const char *v50; // x2
  __int64 v51; // x8
  __int64 v52; // x8
  int v53; // w3
  const char *v54; // [xsp+40h] [xbp-30h]
  int v55; // [xsp+4Ch] [xbp-24h]
  int v56; // [xsp+50h] [xbp-20h]
  int v57; // [xsp+54h] [xbp-1Ch]
  __int64 v58; // [xsp+58h] [xbp-18h] BYREF
  __int64 v59[2]; // [xsp+60h] [xbp-10h] BYREF

  v59[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
    v8 = *(_QWORD *)(a3 + 8);
  else
    v8 = 0;
  v9 = a1[1783];
  v58 = 0;
  v59[0] = 0;
  v10 = *(_QWORD *)(v9 + 40);
  v11 = adreno_gx_is_on((__int64)a1);
  if ( a2 )
    v12 = *(_DWORD *)(a2 + 28);
  else
    v12 = -1;
  if ( (a4 & 0x20) != 0 )
    v13 = "gmu";
  else
    v13 = "gpu";
  if ( (v11 & 1) == 0 )
  {
    v16 = *a1;
    if ( a3 )
    {
      v19 = *(_QWORD *)(a3 + 8);
      if ( v19 )
      {
        v21 = *(_QWORD *)(v19 + 24);
        if ( v21 )
          v20 = (const char *)(v21 + 16);
        else
          v20 = "unknown";
      }
      else
      {
        v20 = "unknown";
        v21 = 0x183560000F4F68LL;
      }
      v30 = *(_QWORD *)(v21 + 8);
      if ( v30 )
        v31 = *(_DWORD *)(v30 + 112);
      else
        v31 = 0;
      v32 = *(_DWORD *)(v19 + 4);
      v33 = (const char *)kgsl_context_type(*(unsigned int *)(v8 + 400));
      dev_err(
        v16,
        "%s[%d]: %s fault ctx %u ctx_type %s ts %u and GX is OFF\n",
        v20,
        v31,
        v13,
        v32,
        v33,
        *(_DWORD *)(a3 + 20));
      v34 = *(_QWORD *)(a3 + 8);
      if ( v34 )
      {
        v36 = *(_QWORD *)(v34 + 24);
        if ( v36 )
          v35 = (const char *)(v36 + 16);
        else
          v35 = "unknown";
      }
      else
      {
        v35 = "unknown";
        v36 = 0x183560000F4F68LL;
      }
      v37 = *(_QWORD *)(v36 + 8);
      if ( v37 )
        v38 = *(_DWORD *)(v37 + 112);
      else
        v38 = 0;
      result = dev_err(*a1, "%s[%d]: cmdline: %s\n", v35, v38, *(const char **)(*(_QWORD *)(v8 + 24) + 648LL));
    }
    else
    {
      result = dev_err(*a1, "RB[%d] : %s fault and GX is OFF\n", v12, v13);
    }
    goto LABEL_15;
  }
  v14 = *(_DWORD **)(v10 + 280);
  if ( v14 )
  {
    if ( *(v14 - 1) != -1245822001 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(_QWORD *, __int64))v14)(a1, a3);
    goto LABEL_15;
  }
  v17 = **(_DWORD ***)(a1[1783] + 40LL);
  if ( v17[14] > 0xFFFFFFFD )
  {
    v18 = 0;
  }
  else
  {
    v18 = kgsl_regmap_read(a1 + 1650);
    v17 = **(_DWORD ***)(a1[1783] + 40LL);
  }
  if ( v17[4] > 0xFFFFFFFD )
  {
    v22 = 0;
  }
  else
  {
    v22 = kgsl_regmap_read(a1 + 1650);
    v17 = **(_DWORD ***)(a1[1783] + 40LL);
  }
  if ( v17[5] > 0xFFFFFFFD )
    v23 = 0;
  else
    v23 = kgsl_regmap_read(a1 + 1650);
  adreno_readreg64((__int64)a1, 8u, 9u, v59);
  if ( *(_DWORD *)(**(_QWORD **)(a1[1783] + 40LL) + 40LL) > 0xFFFFFFFD )
    v24 = 0;
  else
    v24 = kgsl_regmap_read(a1 + 1650);
  adreno_readreg64((__int64)a1, 0xBu, 0xCu, &v58);
  if ( *(_DWORD *)(**(_QWORD **)(a1[1783] + 40LL) + 52LL) > 0xFFFFFFFD )
  {
    v25 = 0;
    if ( a3 )
      goto LABEL_34;
  }
  else
  {
    v25 = kgsl_regmap_read(a1 + 1650);
    if ( a3 )
    {
LABEL_34:
      v55 = v25;
      v56 = v24;
      ++*(_DWORD *)(v8 + 280);
      *(_DWORD *)(v8 + 284) = *(_DWORD *)(a3 + 20);
      v26 = *(_QWORD *)(a3 + 8);
      v27 = *a1;
      if ( v26 )
      {
        v29 = *(_QWORD *)(v26 + 24);
        v28 = (const char *)(v29 + 16);
        if ( !v29 )
          v28 = "unknown";
      }
      else
      {
        v28 = "unknown";
        v29 = 0x183560000F4F68LL;
      }
      v39 = *(_QWORD *)(v29 + 8);
      v40 = v18;
      v54 = v28;
      v57 = v22;
      if ( v39 )
        v41 = *(_DWORD *)(v39 + 112);
      else
        v41 = 0;
      v42 = *(_DWORD *)(v26 + 4);
      v43 = (const char *)kgsl_context_type(*(unsigned int *)(v8 + 400));
      dev_err(
        v27,
        "%s[%d]: %s fault ctx %u ctx_type %s ts %u status %8.8X rb %4.4x/%4.4x ib1 %16.16llX/%4.4x ib2 %16.16llX/%4.4x\n",
        v54,
        v41,
        v13,
        v42,
        v43,
        *(_DWORD *)(a3 + 20),
        v40,
        v57,
        v23,
        v59[0],
        v56,
        v58,
        v55);
      v44 = *(_QWORD *)(a3 + 8);
      if ( v44 )
      {
        v46 = *(_QWORD *)(v44 + 24);
        if ( v46 )
          v45 = (const char *)(v46 + 16);
        else
          v45 = "unknown";
      }
      else
      {
        v45 = "unknown";
        v46 = 0x183560000F4F68LL;
      }
      v47 = *(_QWORD *)(v46 + 8);
      if ( v47 )
        v48 = *(_DWORD *)(v47 + 112);
      else
        v48 = 0;
      result = dev_err(*a1, "%s[%d]: cmdline: %s\n", v45, v48, *(const char **)(*(_QWORD *)(v8 + 24) + 648LL));
      if ( a2 )
      {
        v49 = *(_QWORD *)(a3 + 8);
        if ( v49 )
        {
          v51 = *(_QWORD *)(v49 + 24);
          if ( v51 )
            v50 = (const char *)(v51 + 16);
          else
            v50 = "unknown";
        }
        else
        {
          v50 = "unknown";
          v51 = 0x183560000F4F68LL;
        }
        v52 = *(_QWORD *)(v51 + 8);
        if ( v52 )
          v53 = *(_DWORD *)(v52 + 112);
        else
          v53 = 0;
        result = dev_err(
                   *a1,
                   "%s[%d]: %s fault rb %d rb sw r/w %4.4x/%4.4x\n",
                   v50,
                   v53,
                   v13,
                   *(_DWORD *)(a2 + 28),
                   v57,
                   *(_DWORD *)(a2 + 20));
      }
      goto LABEL_15;
    }
  }
  result = dev_err(
             *a1,
             "RB[%d] : %s fault status %8.8X rb %4.4x/%4.4x ib1 %16.16llX/%4.4x ib2 %16.16llX/%4.4x\n",
             v12,
             v13,
             v18,
             v22,
             v23,
             v59[0],
             v24,
             v58,
             v25);
  if ( a2 )
    result = dev_err(
               *a1,
               "RB[%d] : %s fault rb sw r/w %4.4x/%4.4x\n",
               *(_DWORD *)(a2 + 28),
               v13,
               v22,
               *(_DWORD *)(a2 + 20));
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
