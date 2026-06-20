__int64 __fastcall adreno_drawctxt_set_guilty(__int64 result, __int64 a2)
{
  if ( a2 )
  {
    *(_DWORD *)(a2 + 48) = 1;
    return adreno_drawctxt_invalidate(result, a2);
  }
  return result;
}
