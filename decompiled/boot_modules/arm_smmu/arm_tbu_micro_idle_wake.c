__int64 __fastcall arm_tbu_micro_idle_wake(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x1

  v1 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
  if ( *(_BYTE *)(v1 + 80) != 1 )
    return 0;
  v2 = (unsigned int)(1 << (*(_DWORD *)(v1 + 56) >> 10));
  return _arm_tbu_micro_idle_cfg(*(_QWORD *)(v1 + 24), v2, (unsigned int)v2);
}
