__int64 __fastcall gen7_hwsched_add_to_minidump(_QWORD *a1)
{
  __int64 result; // x0
  unsigned __int64 v3; // x8
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x22
  _QWORD *v9; // x24
  int v10; // w9
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x10
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  char s[24]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v17; // [xsp+20h] [xbp-10h]
  __int64 v18; // [xsp+28h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = kgsl_add_va_to_minidump(*a1, "kgsl_hwsched_device", a1 - 222, 26592);
  if ( (_DWORD)result )
    goto LABEL_2;
  v3 = *(a1 - 220);
  if ( v3 )
  {
    if ( v3 <= 0xFFFFFFFFFFFFF000LL )
    {
      result = kgsl_add_va_to_minidump(*a1, "kgsl_gmu_log", *(_QWORD *)(v3 + 8), *(_QWORD *)(v3 + 40));
      if ( (_DWORD)result )
        goto LABEL_2;
    }
  }
  if ( (v4 = *(a1 - 216)) != 0
    && v4 <= 0xFFFFFFFFFFFFF000LL
    && (result = kgsl_add_va_to_minidump(*a1, "kgsl_hfi_mem", *(_QWORD *)(v4 + 8), *(_QWORD *)(v4 + 40)), (_DWORD)result)
    || (v5 = a1[1083]) != 0
    && v5 <= 0xFFFFFFFFFFFFF000LL
    && (result = kgsl_add_va_to_minidump(*a1, "kgsl_gmu_vrb", *(_QWORD *)(v5 + 8), *(_QWORD *)(v5 + 40)), (_DWORD)result)
    || (v6 = a1[1084]) != 0
    && v6 <= 0xFFFFFFFFFFFFF000LL
    && (result = kgsl_add_va_to_minidump(*a1, "kgsl_gmu_trace", *(_QWORD *)(v6 + 8), *(_QWORD *)(v6 + 40)),
        (_DWORD)result) )
  {
LABEL_2:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v7 = *((unsigned int *)a1 + 5610);
  if ( !(_DWORD)v7 )
  {
LABEL_33:
    v14 = a1[3077];
    if ( !v14
      || v14 > 0xFFFFFFFFFFFFF000LL
      || (result = kgsl_add_va_to_minidump(*a1, "kgsl_hfi_big_ib", *(_QWORD *)(v14 + 8), *(_QWORD *)(v14 + 40)),
          !(_DWORD)result) )
    {
      v15 = a1[3078];
      result = 0;
      if ( v15 )
      {
        if ( v15 <= 0xFFFFFFFFFFFFF000LL )
          result = kgsl_add_va_to_minidump(*a1, "kgsl_hfi_big_ib_rec", *(_QWORD *)(v15 + 8), *(_QWORD *)(v15 + 40));
      }
    }
    goto LABEL_2;
  }
  v8 = 0;
  v9 = a1 + 2618;
  while ( v8 != 33 )
  {
    v10 = *((_DWORD *)v9 - 7);
    v17 = 0;
    memset(s, 0, sizeof(s));
    if ( v10 <= 13 )
    {
      if ( v10 == 1 )
      {
        snprintf(s, 0x20u, "kgsl_gmu_rb_%d", 0);
      }
      else
      {
        if ( v10 != 2 )
          goto LABEL_17;
        strcpy(s, "kgsl_scratch");
      }
      goto LABEL_31;
    }
    if ( v10 == 14 )
    {
      v11 = *(_QWORD *)"kgsl_gmu_kernel_profiling";
      v12 = *(_QWORD *)"_kernel_profiling";
      v13 = *(_QWORD *)"profiling";
      LOWORD(v17) = 103;
LABEL_29:
      *(_QWORD *)s = v11;
      *(_QWORD *)&s[8] = v12;
      *(_QWORD *)&s[16] = v13;
      goto LABEL_31;
    }
    if ( v10 == 15 )
    {
      v11 = *(_QWORD *)"kgsl_gmu_user_profiling";
      v12 = *(_QWORD *)"_user_profiling";
      v13 = *(_QWORD *)"ofiling";
      goto LABEL_29;
    }
    if ( v10 != 16 )
      goto LABEL_17;
    strcpy(s, "kgsl_gmu_cmd_buffer");
LABEL_31:
    result = kgsl_add_va_to_minidump(*a1, s, *(_QWORD *)(*v9 + 8LL), *(_QWORD *)(*v9 + 40LL));
    if ( (_DWORD)result )
      goto LABEL_2;
    v7 = *((unsigned int *)a1 + 5610);
LABEL_17:
    ++v8;
    v9 += 6;
    if ( v8 >= v7 )
      goto LABEL_33;
  }
  __break(0x5512u);
  return gen7_hwsched_gmu_boot(result);
}
