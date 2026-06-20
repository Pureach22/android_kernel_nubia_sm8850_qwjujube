__int64 __fastcall arm_tbu_micro_idle_allow(__int64 result)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(*(_QWORD *)result + 152LL);
  if ( *(_BYTE *)(v1 + 80) == 1 )
    return _arm_tbu_micro_idle_cfg(*(const char ****)(v1 + 24), 0, 1 << (*(_DWORD *)(v1 + 56) >> 10));
  return result;
}
