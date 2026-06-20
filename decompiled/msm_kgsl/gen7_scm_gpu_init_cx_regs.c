__int64 __fastcall gen7_scm_gpu_init_cx_regs(__int64 a1)
{
  int *v1; // x9
  __int64 v3; // x10
  unsigned int v4; // w9
  int v5; // w8
  unsigned int v6; // w8
  __int64 v7; // x1
  __int64 result; // x0
  __int64 v9; // x10
  __int64 v10; // x9

  v1 = *(int **)(a1 + 14264);
  v3 = *((_QWORD *)v1 + 4);
  v4 = *v1;
  if ( (v3 & 0x1000) != 0 )
    v5 = 3;
  else
    v5 = 1;
  v6 = v5 | ((unsigned int)v3 >> 18) & 4;
  if ( v4 >> 1 == 230528 )
    v7 = v6 | 8;
  else
    v7 = v6;
  LODWORD(result) = kgsl_scm_gpu_init_regs(*(_QWORD *)(a1 + 11168) + 16LL, v7);
  if ( !(_DWORD)result )
  {
    v9 = *(_QWORD *)(a1 + 14264);
    v10 = *(_QWORD *)(v9 + 32);
    if ( (v10 & 0x1000) != 0 )
    {
      *(_BYTE *)(a1 + 20437) = 1;
      v10 = *(_QWORD *)(v9 + 32);
    }
    if ( (v10 & 0x100000) != 0 )
      *(_BYTE *)(a1 + 20438) = 1;
  }
  if ( (_DWORD)result == -95 )
    return 0;
  else
    return (unsigned int)result;
}
