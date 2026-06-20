unsigned __int64 __fastcall gmu_core_capabilities_enabled(__int64 a1, unsigned int a2)
{
  __int64 v2; // x8

  if ( *(_DWORD *)a1 && (v2 = *(_QWORD *)(a1 + 8)) != 0 )
    return ((unsigned __int64)*(unsigned __int8 *)(v2 + ((unsigned __int64)a2 >> 3)) >> (a2 & 7)) & 1;
  else
    return 0;
}
