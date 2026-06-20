__int64 __fastcall adreno_is_reset_recovery(__int64 a1)
{
  return (*(_QWORD *)(a1 + 14240) >> 18) & 1LL;
}
