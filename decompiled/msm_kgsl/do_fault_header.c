__int64 __fastcall do_fault_header(_QWORD *a1, __int64 a2, unsigned int a3)
{
  __int64 v6; // x8
  __int64 v7; // x23
  char v8; // w19
  const char *v9; // x3
  __int64 result; // x0
  _DWORD *v11; // x8
  _DWORD *v12; // x8
  int v13; // w19
  int v14; // w20
  int v15; // w23
  int v16; // w24
  int v17; // w25
  __int64 v18; // x11
  __int64 v19; // x8
  int v20; // w26
  __int64 v21; // x8
  const char *v22; // x9
  __int64 v23; // x8
  const char *v24; // x0
  __int64 v25; // x8
  const char *v26; // x2
  __int64 v27; // x8
  __int64 v28; // x8
  int v29; // w3
  int v30; // [xsp+1Ch] [xbp-34h]
  __int64 v31; // [xsp+20h] [xbp-30h]
  const char *v32; // [xsp+28h] [xbp-28h]
  __int64 v33; // [xsp+30h] [xbp-20h]
  __int64 v34; // [xsp+38h] [xbp-18h] BYREF
  __int64 v35[2]; // [xsp+40h] [xbp-10h] BYREF

  v35[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a1[1783];
  v34 = 0;
  v35[0] = 0;
  v7 = *(_QWORD *)(v6 + 40);
  v8 = adreno_gx_is_on((__int64)a1);
  if ( (v8 & 1) != 0 )
    v9 = "ON";
  else
    v9 = "OFF";
  result = dev_err(*a1, "Fault id:%d and GX is %s\n", a3, v9);
  if ( !a2 && (v8 & 1) == 0 )
    goto LABEL_12;
  v11 = *(_DWORD **)(v7 + 280);
  if ( v11 )
  {
    if ( *(v11 - 1) != -1245822001 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(_QWORD *, __int64))v11)(a1, a2);
  }
  else
  {
    if ( (v8 & 1) != 0 )
    {
      v12 = **(_DWORD ***)(a1[1783] + 40LL);
      if ( v12[14] > 0xFFFFFFFD )
      {
        v13 = 0;
      }
      else
      {
        v13 = kgsl_regmap_read(a1 + 1650);
        v12 = **(_DWORD ***)(a1[1783] + 40LL);
      }
      if ( v12[4] > 0xFFFFFFFD )
      {
        v14 = 0;
      }
      else
      {
        v14 = kgsl_regmap_read(a1 + 1650);
        v12 = **(_DWORD ***)(a1[1783] + 40LL);
      }
      if ( v12[5] > 0xFFFFFFFD )
        v15 = 0;
      else
        v15 = kgsl_regmap_read(a1 + 1650);
      adreno_readreg64((__int64)a1, 8u, 9u, v35);
      if ( *(_DWORD *)(**(_QWORD **)(a1[1783] + 40LL) + 40LL) > 0xFFFFFFFD )
        v16 = 0;
      else
        v16 = kgsl_regmap_read(a1 + 1650);
      adreno_readreg64((__int64)a1, 0xBu, 0xCu, &v34);
      if ( *(_DWORD *)(**(_QWORD **)(a1[1783] + 40LL) + 52LL) > 0xFFFFFFFD )
        v17 = 0;
      else
        v17 = kgsl_regmap_read(a1 + 1650);
      result = dev_err(
                 *a1,
                 "status %8.8X rb %4.4x/%4.4x ib1 %16.16llX/%4.4x ib2 %16.16llX/%4.4x\n",
                 v13,
                 v14,
                 v15,
                 v35[0],
                 v16,
                 v34,
                 v17);
      if ( !a2 )
        goto LABEL_12;
    }
    else if ( !a2 )
    {
      goto LABEL_12;
    }
    v18 = *(_QWORD *)(a2 + 8);
    *(_DWORD *)(v18 + 284) = *(_DWORD *)(a2 + 20);
    ++*(_DWORD *)(*(_QWORD *)(a2 + 8) + 280LL);
    v19 = *(_QWORD *)(a2 + 8);
    v20 = *(_DWORD *)(v19 + 4);
    if ( v19 )
    {
      v21 = *(_QWORD *)(v19 + 24);
      v22 = (const char *)(v21 + 16);
      if ( !v21 )
        v22 = "unknown";
    }
    else
    {
      v21 = 0x183560000F4F68LL;
      v22 = "unknown";
    }
    v32 = v22;
    v23 = *(_QWORD *)(v21 + 8);
    v31 = *a1;
    if ( v23 )
      v30 = *(_DWORD *)(v23 + 112);
    else
      v30 = 0;
    v33 = v18;
    v24 = (const char *)kgsl_context_type(*(unsigned int *)(v18 + 400));
    dev_err(
      v31,
      "%s[%d]: ctx %u ctx_type %s ts %u policy %lX dispatch_queue=%d\n",
      v32,
      v30,
      v20,
      v24,
      *(_DWORD *)(a2 + 20),
      *(_QWORD *)(a2 + 80),
      *(_DWORD *)(*(_QWORD *)(a2 + 8) + 292LL));
    v25 = *(_QWORD *)(a2 + 8);
    if ( v25 )
    {
      v27 = *(_QWORD *)(v25 + 24);
      if ( v27 )
        v26 = (const char *)(v27 + 16);
      else
        v26 = "unknown";
    }
    else
    {
      v26 = "unknown";
      v27 = 0x183560000F4F68LL;
    }
    v28 = *(_QWORD *)(v27 + 8);
    if ( v28 )
      v29 = *(_DWORD *)(v28 + 112);
    else
      v29 = 0;
    result = dev_err(*a1, "%s[%d]: cmdline: %s\n", v26, v29, *(const char **)(*(_QWORD *)(v33 + 24) + 648LL));
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
