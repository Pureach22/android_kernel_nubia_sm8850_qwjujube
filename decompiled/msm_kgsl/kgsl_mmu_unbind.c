__int64 __fastcall kgsl_mmu_unbind(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 result; // x0
  __int64 (__fastcall **v4)(_QWORD); // x8
  __int64 (__fastcall *v5)(_QWORD); // x8

  v2 = *(_QWORD *)(a2 + 152);
  result = v2 + 56;
  if ( v2 != -56 )
  {
    v4 = *(__int64 (__fastcall ***)(_QWORD))(v2 + 88);
    if ( v4 )
    {
      v5 = *v4;
      if ( v5 )
      {
        if ( *((_DWORD *)v5 - 1) != -919125270 )
          __break(0x8228u);
        return v5(result);
      }
    }
  }
  return result;
}
