__int64 __fastcall lm_threshold_count_get(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8

  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 32LL) & 8) != 0 )
    v2 = *(unsigned int *)(a1 + 20644);
  else
    v2 = 0;
  *a2 = v2;
  return 0;
}
