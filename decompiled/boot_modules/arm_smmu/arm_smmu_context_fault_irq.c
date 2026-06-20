__int64 __fastcall arm_smmu_context_fault_irq(__int64 a1, __int64 a2)
{
  void (__fastcall *v2)(__int64, __int64); // x9
  __int64 v3; // x0
  __int64 v4; // x1

  v2 = *(void (__fastcall **)(__int64, __int64))(a2 + 144);
  if ( v2 )
  {
    v3 = a2 + 184;
    v4 = *(_QWORD *)(a2 + 152);
    if ( *((_DWORD *)v2 - 1) != 590653315 )
      __break(0x8229u);
    v2(v3, v4);
  }
  return 2;
}
