__int64 __fastcall adreno_verify_cmdobj(_QWORD *a1, __int64 a2, __int64 a3, unsigned int a4)
{
  _QWORD *v4; // x24
  __int64 v8; // x23
  __int64 v9; // x26
  __int64 v10; // x8
  _QWORD *v11; // x27
  _QWORD *v12; // x22
  __int64 v13; // x5
  _QWORD *v14; // x28
  const char *v15; // x2
  __int64 v16; // x8
  __int64 v17; // x3
  const char *v19; // x2
  __int64 v20; // x8
  __int64 v21; // x3
  __int64 v22; // x8
  __int64 v23; // x8

  if ( !a4 )
    return 0;
  v4 = (_QWORD *)*a1;
  v8 = 0;
  v9 = a4;
  while ( 1 )
  {
    v10 = *(_QWORD *)(a3 + 8 * v8);
    if ( *(_DWORD *)(v10 + 16) == 1 )
      break;
LABEL_4:
    if ( ++v8 == v9 )
      return 0;
  }
  v11 = (_QWORD *)(v10 + 88);
  v12 = (_QWORD *)(v10 + 88);
  while ( 1 )
  {
    v12 = (_QWORD *)*v12;
    if ( v12 == v11 )
    {
      *((_BYTE *)v4 + 10952) = 0;
      goto LABEL_4;
    }
    v13 = v12[5];
    v14 = (_QWORD *)*a1;
    if ( (unsigned __int64)(v13 - 0x400000) <= 0xFFFFFFFFFFC00000LL )
      break;
    if ( (kgsl_mmu_gpuaddr_in_range(*(_QWORD *)(a1[1] + 64LL), v12[4], v12[5]) & 1) == 0 || (v12[4] & 3) != 0 )
    {
      if ( a2 )
      {
        v22 = *(_QWORD *)(a2 + 24);
        if ( v22 )
          v15 = (const char *)(v22 + 16);
        else
          v15 = "unknown";
        v16 = *(_QWORD *)(v22 + 8);
        if ( !v16 )
          goto LABEL_23;
LABEL_13:
        v17 = *(unsigned int *)(v16 + 112);
      }
      else
      {
        v15 = "unknown";
        v16 = MEMORY[0x183560000F4F70];
        if ( MEMORY[0x183560000F4F70] )
          goto LABEL_13;
LABEL_23:
        v17 = 0;
      }
      dev_err(*v14, "%s[%d]: ctxt %u invalid ib gpuaddr %llX\n", v15, v17, *(unsigned int *)(a2 + 4), v12[4]);
      return 4294967274LL;
    }
  }
  if ( a2 )
  {
    v23 = *(_QWORD *)(a2 + 24);
    if ( v23 )
      v19 = (const char *)(v23 + 16);
    else
      v19 = "unknown";
    v20 = *(_QWORD *)(v23 + 8);
    if ( v20 )
      goto LABEL_18;
  }
  else
  {
    v19 = "unknown";
    v20 = MEMORY[0x183560000F4F70];
    if ( MEMORY[0x183560000F4F70] )
    {
LABEL_18:
      v21 = *(unsigned int *)(v20 + 112);
      goto LABEL_30;
    }
  }
  v21 = 0;
LABEL_30:
  dev_err(*v14, "%s[%d]: ctxt %u invalid ib size %lld\n", v19, v21, *(unsigned int *)(a2 + 4), v13);
  return 4294967274LL;
}
