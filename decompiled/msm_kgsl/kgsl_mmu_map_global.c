__int64 __fastcall kgsl_mmu_map_global(__int64 result)
{
  __int64 v1; // x8
  __int64 (__fastcall *v2)(_QWORD); // x8
  __int64 v3; // x0

  v1 = *(_QWORD *)(result + 88);
  if ( v1 )
  {
    v2 = *(__int64 (__fastcall **)(_QWORD))(v1 + 88);
    if ( v2 )
    {
      v3 = result + 56;
      if ( *((_DWORD *)v2 - 1) != -104988489 )
        __break(0x8228u);
      return v2(v3);
    }
  }
  return result;
}
