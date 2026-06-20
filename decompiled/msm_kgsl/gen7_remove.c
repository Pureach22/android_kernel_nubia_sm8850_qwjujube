__int64 __fastcall gen7_remove(__int64 a1)
{
  __int64 result; // x0

  result = to_gen7_gmu();
  if ( ((*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 32LL) & 4) != 0 || *(_BYTE *)(a1 + 20443) == 1)
    && (*(_QWORD *)(result + 1096) & 1) != 0 )
  {
    return timer_delete((timer_t)(a1 + 20504));
  }
  return result;
}
