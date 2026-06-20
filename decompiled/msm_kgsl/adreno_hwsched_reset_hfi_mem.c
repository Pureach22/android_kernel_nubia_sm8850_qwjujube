unsigned int *__fastcall adreno_hwsched_reset_hfi_mem(unsigned int *result, __int64 a2, __int64 a3)
{
  unsigned int *v3; // x19
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x21
  char *v6; // x22
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x8

  v3 = result;
  v4 = result[5610];
  if ( (_DWORD)v4 )
  {
    v5 = 0;
    v6 = (char *)(result + 5236);
    while ( v5 != 32 )
    {
      if ( (*(v6 - 31) & 2) != 0 && *(_QWORD *)(*(_QWORD *)v6 + 8LL) )
      {
        result = (unsigned int *)memset(*(void **)(*(_QWORD *)v6 + 8LL), 0, *(_QWORD *)(*(_QWORD *)v6 + 40LL));
        v4 = v3[5610];
      }
      ++v5;
      v6 += 48;
      if ( v5 >= v4 )
        goto LABEL_8;
    }
    __break(0x5512u);
    return (unsigned int *)print_fault_syncobj(result, a2, a3);
  }
  else
  {
LABEL_8:
    if ( (*((_QWORD *)v3 + 1780) & 0x200) != 0 && (*(_BYTE *)(*((_QWORD *)v3 + 1783) + 35LL) & 1) != 0 )
    {
      v7 = *((_QWORD *)v3 + 2931);
      if ( v7 && *(_QWORD *)(v7 + 8) )
        result = (unsigned int *)memset(*(void **)(v7 + 8), 0, *(_QWORD *)(v7 + 40));
      v8 = *((_QWORD *)v3 + 2932);
      if ( v8 && *(_QWORD *)(v8 + 8) )
        result = (unsigned int *)memset(*(void **)(v8 + 8), 0, *(_QWORD *)(v8 + 40));
      v9 = *((_QWORD *)v3 + 2933);
      if ( v9 && *(_QWORD *)(v9 + 8) )
        result = (unsigned int *)memset(*(void **)(v9 + 8), 0, *(_QWORD *)(v9 + 40));
      v10 = *((_QWORD *)v3 + 2934);
      if ( v10 )
      {
        if ( *(_QWORD *)(v10 + 8) )
          return (unsigned int *)memset(*(void **)(v10 + 8), 0, *(_QWORD *)(v10 + 40));
      }
    }
  }
  return result;
}
