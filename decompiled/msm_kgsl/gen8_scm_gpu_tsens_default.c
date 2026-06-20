__int64 __fastcall gen8_scm_gpu_tsens_default(__int64 a1, char a2)
{
  __int64 v3; // x1

  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 35LL) & 8) == 0 )
    return 0;
  if ( (a2 & 1) != 0 )
    v3 = 8;
  else
    v3 = 24;
  return kgsl_scm_gpu_init_regs(*(_QWORD *)(a1 + 11168) + 16LL, v3);
}
