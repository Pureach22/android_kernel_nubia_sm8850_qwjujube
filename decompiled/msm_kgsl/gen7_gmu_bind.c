__int64 __fastcall gen7_gmu_bind(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 result; // x0
  __int64 (__fastcall *v5)(_QWORD); // x8
  unsigned int v6; // w20

  v2 = *(_QWORD *)(a2 + 152);
  v3 = *(_QWORD *)(*(_QWORD *)(v2 + 14264) + 40LL);
  result = gen7_gmu_probe(v2, a1 - 16);
  if ( !(_DWORD)result )
  {
    v5 = *(__int64 (__fastcall **)(_QWORD))(v3 + 328);
    if ( v5 )
    {
      if ( *((_DWORD *)v5 - 1) != -83892780 )
        __break(0x8228u);
      result = v5(v2);
      if ( (_DWORD)result )
      {
        v6 = result;
        gen7_gmu_remove(v2);
        return v6;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
