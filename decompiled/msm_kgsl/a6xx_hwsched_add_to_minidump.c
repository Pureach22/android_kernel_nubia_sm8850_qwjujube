__int64 __fastcall a6xx_hwsched_add_to_minidump(_QWORD *a1)
{
  __int64 result; // x0
  unsigned __int64 v3; // x8
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x22
  _QWORD *v10; // x24
  int v11; // w9
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x10
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  char s[24]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v18; // [xsp+20h] [xbp-10h]
  __int64 v19; // [xsp+28h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = kgsl_add_va_to_minidump(*a1, "kgsl_hwsched_device", a1 - 206, 26328);
  if ( (_DWORD)result )
    goto LABEL_2;
  v3 = *(a1 - 203);
  if ( v3 )
  {
    if ( v3 <= 0xFFFFFFFFFFFFF000LL )
    {
      result = kgsl_add_va_to_minidump(*a1, "kgsl_gmu_log", *(_QWORD *)(v3 + 8), *(_QWORD *)(v3 + 40));
      if ( (_DWORD)result )
        goto LABEL_2;
    }
  }
  v4 = *(a1 - 201);
  if ( v4 )
  {
    if ( v4 <= 0xFFFFFFFFFFFFF000LL )
    {
      result = kgsl_add_va_to_minidump(*a1, "kgsl_hfi_mem", *(_QWORD *)(v4 + 8), *(_QWORD *)(v4 + 40));
      if ( (_DWORD)result )
        goto LABEL_2;
    }
  }
  if ( (v5 = a1[1083]) != 0
    && v5 <= 0xFFFFFFFFFFFFF000LL
    && (result = kgsl_add_va_to_minidump(*a1, "kgsl_gmu_vrb", *(_QWORD *)(v5 + 8), *(_QWORD *)(v5 + 40)), (_DWORD)result)
    || (v6 = *(a1 - 204)) != 0
    && v6 <= 0xFFFFFFFFFFFFF000LL
    && (result = kgsl_add_va_to_minidump(*a1, "kgsl_gmu_dump_mem", *(_QWORD *)(v6 + 8), *(_QWORD *)(v6 + 40)),
        (_DWORD)result)
    || (v7 = a1[1084]) != 0
    && v7 <= 0xFFFFFFFFFFFFF000LL
    && (result = kgsl_add_va_to_minidump(*a1, "kgsl_gmu_trace", *(_QWORD *)(v7 + 8), *(_QWORD *)(v7 + 40)),
        (_DWORD)result) )
  {
LABEL_2:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v8 = *((unsigned int *)a1 + 5610);
  if ( !(_DWORD)v8 )
  {
LABEL_36:
    v15 = a1[3076];
    if ( !v15
      || v15 > 0xFFFFFFFFFFFFF000LL
      || (result = kgsl_add_va_to_minidump(*a1, "kgsl_hfi_big_ib", *(_QWORD *)(v15 + 8), *(_QWORD *)(v15 + 40)),
          !(_DWORD)result) )
    {
      v16 = a1[3077];
      result = 0;
      if ( v16 )
      {
        if ( v16 <= 0xFFFFFFFFFFFFF000LL )
          result = kgsl_add_va_to_minidump(*a1, "kgsl_hfi_big_ib_rec", *(_QWORD *)(v16 + 8), *(_QWORD *)(v16 + 40));
      }
    }
    goto LABEL_2;
  }
  v9 = 0;
  v10 = a1 + 2618;
  while ( v9 != 33 )
  {
    v11 = *((_DWORD *)v10 - 7);
    v18 = 0;
    memset(s, 0, sizeof(s));
    if ( v11 <= 13 )
    {
      if ( v11 == 1 )
      {
        snprintf(s, 0x20u, "kgsl_gmu_rb_%d", 0);
      }
      else
      {
        if ( v11 != 2 )
          goto LABEL_20;
        strcpy(s, "kgsl_scratch");
      }
      goto LABEL_34;
    }
    if ( v11 == 14 )
    {
      v12 = *(_QWORD *)"kgsl_gmu_kernel_profiling";
      v13 = *(_QWORD *)"_kernel_profiling";
      v14 = *(_QWORD *)"profiling";
      LOWORD(v18) = 103;
LABEL_32:
      *(_QWORD *)s = v12;
      *(_QWORD *)&s[8] = v13;
      *(_QWORD *)&s[16] = v14;
      goto LABEL_34;
    }
    if ( v11 == 15 )
    {
      v12 = *(_QWORD *)"kgsl_gmu_user_profiling";
      v13 = *(_QWORD *)"_user_profiling";
      v14 = *(_QWORD *)"ofiling";
      goto LABEL_32;
    }
    if ( v11 != 16 )
      goto LABEL_20;
    strcpy(s, "kgsl_gmu_cmd_buffer");
LABEL_34:
    result = kgsl_add_va_to_minidump(*a1, s, *(_QWORD *)(*v10 + 8LL), *(_QWORD *)(*v10 + 40LL));
    if ( (_DWORD)result )
      goto LABEL_2;
    v8 = *((unsigned int *)a1 + 5610);
LABEL_20:
    ++v9;
    v10 += 6;
    if ( v9 >= v8 )
      goto LABEL_36;
  }
  __break(0x5512u);
  return a6xx_hwsched_gmu_boot(result);
}
