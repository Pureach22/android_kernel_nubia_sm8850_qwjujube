__int64 __fastcall kgsl_mmu_start(__int64 a1)
{
  __int64 v1; // x8
  __int64 (__fastcall *v2)(_QWORD); // x8
  __int64 v3; // x0

  v1 = *(_QWORD *)(a1 + 88);
  if ( !v1 )
    return 0;
  v2 = *(__int64 (__fastcall **)(_QWORD))(v1 + 8);
  if ( !v2 )
    return 0;
  v3 = a1 + 56;
  if ( *((_DWORD *)v2 - 1) != -1979566203 )
    __break(0x8228u);
  return v2(v3);
}
