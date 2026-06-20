__int64 __fastcall gen8_scm_gpu_init_cx_regs(__int64 a1)
{
  __int64 v2; // x9
  int v3; // w8
  __int64 result; // x0
  __int64 v5; // x10
  __int64 v6; // x9

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 32LL);
  if ( (v2 & 0x1000) != 0 )
    v3 = 3;
  else
    v3 = 1;
  LODWORD(result) = kgsl_scm_gpu_init_regs(*(_QWORD *)(a1 + 11168) + 16LL, ((unsigned int)v2 >> 18) & 4 | v3 | 8);
  if ( !(_DWORD)result )
  {
    v5 = *(_QWORD *)(a1 + 14264);
    v6 = *(_QWORD *)(v5 + 32);
    if ( (v6 & 0x1000) != 0 )
    {
      *(_BYTE *)(a1 + 20437) = 1;
      v6 = *(_QWORD *)(v5 + 32);
    }
    if ( (v6 & 0x100000) != 0 )
      *(_BYTE *)(a1 + 20438) = 1;
  }
  if ( (_DWORD)result == -95 )
    return 0;
  else
    return (unsigned int)result;
}
