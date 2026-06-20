__int64 __fastcall adreno_perfcounter_get_name(__int64 a1, unsigned int a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 48LL);
  if ( v2 && *(_DWORD *)(v2 + 8) > a2 )
    return *(_QWORD *)(*(_QWORD *)v2 + 56LL * a2 + 16);
  else
    return 0;
}
