__int64 __fastcall gen7_gmu_unbind(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  void (__fastcall *v3)(_QWORD); // x8
  __int64 v4; // x0

  v2 = *(_QWORD *)(a2 + 152);
  v3 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v2 + 14264) + 40LL) + 336LL);
  if ( v3 )
  {
    v4 = *(_QWORD *)(a2 + 152);
    if ( *((_DWORD *)v3 - 1) != 994519391 )
      __break(0x8228u);
    v3(v4);
  }
  return gen7_gmu_remove(v2);
}
