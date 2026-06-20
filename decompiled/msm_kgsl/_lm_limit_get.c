__int64 __fastcall lm_limit_get(__int64 a1, _QWORD *a2)
{
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 32LL) & 8) == 0 )
    *a2 = 0;
  *a2 = *(unsigned int *)(a1 + 20636);
  return 0;
}
