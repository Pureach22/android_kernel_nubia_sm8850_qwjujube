__int64 __fastcall arm_smmu_global_fault(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x20
  _DWORD **v4; // x8
  _DWORD *v5; // x8
  unsigned int v6; // w0
  _DWORD **v7; // x8
  unsigned int v8; // w20
  _DWORD *v9; // x8
  int v10; // w0
  _DWORD **v11; // x8
  int v12; // w21
  _DWORD *v13; // x8
  int v14; // w0
  _DWORD **v15; // x8
  int v16; // w22
  _DWORD *v17; // x8
  int v18; // w0
  int v19; // w23
  __int64 v20; // x8
  _DWORD *v21; // x8
  __int64 v22; // x20
  __int64 result; // x0
  unsigned int v24; // w21
  unsigned int v25; // w8
  unsigned int v32; // w10
  __int64 v33; // x0

  v2 = *a2;
  if ( (*(_WORD *)(*a2 + 488LL) & 7) != 0 || (_pm_runtime_resume(*a2, 4) & 0x80000000) == 0 )
  {
    v4 = (_DWORD **)a2[6];
    if ( v4 && (v5 = *v4) != nullptr )
    {
      if ( *(v5 - 1) != 616069899 )
        __break(0x8228u);
      v6 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64))v5)(a2, 0, 72);
    }
    else
    {
      v6 = readl_relaxed_0((unsigned int *)(a2[1] + 72LL));
    }
    v7 = (_DWORD **)a2[6];
    v8 = v6;
    if ( v7 && (v9 = *v7) != nullptr )
    {
      if ( *(v9 - 1) != 616069899 )
        __break(0x8228u);
      v10 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64))v9)(a2, 0, 80);
    }
    else
    {
      v10 = readl_relaxed_0((unsigned int *)(a2[1] + 80LL));
    }
    v11 = (_DWORD **)a2[6];
    v12 = v10;
    if ( v11 && (v13 = *v11) != nullptr )
    {
      if ( *(v13 - 1) != 616069899 )
        __break(0x8228u);
      v14 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64))v13)(a2, 0, 84);
    }
    else
    {
      v14 = readl_relaxed_0((unsigned int *)(a2[1] + 84LL));
    }
    v15 = (_DWORD **)a2[6];
    v16 = v14;
    if ( v15 && (v17 = *v15) != nullptr )
    {
      if ( *(v17 - 1) != 616069899 )
        __break(0x8228u);
      v18 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64))v17)(a2, 0, 88);
      if ( v8 )
      {
LABEL_15:
        v19 = v18;
        if ( (unsigned int)__ratelimit(&arm_smmu_global_fault_rs, "arm_smmu_global_fault") )
        {
          v33 = *a2;
          if ( (v8 & 2) != 0 )
            dev_err(
              v33,
              "Blocked unknown Stream ID 0x%hx; boot with \"arm-smmu.disable_bypass=0\" to allow, but this may have secur"
              "ity implications\n",
              (unsigned __int16)v16);
          else
            dev_err(v33, "Unexpected global fault, this could be serious\n");
          dev_err(*a2, "\tGFSR 0x%08x, GFSYNR0 0x%08x, GFSYNR1 0x%08x, GFSYNR2 0x%08x\n", v8, v12, v16, v19);
          v20 = a2[6];
          if ( !v20 )
            goto LABEL_18;
        }
        else
        {
          v20 = a2[6];
          if ( !v20 )
            goto LABEL_18;
        }
        v21 = *(_DWORD **)(v20 + 8);
        if ( v21 )
        {
          if ( *(v21 - 1) != -1008624849 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, _QWORD, __int64, _QWORD))v21)(a2, 0, 72, v8);
          goto LABEL_19;
        }
LABEL_18:
        writel_relaxed_0(v8, (unsigned int *)(a2[1] + 72LL));
LABEL_19:
        v22 = *a2;
        result = 1;
        if ( (*(_WORD *)(*a2 + 488LL) & 7) != 0 )
          return result;
        v24 = 1;
LABEL_49:
        *(_QWORD *)(v22 + 520) = ktime_get_mono_fast_ns(result);
        _pm_runtime_suspend(*a2, 13);
        return v24;
      }
    }
    else
    {
      v18 = readl_relaxed_0((unsigned int *)(a2[1] + 88LL));
      if ( v8 )
        goto LABEL_15;
    }
    v22 = *a2;
    result = 0;
    if ( (*(_WORD *)(*a2 + 488LL) & 7) != 0 )
      return result;
    v24 = 0;
    goto LABEL_49;
  }
  v25 = *(_DWORD *)(v2 + 480);
  while ( v25 )
  {
    _X12 = (unsigned int *)(v2 + 480);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v32 = __ldxr(_X12);
      if ( v32 != v25 )
        break;
      if ( !__stlxr(v25 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    result = 0;
    _ZF = v32 == v25;
    v25 = v32;
    if ( _ZF )
      return result;
  }
  return 0;
}
