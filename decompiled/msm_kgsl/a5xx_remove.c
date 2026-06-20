__int64 __fastcall a5xx_remove(__int64 result)
{
  if ( (*(_BYTE *)(*(_QWORD *)(result + 14264) + 32LL) & 4) != 0 || *(_BYTE *)(result + 20443) == 1 )
    return timer_delete((timer_t)(result + 20504));
  return result;
}
